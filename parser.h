/* A Bison parser, made by GNU Bison 3.5.1.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2020 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

#ifndef YY_YY_PARSER_H_INCLUDED
# define YY_YY_PARSER_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    T_AND = 258,
    T_CHAR = 259,
    T_DIV = 260,
    T_DO = 261,
    T_ELSE = 262,
    T_FUN = 263,
    T_IF = 264,
    T_INT = 265,
    T_MOD = 266,
    T_NOT = 267,
    T_NOTHING = 268,
    T_OR = 269,
    T_REF = 270,
    T_RETURN = 271,
    T_THEN = 272,
    T_VAR = 273,
    T_WHILE = 274,
    T_ID = 275,
    T_NUM = 276,
    T_FIXED_CHAR = 277,
    T_STR = 278,
    T_LPAREN = 279,
    T_RPAREN = 280,
    T_LBRACKET = 281,
    T_RBRACKET = 282,
    T_LBRACE = 283,
    T_RBRACE = 284,
    T_COMMA = 285,
    T_SEMICOLON = 286,
    T_COLON = 287,
    T_ASSIGN = 288,
    T_PLUS = 289,
    T_MINUS = 290,
    T_MULTIPLY = 291,
    T_DIVIDE = 292,
    T_NOT_EQUAL = 293,
    T_EQUAL = 294,
    T_LESS_THAN = 295,
    T_GREATER_THAN = 296,
    T_LESS_EQUAL = 297,
    T_GREATER_EQUAL = 298,
    T_HASH = 299
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 20 "parser.y"

  ast node;
  char c;
  int n;
  char* str;
  Type t;

#line 110 "parser.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_PARSER_H_INCLUDED  */
