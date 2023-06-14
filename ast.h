#ifndef AST_H
#define AST_H

#include "symbol.h"


typedef enum {
    ID,
    NUM,
    STR,
    PLUS,
    MINUS,
    MULTIPLY,
    MOD,
    DIV,
    VAR,
    CHAR,
    NOTHING,
    INT,
    FUN,
    REF,
    IF,
    ELSE,
    BLOCK,
    FUNCTION_DEF,
    LOCAL_DEFS,
    LOCAL_DEF,
    FPAR_DEF,
    FPAR_DEFS,
    ASSIGN,
    GREATER_THAN,
    LESS_THAN,
    LESS_EQUAL,
    GREATER_EQUAL,
    NOT_EQUAL,
    AND,
    OR,
    EQUAL,
    NOT,
    EMPTY_STMTS,
    STMTS,
    WHILE,
    RETURN,
    NEGATIVE,
    POSITIVE,
    FUNC_CALL,
    ARRAY,
    ARG_LIST,
    TYPE,
    ARRAY_INDEX,
    ID_LIST
} ast_type;

typedef struct node {
    ast_type k;
    union {
        char c;
        int num;
        char* str;
    } data;
    struct node *left;
    struct node *middle;
    struct node *right;
    Type type;
} *ast;


ast ast_id_list(ast l, ast r);
ast ast_stmts(ast stmt, ast next);
ast ast_empty_stmts();
ast ast_function_def(ast header,ast local_defs, ast body);
ast ast_id(char* str); 
ast ast_num(int num);
ast ast_local_defs(ast l, ast r);
ast ast_local_def(ast l);
ast ast_data_type(ast_type k,Type t);
ast ast_fpar_def(ast ref, ast id_list, Type type) ;
ast ast_array(int size);
ast ast_fpar_defs(ast l, ast r);
ast ast_ref();
ast ast_op(ast_type op, ast l, ast r);
ast ast_arg_list(ast arg, ast next);
ast ast_if(ast cond, ast l, ast r);
ast ast_else(ast stmt);
ast ast_for(ast l, ast r);
ast ast_block(ast l);
ast ast_var(ast id, ast r);
ast ast_char(char c);
ast ast_nothing();
ast ast_int();
ast ast_return(ast e);
ast ast_fun(char* str, ast l, Type t);
ast ast_while(ast cond, ast stmt) ;
ast ast_str(char* str);
ast ast_func_call(char* str, ast args);
ast ast_type_node(ast data_type, ast array);
ast ast_array_index(ast id, ast index);


void free_ast(ast ast);


#endif
