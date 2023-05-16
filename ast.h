#ifndef AST_H
#define AST_H

typedef enum {
    ID,
    NUM,
    STR,
    PLUS,
    MINUS,
    MULTIPLY,
    DIVIDE,
    MOD,
    DIV,
    VAR,
    FUN,
    FOR,
    PUTS,
    IF,
    BLOCK,
    DECL,
    FUNCTION_DEF
} ast_type;

typedef struct node {
    ast_type type;
    union {
        char id;
        int num;
        char* str;
    } data;
    struct node *left;
    struct node *right;
} *ast;


ast ast_function_def(ast header, ast body);
ast ast_sep(ast_type sep, ast l, ast r);
ast ast_id(char c);
ast ast_num(int num);
ast ast_str(char* str);
ast ast_var(char* str,ast l);
ast ast_op(ast_type op, ast l, ast r);
ast ast_puts(ast e);
ast ast_if(ast cond, ast l, ast r);
ast ast_for(ast l, ast r);
ast ast_block(ast l);



void free_ast(ast ast);


#endif
