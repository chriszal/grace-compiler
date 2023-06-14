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
    // check if l_value is type of array and not just id
    if (a->left->k == ARRAY_INDEX)
    {
      ast_sem(a->left->left);

      SymbolEntry *symEntry = lookup(a->left->left->data.str); // Get the SymbolEntry for the array
      ast_sem(a->left->right);
      int index = a->left->right->data.num; // Get the index

      printf("Index of array is: %d\n", index);
      printf("Size of saved array is: %d\n", symEntry->type->u.arraySize);

      ast_sem(a->right);
      if (index >= symEntry->type->u.arraySize || index < 0)
      {
        error("array index out of bounds"); // Check if index is within the bounds of the array
      }
      else if (!equalType(symEntry->type, a->right->type))
      {
        error("type mismatch in array assignment"); // Check if the type of a->right matches the type of the array elements
      }
    }
    else
    {
      // ast_sem(a->left);
      
      SymbolEntry *symEntry = lookup(a->left->data.str);
      ast_sem(a->right);
      printf("Error1\n");
      if (equalType(symEntry->type, a->right->type) == 0)
        error("type mismatch in assignment");
      printf("Error2\n");
      if (symEntry->type->kind == TYPE_ARRAY_CHAR)
      {
        int arraySize = symEntry->u.arraySize;
        int strLength = strlen(a->right->data.str);
        if (strLength != arraySize)
        {
          error("incorrect string length in assignment");
        }
      }
    }
    printf("Finished ASSIGN operation.\n");
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

  case PLUS:{
    printf("Processing PLUS operation.\n");
    ast_sem(a->left);
    ast_sem(a->right);
    SymbolEntry *symEntry = lookup(a->left->data.str);
    printf("Left operand type: ");
    printType(symEntry->type);
    printf("\n");

    printf("Right operand type: ");
    printType(a->right->type);
    printf("\n");


    if (!equalType(symEntry->type, a->right->type) ||symEntry->type->kind != TYPE_INT)
    {
      error("type mismatch in + operation");
    }

    // a->data.num = a->left->data.num + a->right->data.num;
    // a->type = tyINT;
    // printf("PLUS operation result: %d\n", a->data.num);
    // printf("Finished PLUS operation.\n");

    return;
  }
  case MINUS:{
    printf("Entering MINUS operation\n");
    ast_sem(a->left);
    ast_sem(a->right);
    SymbolEntry *symEntry = lookup(a->left->data.str);
    printf("Left operand type: ");
    printType(symEntry->type);
    printf("\n");

    printf("Right operand type: ");
    printType(a->right->type);
    printf("\n");

    if (!equalType(symEntry->type, a->right->type) || symEntry->type->kind != TYPE_INT)
    {
      error("type mismatch in - operation");
    }

    // a->data.num = a->left->data.num - a->right->data.num;
    // a->type = tyINT;

    // printf("Result: %d\n", a->data.num);
    // printf("Leaving MINUS operation\n");

    return;
  }

  case MULTIPLY:{
    printf("Entering MULTIPLY operation\n");
    ast_sem(a->left);
    ast_sem(a->right);

    SymbolEntry *symEntry = lookup(a->left->data.str);
    printf("Left operand type: ");
    printType(symEntry->type);
    printf("\n");

    printf("Right operand type: ");
    printType(a->right->type);
    printf("\n");

    if (!equalType(symEntry->type, a->right->type) || symEntry->type->kind != TYPE_INT)
    {
      error("type mismatch in * operation");
    }

    // a->data.num = a->left->data.num * a->right->data.num;
    // a->type = tyINT;

    // printf("Result: %d\n", a->data.num);
    // printf("Leaving MULTIPLY operation\n");

    return;
  }
  case DIV:{
    printf("Entering DIV operation\n");
    ast_sem(a->left);
    ast_sem(a->right);

    SymbolEntry *symEntry = lookup(a->left->data.str);
    printf("Left operand type: ");
    printType(symEntry->type);
    printf("\n");

    printf("Right operand type: ");
    printType(a->right->type);
    printf("\n");


    if (!equalType(symEntry->type, a->right->type) || symEntry->type->kind != TYPE_INT)
    {
      error("type mismatch in / operation");
    }

    if (a->right->data.num == 0)
    {
      error("division by zero");
    }

    // a->data.num = a->left->data.num / a->right->data.num;
    // a->type = tyINT;

    // printf("Result: %d\n", a->data.num);
    // printf("Leaving DIV operation\n");

    return;
  }
  case MOD:{
    printf("Entering MOD operation\n");
    ast_sem(a->left);
    ast_sem(a->right);

    SymbolEntry *symEntry = lookup(a->left->data.str);
    printf("Left operand type: ");
    printType(symEntry->type);
    printf("\n");

    printf("Right operand type: ");
    printType(a->right->type);
    printf("\n");


    if (!equalType(symEntry->type, a->right->type) || symEntry->type->kind != TYPE_INT)
    {
      error("type mismatch in mod operation");
    }

    if (a->right->data.num == 0)
    {
      error("division by zero");
    }

    // a->data.num = a->left->data.num % a->right->data.num;
    // a->type = tyINT;

    // printf("Result: %d\n", a->data.num);
    // printf("Leaving MOD operation\n");

    return;
  }
  default:
    ast_sem(a->left);
    ast_sem(a->middle);
    ast_sem(a->right);
    return;
  }
}
