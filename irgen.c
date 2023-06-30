#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ast.h"
#include <llvm-c/Core.h>
#include <llvm-c/Analysis.h>
#include <llvm-c/ExecutionEngine.h>
#include <llvm-c/Target.h>
#include <llvm-c/Transforms/Scalar.h>
#include <llvm-c/Transforms/Utils.h>

LLVMBuilderRef builder;
LLVMModuleRef mod;
LLVMValueRef mainFunc;
LLVMValueRef putiFunc;
LLVMValueRef theVars;
LLVMTypeRef theVars_type;
LLVMValueRef writeIntegerFunc;
LLVMTypeRef writeInteger_type;

void irgen_aux(ast node)
{
  if (node == NULL)
  {
    printf("Skipping NULL node\n");
    return;
  }

  switch (node->k)
  {
  case FUNCTION_DEF:
  {
    // printf("Processing node FUNCTION_DEF kind. \n");
    LLVMTypeRef funcType;
    switch (node->left->right->k)
    {
    case INT:
      funcType = LLVMFunctionType(LLVMInt32Type(), NULL, 0, 0);
      break;
    case CHAR:
      funcType = LLVMFunctionType(LLVMInt8Type(), NULL, 0, 0);
      break;
    case NOTHING:
      funcType = LLVMFunctionType(LLVMVoidType(), NULL, 0, 0);
      break;
    default:
      break;
    }
    mainFunc = LLVMAddFunction(mod, node->left->data.str, funcType);
    LLVMBasicBlockRef entry = LLVMAppendBasicBlock(mainFunc, "entry");
    LLVMPositionBuilderAtEnd(builder, entry);
    if (node->middle != NULL)
    {
      irgen_aux(node->middle);
    }
    if (node->right != NULL)
    {
      irgen_aux(node->right);
    }
    LLVMBuildRetVoid(builder);
    // printf("Finished node FUNCTION_DEF kind. \n");
    return;
  }

  case VAR:
  {
    // printf("Processing VAR kind. \n");

    LLVMTypeRef varType;
    switch (node->right->k)
    {
    case INT:
      varType = LLVMInt32Type();
      break;
    case CHAR:
      varType = LLVMInt8Type();
      break;
    case ARRAY:
      varType = LLVMArrayType(LLVMInt32Type(), node->right->data.num);
      break;
    default:
      break;
    }
    // making them global for now because i do not have the symbol table to grab the id after
    LLVMValueRef globalVar = LLVMAddGlobal(mod, varType, node->left->data.str);
    LLVMSetLinkage(globalVar, LLVMInternalLinkage);  
    LLVMSetInitializer(globalVar, LLVMConstNull(varType)); 

    node->addr = globalVar;
    // printf("Finished VAR kind. \n");

    return;
  }
  case ASSIGN:
  {
    // printf("Processing ASSIGN kind. \n");

    irgen_aux(node->right);
    LLVMValueRef val = node->right->addr;

    irgen_aux(node->left);
    LLVMValueRef var = node->left->addr;

    LLVMBuildStore(builder, val, var);
    // printf("Finished Assign kind. \n");

    return;
  }

  case ID:
  {
    // printf("Processing ID kind. \n");
    LLVMValueRef var = LLVMGetNamedGlobal(mod, node->data.str);
    if (var == NULL)
    {
      fprintf(stderr, "Variable %s not declared\n", node->data.str);
      exit(-1);
    }
    node->addr = var;
    // printf("Finished ID kind. \n");
    return;
  }

  case NUM:
    // printf("Processing NUM kind. \n");
    // printf("Num: %d\n", node->data.num);
    node->addr = LLVMConstInt(LLVMInt32Type(), node->data.num, 0);
    // printf("Finished NUM kind. \n");
    return;

  case ID_LIST:
  {
    printf("Processing ID_LIST kind. \n");
    ast currentNode = node;
    while (currentNode != NULL)
    {
      // process each identifier node
      irgen_aux(currentNode);
      currentNode = currentNode->right;
    }
    printf("Finished ID_LIST kind. \n");
    return;
  }

  case BLOCK:
  {
    // printf("Processing BLOCK kind. \n");
    ast currentNode = node->left;
    while (currentNode != NULL)
    {
      // process each statement node
      irgen_aux(currentNode->left);
      currentNode = currentNode->right;
    }
    // printf("Finished processing BLOCK kind. \n");
    return;
  }

  case ARG_LIST:
  {
    // printf("Processing ARG_LIST kind. \n");

    LLVMValueRef *args = malloc(sizeof(LLVMValueRef));
    int num_args = 0;

    for (ast currentNode = node; currentNode != NULL; currentNode = currentNode->right)
    {
      irgen_aux(currentNode->left);
      args[num_args] = currentNode->left->addr;
      num_args++;
    }

    node->addr = args;
    node->data.num = num_args;

    // printf("Finished processing ARG_LIST kind. \n");
    return;
  }

  case STR:
    node->addr = LLVMBuildGlobalStringPtr(builder, node->data.str, "globalstr");
    return;
  case FUNC_CALL:
  {
    // printf("Processing FUNC_CALL kind. \n");
    LLVMValueRef func = LLVMGetNamedFunction(mod, node->data.str);
    if (func == NULL)
    {
      fprintf(stderr, "Function %s not declared\n", node->data.str);
      exit(-1);
    }

    if (strcmp(node->data.str, "puti") == 0)
    {
      func = writeIntegerFunc;
    }

    if (node->left != NULL)
    {
      irgen_aux(node->left);
    }
    LLVMValueRef *args = (LLVMValueRef *)node->left->addr;
    int num_args = node->left->data.num;

    if (LLVMGetTypeKind(LLVMTypeOf(args[0])) == LLVMPointerTypeKind)
    {
      args[0] = LLVMBuildLoad(builder, args[0], "");
    }

    LLVMBuildCall(builder, func, args, num_args, "");
    // printf("Finished FUNC_CALL kind. \n");
    return;
  }

  case NEGATIVE:
  {
    LLVMValueRef val = LLVMBuildNeg(builder, node->left->addr, "negtmp");
    node->addr = val;
    break;
  }
  case PLUS:
  {
    LLVMValueRef leftVal = node->left->addr;
    LLVMValueRef rightVal = node->right->addr;
    LLVMValueRef sumVal = LLVMBuildAdd(builder, leftVal, rightVal, "addtmp");
    node->addr = sumVal;
    break;
  }

  default:
    break;
  }
}

void irgen(ast root)
{
  mod = LLVMModuleCreateWithName("minibasic");
  builder = LLVMCreateBuilder();
  theVars_type = LLVMArrayType(LLVMInt32Type(), 26);
  theVars = LLVMAddGlobal(mod, theVars_type, "vars");
  LLVMSetLinkage(theVars, LLVMInternalLinkage);
  LLVMSetInitializer(theVars, LLVMConstNull(theVars_type));

  LLVMTypeRef writeInteger_param_types[] = {LLVMInt32Type()};
  writeInteger_type = LLVMFunctionType(LLVMVoidType(), writeInteger_param_types, 1, 0);
  writeIntegerFunc = LLVMAddFunction(mod, "writeInteger", writeInteger_type);
  LLVMSetLinkage(writeIntegerFunc, LLVMExternalLinkage);

  LLVMTypeRef putiParamtypes[] = {LLVMInt32Type()};
  LLVMTypeRef puti_type = LLVMFunctionType(LLVMVoidType(), putiParamtypes, 1, 0);
  putiFunc = LLVMAddFunction(mod, "puti", puti_type);
  LLVMSetLinkage(putiFunc, LLVMExternalLinkage);
  // LLVMAddAlias(mod, puti_type, writeIntegerFunc, "puti");

  // Start generating code
  irgen_aux(root);

  // Handle necessary cleanup
  LLVMDisposeBuilder(builder);
  char *irCode = LLVMPrintModuleToString(mod);
  printf("%s", irCode);
  LLVMDisposeMessage(irCode);
  LLVMDisposeModule(mod);
}
