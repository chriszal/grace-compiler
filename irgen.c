#include <llvm-c/Core.h>
#include <stdio.h>
#include <string.h>
#include "ast.h"

LLVMValueRef generate_ir(ast node)
{
  if (node == NULL)
  {
    return NULL;
  }

  LLVMModuleRef module = LLVMModuleCreateWithName("my_module");
  LLVMBuilderRef builder = LLVMCreateBuilder();

  // Variables for holding function and block
  LLVMValueRef func = NULL;
  LLVMBasicBlockRef block = NULL;

  // Generate IR based on AST nodes
  switch (node->k)
  {
  case FUNCTION_DEF:
  {
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
    func = LLVMAddFunction(module, node->left->data.str, funcType);
    block = LLVMAppendBasicBlock(func, "entry");
    LLVMPositionBuilderAtEnd(builder, block);
    break;
  }
  case VAR:
  {
    ast id_list = node->left;
    while (id_list != NULL)
    {
      LLVMTypeRef varType = LLVMInt32Type();
      LLVMValueRef var = LLVMBuildAlloca(builder, varType, id_list->data.str);
      id_list = id_list->right;
    }
    break;
  }
  case ASSIGN:
  {
    ast l_value = node->left;
    ast expr = node->right;
    LLVMValueRef var = LLVMBuildLoad(builder, LLVMBuildAlloca(builder, LLVMInt32Type(), l_value->data.str), "");
    LLVMValueRef value = generate_ir(expr);
    LLVMBuildStore(builder, value, var);
    break;
  }
  case FUNC_CALL:
  {
    char *funcName = node->data.str;

    // Handle built-in function "puts"
    if (strcmp(funcName, "puts") == 0)
    {
      LLVMValueRef putsFunc = LLVMGetNamedFunction(module, "puts");
      LLVMValueRef arg = generate_ir(node->left);
      LLVMBuildCall(builder, putsFunc, &arg, 1, "");
    }
    //HERE I CAN HANDLE MORE BUILD IN FUNCTIONS
    break;
  }
  case BLOCK:
  {
    ast stmts = node->left;
    while (stmts != NULL)
    {
      generate_ir(stmts->left);
      stmts = stmts->right;
    }
    break;
  }
  case RETURN:
  {
    ast expr = node->left;
    LLVMValueRef returnValue = generate_ir(expr);
    LLVMBuildRet(builder, returnValue);
    break;
  }
  case NUM:
  {
    int num = node->data.num;
    return LLVMConstInt(LLVMInt32Type(), num, 0);
  }
  case STR:
  {
    char *str = node->data.str;
    LLVMValueRef strValue = LLVMBuildGlobalStringPtr(builder, str, "globalstr");
    return strValue;
  }
  // Handle other cases...
  default:
    break;
  }

  LLVMDisposeBuilder(builder);

  // Print the generated LLVM IR
  char *irCode = LLVMPrintModuleToString(module);
  printf("%s", irCode);
  LLVMDisposeMessage(irCode);

  // Clean up LLVM objects
  LLVMDisposeModule(module);

  return NULL;
}
