%{
#define YYDEBUG 1
#include <stdio.h>
#include <stdlib.h>
#include "ast.h"
#include "print.h"

extern int yylex();
extern int yyparse();
extern int yylineno;

void yyerror(const char *msg);
%}

%union {
  ast node;
  char c;
  int n;
  char* str;
}

%token T_AND T_CHAR T_DIV T_DO T_ELSE T_FUN T_IF T_INT T_MOD T_NOT T_NOTHING
%token T_OR T_REF T_RETURN T_THEN T_VAR T_WHILE
%token<c> T_ID 
%token<n> T_NUM 
%token<c> T_FIXED_CHAR 
%token<str> T_STR
%token<c> T_LPAREN "("
%token<c> T_RPAREN ")"
%token<c> T_LBRACKET "["
%token<c> T_RBRACKET "]"
%token<c> T_LBRACE "{"
%token<c> T_RBRACE "}"
%token<c> T_COMMA ","
%token<c> T_SEMICOLON ";"
%token<c> T_COLON ":"
%token<c> T_ASSIGN "<-"
%token<c> T_PLUS "+"
%token<c> T_MINUS "-"
%token<c> T_MULTIPLY "*"
%token<c> T_DIVIDE "/"
%token<c> T_HASH "#"
%token<c> T_EQUAL "="
%token<c> T_NOT_EQUAL "<>"
%token<c> T_LESS_THAN "<"
%token<c> T_GREATER_THAN ">"
%token<c> T_LESS_EQUAL "<="
%token<c> T_GREATER_EQUAL ">="

%type<node> func_def header fpar_defs fpar_def ref_opt id_list fpar_type data_type arr_opt ret_type local_defs local_def var_def type func_decl stmt else_opt expr_opt block stmts func_call exprs expr_list l_value expr cond

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
    func_def                                   { print_ast($1);}
    

func_def:
    header local_defs block                    { $$ = ast_function_def($1, $3); }
    

header:
    T_FUN T_ID "(" fpar_defs ")" ":" ret_type  { $$ = ast_function_def($1, $7); }
    

fpar_defs:
    /* empty */                                 { $$ = NULL; }
    | fpar_def                                  { $$ = $1; }
    | fpar_defs ";" fpar_def                    { $$ = ast_sep(SEMICOLON, $1, $3); }
    

fpar_def:
    ref_opt id_list ":" fpar_type               { $$ = ast_var($2, $4); }
    

ref_opt:
    /* empty */                                 { $$ = NULL; }
    | T_REF                                     { $$ = ast_id($1); }
    

id_list:
    T_ID                                        { $$ = ast_id($1); }
    | id_list "," T_ID                          { $$ = ast_op(',', $1, $3); }
    

fpar_type:
    data_type arr_opt                           { $$ = ast_op(':', $1, $2); }
    

data_type:
    T_INT                                       { $$ = ast_id($1); }
    | T_CHAR                                    { $$ = ast_id($1); }
    

arr_opt:
/* empty */                                     { $$ = NULL; }
    | "[" "]"                                   {  }
    | "[" T_NUM "]"                             {  }
    

ret_type:
    data_type                                   { $$ = $1; }
    | T_NOTHING                                 { $$ = ast_id($1); }
    


local_defs:
    /* empty */                                 {}
    | local_defs local_def                      {}
    

local_def:
    func_def                                    {}
    | func_decl                                 {}
    | var_def                                   {}
    

var_def:
    T_VAR id_list ":" type ";"                  {}
    

type:
    data_type arr_opt                           {}
    

func_decl:
    header ";"                                  {}
    

stmt:
    ";"                                         {}
    | l_value "<-" expr ";"                     {}
    | block                                     {  }
    | func_call ";"                             {}
    | T_IF cond T_THEN stmt else_opt            {}
    | T_WHILE cond T_DO stmt                    {}
    | T_RETURN expr_opt ";"                     {}
    

else_opt:
    /* empty */                                 {  }
    | T_ELSE stmt                               {}
    

expr_opt:
    /* empty */                                 {  }
    | expr                                      {}
    

block:
    "{" stmts "}"                               {}
    

stmts:
    /* empty */                                 {}
    | stmts stmt                                {}
    

func_call:          
    T_ID "(" exprs ")"                          {}
    

exprs:
    /* empty */                                 { }
    | expr_list                                 {}
    

expr_list:
    expr                                        {}
    | expr_list "," expr                        {}
    

l_value:
    T_ID                                        {}
    | T_STR                                     {}
    | l_value "[" expr "]"                      {}
    

expr:
    T_NUM                                       { }
    | T_FIXED_CHAR                              {  }
    | l_value                                   {}
    | func_call                                 {}
    | "(" expr ")"                              {}
    | "+" expr                                  {  }
    | "-" expr                                  {  }
    | expr "+" expr                             { }
    | expr "-" expr                             {  }
    | expr "*" expr                             {  }
    | expr T_DIV expr                           {  }
    | expr T_MOD expr                           {  }
    

cond:
    "(" cond ")"                                {}
    | T_NOT cond                                {}
    | cond T_AND cond                           {}
    | cond T_OR cond                            {}
    | expr "=" expr                             {}   
    | expr "#" expr                             {}
    | expr "<" expr                             {}
    | expr ">" expr                             {}
    | expr "<=" expr                            {}
    | expr ">=" expr                            {}
    

%%

void yyerror(const char *msg) {
    fprintf(stderr, "Line %d: %s\n", yylineno, msg);
    fprintf(stderr, "Current token: %d\n", yychar);
}

int main() { 
    int result = yyparse();
    // if (result == 0) printf("Success.\n");
    return result;
}

