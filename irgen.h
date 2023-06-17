#ifndef __IRGEN_H__
#define __IRGEN_H__
#include "ast.h"
#include <llvm-c/Core.h>

LLVMValueRef generate_ir(ast node);

#endif