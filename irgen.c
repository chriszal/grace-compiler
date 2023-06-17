#include <llvm-c/Core.h>
#include <stdio.h>
#include "ast.h"

LLVMValueRef generate_ir(ast node) {
  if (node == NULL) {
    return NULL;
  }

  LLVMModuleRef module = LLVMModuleCreateWithName("my_module");
  LLVMBuilderRef builder = LLVMCreateBuilder();

  // Define the function signature
  LLVMTypeRef paramTypes[] = { LLVMPointerType(LLVMInt32Type(), 0), LLVMPointerType(LLVMInt32Type(), 0) };
  LLVMTypeRef funcType = LLVMFunctionType(LLVMInt32Type(), paramTypes, 2, 0);
  LLVMValueRef func = LLVMAddFunction(module, "add", funcType);
  LLVMBasicBlockRef entry = LLVMAppendBasicBlock(func, "entry");
  LLVMPositionBuilderAtEnd(builder, entry);

  // Generate IR based on AST nodes
  LLVMValueRef result = NULL;
  switch (node->k) {
    case ASSIGN: {
      LLVMValueRef lhs = LLVMBuildAlloca(builder, LLVMInt32Type(), "");
      LLVMValueRef rhs = LLVMConstInt(LLVMInt32Type(), node->right->data.num, 1);
      LLVMBuildStore(builder, rhs, lhs);
      break;
    }
    case PLUS: {
      LLVMValueRef lhs = generate_ir(node->left);
      LLVMValueRef rhs = generate_ir(node->right);
      result = LLVMBuildAdd(builder, lhs, rhs, "");
      break;
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

  return result;
}
