#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ast.h"

ast create_ast_node(ast_type t, char c, int num, char* str, ast l,ast m, ast r) {
    ast n;
    if ((n = malloc(sizeof(struct node))) == NULL) {
        fprintf(stderr, "Failed to allocate memory for AST node\n");
        exit(1);
    }
    n->type = t;
    n->data.c = c;
    n->data.num = num;
    if (str != NULL) {
        n->data.str = strdup(str);
        if (n->data.str == NULL) {
            fprintf(stderr, "Failed to allocate memory for string data in AST node\n");
            exit(1);
        }
    }
    n->left = l;
    n->middle = m;
    n->right = r;
    return n;
}

ast ast_stmts(ast stmts, ast stmt) {
    if (stmts == NULL) {
        return create_ast_node(STMTS, '\0', 0, NULL, stmt, NULL, NULL);
    } else {
        ast last_stmts = stmts;
        while (last_stmts->right != NULL) {
            last_stmts = last_stmts->right;
        }
        last_stmts->right = create_ast_node(STMTS, '\0', 0, NULL, stmt, NULL, NULL);
        return stmts;
    }
}


ast ast_empty_stmts() {
    return create_ast_node(EMPTY_STMTS, '\0', 0, NULL, NULL,NULL, NULL);
}

ast ast_function_def(ast header,ast local_defs, ast body) {
    if (local_defs == NULL) {
        local_defs = create_ast_node(EMPTY_STMTS, '\0', 0, NULL, NULL, NULL, NULL);
    }
    return create_ast_node(FUNCTION_DEF, '\0', 0, NULL, header, local_defs, body);
}

ast ast_sep(ast_type sep, ast l, ast r) { 
    return create_ast_node(sep, '\0', 0, NULL, l,NULL, r);
}

ast ast_id(char* str){
    return create_ast_node(ID, '\0', 0, str, NULL,NULL, NULL); 
}    
ast ast_array(int size){
    return create_ast_node(ARRAY, '\0', size, NULL, NULL, NULL, NULL);
}

ast ast_local_defs(ast l, ast r) {
    if (l == NULL) {
        return r;
    } else {
        return create_ast_node(LOCAL_DEFS, '\0', 0, NULL, l, NULL, r);
    }
}


ast ast_local_def(ast l) {
    return create_ast_node(LOCAL_DEF, '\0', 0, NULL, l,NULL, NULL);
}

ast ast_data_type(ast_type t) {
    return create_ast_node(t, '\0', 0, NULL, NULL,NULL, NULL);
}

ast ast_ref_list(ast l, ast r) {
    return create_ast_node(REF_LIST, '\0', 0, NULL, l, NULL, r);
}


ast ast_fpar_def(ast ref, ast id_list, ast type) {
    return create_ast_node(FPAR_DEF, '\0', 0, NULL, ref, id_list, type);
}

ast ast_fpar_defs(ast l, ast r) {
    return create_ast_node(FPAR_DEFS, '\0', 0, NULL, l,NULL, r);
}
ast ast_num(int num){
    return create_ast_node(NUM, '\0', num, NULL, NULL,NULL, NULL);
}


ast ast_op(ast_type op, ast l, ast r) { 
  return create_ast_node(op, '\0', 0,NULL, l,NULL, r);
}


ast ast_puts(ast l) {
  return create_ast_node(PUTS, '\0', 0,NULL, l,NULL, NULL);
}

ast ast_for (ast l, ast r) {
  return create_ast_node(FOR, '\0', 0,NULL, l,NULL, r);
}

ast ast_if (ast cond, ast l, ast r) {
  if (l == NULL) {
    l = ast_empty_stmts();
  }
  if (r == NULL) {
    r = ast_empty_stmts();
  }
  return create_ast_node(IF, '\0', 0,NULL, cond, l, r);
}


ast ast_else(ast stmt) {
    return create_ast_node(ELSE, '\0', 0, NULL, stmt, NULL, NULL);
}


ast ast_block(ast l) {
    if (l == NULL) {
        l = create_ast_node(EMPTY_STMTS, '\0', 0, NULL, NULL, NULL, NULL);
    }
    return create_ast_node(BLOCK, '\0', 0, NULL, l, NULL, NULL);
}
ast ast_var(ast id, ast r) {
    if (id == NULL) {
        id = create_ast_node(EMPTY_STMTS, '\0', 0, NULL, NULL,NULL, NULL);
    }
    return create_ast_node(VAR, '\0', 0, NULL, id,NULL, r);
}

ast ast_char(char c){
    return create_ast_node(CHAR, c, 0, NULL, NULL,NULL, NULL);
}
ast ast_nothing() {
    return create_ast_node(NOTHING, '\0', 0, NULL, NULL,NULL, NULL);
}

ast ast_int() {
    return create_ast_node(INT, '\0', 0, NULL, NULL,NULL, NULL);
}

ast ast_fun(char* str, ast l, ast r ) {
    if (l == NULL) {
        l = create_ast_node(EMPTY_STMTS, '\0', 0, NULL, NULL,NULL, NULL);
    }
    return create_ast_node(FUN, '\0', 0, str, l,NULL, r);
}
ast ast_ref() {
    return create_ast_node(FPAR_DEF, '\0', 0, NULL, NULL, NULL, NULL);
}

ast ast_arg_list(ast arg, ast next) {
    if (next != NULL) {
        return create_ast_node(ARG_LIST, '\0', 0, NULL, arg, NULL, next);
    }
    return create_ast_node(ARG_LIST, '\0', 0, NULL, arg, NULL, NULL);
}
ast ast_array_index(ast id, ast index){
    return create_ast_node(ARRAY_INDEX, '\0', 0, NULL, id, NULL, index);
}


ast ast_while(ast cond, ast stmt) {
    return create_ast_node(WHILE, '\0', 0, NULL, cond, NULL, stmt);
}

ast ast_str(char* str) {
    return create_ast_node(STR, '\0', 0, str, NULL, NULL, NULL);
}
ast ast_func_call(char* str, ast args) {
    if (args == NULL) {
        args = create_ast_node(EMPTY_STMTS, '\0', 0, NULL, NULL,NULL, NULL);
    }
    return create_ast_node(FUNC_CALL, '\0', 0, str, args, NULL, NULL);
}

ast ast_type_node(ast data_type, ast array) {
    return create_ast_node(TYPE, '\0', 0, NULL, data_type, array, NULL);
}



void free_ast(ast ast) {
    if (ast == NULL) return;

    free_ast(ast->left);
    free_ast(ast->middle);
    free_ast(ast->right);
    if (ast->type == STR) {
        free(ast->data.str);
    }
    free(ast);
}

