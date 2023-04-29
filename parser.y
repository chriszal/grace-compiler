%{
#define YYDEBUG 1
#include <stdio.h>
#include <stdlib.h>
#include "parser.tab.h"

extern int yylex();
extern int yyparse();
extern int yylineno;

void yyerror(const char *msg);
%}

%token T_AND T_CHAR T_DIV T_DO T_ELSE T_FUN T_IF T_INT T_MOD T_NOT T_NOTHING
%token T_OR T_REF T_RETURN T_THEN T_VAR T_WHILE
%token T_ID T_NUM T_FIXED_CHAR T_STR
%token T_LPAREN "("
%token T_RPAREN ")"
%token T_LBRACKET "["
%token T_RBRACKET "]"
%token T_LBRACE "{"
%token T_RBRACE "}"
%token T_COMMA ","
%token T_SEMICOLON ";"
%token T_COLON ":"
%token T_ASSIGN "<-"
%token T_PLUS "+"
%token T_MINUS "-"
%token T_MULTIPLY "*"
%token T_DIVIDE "/"
%token T_HASH "#"
%token T_EQUAL "="
%token T_NOT_EQUAL "<>"
%token T_LESS_THAN "<"
%token T_GREATER_THAN ">"
%token T_LESS_EQUAL "<="
%token T_GREATER_EQUAL ">="


%expect 1
%left T_OR
%left T_AND
%right T_NOT
%left T_HASH T_EQUAL T_NOT_EQUAL T_LESS_THAN T_GREATER_THAN T_LESS_EQUAL T_GREATER_EQUAL
%left T_MOD T_DIV
%left T_PLUS T_MINUS
%left T_MULTIPLY

%%

program:

    func_def
    ;

func_def:
    header local_defs block
    ;

header:
    T_FUN T_ID "(" fpar_defs ")" ":" ret_type
    ;

fpar_defs:
    /* empty */
    | fpar_def
    | fpar_defs ";" fpar_def
    ;

fpar_def:
    ref_opt id_list ":" fpar_type
    ;

ref_opt:
    /* empty */
    | T_REF
    ;

id_list:
    T_ID
    | id_list "," T_ID
    ;

fpar_type:
    data_type arr_opt
    ;

data_type:
    T_INT
    | T_CHAR
    ;

arr_opt:
    /* empty */
    | "[" "]" 
    | "[" T_NUM "]"
    ;

ret_type:
    data_type
    | T_NOTHING
    ;


local_defs:
    /* empty */
    | local_defs local_def
    ;

local_def:
    func_def
    | func_decl
    | var_def
    ;

var_def:
    T_VAR id_list ":" type ";"
    ;

type:
    data_type arr_opt
    ;

func_decl:
    header ";"
    ;

stmt:
    ";"
    | l_value "<-" expr ";"
    | block
    | func_call ";"
    | T_IF cond T_THEN stmt else_opt
    | T_WHILE cond T_DO stmt
    | T_RETURN expr_opt ";"
    ;

else_opt:
    /* empty */
    | T_ELSE stmt
    ;

expr_opt:
    /* empty */
    | expr
    ;

block:
    "{" stmts "}"
    ;

stmts:
    /* empty */
    | stmts stmt
    ;

func_call:
    T_ID "(" exprs ")"
    ;

exprs:
    /* empty */
    | expr_list
    ;

expr_list:
    expr
    | expr_list "," expr
    ;

l_value:
    T_ID
    | T_STR
    | l_value "[" expr "]"
    ;

expr:
    T_NUM
    | T_FIXED_CHAR
    | l_value
    | func_call
    | "(" expr ")"
    | "+" expr
    | "-" expr
    | expr "+" expr
    | expr "-" expr
    | expr "*" expr
    | expr T_DIV expr
    | expr T_MOD expr
    ;

cond:
    "(" cond ")"
    | T_NOT cond
    | cond T_AND cond
    | cond T_OR cond
    | expr "=" expr
    | expr "#" expr
    | expr "<" expr
    | expr ">" expr
    | expr "<=" expr
    | expr ">=" expr
    ;

%%

void yyerror(const char *msg) {
    fprintf(stderr, "Line %d: %s\n", yylineno, msg);
    fprintf(stderr, "Current token: %d\n", yychar);
}

int main() { 
    int result = yyparse();
    if (result == 0) printf("Success.\n");
    return result;
}

