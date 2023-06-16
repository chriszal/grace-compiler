/* A Bison parser, made by GNU Bison 3.5.1.  */

/* Bison implementation for Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.5.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "parser.y"

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

#line 87 "parser.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Use api.header.include to #include this header
   instead of duplicating it here.  */
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
#line 18 "parser.y"

  ast node;
  char c;
  int n;
  char* str;
  Type t;

#line 192 "parser.c"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_PARSER_H_INCLUDED  */



#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))

/* Stored state numbers (used for stacks). */
typedef yytype_uint8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && ! defined __ICC && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                            \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  5
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   177

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  45
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  28
/* YYNRULES -- Number of rules.  */
#define YYNRULES  74
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  135

#define YYUNDEFTOK  2
#define YYMAXUTOK   299


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    67,    67,    71,    75,    76,    77,    81,    85,    86,
      90,    91,    95,   100,   101,   105,   106,   107,   108,   111,
     112,   115,   116,   121,   122,   126,   127,   128,   132,   136,
     140,   144,   145,   146,   147,   148,   149,   150,   153,   154,
     158,   159,   162,   165,   166,   169,   172,   173,   176,   177,
     181,   182,   185,   186,   187,   188,   189,   190,   191,   192,
     193,   194,   195,   196,   197,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "T_AND", "T_CHAR", "T_DIV", "T_DO",
  "T_ELSE", "T_FUN", "T_IF", "T_INT", "T_MOD", "T_NOT", "T_NOTHING",
  "T_OR", "T_REF", "T_RETURN", "T_THEN", "T_VAR", "T_WHILE", "T_ID",
  "T_NUM", "T_FIXED_CHAR", "T_STR", "\"(\"", "\")\"", "\"[\"", "\"]\"",
  "\"{\"", "\"}\"", "\",\"", "\";\"", "\":\"", "\"<-\"", "\"+\"", "\"-\"",
  "\"*\"", "\"/\"", "\"#\"", "\"=\"", "\"<\"", "\">\"", "\"<=\"", "\">=\"",
  "T_HASH", "$accept", "func_def", "header", "fpar_defs", "fpar_def",
  "ref_opt", "id_list", "fpar_type", "data_type", "arr_dims", "arr_opt",
  "ret_type", "local_defs", "local_def", "var_def", "type", "func_decl",
  "stmt", "else_opt", "expr_opt", "block", "stmts", "func_call", "exprs",
  "expr_list", "l_value", "expr", "cond", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_int16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299
};
# endif

#define YYPACT_NINF (-90)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-9)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      43,    45,    73,   -90,    62,   -90,     0,    48,    68,   -90,
     -90,    89,   -90,   -90,   -90,   -90,   -90,   -12,   -90,    68,
     -90,   -18,   127,   -90,    90,   108,     1,   105,    80,    57,
     130,    57,   104,   -90,   -90,   -90,   -90,    98,   -23,     7,
     -90,    80,   -90,   -90,   -90,   118,   100,    57,   -90,   -90,
     -90,    57,   130,   130,   -90,   133,    59,    18,   130,   101,
      71,   113,   130,   -90,   130,   130,   -90,   -90,   -90,   -90,
     118,    94,   135,   -90,   -90,   -90,     4,     2,   103,   103,
     130,   130,   130,   130,   130,   130,   130,   130,   130,   130,
     130,    57,    57,   129,    78,   -90,   129,   137,   136,    71,
      99,   106,   -90,   140,   -90,    97,   -90,   -90,    14,    14,
     103,   103,   -90,    71,    71,    71,    71,    71,    71,   -90,
     160,   123,   -90,   -90,   130,   -90,   -90,   -90,   141,   -90,
     129,   -90,    71,   -90,   -90
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     0,    23,     0,     1,     0,     4,     0,    43,
      25,    23,    24,    27,    26,     2,     9,     0,     5,     0,
      10,     0,     0,    30,     0,     8,     0,     0,     0,     0,
      40,     0,    50,    42,    31,    44,    33,     0,     0,     0,
       6,     0,    11,    14,    13,    19,     0,     0,    52,    53,
      54,     0,     0,     0,    56,    55,     0,     0,     0,     0,
      41,     0,    46,    34,     0,     0,    22,    21,     3,     7,
      19,     0,    20,    29,    28,    66,     0,     0,    58,    59,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    37,     0,     0,    47,    48,
       0,     0,    12,     0,    15,     0,    57,    65,    63,    64,
      60,    61,    62,    70,    69,    71,    72,    73,    74,    67,
      68,    38,    36,    45,     0,    51,    32,    16,     0,    17,
       0,    35,    49,    18,    39
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -90,   163,   164,   -90,   146,   -90,   153,   -90,    46,   -90,
     107,   -90,   -90,   -90,   -90,   -90,   -90,   -89,   -90,   -90,
     167,   -90,   -22,   -90,   -90,   -21,   -28,   -25
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     3,    17,    18,    19,    21,    69,    45,    72,
      73,    68,     6,    12,    13,    46,    14,    35,   131,    59,
      36,    22,    54,    97,    98,    55,    56,    57
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      37,    38,    60,    64,   121,    91,    61,   122,     1,    80,
      65,    43,    27,    24,    28,    81,    92,    44,     8,    25,
      66,    91,    75,    76,    78,    79,    77,   107,     9,   106,
      94,    27,    92,    41,    99,    93,   100,   101,    82,    83,
      84,   134,    85,    86,    87,    88,    89,    90,    82,    83,
      84,     1,   108,   109,   110,   111,   112,   113,   114,   115,
     116,   117,   118,    16,    80,     4,   119,   120,    -8,    47,
      81,    37,    38,     5,    37,    38,    80,    32,    48,    49,
      50,    51,    81,    80,    43,    67,     7,    70,    20,    81,
      44,    52,    53,    82,    83,    84,   132,    85,    86,    87,
      88,    89,    90,   106,    80,    82,    83,    84,    37,    38,
      81,    80,    82,    83,    84,   103,    91,    81,   128,    96,
      23,   104,    39,    16,   129,    42,   125,    92,    62,    63,
     130,    74,    95,    82,    83,    84,    29,   126,    29,    84,
      82,    83,    84,    30,    71,    30,    31,    32,    31,    32,
      32,    48,    49,    50,    58,     9,    33,     9,    34,    64,
      34,   105,   123,    91,    52,    53,   124,   127,   133,    10,
      11,    40,    26,    15,     0,     0,     0,   102
};

static const yytype_int16 yycheck[] =
{
      22,    22,    30,    26,    93,     3,    31,    96,     8,     5,
      33,     4,    30,    25,    32,    11,    14,    10,    18,    31,
      13,     3,    47,    51,    52,    53,    51,    25,    28,    25,
      58,    30,    14,    32,    62,    17,    64,    65,    34,    35,
      36,   130,    38,    39,    40,    41,    42,    43,    34,    35,
      36,     8,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    89,    90,    15,     5,    20,    91,    92,    20,    12,
      11,    93,    93,     0,    96,    96,     5,    20,    21,    22,
      23,    24,    11,     5,     4,    39,    24,    41,    20,    11,
      10,    34,    35,    34,    35,    36,   124,    38,    39,    40,
      41,    42,    43,    25,     5,    34,    35,    36,   130,   130,
      11,     5,    34,    35,    36,    21,     3,    11,    21,     6,
      31,    27,    32,    15,    27,    20,    27,    14,    24,    31,
       7,    31,    31,    34,    35,    36,     9,    31,     9,    36,
      34,    35,    36,    16,    26,    16,    19,    20,    19,    20,
      20,    21,    22,    23,    24,    28,    29,    28,    31,    26,
      31,    26,    25,     3,    34,    35,    30,    27,    27,     6,
       6,    25,    19,     6,    -1,    -1,    -1,    70
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     8,    46,    47,    20,     0,    57,    24,    18,    28,
      46,    47,    58,    59,    61,    65,    15,    48,    49,    50,
      20,    51,    66,    31,    25,    31,    51,    30,    32,     9,
      16,    19,    20,    29,    31,    62,    65,    67,    70,    32,
      49,    32,    20,     4,    10,    53,    60,    12,    21,    22,
      23,    24,    34,    35,    67,    70,    71,    72,    24,    64,
      71,    72,    24,    31,    26,    33,    13,    53,    56,    52,
      53,    26,    54,    55,    31,    72,    71,    72,    71,    71,
       5,    11,    34,    35,    36,    38,    39,    40,    41,    42,
      43,     3,    14,    17,    71,    31,     6,    68,    69,    71,
      71,    71,    55,    21,    27,    26,    25,    25,    71,    71,
      71,    71,    71,    71,    71,    71,    71,    71,    71,    72,
      72,    62,    62,    25,    30,    27,    31,    27,    21,    27,
       7,    63,    71,    27,    62
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    45,    46,    47,    48,    48,    48,    49,    50,    50,
      51,    51,    52,    53,    53,    54,    54,    54,    54,    55,
      55,    56,    56,    57,    57,    58,    58,    58,    59,    60,
      61,    62,    62,    62,    62,    62,    62,    62,    63,    63,
      64,    64,    65,    66,    66,    67,    68,    68,    69,    69,
      70,    70,    71,    71,    71,    71,    71,    71,    71,    71,
      71,    71,    71,    71,    71,    72,    72,    72,    72,    72,
      72,    72,    72,    72,    72
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     3,     7,     0,     1,     3,     4,     0,     1,
       1,     3,     2,     1,     1,     2,     3,     3,     4,     0,
       1,     1,     1,     0,     2,     1,     1,     1,     5,     2,
       2,     1,     4,     1,     2,     5,     4,     3,     0,     2,
       0,     1,     3,     0,     2,     4,     0,     1,     1,     3,
       1,     4,     1,     1,     1,     1,     1,     3,     2,     2,
       3,     3,     3,     3,     3,     3,     2,     3,     3,     3,
       3,     3,     3,     3,     3
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YYUSE (yyoutput);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyo, yytoknum[yytype], *yyvaluep);
# endif
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyo, yytype, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[+yyssp[yyi + 1 - yynrhs]],
                       &yyvsp[(yyi + 1) - (yynrhs)]
                                              );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen(S) (YY_CAST (YYPTRDIFF_T, strlen (S)))
#  else
/* Return the length of YYSTR.  */
static YYPTRDIFF_T
yystrlen (const char *yystr)
{
  YYPTRDIFF_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYPTRDIFF_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYPTRDIFF_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            else
              goto append;

          append:
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (yyres)
    return yystpcpy (yyres, yystr) - yyres;
  else
    return yystrlen (yystr);
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYPTRDIFF_T *yymsg_alloc, char **yymsg,
                yy_state_t *yyssp, int yytoken)
{
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat: reported tokens (one for the "unexpected",
     one per "expected"). */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Actual size of YYARG. */
  int yycount = 0;
  /* Cumulated lengths of YYARG.  */
  YYPTRDIFF_T yysize = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[+*yyssp];
      YYPTRDIFF_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
      yysize = yysize0;
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYPTRDIFF_T yysize1
                    = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
                    yysize = yysize1;
                  else
                    return 2;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
    default: /* Avoid compiler warnings. */
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    /* Don't count the "%s"s in the final size, but reserve room for
       the terminator.  */
    YYPTRDIFF_T yysize1 = yysize + (yystrlen (yyformat) - 2 * yycount) + 1;
    if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
      yysize = yysize1;
    else
      return 2;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          ++yyp;
          ++yyformat;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    yy_state_fast_t yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss;
    yy_state_t *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYPTRDIFF_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYPTRDIFF_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    goto yyexhaustedlab;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
# undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;


/*-----------.
| yybackup.  |
`-----------*/
yybackup:
  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 2:
#line 67 "parser.y"
                                               { p = (yyval.node) = ast_function_def((yyvsp[-2].node),(yyvsp[-1].node), (yyvsp[0].node)); }
#line 1469 "parser.c"
    break;

  case 3:
#line 71 "parser.y"
                                               { (yyval.node) = ast_fun((yyvsp[-5].str),(yyvsp[-3].node),(yyvsp[0].node)); }
#line 1475 "parser.c"
    break;

  case 4:
#line 75 "parser.y"
                                                { (yyval.node) = ast_empty_stmts(); }
#line 1481 "parser.c"
    break;

  case 5:
#line 76 "parser.y"
                                                { (yyval.node) = (yyvsp[0].node); }
#line 1487 "parser.c"
    break;

  case 6:
#line 77 "parser.y"
                                                { (yyval.node) = ast_fpar_defs((yyvsp[-2].node), (yyvsp[0].node)); }
#line 1493 "parser.c"
    break;

  case 7:
#line 81 "parser.y"
                                                { (yyval.node) = ast_fpar_def((yyvsp[-3].node),(yyvsp[-2].node), (yyvsp[0].node));  }
#line 1499 "parser.c"
    break;

  case 8:
#line 85 "parser.y"
                                                { (yyval.node) = NULL; }
#line 1505 "parser.c"
    break;

  case 9:
#line 86 "parser.y"
                                                { (yyval.node) = ast_ref(); }
#line 1511 "parser.c"
    break;

  case 10:
#line 90 "parser.y"
                                                { (yyval.node) = ast_id((yyvsp[0].str)); }
#line 1517 "parser.c"
    break;

  case 11:
#line 91 "parser.y"
                                                { (yyval.node) = ast_id_list((yyvsp[-2].node), ast_id((yyvsp[0].str))); }
#line 1523 "parser.c"
    break;

  case 12:
#line 95 "parser.y"
                                                { (yyval.node) = ast_type_node((yyvsp[-1].node), (yyvsp[0].node)); }
#line 1529 "parser.c"
    break;

  case 13:
#line 100 "parser.y"
                                                { (yyval.node) = ast_data_type(INT,tyINT); }
#line 1535 "parser.c"
    break;

  case 14:
#line 101 "parser.y"
                                                { (yyval.node) = ast_data_type(CHAR,tyCHAR); }
#line 1541 "parser.c"
    break;

  case 15:
#line 105 "parser.y"
                                                { (yyval.node) = ast_array(0); }
#line 1547 "parser.c"
    break;

  case 16:
#line 106 "parser.y"
                                                { (yyval.node) = ast_array((yyvsp[-1].n)); }
#line 1553 "parser.c"
    break;

  case 17:
#line 107 "parser.y"
                                                { (yyval.node) = ast_array_dim((yyval.node), 0); }
#line 1559 "parser.c"
    break;

  case 18:
#line 108 "parser.y"
                                                { (yyval.node) = ast_array_dim((yyval.node), (yyvsp[-1].n)); }
#line 1565 "parser.c"
    break;

  case 19:
#line 111 "parser.y"
                                                { (yyval.node) = NULL; }
#line 1571 "parser.c"
    break;

  case 20:
#line 112 "parser.y"
                                                { (yyval.node) = (yyvsp[0].node); }
#line 1577 "parser.c"
    break;

  case 21:
#line 115 "parser.y"
                                                { (yyval.node) = (yyvsp[0].node); }
#line 1583 "parser.c"
    break;

  case 22:
#line 116 "parser.y"
                                                { (yyval.node) = ast_data_type(NOTHING,tyNOTHING);}
#line 1589 "parser.c"
    break;

  case 23:
#line 121 "parser.y"
                                               { (yyval.node) = NULL; }
#line 1595 "parser.c"
    break;

  case 24:
#line 122 "parser.y"
                                               { (yyval.node) = ast_local_defs((yyvsp[-1].node), (yyvsp[0].node)); }
#line 1601 "parser.c"
    break;

  case 25:
#line 126 "parser.y"
                                               { (yyval.node) = (yyvsp[0].node); }
#line 1607 "parser.c"
    break;

  case 26:
#line 127 "parser.y"
                                               { (yyval.node) = (yyvsp[0].node); }
#line 1613 "parser.c"
    break;

  case 27:
#line 128 "parser.y"
                                               { (yyval.node) = (yyvsp[0].node); }
#line 1619 "parser.c"
    break;

  case 28:
#line 132 "parser.y"
                                                { (yyval.node) = ast_var((yyvsp[-3].node), (yyvsp[-1].node)); }
#line 1625 "parser.c"
    break;

  case 29:
#line 136 "parser.y"
                                                { (yyval.node) = ast_type_node((yyvsp[-1].node), (yyvsp[0].node)); }
#line 1631 "parser.c"
    break;

  case 30:
#line 140 "parser.y"
                                                 { (yyval.node) = (yyvsp[-1].node); }
#line 1637 "parser.c"
    break;

  case 31:
#line 144 "parser.y"
                                                { (yyval.node) = NULL; }
#line 1643 "parser.c"
    break;

  case 32:
#line 145 "parser.y"
                                                { (yyval.node) = ast_op(ASSIGN, (yyvsp[-3].node), (yyvsp[-1].node)); }
#line 1649 "parser.c"
    break;

  case 33:
#line 146 "parser.y"
                                                { (yyval.node) = (yyvsp[0].node); }
#line 1655 "parser.c"
    break;

  case 34:
#line 147 "parser.y"
                                                { (yyval.node) = (yyvsp[-1].node); }
#line 1661 "parser.c"
    break;

  case 35:
#line 148 "parser.y"
                                                { (yyval.node) = ast_if((yyvsp[-3].node), (yyvsp[-1].node), (yyvsp[0].node)); }
#line 1667 "parser.c"
    break;

  case 36:
#line 149 "parser.y"
                                                { (yyval.node) = ast_while((yyvsp[-2].node), (yyvsp[0].node)); }
#line 1673 "parser.c"
    break;

  case 37:
#line 150 "parser.y"
                                                { (yyval.node) = ast_return((yyvsp[-1].node)); }
#line 1679 "parser.c"
    break;

  case 38:
#line 153 "parser.y"
                                                { (yyval.node) = NULL; }
#line 1685 "parser.c"
    break;

  case 39:
#line 154 "parser.y"
                                                { (yyval.node) = ast_else((yyvsp[0].node)); }
#line 1691 "parser.c"
    break;

  case 40:
#line 158 "parser.y"
                                                { (yyval.node) = NULL; }
#line 1697 "parser.c"
    break;

  case 41:
#line 159 "parser.y"
                                                { (yyval.node) = (yyvsp[0].node); }
#line 1703 "parser.c"
    break;

  case 42:
#line 162 "parser.y"
                                                { (yyval.node) = ast_block((yyvsp[-1].node));  }
#line 1709 "parser.c"
    break;

  case 43:
#line 165 "parser.y"
                                                { (yyval.node) = NULL; }
#line 1715 "parser.c"
    break;

  case 44:
#line 166 "parser.y"
                                                { (yyval.node) = ast_stmts((yyvsp[-1].node), (yyvsp[0].node)); }
#line 1721 "parser.c"
    break;

  case 45:
#line 169 "parser.y"
                                                { (yyval.node) = ast_func_call((yyvsp[-3].str), (yyvsp[-1].node)); }
#line 1727 "parser.c"
    break;

  case 46:
#line 172 "parser.y"
                                                { (yyval.node) = NULL; }
#line 1733 "parser.c"
    break;

  case 47:
#line 173 "parser.y"
                                                { (yyval.node) = (yyvsp[0].node);}
#line 1739 "parser.c"
    break;

  case 48:
#line 176 "parser.y"
                                                { (yyval.node) = ast_arg_list((yyvsp[0].node), NULL); }
#line 1745 "parser.c"
    break;

  case 49:
#line 177 "parser.y"
                                                { (yyval.node) = ast_arg_list((yyvsp[0].node), (yyvsp[-2].node)); }
#line 1751 "parser.c"
    break;

  case 50:
#line 181 "parser.y"
                                                { (yyval.node) = ast_id((yyvsp[0].str)); }
#line 1757 "parser.c"
    break;

  case 51:
#line 182 "parser.y"
                                                { (yyval.node) = ast_array_index((yyvsp[-3].node), (yyvsp[-1].node)); }
#line 1763 "parser.c"
    break;

  case 52:
#line 185 "parser.y"
                                                { (yyval.node) = ast_num((yyvsp[0].n)); }
#line 1769 "parser.c"
    break;

  case 53:
#line 186 "parser.y"
                                                { (yyval.node) = ast_char((yyvsp[0].c)); }
#line 1775 "parser.c"
    break;

  case 54:
#line 187 "parser.y"
                                                { (yyval.node) = ast_str((yyvsp[0].str)); }
#line 1781 "parser.c"
    break;

  case 55:
#line 188 "parser.y"
                                                { (yyval.node) = (yyvsp[0].node); }
#line 1787 "parser.c"
    break;

  case 56:
#line 189 "parser.y"
                                                { (yyval.node) = (yyvsp[0].node); }
#line 1793 "parser.c"
    break;

  case 57:
#line 190 "parser.y"
                                                { (yyval.node) = (yyvsp[-1].node); }
#line 1799 "parser.c"
    break;

  case 58:
#line 191 "parser.y"
                                                { (yyval.node) = ast_op(POSITIVE, (yyvsp[0].node), NULL); }
#line 1805 "parser.c"
    break;

  case 59:
#line 192 "parser.y"
                                                { (yyval.node) = ast_op(NEGATIVE, (yyvsp[0].node), NULL); }
#line 1811 "parser.c"
    break;

  case 60:
#line 193 "parser.y"
                                                { (yyval.node) = ast_op(PLUS, (yyvsp[-2].node), (yyvsp[0].node)); }
#line 1817 "parser.c"
    break;

  case 61:
#line 194 "parser.y"
                                                { (yyval.node) = ast_op(MINUS, (yyvsp[-2].node), (yyvsp[0].node)); }
#line 1823 "parser.c"
    break;

  case 62:
#line 195 "parser.y"
                                                { (yyval.node) = ast_op(MULTIPLY, (yyvsp[-2].node), (yyvsp[0].node)); }
#line 1829 "parser.c"
    break;

  case 63:
#line 196 "parser.y"
                                                { (yyval.node) = ast_op(DIV, (yyvsp[-2].node), (yyvsp[0].node)); }
#line 1835 "parser.c"
    break;

  case 64:
#line 197 "parser.y"
                                                { (yyval.node) = ast_op(MOD, (yyvsp[-2].node), (yyvsp[0].node)); }
#line 1841 "parser.c"
    break;

  case 65:
#line 200 "parser.y"
                                                { (yyval.node) = (yyvsp[-1].node); }
#line 1847 "parser.c"
    break;

  case 66:
#line 201 "parser.y"
                                                { (yyval.node) = ast_op(NOT, (yyvsp[0].node), NULL); }
#line 1853 "parser.c"
    break;

  case 67:
#line 202 "parser.y"
                                                { (yyval.node) = ast_op(AND, (yyvsp[-2].node), (yyvsp[0].node)); }
#line 1859 "parser.c"
    break;

  case 68:
#line 203 "parser.y"
                                                { (yyval.node) = ast_op(OR, (yyvsp[-2].node), (yyvsp[0].node)); }
#line 1865 "parser.c"
    break;

  case 69:
#line 204 "parser.y"
                                                { (yyval.node) = ast_op(EQUAL, (yyvsp[-2].node), (yyvsp[0].node)); }
#line 1871 "parser.c"
    break;

  case 70:
#line 205 "parser.y"
                                                { (yyval.node) = ast_op(NOT_EQUAL, (yyvsp[-2].node), (yyvsp[0].node)); }
#line 1877 "parser.c"
    break;

  case 71:
#line 206 "parser.y"
                                                { (yyval.node) = ast_op(LESS_THAN, (yyvsp[-2].node), (yyvsp[0].node)); }
#line 1883 "parser.c"
    break;

  case 72:
#line 207 "parser.y"
                                                { (yyval.node) = ast_op(GREATER_THAN, (yyvsp[-2].node), (yyvsp[0].node)); }
#line 1889 "parser.c"
    break;

  case 73:
#line 208 "parser.y"
                                                { (yyval.node) = ast_op(LESS_EQUAL, (yyvsp[-2].node), (yyvsp[0].node)); }
#line 1895 "parser.c"
    break;

  case 74:
#line 209 "parser.y"
                                                { (yyval.node) = ast_op(GREATER_EQUAL, (yyvsp[-2].node), (yyvsp[0].node)); }
#line 1901 "parser.c"
    break;


#line 1905 "parser.c"

      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = YY_CAST (char *, YYSTACK_ALLOC (YY_CAST (YYSIZE_T, yymsg_alloc)));
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYTERROR;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;


#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif


/*-----------------------------------------------------.
| yyreturn -- parsing is finished, return the result.  |
`-----------------------------------------------------*/
yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[+*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  return yyresult;
}
#line 213 "parser.y"


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

