%{
#include <stdio.h>
#include <stdlib.h>

int yylex();
void yyerror(const char *msg);

%}

%token T_AND T_CHAR T_DIV T_DO T_ELSE T_FUN T_IF T_INT T_MOD T_NOT T_NOTHING T_OR T_REF T_RETURN T_THEN T_VAR T_WHILE T_ID T_NUM T_FIXED_CHAR T_STR T_OPERATOR T_SEPARATOR

%expect 1
%left '+' '-'
%left '*' 

%%

program :
    declarations
    compound_stmt
    ;

declarations :
    | declarations declaration
    ;

declaration :
    var_declaration
    | fun_declaration
    | fun_definition
    ;

var_declaration :
    T_VAR var_list ':' type ';'
    ;

var_list :
    T_ID
    | var_list ',' T_ID
    ;

type :
    T_INT
    | T_CHAR
    | array_type
    ;

array_type :
    type '[' T_NUM ']'
    ;

fun_declaration :
    T_FUN T_ID '(' formal_param_list ')' ':' type ';'
    ;

formal_param_list :
    | formal_param_list ',' formal_params
    ;

formal_params :
    T_REF param_list ':' type
    | param_list ':' type
    ;

param_list :
    T_ID
    | param_list ',' T_ID
    ;

fun_definition :
    T_FUN T_ID '(' formal_param_list ')' ':' type declarations compound_stmt
    ;

stmtlst :
    | stmtlst stmt
    ;

compound_stmt :
    "begin" stmtlst "end"
    ;

stmt : 
    var_declaration
    | fun_definition
    | fun_declaration
    | compound_stmt
    | "if" expr "then" stmt
    | "if" expr "then" stmt "else" stmt
    | "while" expr "do" stmt
    ;

expr : 
    expr '+' expr
    | expr '*' expr
    | expr '/' expr
    | '(' expr ')'
    | T_NUM
    | T_ID
    ;

%%

void yyerror(const char *msg) {
  fprintf(stderr, "%s\n", msg);
  exit(1);
}

int main() {
        int result = yyparse();
        if (result == 0) printf("Success.\n");
        return result;
}
