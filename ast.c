#include <stdio.h>
#include <stdlib.h>
#include "ast.h"

ast create_ast_node(ast_type t, char id, int num, char* str, ast l, ast r) {
    ast n;
    if ((n = malloc(sizeof(struct node))) == NULL)
        fprintf(stderr, "Failed to allocate memory for AST node\n");
        exit(1);
    n->type = t;
    n->data.id = id;
    n->data.num = num;
    if (str != NULL) {
        n->data.str = str;
        if (n->data.str == NULL) {
            fprintf(stderr, "Failed to allocate memory for string data in AST node\n");
            exit(1);
        }
    }
    n->left = l;
    n->right = r;
    return n;
}

ast ast_function_def(ast header, ast body) {
    return create_ast_node(FUNCTION_DEF, '\0', 0, NULL, header, body);
}
ast ast_sep(ast_type sep, ast l, ast r) { 
    return create_ast_node(sep, '\0', 0, NULL, l, r);
}

ast ast_id(char c){
    return create_ast_node(ID, c, 0, NULL, NULL, NULL);
}

ast ast_num(int num){
    return create_ast_node(NUM, '\0', num, NULL, NULL, NULL);
}

ast ast_str(char* str){
    return create_ast_node(STR, '\0', 0, str, NULL, NULL);
}

ast ast_var(char* str,ast l){
    return create_ast_node(VAR, '\0', 0, str, l, NULL);
}

ast ast_op(ast_type op, ast l, ast r) { 
  return create_ast_node(op, '\0', 0,NULL, l, r);
}


ast ast_puts(ast l) {
  return create_ast_node(PUTS, '\0', 0,NULL, l, NULL);
}

ast ast_for (ast l, ast r) {
  return create_ast_node(FOR, '\0', 0,NULL, l, r);
}

ast ast_if (ast cond, ast l, ast r) {
  return create_ast_node(IF, '\0', 0,NULL, l, r);
}
ast ast_block (ast l) {
  return create_ast_node(BLOCK, '\0', 0,NULL, l, NULL);
}


void free_ast(ast ast) {
    if (ast == NULL) return;

    free_ast(ast->left);
    free_ast(ast->right);
    if (ast->type == STR) {
        free(ast->data.str);
    }
    free(ast);
}

