#include <stdlib.h>
#include <stdio.h>
#include "sem.h"
#include <string.h>
#include "error.h"
#include "symbol.h"
#include "type.h"

SymbolEntry *lookup(char *name)
{
  printf("Lookup for %s inside symbol table\n", name);
  return lookupEntry(name, 1);
}

SymbolEntry *insert(char *name, Type t)
{
  printf("Insert: %s in symbol table\n", name);
  printf("Inserted Type: ");
  printType(t);
  printf("\n");
  return newEntry(name, t);
}

void ast_sem(ast a)
{
  if (a == NULL)
  {
    printf("NOT COMPLETE\n");
    return;
  }

  switch (a->k)
  {
  case VAR:
  {
    printf("Entering VAR declaration\n");
    ast id_node = a->left;
    printf("First id: %s\n",id_node->left->left->data.str);
    printf("Second id: %s\n",id_node->left->right->data.str);
    printf("Third id: %s\n",id_node->right->data.str);
    
    if (a->right->middle == NULL)
    {
      printf("Non Array type provided. Inserting into symbol table...\n");
      insert(a->left->data.str, a->right->left->type);
    }
    else
    {
      printf("Array type provided. Inserting into symbol table...\n");
      insert(a->left->data.str, a->right->type);
    }

    printf("Finished VAR declaration.\n");
    return;
  }
  case ID:
  {
    printf("Processing ID operation.\n");

    SymbolEntry *e = lookup(a->data.str);

    if (e == NULL)
    {
      error("undefined identifier");
      return;
    }

    a->type = e->type;
    printf("Found type: ");
    printType(a->type);
    printf("\n");
    printf("Finished ID operation.\n");
    return;
  }

  case NUM:
    a->type = tyINT;
    return;
  case CHAR:
    a->type = tyCHAR;
    return;
  case STR:
    a->type = tyARRAY_CHAR;
    a->type->u.arraySize = strlen(a->data.str);
    return;

  case ASSIGN:
  {
    printf("Processing ASSIGN operation.\n");

    ast_sem(a->left);
    ast_sem(a->right);

    if (!equalType(a->left->type, a->right->type))
    {
      error("type mismatch in assignment");
    }

    if (a->left->type->kind == TYPE_ARRAY_CHAR)
    {
      int arraySize = a->left->type->u.arraySize;
      int strLength = strlen(a->right->data.str);
      if (strLength != arraySize)
      {
        error("incorrect string length in assignment");
      }
    }

    printf("Finished ASSIGN operation.\n");
    return;
  }

  case ARRAY_INDEX:
  {
    printf("Processing ARRAY_INDEX operation.\n");

    ast_sem(a->left);
    ast_sem(a->right);

    int index = a->right->data.num; // Get the index
    printf("Index of array is: %d\n", index);

    if (a->left->type->kind != TYPE_ARRAY_INT && a->left->type->kind != TYPE_ARRAY_CHAR)
    {
      error("invalid operation on non-array type");
    }

    printf("Size of saved array is: %d\n", a->left->type->u.arraySize);

    if (index >= a->left->type->u.arraySize || index < 0)
    {
      error("array index out of bounds"); // Check if index is within the bounds of the array
    }

    a->type = (a->left->type->kind == TYPE_ARRAY_INT) ? tyINT : tyCHAR;

    printf("Finished ARRAY_INDEX operation.\n");
    return;
  }

  case POSITIVE:
  {
    printf("Processing POSITIVE operation. Operand: %d\n", a->left->data.num);
    ast_sem(a->left);
    a->type = a->left->type;
    a->data.num = a->left->data.num;
    printf("POSITIVE operation result: %d\n", a->data.num);
    printf("Finished POSITIVE operation.\n");
    return;
  }

  case NEGATIVE:
  {
    printf("Processing NEGATIVE operation. Operand: %d\n", a->left->data.num);
    ast_sem(a->left);
    a->type = a->left->type;
    a->data.num = -a->left->data.num;
    printf("NEGATIVE operation result: %d\n", a->data.num);
    printf("Finished NEGATIVE operation.\n");
    return;
  }

  case PLUS:
  {
    printf("Processing PLUS operation.\n");
    ast_sem(a->left);
    ast_sem(a->right);

    printf("Left operand type: ");
    printType(a->left->type);
    printf("\n");

    printf("Right operand type: ");
    printType(a->right->type);
    printf("\n");

    if (!equalType(a->left->type, a->right->type) || a->left->type->kind != TYPE_INT)
    {
      error("type mismatch in + operation");
    }
    a->type = a->left->type;
    printf("Finished PLUS operation with result type: ");
    printType(a->type);
    printf("\n");
    return;
  }
  case MINUS:
  {
    printf("Entering MINUS operation\n");

    ast_sem(a->left);
    ast_sem(a->right);

    printf("Left operand type: ");
    printType(a->left->type);
    printf("\n");

    printf("Right operand type: ");
    printType(a->right->type);
    printf("\n");

    if (!equalType(a->left->type, a->right->type) || a->left->type->kind != TYPE_INT)
    {
      error("type mismatch in - operation");
    }

    a->type = a->left->type;
    printf("Finished MINUS operation with result type: ");
    printType(a->type);
    printf("\n");

    return;
  }

  case MULTIPLY:
  {
    printf("Entering MULTIPLY operation\n");
    ast_sem(a->left);
    ast_sem(a->right);

    printf("Left operand type: ");
    printType(a->left->type);
    printf("\n");

    printf("Right operand type: ");
    printType(a->right->type);
    printf("\n");

    if (!equalType(a->left->type, a->right->type) || a->left->type->kind != TYPE_INT)
    {
      error("type mismatch in * operation");
    }
    a->type = a->left->type;
    printf("Finished MULTIPLY operation with result type: ");
    printType(a->type);
    printf("\n");

    return;
  }
  case DIV:
  {
    printf("Entering DIV operation\n");
    ast_sem(a->left);
    ast_sem(a->right);

    printf("Left operand type: ");
    printType(a->left->type);
    printf("\n");

    printf("Right operand type: ");
    printType(a->right->type);
    printf("\n");

    if (!equalType(a->left->type, a->right->type) || a->left->type->kind != TYPE_INT)
    {
      error("type mismatch in / operation");
    }

    if (a->right->data.num == 0)
    {
      error("division by zero");
    }
    a->type = a->left->type;
    printf("Finished DIV operation with result type: ");
    printType(a->type);
    printf("\n");
    return;
  }
  case MOD:
  {
    printf("Entering MOD operation\n");
    ast_sem(a->left);
    ast_sem(a->right);

    printf("Left operand type: ");
    printType(a->left->type);
    printf("\n");

    printf("Right operand type: ");
    printType(a->right->type);
    printf("\n");

    if (!equalType(a->left->type, a->right->type) || a->left->type->kind != TYPE_INT)
    {
      error("type mismatch in mod operation");
    }

    if (a->right->data.num == 0)
    {
      error("division by zero");
    }
    a->type = a->left->type;
    printf("Finished MOD operation with result type: ");
    printType(a->type);
    printf("\n");

    return;
  }
  default:
    ast_sem(a->left);
    ast_sem(a->middle);
    ast_sem(a->right);
    return;
  }
}
