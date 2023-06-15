%{
#define YYDEBUG 1
#include <stdio.h>
#include <stdlib.h>
#include "ast.h"
#include "type.h"
#include "symbol.h"
#include "sem.h"

extern int yyparse();
extern int yylineno;

void yyerror(const char *msg);

ast p;
%}

%union {
  ast node;
  char c;
  int n;
  char* str;
  Type t;
}

%token T_AND T_CHAR T_DIV T_DO T_ELSE T_FUN T_IF T_INT T_MOD T_NOT T_NOTHING
%token T_OR T_REF T_RETURN T_THEN T_VAR T_WHILE
%token<str> T_ID 
%token<n> T_NUM 
%token<c> T_FIXED_CHAR 
%token<str> T_STR
%token T_LPAREN "("
%token T_RPAREN ")"
%token<c> T_LBRACKET "["
%token<c> T_RBRACKET "]"
%token<c> T_LBRACE "{"
%token<c> T_RBRACE "}"
%token T_COMMA ","
%token T_SEMICOLON ";"
%token T_COLON ":"
%token<c> T_ASSIGN "<-"
%token<c> T_PLUS "+"
%token<c> T_MINUS "-"
%token<c> T_MULTIPLY "*"
%token<c> T_DIVIDE "/"
%token<c> T_NOT_EQUAL "#"
%token<c> T_EQUAL "="
%token<c> T_LESS_THAN "<"
%token<c> T_GREATER_THAN ">"
%token<c> T_LESS_EQUAL "<="
%token<c> T_GREATER_EQUAL ">="

%type<node> func_def header fpar_defs fpar_def ref_opt id_list  local_defs local_def var_def func_decl stmt else_opt expr_opt block stmts func_call exprs expr_list l_value expr cond data_type ret_type type arr_opt fpar_type

%expect 1
%left T_OR
%left T_AND
%right T_NOT
%left T_HASH T_EQUAL T_NOT_EQUAL T_LESS_THAN T_GREATER_THAN T_LESS_EQUAL T_GREATER_EQUAL
%left T_MOD T_DIV
%left T_PLUS T_MINUS
%left T_MULTIPLY

%%

func_def:
    header local_defs block                    { p = $$ = ast_function_def($1,$2, $3); }
    

header:
    T_FUN T_ID "(" fpar_defs ")" ":" ret_type  { $$ = ast_fun($2,$4,$7); }
    

fpar_defs:
    /* empty */                                 { $$ = ast_empty_stmts(); }
    | fpar_def                                  { $$ = $1; }
    | fpar_defs ";" fpar_def                    { $$ = ast_fpar_defs($1, $3); }
    

fpar_def:
    ref_opt id_list ":" fpar_type               { $$ = ast_fpar_def($1,$2, $4);  }
    

ref_opt:
    /* empty */                                 { $$ = NULL; }
    | T_REF                                     { $$ = ast_ref(); }

    
id_list:
    T_ID                                        { $$ = ast_id($1); }
    | id_list "," T_ID                          { $$ = ast_id_list($1, ast_id($3)); }


fpar_type:
    data_type arr_opt                           { $$ = ast_type_node($1, $2); }

    

data_type:
    T_INT                                       { $$ = ast_data_type(INT,tyINT); }
    | T_CHAR                                    { $$ = ast_data_type(CHAR,tyCHAR); }
    

arr_opt:
    /* empty */                                 { $$ = NULL; }
    | "[" "]"                                   { $$ = ast_array(0); } // represents an empty array
    | "[" T_NUM "]"                             { $$ = ast_array($2); } // represents an array with size


ret_type:
    data_type                                   { $$ = $1; }
    | T_NOTHING                                 { $$ = ast_data_type(NOTHING,tyNOTHING);}
    


local_defs:
    /* empty */                                { $$ = NULL; }
    | local_defs local_def                     { $$ = ast_local_defs($1, $2); }
    

local_def:
     func_def                                  { $$ = $1; }
    | func_decl                                { $$ = $1; }
    | var_def                                  { $$ = $1; }
    

var_def:
    T_VAR id_list ":" type ";"                  { $$ = ast_var($2, $4); }
    

type:
    data_type arr_opt                           { $$ = ast_type_node($1, $2); }
    

func_decl:
    header ";"                                   { $$ = $1; }
    

stmt:
    ";"                                         { $$ = NULL; }
    | l_value T_ASSIGN expr ";"                 { $$ = ast_op(ASSIGN, $1, $3); }
    | block                                     { $$ = $1; }
    | func_call ";"                             { $$ = $1; }
    | T_IF cond T_THEN stmt else_opt            { $$ = ast_if($2, $4, $5); }
    | T_WHILE cond T_DO stmt                    { $$ = ast_while($2, $4); }
    | T_RETURN expr_opt ";"                     { $$ = ast_return($2); }

else_opt:
    /* empty */                                 { $$ = NULL; }
    | T_ELSE stmt                               { $$ = ast_else($2); }


expr_opt:
    /* empty */                                 { $$ = NULL; }
    | expr                                      { $$ = $1; }

block:
    "{" stmts "}"                               { $$ = ast_block($2);  }

stmts:
    /* empty */                                 { $$ = NULL; }
    | stmts stmt                                { $$ = ast_stmts($1, $2); }

func_call:          
    T_ID "(" exprs ")"                          { $$ = ast_func_call($1, $3); }

exprs:
    /* empty */                                 { $$ = NULL; }
    | expr_list                                 { $$ = $1;}

expr_list:
    expr                                        { $$ = ast_arg_list($1, NULL); }
    | expr_list "," expr                        { $$ = ast_arg_list($3, $1); }    


l_value:
    T_ID                                        { $$ = ast_id($1); }
    | l_value "[" expr "]"                      { $$ = ast_array_index($1, $3); }

expr:
    T_NUM                                       { $$ = ast_num($1); }
    | T_FIXED_CHAR                              { $$ = ast_char($1); }
    | T_STR                                     { $$ = ast_str($1); } 
    | l_value                                   { $$ = $1; }
    | func_call                                 { $$ = $1; }
    | "(" expr ")"                              { $$ = $2; }
    | "+" expr                                  { $$ = ast_op(POSITIVE, $2, NULL); }
    | "-" expr                                  { $$ = ast_op(NEGATIVE, $2, NULL); }
    | expr "+" expr                             { $$ = ast_op(PLUS, $1, $3); }
    | expr "-" expr                             { $$ = ast_op(MINUS, $1, $3); }
    | expr "*" expr                             { $$ = ast_op(MULTIPLY, $1, $3); }
    | expr T_DIV expr                           { $$ = ast_op(DIV, $1, $3); }
    | expr T_MOD expr                           { $$ = ast_op(MOD, $1, $3); }

cond:
    "(" cond ")"                                { $$ = $2; }
    | T_NOT cond                                { $$ = ast_op(NOT, $2, NULL); }
    | cond T_AND cond                           { $$ = ast_op(AND, $1, $3); }
    | cond T_OR cond                            { $$ = ast_op(OR, $1, $3); }
    | expr "=" expr                             { $$ = ast_op(EQUAL, $1, $3); }   
    | expr "#" expr                             { $$ = ast_op(NOT_EQUAL, $1, $3); }
    | expr "<" expr                             { $$ = ast_op(LESS_THAN, $1, $3); }
    | expr ">" expr                             { $$ = ast_op(GREATER_THAN, $1, $3); }
    | expr "<=" expr                            { $$ = ast_op(LESS_EQUAL, $1, $3); }
    | expr ">=" expr                            { $$ = ast_op(GREATER_EQUAL, $1, $3); }

    

%%

void yyerror(const char *msg) {
    fprintf(stderr, "Line %d: %s\n", yylineno, msg);
    fprintf(stderr, "Current token: %d\n", yychar);
    exit(1);
}

int main() { 
    int result = yyparse();
    if (result != 0) fprintf(stderr, "Failure.\n");
    initSymbolTable(999);
    openScope();
    ast_sem(p);
    closeScope();
    destroySymbolTable();
    return result;
}

