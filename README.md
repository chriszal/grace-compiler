# grace-compiler
%{
#include <stdio.h>
#include <stdlib.h>

int yylex();
void yyerror(const char *msg);

%}

%token T_AND T_CHAR T_DIV T_DO T_ELSE T_FUN T_IF T_INT T_MOD T_NOT T_NOTHING T_OR T_REF T_RETURN T_THEN T_VAR T_WHILE T_ID T_NUM T_FIXED_CHAR T_STR T_OPERATOR T_SEPARATOR

%expect 1
%left T_OPERATOR
%left '+' '-'
%left '*'
%left T_AND T_OR
%left T_EQ T_NE T_LT T_GT T_LE T_GE

%start program

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
    '{' stmtlst '}'
    ;

stmt :
    var_declaration
    | fun_definition
    | fun_declaration
    | compound_stmt
    | if_stmt
    | while_stmt
    | assign_stmt
    | fun_call_stmt
    | return_stmt
    | T_SEPARATOR
    ;

assign_stmt :
    l_value T_SEPARATOR expr
    ;

l_value :
    T_ID
    | array_access
    ;

array_access :
    expr '[' expr ']'
    ;

if_stmt :
    "if" expr "then" stmt "else" stmt
    | "if" expr "then" stmt
    ;

while_stmt :
    "while" expr "do" stmt
    ;

fun_call_stmt :
    T_ID '(' actual_param_list ')' T_SEPARATOR
    ;

actual_param_list :
    | actual_param_list ',' expr
    ;

return_stmt :
    "return" expr T_SEPARATOR
    | "return" T_SEPARATOR
    ;

expr :
    l_value
    | expr '+' expr
    | expr '-' expr
    | expr '*' expr
    | expr T_AND expr
    | expr T_OR expr
    | expr T_EQ expr
    | expr T_NE expr
    | expr T_LT expr
    | expr T_GT expr
    | expr T_LE expr
    | expr T_GE expr
    | '(' expr ')'
    | T_NUM
    | T_OPERATOR logical_expr
    | fun_call_expr
    ;

logical_expr :
    expr T_OPERATOR expr
    ;

fun_call_expr :
    T_ID '(' actual_param_list ')'
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
