%{
#define YYDEBUG 1

#include <stdio.h>
#include <stdlib.h>

int yylex();
void yyerror(const char *msg);

%}

%token T_AND T_CHAR T_DIV T_DO T_ELSE T_FUN T_IF T_INT T_MOD T_NOT T_NOTHING T_OR T_REF T_RETURN T_THEN T_VAR T_WHILE T_ID T_NUM T_FIXED_CHAR T_STR T_OPERATOR T_SEPARATOR

%expect 0
%left T_OR
%left T_AND
%right T_NOT
%right T_OPERATOR
%left T_MOD T_DIV
%left '+' '-'
%left '*'
%nonassoc T_ELSE
%nonassoc UMINUS
%nonassoc T_SEPARATOR


%start program

%%

program :
    | program func_def
    ;

func_def :
    header local_defs block
    ;

header :
    T_FUN T_ID '(' fpar_def_list ')' ':' ret_type
    ;

fpar_def_list :
    fpar_def
    | fpar_def_list ';' fpar_def
    ;

fpar_def :
    ref_opt id_list ':' fpar_type
    ;

ref_opt :
    | T_REF
    ;

id_list :
    T_ID
    | id_list ',' T_ID
    ;

data_type :
    T_INT
    | T_CHAR
    ;

type :
    data_type
    | data_type '[' T_NUM ']'
    ;

ret_type :
    data_type
    | T_NOTHING
    ;

fpar_type :
    data_type
    | data_type '[' ']'
    | data_type '[' T_NUM ']'
    ;

local_defs :
    | local_defs local_def
    ;

local_def :
    func_def
    | func_decl
    | var_def
    ;

var_def :
    T_VAR id_list ':' type ';'
    ;

func_decl :
    header ';'
    ;

stmt :
    ';'
    | l_value "<-" expr ';'
    | block
    | func_call ';'
    | T_IF cond T_THEN stmt '[' T_ELSE stmt ']'
    | T_WHILE cond T_DO stmt
    | T_RETURN expr_opt ';'
    ;


expr_opt :
    | expr
    ;

block :
    '{' stmt_list '}'
    ;

stmt_list :
    | stmt_list stmt
    ;

func_call :
    T_ID '(' expr_list_opt ')'
    ;

expr_list_opt :
    | expr_list
    ;

expr_list :
    expr
    | expr_list ',' expr
    ;

l_value :
    T_ID
    | T_STR
    | l_value '[' expr ']'
    ;

expr
    : T_NUM
    | T_FIXED_CHAR
    | l_value
    | func_call
    | '(' expr ')'
    | '+' expr %prec UMINUS
    | '-' expr %prec UMINUS
    | expr '+' expr
    | expr '-' expr
    | expr '*' expr
    | expr T_DIV expr
    | expr T_MOD expr
    | expr T_SEPARATOR %prec T_SEPARATOR
    ;

cond
    : '(' cond ')'
    | T_NOT cond
    | cond T_AND cond
    | cond T_OR cond
    | expr T_OPERATOR expr
    ;


%%

extern int yylineno;

void yyerror(const char *msg) {
  fprintf(stderr, "Line %d: %s\n", yylineno, msg);
  exit(1);
}


int main() {
    yydebug = 1; 
    int result = yyparse();
    if (result == 0) printf("Success.\n");
    return result;
}
