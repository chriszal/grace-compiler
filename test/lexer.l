%{
#include <stdio.h>
#define T_AND        1001
#define T_CHAR       1002
#define T_DIV        1003
#define T_DO         1004
#define T_ELSE       1005
#define T_FUN        1006
#define T_IF         1007
#define T_INT        1008
#define T_MOD        1009
#define T_NOT        1010
#define T_NOTHING    1011
#define T_OR         1012
#define T_REF        1013
#define T_RETURN     1014
#define T_THEN       1015
#define T_VAR        1016
#define T_WHILE      1017
#define T_ID         1018
#define T_NUM        1019
#define T_FIXED_CHAR 1020
#define T_STR        1021
#define T_OPERATOR   1022
#define T_SEPARATOR  1023
%}

%option noyywrap

%x COMMENT

delim       [ \t\n]
ws          {delim}+
l           [A-Za-z]
d           [0-9]
fixed_char  (\\([\\'\"ntr0]|x[a-fA-F0-9]{2})|[^\\'"])
str_char    (\\([\\\"ntr0]|x[a-fA-F0-9]{2})|[^\\""])
operator    (\+|-|\*|\/|#|=|<>|<|>|<=|>=)
separator   [\(\)\[\]\{\},;:]|<-

%%

"and"          { return T_AND; }
"char"         { return T_CHAR; }
"div"          { return T_DIV; }
"do"           { return T_DO; }
"else"         { return T_ELSE; }
"fun"          { return T_FUN; }
"if"           { return T_IF; }
"int"          { return T_INT; }
"mod"          { return T_MOD; }
"not"          { return T_NOT; }
"nothing"      { return T_NOTHING; }
"or"           { return T_OR; }
"ref"          { return T_REF; }
"return"       { return T_RETURN; }
"then"         { return T_THEN; }
"var"          { return T_VAR; }
"while"        { return T_WHILE; }

{l}({l}|{d}|_)* { return T_ID; }
{d}+            { return T_NUM; }
'{fixed_char}'  { return T_FIXED_CHAR; }
\"{str_char}*\" { return T_STR; }
{operator}      { return T_OPERATOR; }
{separator}     { return T_SEPARATOR; }

{ws}            {}

\$[^$\n]*       { }

\$\$             { BEGIN(COMMENT);}

<COMMENT>\$\$    { BEGIN(INITIAL);}
<COMMENT>[^$\n]+ { }
<COMMENT>\$[^$\n]{0,1} { }
<COMMENT>\n       { }


.               { printf("Illegal token\n"); exit(1); }

%%

int main() {
    int token;
    do {
        token = yylex();
        printf("token=%d, lexeme=\"%s\"\n", token, yytext);
    } while(token != 0);
}