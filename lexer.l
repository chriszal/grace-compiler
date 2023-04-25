%{
#include "parser.tab.h"
#include <stdio.h>
%}

%option noyywrap

delim       [ \t\n]
ws          {delim}+
l           [A-Za-z]
d           [0-9]
fixed_char  (\\.|[^\\'"])
str_char    (\\.|[^\\""])
operator    (\+|-|\*|\/|#|=|<>|<|>|<=|>=)
separator   [\(\)\[\]\{\},;:|<-]

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
\$.*\n          { }
\$\$.*\$\$       {}

.               { printf("Illegal token\n"); exit(1); }

%%

