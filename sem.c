#include <stdlib.h>
#include <stdio.h>
#include "sem.h"
#include "error.h"
#include "symbol.h"
#include "type.h"

SymbolEntry * lookup(char c) {
  char name[] = " ";
  name[0] = c;
  return lookupEntry(name, 1);
}

SymbolEntry* insert(char c, Type t) {
    char name[] =  " ";
    name[0] = c;
    return newEntry(name, t);
}

void ast_sem (ast a) {
  if (a == NULL) {
    printf("AST NOT COMPLETE\n");
    return;
  }

  switch (a->k) {
    case VAR:{
      SymbolEntry * e = lookup(a->data.c);
      ast_sem(a->left);
      if (!equalType(e->type, a->left->type))
        error("type mismatch in assignment");
      return;
    }
    case ID:
      {
        SymbolEntry *symEntry = lookup(a->data.c);
        if (symEntry == NULL) {
          printf("Identifier not found: %s\n", a->data.str);
        }
        return;
      }
    // case NUM:
    // case STR:
    //   return; 
    // case PLUS:
    // case MINUS:
    // case MULTIPLY:
    // case DIV:
    // case MOD:
    //   ast_sem(a->left);
    //   ast_sem(a->right);
    //   return;
    // case ASSIGN:
    //   {
    //     SymbolEntry *symEntry = lookup(a->left->data.c);
    //     if (symEntry == NULL) {
    //       printf("Identifier not found: %s\n", a->left->data.str);
    //     } else {
    //       ast_sem(a->right);
    //     }
    //     return;
    //   }
    // case FUNCTION_DEF:
    // {
    //     SymbolEntry *symEntry = lookupEntry(a->data.c, 0);
    //     if (symEntry != NULL) {
    //       printf("Function already defined: %s\n", a->data.str);
    //       return;
    //     } 
    //     symEntry = newEntry(a->data.c, a->type);
    //     if (symEntry == NULL) {
    //       printf("Error inserting function: %s\n", a->data.str);
    //       return;
    //     } 
    //     openScope();
    //     ast_sem(a->left);  // Check the header
    //     ast_sem(a->middle);  // Check local definitions
    //     ast_sem(a->right);  // Check function body
    //     closeScope();
    //     return;
    // }
    // case EMPTY_STMTS:
    // case STMTS:
    //   {
    //     ast cur_stmts = a;
    //     while (cur_stmts != NULL) {
    //       ast_sem(cur_stmts->left);
    //       cur_stmts = cur_stmts->right;
    //     }
    //     return;
  //     }
  //   // Continue with the rest of your node types
  //   default:
  //     printf("Unknown AST node type: %d\n", a->k);
  //     return;
  }
}
  