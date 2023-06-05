#include "ast.h"
#include <stdio.h>

int label;

void ast_compile_aux (ast t) {
  if (t == NULL) return;
  switch (t->k) {
    case ID:
        printf("  pushl %d(%%edi)\n", 4*(t->data.c - 'a'));
        return;
    case NUM:
        printf("  pushl $%d\n", t->data.num);
        return;
    case PLUS:
        ast_compile_aux(t->left);
        ast_compile_aux(t->right);
        printf("  popl %%ebx\n");
        printf("  popl %%eax\n");
        printf("  addl %%ebx, %%eax\n");
        printf("  pushl %%eax\n");
        return;
    case MINUS:
        ast_compile_aux(t->left);
        ast_compile_aux(t->right);
        printf("  popl %%ebx\n");
        printf("  popl %%eax\n");
        printf("  subl %%ebx, %%eax\n");
        printf("  pushl %%eax\n");
        return;
    case MULTIPLY:
        ast_compile_aux(t->left);
        ast_compile_aux(t->right);
        printf("  popl %%ebx\n");
        printf("  popl %%eax\n");
        printf("  mull %%ebx\n");
        printf("  pushl %%eax\n");
        return;
    case DIV:
        ast_compile_aux(t->left);
        ast_compile_aux(t->right);
        printf("  popl %%ebx\n");
        printf("  popl %%eax\n");
        printf("  cdq\n");
        printf("  divl %%ebx\n");
        printf("  pushl %%eax\n");
        return;
    case IF: {
        ast_compile_aux(t->left);
        printf("  popl %%eax\n");
        printf("  andl %%eax, %%eax\n");
        int l = ++label;
        printf("  jz L%d\n", l);
        ast_compile_aux(t->right);
        printf("L%d:\n", l);
        return;
  }
    case FUNC_CALL:
        printf("  call _%s\n", t->data.str);
        return;
  }
}

void prologue() {
  printf(".text\n"
         ".global _start\n"
         "\n"
         "_start:\n"
         "  movl $var, %%edi\n"
         "\n");
}

void epilogue() {
  printf("\n");
  printf("  movl $0, %%ebx\n");
  printf("  movl $1, %%eax\n");
  printf("  int $0x80\n");
  printf("\n");
  printf(".data\n");
  printf("var:\n");
  printf(".rept 26\n");
  printf(".long 0\n");
  printf(".endr\n");
  printf("NL:\n");
  printf(".asciz \"\\n\"\n");  
}

void ast_compile (ast t) {
  prologue();
  ast_compile_aux(t);
  epilogue();
}
