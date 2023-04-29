%{
#define YY_DECL int yylex(void)


#include "parser.tab.h"
#include <stdio.h>
%}
%option debug
%option noyywrap

%x COMMENT

delim       [ \t\n]
ws          {delim}+
l           [A-Za-z]
d           [0-9]
common_char [^\\'"\n]
escape_seq  (\\[ntr0'"]|\\x[a-fA-F0-9]{2})
fixed_char  ({common_char}|{escape_seq})
str_char    ({common_char}|{escape_seq})



%%
\n              { ++yylineno; }

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
"("           { return T_LPAREN; }
")"           { return T_RPAREN; }
"["           { return T_LBRACKET; }
"]"           { return T_RBRACKET; }
"{"           { return T_LBRACE; }
"}"           { return T_RBRACE; }
","           { return T_COMMA; }
";"           { return T_SEMICOLON; }
":"           { return T_COLON; }
"<-"          { return T_ASSIGN; }

"+"           { return T_PLUS; }
"-"           { return T_MINUS; }
"*"           { return T_MULTIPLY; }
"/"           { return T_DIVIDE; }
"#"           { return T_HASH; }
"="           { return T_EQUAL; }
"<>"          { return T_NOT_EQUAL; }
"<"           { return T_LESS_THAN; }
">"           { return T_GREATER_THAN; }
"<="          { return T_LESS_EQUAL; }
">="          { return T_GREATER_EQUAL; }


{l}({l}|{d}|_)* { return T_ID; }
{d}+            { return T_NUM; }
'{fixed_char}'  { return T_FIXED_CHAR; }
\"{str_char}*\" { return T_STR; }

{delim}         {
                    if (*yytext == '\n') {
                        ++yylineno;
                    }
                }

\$[^$\n]*       { }

\$\$             { BEGIN(COMMENT);}

<COMMENT>\$\$    { BEGIN(INITIAL);}
<COMMENT>[^$\n]+ { }
<COMMENT>\$[^$\n]{0,1} { }
<COMMENT>\n       {++yylineno;  }
<<EOF>> { return 0; } 

.               { printf("Illegal token\n"); exit(1); }



%%
