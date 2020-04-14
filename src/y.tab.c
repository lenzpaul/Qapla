/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

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

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.0.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 18 "fooChecker_debug.yacc" /* yacc.c:339  */

#include "dataStructures/Nodes.h"
#include "dataStructures/functions.h"
#define DEBUGTAG 1
//#define YYSTYPE dataNode
#include<stdio.h>
#include<string.h>
#include <math.h>
#include <stdbool.h>

//#include "dataStructures/functions.c"
int yylex(void);
int yywrap();
int yyerror(char* s);

#line 82 "y.tab.c" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* In a future release of Bison, this section will be replaced
   by #include "y.tab.h".  */
#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
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
    INTEGER = 258,
    REAL = 259,
    IDENTIFIER = 260,
    STRING = 261,
    BOOLEAN = 262,
    PRINT = 263,
    VAR = 264,
    MOD = 265,
    FUNC = 266,
    EVAL = 267,
    RETURN = 268,
    IF = 269,
    ELSEIF = 270,
    ELSE = 271,
    WHILE = 272,
    AND = 273,
    OR = 274,
    NOT = 275,
    NEQ = 276
  };
#endif
/* Tokens.  */
#define INTEGER 258
#define REAL 259
#define IDENTIFIER 260
#define STRING 261
#define BOOLEAN 262
#define PRINT 263
#define VAR 264
#define MOD 265
#define FUNC 266
#define EVAL 267
#define RETURN 268
#define IF 269
#define ELSEIF 270
#define ELSE 271
#define WHILE 272
#define AND 273
#define OR 274
#define NOT 275
#define NEQ 276

/* Value type.  */


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 170 "y.tab.c" /* yacc.c:358  */

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

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

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
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
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
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
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  41
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   263

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  35
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  29
/* YYNRULES -- Number of rules.  */
#define YYNRULES  64
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  120

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   276

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      29,    30,    25,    23,     2,    24,     2,    26,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    33,    28,
      34,    22,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,    27,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    31,     2,    32,     2,     2,     2,     2,
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
      15,    16,    17,    18,    19,    20,    21
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   123,   123,   132,   133,   137,   144,   154,   161,   171,
     196,   206,   221,   236,   251,   262,   271,   290,   303,   322,
     342,   361,   399,   413,   424,   455,   496,   512,   518,   599,
     705,   725,   745,   755,   793,   800,   809,   821,   863,   873,
     882,   893,   905,   926,   967,   980,   991,  1000,  1019,  1055,
    1149,  1175,  1214,  1223,  1242,  1261,  1278,  1298,  1317,  1336,
    1346,  1362,  1377,  1392,  1417
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "INTEGER", "REAL", "IDENTIFIER",
  "STRING", "BOOLEAN", "PRINT", "VAR", "MOD", "FUNC", "EVAL", "RETURN",
  "IF", "ELSEIF", "ELSE", "WHILE", "AND", "OR", "NOT", "NEQ", "'='", "'+'",
  "'-'", "'*'", "'/'", "'^'", "';'", "'('", "')'", "'{'", "'}'", "':'",
  "'<'", "$accept", "script", "threads", "thread", "evaluations",
  "evaluation", "funbody", "statements", "statement", "selection",
  "ifcomponent", "elseifcomponents", "elseifcomponent", "elsecomponent",
  "declarations", "fundecl", "paramdecl_list", "paramdecl", "expression",
  "funcall", "paramassign_list", "paramassign", "retstmt", "vardecl",
  "assignexpr", "ioexpr", "boolexpr", "strexpr", "intexpr", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,    61,    43,    45,    42,    47,    94,    59,    40,
      41,   123,   125,    58,    60
};
# endif

#define YYPACT_NINF -64

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-64)))

#define YYTABLE_NINF -56

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     149,   -64,   -20,   -64,   -64,   -18,    16,    23,    -4,   209,
       2,   209,    53,   149,   -64,   199,   -64,   -64,   -64,    62,
      49,   -64,   163,   -64,   -64,    35,   -64,    68,   -64,    36,
     209,    11,   234,   -64,    59,   209,    77,    69,   114,   -64,
      15,   -64,   -64,   -64,    79,    80,    62,   -64,   -64,   -64,
     209,   209,   209,   -64,   209,   -64,   209,   209,     2,     2,
      69,   -64,    69,    -1,   -64,    54,    46,     7,    20,   -64,
     209,   199,   -64,   -64,    69,    69,    70,    69,   118,   192,
      85,   -64,   -64,   209,   -64,   -64,   -64,   -64,    81,    24,
     -64,    83,   101,    65,   -64,   -64,   174,    84,    61,   199,
      87,   -64,   -64,   209,    89,   174,   -64,   174,   -64,    93,
     199,   223,   -64,   -64,    91,   -64,   121,   -64,   -64,   -64
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,    61,    36,    60,    59,     0,     0,     0,     0,     0,
       0,     0,     0,     2,     3,     5,     7,     9,    15,    17,
       6,    26,     0,    35,    34,     0,    40,    41,    39,    38,
       0,     0,     0,    48,     0,     0,    36,     0,    41,    62,
      41,     1,     4,     8,     0,     0,    18,    22,    20,    27,
       0,     0,     0,    16,     0,    14,     0,     0,     0,     0,
      49,    42,    46,     0,    44,    36,     0,     0,    41,    52,
       0,     0,    23,    19,    57,    58,    37,    56,    41,    41,
      63,    64,    43,     0,    51,    50,    33,    32,     0,     0,
      30,     0,    41,     0,    12,    45,     0,     0,     0,     0,
       0,    25,    13,     0,     0,     0,    11,     0,    31,     0,
       0,     0,    28,    10,     0,    21,     0,    47,    29,    24
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -64,   -64,   -64,   125,   -64,   119,    32,   -63,     0,   -64,
     -64,   -64,    94,    97,   -64,   129,   -64,    63,    -8,   -64,
     -64,    76,    57,   -64,   -64,   -64,    -5,   -64,    -3
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,    12,    13,    14,    15,    16,   104,   105,    94,    18,
      19,    46,    47,    48,    20,    21,    89,    90,    22,    23,
      63,    64,   106,    24,    25,    26,    27,    28,    29
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int8 yytable[] =
{
      17,    37,    30,    37,    38,     1,    40,    39,    93,    31,
      86,    32,    87,    17,     1,    17,    36,     3,     4,     5,
       6,    33,    60,    62,    66,    35,    10,    37,    34,    82,
      68,     9,    83,    56,    57,    10,   109,    88,    56,    57,
      11,    61,    74,    75,    76,    69,    77,   116,    37,    37,
      91,    78,    79,    41,    97,    80,    81,    98,    50,    58,
       7,    59,    37,    55,    86,    92,    87,    51,     1,    52,
       2,     3,     4,     5,     6,    62,    85,    44,    45,     8,
      54,    50,    50,    31,    84,     9,    56,    57,    67,    10,
      51,    51,    52,   102,    11,   111,     1,   101,     2,     3,
       4,     5,     6,    54,    54,   102,    31,     8,    70,   102,
      59,    71,    96,     9,    99,   107,   102,    10,   110,    56,
      57,   112,    11,   118,     1,   115,     2,     3,     4,     5,
       6,   100,    56,    57,    43,     8,    56,    57,    42,   114,
      72,     9,   -55,    73,   -55,    10,   -53,   -55,   -53,    49,
      11,   -53,     1,   119,     2,     3,     4,     5,     6,    95,
       7,   108,   113,     8,     0,     0,     0,     0,     0,     9,
       0,     0,     0,    10,     0,    50,     0,     1,    11,     2,
       3,     4,     5,     6,    51,     0,    52,   103,     8,     0,
       0,    53,     0,     0,     9,     0,     0,    54,    10,     0,
       0,     0,     1,    11,     2,     3,     4,     5,     6,     0,
      56,    57,     1,     8,    36,     3,     4,     5,     6,     9,
     -54,     0,   -54,    10,     0,   -54,     0,     0,    11,     9,
       0,     0,     0,    10,     0,    50,     0,     1,    11,    65,
       3,     4,     5,     6,    51,     0,    52,     0,     0,     0,
       0,   117,     0,     0,     9,     0,     0,    54,    10,     0,
       0,     0,     0,    11
};

static const yytype_int8 yycheck[] =
{
       0,     9,    22,    11,     9,     3,    11,    10,    71,    29,
       3,    29,     5,    13,     3,    15,     5,     6,     7,     8,
       9,     5,    30,    31,    32,    29,    24,    35,     5,    30,
      35,    20,    33,    18,    19,    24,    99,    30,    18,    19,
      29,    30,    50,    51,    52,    30,    54,   110,    56,    57,
      30,    56,    57,     0,    30,    58,    59,    33,    12,    23,
      11,    25,    70,    28,     3,    70,     5,    21,     3,    23,
       5,     6,     7,     8,     9,    83,    30,    15,    16,    14,
      34,    12,    12,    29,    30,    20,    18,    19,    29,    24,
      21,    21,    23,    93,    29,   103,     3,    32,     5,     6,
       7,     8,     9,    34,    34,   105,    29,    14,    29,   109,
      25,    31,    31,    20,    31,    31,   116,    24,    31,    18,
      19,    32,    29,    32,     3,    32,     5,     6,     7,     8,
       9,    30,    18,    19,    15,    14,    18,    19,    13,   107,
      46,    20,    28,    46,    30,    24,    28,    33,    30,    20,
      29,    33,     3,    32,     5,     6,     7,     8,     9,    83,
      11,    98,   105,    14,    -1,    -1,    -1,    -1,    -1,    20,
      -1,    -1,    -1,    24,    -1,    12,    -1,     3,    29,     5,
       6,     7,     8,     9,    21,    -1,    23,    13,    14,    -1,
      -1,    28,    -1,    -1,    20,    -1,    -1,    34,    24,    -1,
      -1,    -1,     3,    29,     5,     6,     7,     8,     9,    -1,
      18,    19,     3,    14,     5,     6,     7,     8,     9,    20,
      28,    -1,    30,    24,    -1,    33,    -1,    -1,    29,    20,
      -1,    -1,    -1,    24,    -1,    12,    -1,     3,    29,     5,
       6,     7,     8,     9,    21,    -1,    23,    -1,    -1,    -1,
      -1,    28,    -1,    -1,    20,    -1,    -1,    34,    24,    -1,
      -1,    -1,    -1,    29
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,     5,     6,     7,     8,     9,    11,    14,    20,
      24,    29,    36,    37,    38,    39,    40,    43,    44,    45,
      49,    50,    53,    54,    58,    59,    60,    61,    62,    63,
      22,    29,    29,     5,     5,    29,     5,    53,    61,    63,
      61,     0,    38,    40,    15,    16,    46,    47,    48,    50,
      12,    21,    23,    28,    34,    28,    18,    19,    23,    25,
      53,    30,    53,    55,    56,     5,    53,    29,    61,    30,
      29,    31,    47,    48,    53,    53,    53,    53,    61,    61,
      63,    63,    30,    33,    30,    30,     3,     5,    30,    51,
      52,    30,    61,    42,    43,    56,    31,    30,    33,    31,
      30,    32,    43,    13,    41,    42,    57,    31,    52,    42,
      31,    53,    32,    57,    41,    32,    42,    28,    32,    32
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    35,    36,    37,    37,    38,    38,    39,    39,    40,
      41,    41,    42,    42,    43,    43,    43,    44,    44,    44,
      44,    45,    46,    46,    47,    48,    49,    49,    50,    50,
      51,    51,    52,    52,    53,    53,    53,    53,    53,    53,
      53,    53,    54,    54,    55,    55,    56,    57,    58,    59,
      60,    60,    61,    61,    61,    61,    61,    61,    61,    61,
      62,    63,    63,    63,    63
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     1,     2,     1,     1,     1,     2,     1,
       2,     1,     1,     2,     2,     1,     2,     1,     2,     3,
       2,     7,     1,     2,     7,     4,     1,     2,     7,     8,
       1,     3,     1,     1,     1,     1,     1,     3,     1,     1,
       1,     1,     3,     4,     1,     3,     1,     3,     2,     3,
       4,     4,     3,     3,     3,     2,     3,     3,     3,     1,
       1,     1,     2,     3,     3
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
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


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
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
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
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
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
yystrlen (const char *yystr)
{
  YYSIZE_T yylen;
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
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
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
            /* Fall through.  */
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

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
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
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

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
      int yyn = yypact[*yyssp];
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
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
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
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
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
          yyp++;
          yyformat++;
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
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

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
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
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
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        YYSTYPE *yyvs1 = yyvs;
        yytype_int16 *yyss1 = yyss;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * sizeof (*yyssp),
                    &yyvs1, yysize * sizeof (*yyvsp),
                    &yystacksize);

        yyss = yyss1;
        yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yytype_int16 *yyss1 = yyss;
        union yyalloc *yyptr =
          (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
                  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

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

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

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
| yyreduce -- Do a reduction.  |
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
#line 124 "fooChecker_debug.yacc" /* yacc.c:1646  */
    {
            #if DEBUGTAG 
               printf(" ~RULE: script --> threads \n "); 
            #endif
         }
#line 1359 "y.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 138 "fooChecker_debug.yacc" /* yacc.c:1646  */
    {
            #if DEBUGTAG 
               printf(" ~RULE:threads --> evaluations \n "); 
            #endif
            
         }
#line 1370 "y.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 145 "fooChecker_debug.yacc" /* yacc.c:1646  */
    {
            #if DEBUGTAG 
               printf(" ~RULE:threads --> declarations \n "); 
            #endif
            
         }
#line 1381 "y.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 155 "fooChecker_debug.yacc" /* yacc.c:1646  */
    { 
            #if DEBUGTAG
               printf(" ~RULE~: evaluations --> evaluation \n"); 
            #endif
         }
#line 1391 "y.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 162 "fooChecker_debug.yacc" /* yacc.c:1646  */
    { 
            #if DEBUGTAG
               printf(" ~RULE~: evaluations --> evaluations evaluation \n"); 
            #endif
         }
#line 1401 "y.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 172 "fooChecker_debug.yacc" /* yacc.c:1646  */
    { 
            #if DEBUGTAG
               printf(" ~RULE~: evaluation --> statement \n"); 
               printf("statement dtype is: %d\n", (yyvsp[0].datanode->dtype));
               printf("statement name is: %s\n", (yyvsp[0].datanode->name));
               //DELETE ME //////////////////////////////////////////////////////////
                     //printf("statement children 0 ival is: %d\n", $<datanode->children[0]->ival>1);
                     //printf("statement children 0 name is: %s\n", $<datanode->children[0]->name>1);
               ////////////////////////////////////////////////////////////////////////////////////
            #endif
            
            //evaluate statement here
            evaluate((yyvsp[0].datanode));    //its children no?

            //This needs to happen ON EVALUATE only 
               //insert IDENTIFIER in varContainer (variable array)
               //ie: create var 
            //insertChild(varContainer,$<datanode>1);        
            ///////
         }
#line 1426 "y.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 197 "fooChecker_debug.yacc" /* yacc.c:1646  */
    {
            #if DEBUGTAG
               printf(" ~RULE~: funbody -->  statements retstmt \n");
            #endif
            //FIXME create array of retstmt + statements
            //insert addtional statements in statements array as children
            (yyval.datanode) = insertChild((yyvsp[-1].datanode), (yyvsp[0].datanode));
              
         }
#line 1440 "y.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 207 "fooChecker_debug.yacc" /* yacc.c:1646  */
    {
            #if DEBUGTAG
               printf(" ~RULE~: funbody -->  retstmt \n");
            #endif
            (yyval.datanode) = constructNode(1); //container for instruction
            (yyval.datanode) = insertChild((yyval.datanode), (yyvsp[0].datanode));

         }
#line 1453 "y.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 222 "fooChecker_debug.yacc" /* yacc.c:1646  */
    { 
            #if DEBUGTAG
               printf(" ~RULE~:statements --> statement \n");
            #endif


            //CREATE ARRAY OF STATMENTS//////////////////////
            (yyval.datanode) = constructNode(2);
            strcpy((yyval.datanode->name), "info_statements");//info label only, has no use

            (yyval.datanode->dtype) = -1; //to ensure it doesn't evaluate

            insertChild((yyval.datanode), (yyvsp[0].datanode));
         }
#line 1472 "y.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 237 "fooChecker_debug.yacc" /* yacc.c:1646  */
    { 
            #if DEBUGTAG
               printf(" ~RULE~:statements --> statements statement \n");
            #endif

            //insert addtional statements in statements array as children
            insertChild((yyval.datanode), (yyvsp[0].datanode));
            /////////////////////////////////////////////////////////////
         }
#line 1486 "y.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 252 "fooChecker_debug.yacc" /* yacc.c:1646  */
    { 
            #if DEBUGTAG
               printf(" ~RULE: statement --> assignexpr \n");    //DEBUG
            #endif

            (yyval.datanode) = (yyvsp[-1].datanode);

         }
#line 1499 "y.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 263 "fooChecker_debug.yacc" /* yacc.c:1646  */
    { 
            #if DEBUGTAG
               printf(" ~RULE: statement --> selection \n");    //DEBUG
            #endif

           // $<datanode>$ = $<datanode>1;
         }
#line 1511 "y.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 272 "fooChecker_debug.yacc" /* yacc.c:1646  */
    { 
            #if DEBUGTAG
               printf(" ~RULE:statement--> expression ; \n"); 
               //printf("expression children[0]: %d \n", $<datanode->children[0]->    ival>1 ); 
               printf("expression dtype is: %d\n", (yyvsp[-1].datanode->dtype));
               printf("expression name is: %s\n", (yyvsp[-1].datanode->name));
               printf(" \n");
            #endif

            (yyval.datanode) = (yyvsp[-1].datanode);
         }
#line 1527 "y.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 291 "fooChecker_debug.yacc" /* yacc.c:1646  */
    {
            #if DEBUGTAG 
               printf(" ~RULE: selection --> ifcomponent \n" );
            #endif           
            struct DataNode *node = constructNode (1) ;
            strcpy(node->name, "selectBlock");
            node = insertChild(node, (yyvsp[0].datanode));
            node->bval = false;
            node->dtype = 8 ; //instruction
            (yyval.datanode) = node;
         }
#line 1543 "y.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 304 "fooChecker_debug.yacc" /* yacc.c:1646  */
    {
            #if DEBUGTAG 
               printf(" ~RULE: selection --> ifcomponent elseifcomponents\n" );
            #endif           

            struct DataNode *node = constructNode (2) ;
            strcpy(node->name, "selectBlock");
            node = insertChild(node, (yyvsp[-1].datanode));
            
            int elseIfCount = (yyvsp[0].datanode)->size;
            for(int i=0; i<elseIfCount; i++) 
                node = insertChild(node, (yyvsp[0].datanode->children[i]));
            
            node->bval = false;
            node->dtype = 8 ; //instruction
            (yyval.datanode) = node;
         }
#line 1565 "y.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 323 "fooChecker_debug.yacc" /* yacc.c:1646  */
    {
            #if DEBUGTAG 
               printf(" ~RULE: selection --> ifcomponent elseifcomponents elsecomponent\n" );
            #endif           

            struct DataNode *node = constructNode (2) ;
            strcpy(node->name, "selectBlock");
            node = insertChild(node, (yyvsp[-2].datanode));

            int elseIfCount = (yyvsp[-1].datanode)->size;
            for(int i=0; i<elseIfCount; i++) 
                node = insertChild(node, (yyvsp[-1].datanode->children[i]));
            
            node = insertChild(node, (yyvsp[0].datanode));
            node->bval = false;
            node->dtype = 8 ; //instruction
            (yyval.datanode) = node;
         }
#line 1588 "y.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 343 "fooChecker_debug.yacc" /* yacc.c:1646  */
    {
            #if DEBUGTAG 
               printf(" ~RULE: selection --> ifcomponent elsecomponent\n" );
            #endif           

            struct DataNode *node = constructNode (2) ;
            strcpy(node->name, "selectBlock");
            node = insertChild(node, (yyvsp[-1].datanode));
            node = insertChild(node, (yyvsp[0].datanode));
            node->bval = false;
            node->dtype = 8 ; //instruction
            (yyval.datanode) = node;
         }
#line 1606 "y.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 362 "fooChecker_debug.yacc" /* yacc.c:1646  */
    {
            #if DEBUGTAG 
               printf(" ~RULE: ifcomponent --> IF '(' boolexpr ')' '{' statements '}'  \n");
            #endif           


            struct DataNode *node = constructNode(4);
            strcpy(node->name,"ifBlock");  
            insertChild(node, (yyvsp[-4].datanode));

            //INSERT THE LIST OF STATEMENTS
            //ie; storing every instruction individually 
            //as children of the if node
            //NOTE: statements is an array of individual instruction nodes
            //    statements->children should be inserted and NOT the whole
            //      container node
            struct DataNode *stmts = (yyvsp[-1].datanode);
            int numStatements = stmts->size;
            for(int i=0; i<numStatements; i++){
               insertChild(node,stmts->children[i]);
            }

            node->dtype = 8 ;
            node->bval = false;
            (yyval.datanode) = node;
         }
#line 1637 "y.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 400 "fooChecker_debug.yacc" /* yacc.c:1646  */
    {
            #if DEBUGTAG 
               printf(" ~RULE: elseifcomponents --> elseifcomponent \n");
            #endif           

            //$$ is an array of elseifcomponent nodes
            //Its children are individual elseifcomponent's
            (yyval.datanode) = constructNode(2);
            //$<datanode->dtype>$ = 7; //parameters  FIXME should be for decl only ?
            strcpy((yyval.datanode->name),"info_elseifcomponents");  //informative label only
            insertChild((yyval.datanode), (yyvsp[0].datanode));
         }
#line 1654 "y.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 414 "fooChecker_debug.yacc" /* yacc.c:1646  */
    {
            #if DEBUGTAG 
               printf(" ~RULE: elseifcomponents --> elseifcomponents elseifcomponent \n");
            #endif           
            insertChild((yyval.datanode), (yyvsp[0].datanode));
         }
#line 1665 "y.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 425 "fooChecker_debug.yacc" /* yacc.c:1646  */
    {
            #if DEBUGTAG 
               printf(" ~RULE: elseifcomponent -->  ELSEIF '(' boolexpr ')' '{' statements '}'\n");
            #endif           

            struct DataNode *node = constructNode(4);
            strcpy(node->name,"elseIfBlock");  
            insertChild(node, (yyvsp[-4].datanode));

            //INSERT THE LIST OF STATEMENTS
            //ie; storing every instruction individually 
            //as children of the elseif node
            //NOTE: statements is an array of individual instruction nodes
            //    statements->children should be inserted and NOT the whole
            //      container node
            struct DataNode *stmts = (yyvsp[-1].datanode);
            int numStatements = stmts->size;
            for(int i=0; i<numStatements; i++){
               insertChild(node,stmts->children[i]);
            }

            node->dtype = 8 ;
            node->bval = false;
            (yyval.datanode) = node;

         }
#line 1696 "y.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 456 "fooChecker_debug.yacc" /* yacc.c:1646  */
    {

            #if DEBUGTAG 
               printf(" ~RULE: elsecomponent -->ELSE '(' boolexpr ')' '{' statements '}'\n");
            #endif           


            struct DataNode *node = constructNode(4);
            strcpy(node->name,"elseBlock");  
            insertChild(node, (yyvsp[-1].datanode));

            //INSERT THE LIST OF STATEMENTS
            //ie; storing every instruction individually 
            //as children of the else node
            //NOTE: statements is an array of individual instruction nodes
            //    statements->children should be inserted and NOT the whole
            //      container node
            struct DataNode *stmts = (yyvsp[-1].datanode);
            int numStatements = stmts->size;
            for(int i=0; i<numStatements; i++){
               insertChild(node,stmts->children[i]);
            }

            node->dtype = 8 ;
            node->bval = true; //if you get to else block, just run the code
            (yyval.datanode) = node;
         }
#line 1728 "y.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 497 "fooChecker_debug.yacc" /* yacc.c:1646  */
    {
            #if DEBUGTAG 
               printf(" ~RULE: declarations --> fundecl \n");
               printf(" ~RULE: Declaring function name: %s\n", 
                                                         (yyvsp[0].datanode->name));
            #endif           

            /*~HACK?~*/ 
            //~~ The function should probably add itself to varContainer
            //         on declaration! ~~ //

            //add function to varContainer local
            insertChild(varContainer, (yyvsp[0].datanode)); 
         }
#line 1747 "y.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 519 "fooChecker_debug.yacc" /* yacc.c:1646  */
    {
            #if DEBUGTAG 
               printf(" ~RULE:fundecl --> ");
               printf("FUNC IDENTIFIER '(' ')' '{' funbody '}'\n"); 
            #endif           

            //FIXME FIXME FIXME : Broken? April 6

            //CREATE VAR FOR FUNCTION
            struct DataNode *func = constructNode(4);  
            strcpy(func->name,(yyvsp[-5].datanode->name)); //IDENTIFIER
            func->dtype = 6; //function type

            ////// Below are instructions only. 
            // ie: will only get evaluated on a funcall/////
            ////////////////////////////////////////////////

            /*CREATE LOCAL VARCONTAINER (LOCAL SCOPE)*/
            //instruction: createNewScope
            struct DataNode *newScopeInst = constructNode(1);
            strcpy(newScopeInst->name,"createNewScope");
            newScopeInst->dtype = 8; //instruction type
            insertChild(func, newScopeInst);
            //^^when evaluated, this label creates new scope^^//
            
            /*DECLARE PARAMETERS AS VARS */
            //No PARAMS: Do nothing
            //loop through param list here
            /*
            struct DataNode *paramList = $<datanode>4;
            for(int i=0; i<paramList->size; i++)
            {
               struct DataNode *declVarInst = constructNode(1);
               strcpy(declVarInst->name,"declareVar");
               declVarInst->dtype = 8;
               strcpy(declVarInst->children[0]->name, paramList->children[i]->name);
               //printf("declVarInst->children[0]->name:   %s \n" ,declVarInst->children[0]->name);
               insertChild(func,declVarInst);
            }
            */
            //

            //CREATE A PARAMETER NODE THAT WILL DO THE ASSIGNING ON FUNCALL
             //empty at first (on func declare)
             //will be used to store values of the parameters passed


            struct DataNode *paramNode = constructNode(2);
            strcpy(paramNode->name,"parametersAssign");  //this node is empty ( no params) 
            paramNode->dtype = 8;
            insertChild(func,paramNode);






            //INSERT THE LIST OF STATEMENTS
            //ie; storing every instruction of the function
               struct DataNode *stmts = (yyvsp[-1].datanode);
               int numStatements = stmts->size;
               for(int i=0; i<numStatements; i++){
                  insertChild(func,stmts->children[i]);
                  ////DELETE ME ////
                  //printf("statment %d name : %s \n", i, stmts->children[i]->name);
                  /////////////////
               }

            
            (yyval.datanode) = func;
            /*
            for(int i =0 ; i<func->size; i++){
               printf("       FUNC -> CHILD %d name is %s \n\n\n\n", i, func->children[i]->name);
            }
            */
           
         }
#line 1829 "y.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 600 "fooChecker_debug.yacc" /* yacc.c:1646  */
    {
            #if DEBUGTAG 
               printf(" ~RULE:fundecl --> ");
                  printf("FUNC IDENTIFIER '(' paramdecl_list ')'"); 
                  printf("'{' funbody '}'\n");
            #endif           
            /*
               paramdecl_list has the names of the var that we should
               declare in the housekeeping instructions part, before the 
               statements
            */

            /* 
               - create a var, the func name  <- this happens now

               Housekeeping instructions (happens  later, on eval of that var )
               - create local varContainer (local scope)
               - declare parameters as vars 
               - create a parameter node that will do the assigning on 
                  funcall
            */ 

            //CREATE VAR FOR FUNCTION
            struct DataNode *func = constructNode(4);  
            strcpy(func->name,(yyvsp[-6].datanode->name)); //IDENTIFIER
            func->dtype = 6; //function type

            ////// Below are instructions only. 
            // ie: will only get evaluated on a funcall/////
            ////////////////////////////////////////////////

            /*CREATE LOCAL VARCONTAINER (LOCAL SCOPE)*/
            //instruction: createNewScope
            struct DataNode *newScopeInst = constructNode(1);
            strcpy(newScopeInst->name,"createNewScope");
            newScopeInst->dtype = 8; //instruction type
            insertChild(func, newScopeInst);
            //^^when evaluated, this label creates new scope^^//
            
            /*DECLARE PARAMETERS AS VARS */
            //loop through param list here
            struct DataNode *paramList = (yyvsp[-4].datanode);
            for(int i=0; i<paramList->size; i++)
            {
               struct DataNode *declVarInst = constructNode(1);
               strcpy(declVarInst->name,"declareVar");
               declVarInst->dtype = 8;
               strcpy(declVarInst->children[0]->name, paramList->children[i]->name);
               //declVarInst->children[0] = paramList->children[i]; 
                  //^^^ not this because separating items from front and back 
               
               //printf("declVarInst->children[0]->name:   %s \n" ,declVarInst->children[0]->name);
               insertChild(func,declVarInst);
            }
            //

            //CREATE A PARAMETER NODE THAT WILL DO THE ASSIGNING ON FUNCALL
             //empty at first (on func declare)
             //will be used to store values of the parameters passed
            struct DataNode *paramNode = constructNode(2);
            strcpy(paramNode->name,"parametersAssign");
            paramNode->dtype = 8;
            insertChild(func,paramNode);


            //INSERT THE LIST OF STATEMENTS

               struct DataNode *stmts = (yyvsp[-1].datanode);
               int numStatements = stmts->size;
               for(int i=0; i<numStatements; i++){
                  insertChild(func,stmts->children[i]);
               }


               /*
               printf("func->size %d\n", func->size);
               for(int i=0; i<func->size; i++){
                  printf(" \n\n\n      func->name %d is %s\n", i , func->children[i]->name);
               }
               */

         //printf("HERE! OK ! \n\n\n\n");

            //INSERT RETURN STATMENT AND DELETE SCOPE 
              // struct DataNode *retInst = $<datanode>8;
               //insertChild(func, retInst); //return instruction

            (yyval.datanode) = func;

 //           #if DEBUGTAG 
               
               /*
               printf(" parameter node name: %s\n", $<datanode->name>4); 
               printf(" parameter node type: %d\n", $<datanode->dtype>4); 
               printf(" Parameter 1: %s\n", $<datanode->children[0]->name>4); 
               printf(" Parameter 2: %s\n", $<datanode->children[1]->name>4); 
               printf(" Parameter 3: %s\n", $<datanode->children[2]->name>4); 
               printf(" Parameter 4: %s\n", $<datanode->children[3]->name>4); 
               */
 //           #endif
         }
#line 1935 "y.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 706 "fooChecker_debug.yacc" /* yacc.c:1646  */
    {   
            #if DEBUGTAG 
               printf(" ~RULE: paramdecl_list --> paramdecl \n ");
               //printf("$<datanode->name>$ : %s \n ",$<datanode->name>$ );
               //printf("$<datanode->name>1 : %s \n ",$<datanode->name>1 );
               //printf("$<datanode->name>$ : %p \n ",$<datanode>$ );
               //printf("$<datanode->name>1 : %p \n ",$<datanode>1 );
               //printf(" $<datanode->children[0]->name>1: %s\n", $<datanode->children[0]->name$); 
            #endif
            //$$ is an array of IDENTIFIER nodes
            //Its children are the IDENTIFIER parameters
            (yyval.datanode) = constructNode(2);
            //$<datanode->dtype>$ = 7; //parameters  //FIXME: type 7 for var declaration list??? Useful?
                  //^^ This node is just a container for the var names of the parameters, not their values?

            //strcpy($<datanode->name>$,"parameters"); //DOES NOT NEED TO BE NAMED... 
            insertChild((yyval.datanode), (yyvsp[0].datanode));

         }
#line 1959 "y.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 726 "fooChecker_debug.yacc" /* yacc.c:1646  */
    {   
            #if DEBUGTAG 
               printf(" ~RULE: paramdecl_list --> paramdecl_list : paramdecl \n ");
               printf(" $<datanode->name>$: %s\n", (yyval.datanode->name)); 
               //printf(" $<datanode->children[0]->name>$: %s\n", $<datanode->children[0]->name>$); 
            #endif
            
            //*USING DEFAULT YACC BEHAVIOUR: $$ = $1 *
            //paramdecl_list was already 'constructed' in 'paramdecl rule'.
            //inserting new paramdecl (IDENTIFIER) as a new children
            insertChild((yyval.datanode), (yyvsp[0].datanode));


         }
#line 1978 "y.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 746 "fooChecker_debug.yacc" /* yacc.c:1646  */
    { 
            #if DEBUGTAG 
               printf(" ~RULE: paramdecl --> IDENTIFIER \n ");
               printf("IDENTIFIER name: %s \n ", (yyvsp[0].datanode->name));
            #endif

            //$<datanode>$ = $<datanode>1;
         }
#line 1991 "y.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 756 "fooChecker_debug.yacc" /* yacc.c:1646  */
    { 
            #if DEBUGTAG 
               printf(" ~RULE: paramdecl --> IDENTIFIER \n ");
               printf("IDENTIFIER name: %s \n ", (yyvsp[0].datanode->name));
            #endif
         }
#line 2002 "y.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 794 "fooChecker_debug.yacc" /* yacc.c:1646  */
    {
            #if DEBUGTAG 
               printf(" ~RULE:  expression --> vardecl \n");
            #endif
         }
#line 2012 "y.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 801 "fooChecker_debug.yacc" /* yacc.c:1646  */
    {
            #if DEBUGTAG 
               printf(" ~RULE:  expression --> funcall \n");
            #endif
         }
#line 2022 "y.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 810 "fooChecker_debug.yacc" /* yacc.c:1646  */
    {
            #if DEBUGTAG 
               printf(" ~RULE:  expression --> IDENTIFIER \n");
            #endif
         }
#line 2032 "y.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 822 "fooChecker_debug.yacc" /* yacc.c:1646  */
    {
            #if DEBUGTAG 
               printf(" ~RULE:  expression --> expression '+' expression \n");
            #endif

            //create operator + node
            struct DataNode *node = constructNode(2) ;
            node->dtype = 5 ; //operator type
            strcpy(node->name,"opPlus");
   
            //insert 2 operands as children
            insertChild(node,(yyvsp[-2].datanode));      
            insertChild(node,(yyvsp[0].datanode));      

            (yyval.datanode) = node ;
         }
#line 2053 "y.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 864 "fooChecker_debug.yacc" /* yacc.c:1646  */
    { 
            #if DEBUGTAG
               printf(" ~RULE:expression--> intexpr \n");    //DEBUG
            #endif

            (yyval.datanode) = (yyvsp[0].datanode);

         }
#line 2066 "y.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 874 "fooChecker_debug.yacc" /* yacc.c:1646  */
    { 
            #if DEBUGTAG
               printf(" ~RULE:expression--> strexpr \n");    //DEBUG
            #endif

            (yyval.datanode) = (yyvsp[0].datanode);
         }
#line 2078 "y.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 883 "fooChecker_debug.yacc" /* yacc.c:1646  */
    { 
            #if DEBUGTAG
               printf(" ~RULE:expression--> ioexpr \n");    //DEBUG
            #endif

            (yyval.datanode) = (yyvsp[0].datanode);

         }
#line 2091 "y.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 894 "fooChecker_debug.yacc" /* yacc.c:1646  */
    { 
            #if DEBUGTAG
               printf(" ~RULE: expression--> boolexpr \n");    //DEBUG
            #endif

         }
#line 2102 "y.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 906 "fooChecker_debug.yacc" /* yacc.c:1646  */
    {
            #if DEBUGTAG
               printf(" ~RULE: funcall -->  IDENTIFIER '(' ')' \n");   
            #endif

            // CREATE FUNCALL NODE
            struct DataNode *funcall = constructNode(2);
            funcall->dtype = 8; //instruction 
            strcpy(funcall->name,"funCall");
            

            //LEFT CHILD IS FUNCTION TO BE CALLED 
            insertChild(funcall,(yyvsp[-2].datanode));

            //RIGHT CHILD IS PARAMETER LIST TO BE ASSIGNED TO FUNCTION
            //FIXME FIXME Insert empty node as no param list but need for evaluate FIXME//
            struct DataNode *emptyParamList = constructNode(0);
            insertChild(funcall, emptyParamList); //paramassign_list
            (yyval.datanode) = funcall;
         }
#line 2127 "y.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 927 "fooChecker_debug.yacc" /* yacc.c:1646  */
    {
            #if DEBUGTAG
               printf(" ~RULE: funcall --> IDENTIFIER '(' paramassign_list ')'  \n");   
            #endif
                    
            //CALL FUNCTION HERE
            //CREATE FUNCTIOn call node
            /*
               - create funcall node
               - left child is function to be called 
                  - look for function name in varContainer 
               - right child is parameter list to be assigned to function
               - when funcall node gets evaluated.. it uses the 2 
            */

            // CREATE FUNCALL NODE
            struct DataNode *funcall = constructNode(2);
            funcall->dtype = 8; //instruction 
            strcpy(funcall->name,"funCall");
            

            //LEFT CHILD IS FUNCTION TO BE CALLED 
            insertChild(funcall,(yyvsp[-3].datanode));

            //RIGHT CHILD IS PARAMETER LIST TO BE ASSIGNED TO FUNCTION
            //(its children will be used as this is only a container)
            insertChild(funcall, (yyvsp[-1].datanode)); //paramassign_list
            (yyval.datanode) = funcall;
            //evaluate();

         }
#line 2163 "y.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 968 "fooChecker_debug.yacc" /* yacc.c:1646  */
    {
            #if DEBUGTAG
               printf(" ~RULE: paramassign_list --> paramassign \n");    //DEBUG
            #endif
            //$$ is an array of IDENTIFIER nodes
            //Its children are the IDENTIFIER parameters
            (yyval.datanode) = constructNode(2);
            //$<datanode->dtype>$ = 7; //parameters  FIXME should be for decl only ?
            strcpy((yyval.datanode->name),"info_paramassign_list");  //informative label only
            insertChild((yyval.datanode), (yyvsp[0].datanode));

         }
#line 2180 "y.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 981 "fooChecker_debug.yacc" /* yacc.c:1646  */
    {
            #if DEBUGTAG
               printf(" ~RULE: paramassign_list --> paramassign_list ':' paramassign \n");    //DEBUG
            #endif
            insertChild((yyval.datanode), (yyvsp[0].datanode));
         }
#line 2191 "y.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 992 "fooChecker_debug.yacc" /* yacc.c:1646  */
    {
            #if DEBUGTAG
               printf(" ~RULE: paramassign_list --> paramassign_list ':' paramassign \n");    //DEBUG
            #endif
         }
#line 2201 "y.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 1001 "fooChecker_debug.yacc" /* yacc.c:1646  */
    {
            #if DEBUGTAG 
               printf(" ~RULE:  retstmt --> RETURN expression ';'\n");
            #endif

            //create instruction node: declareVar
            struct DataNode *node = constructNode(1);
            strcpy(node->name,"returnInstr");
            node->dtype = 8; //instruction

            //insert the var as instruction node's child
            insertChild(node,(yyvsp[-1].datanode));
            (yyval.datanode) = node;
         }
#line 2220 "y.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 1020 "fooChecker_debug.yacc" /* yacc.c:1646  */
    {
            #if DEBUGTAG
               printf(" ~RULE:vardecl --> VAR IDENTIFIER \n");    //DEBUG
            #endif
            
            //create instruction node: declareVar
            struct DataNode *node = constructNode(1);
            strcpy(node->name,"declareVar");
            node->dtype = 8; //instruction

            //insert the var as instruction node's child
            insertChild(node,(yyvsp[0].datanode));
            (yyval.datanode) = node;

            //This needs to happen ON EVALUATE only 
               //insert IDENTIFIER in varContainer (variable array)
               //ie: create var 
               //insertChild(varContainer,$<datanode>2);        
            ///////

            //$<datanode>$ = $<datanode>2;  //vardecl will be the IDENTIFIER
            
           // #if DEBUGTAG
               //int lastElement = varContainer->size - 1;
               //printf("%d \n", lastElement);
               //printf("varContainer->children[lastElement]->name: %s\n",
                 // varContainer->children[lastElement]->name);   

           // #endif
         }
#line 2255 "y.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 1056 "fooChecker_debug.yacc" /* yacc.c:1646  */
    { 
            #if DEBUGTAG
               printf(" ~RULE: assignexpr --> IDENTIFIER '=' expression \n");    //DEBUG
            #endif
            
            //create operator node
            struct DataNode *node = constructNode(2) ;
            node ->dtype = 5 ; //operator type
            strcpy(node->name,"opEqual");
   
            //insert 2 operands as children
            insertChild(node,(yyvsp[-2].datanode));      
            insertChild(node,(yyvsp[0].datanode));      

            /* ON EVALUATION
            //find the var node and insert it in operator node
            struct DataNode *var = findVar($<datanode->name>1); 
            insertChild(node, var); // pos = 0 
            insertChild(node, $<datanode>3) ;//pos = 1 
            */

            (yyval.datanode) = node ;
            /*
            struct DataNode *node = findVar($<datanode->name>1);
            //printf("node->name: %s\n", node->name);    //DEBUG
            node->dtype = $<datanode->dtype>3;

            node->ival = $<datanode->ival>3;
            $<datanode>$ = node ; 
            */
               // TEMP: DELETE ME 
                  //var->dtype = 1;
                  //var->ival = $<datanode->ival>3;
                  //$<datanode>$ = var ;

               //

            //#if DEBUGTAG
               //printf("$<datanode->children[0]->name>$: %s\n", 
                //  $<datanode->children[0]->name>$);
               //printf("$<datanode->children[0]->ival>$: %d\n",
                  //$<datanode->children[0]->ival>$);
            //#endif
         }
#line 2304 "y.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 1150 "fooChecker_debug.yacc" /* yacc.c:1646  */
    { 
            #if DEBUGTAG
               printf(" ~RULE:ioexpr --> PRINT '(' expression ')' \n");    //DEBUG
            #endif

            struct DataNode *io = constructNode(1);
            io->dtype = 8; //instruction type
            strcpy(io->name, "print");

            //insert expression Node as child 
            struct DataNode *expr = (yyvsp[-1].datanode) ;
            insertChild(io,expr);
            (yyval.datanode) = io ;
            
            //BROKEN ? //EVALUATION
            /*
            if(io->children[0]->dtype == 1){
               printf("%d\n", io->children[0]->ival);  
            }else if(io->children[0]->dtype == 3){
               printf("%s\n", io->children[0]->str);    
            }
            */
         }
#line 2332 "y.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 1176 "fooChecker_debug.yacc" /* yacc.c:1646  */
    { 
            #if DEBUGTAG
               printf(" ~RULE:ioexpr --> PRINT '(' IDENTIFIER ')' \n");    //DEBUG
            #endif

            struct DataNode *io = constructNode(1);
            io->dtype = 8; //instruction type
            strcpy(io->name, "print");

            
            //find and insert var in print node
               //struct DataNode *var = findVar($<datanode->name>3);
               //insertChild(io,var);
            insertChild(io,(yyvsp[-1].datanode));
            (yyval.datanode) = io ;
            
            /*
            if(io->children[0]->dtype == 1){
               printf("%d\n", io->children[0]->ival);  
            }else if(io->children[0]->dtype == 3){
               printf("%s\n", io->children[0]->str);    
            }
            
            #if DEBUGTAG
               if(io->children[0]->dtype == 1){
                  printf("io->children[0]->ival: %d\n", io->children[0]->ival);    //DEBUG
               }else if(io->children[0]->dtype == 3){
                  printf("io->children[0]->str: %s\n", io->children[0]->str);    //DEBUG
               }
            #endif

            */
         }
#line 2370 "y.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 1215 "fooChecker_debug.yacc" /* yacc.c:1646  */
    {
            #if DEBUGTAG
               printf(" ~RULE: boolexpr --> '(' boolexpr ')' \n");    //DEBUG
            #endif

            (yyval.datanode) =  (yyvsp[-1].datanode);
         }
#line 2382 "y.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 1224 "fooChecker_debug.yacc" /* yacc.c:1646  */
    {
            #if DEBUGTAG
               printf(" ~RULE: boolexpr --> boolexpr AND boolexpr \n");    //DEBUG
            #endif

            //create operator AND node
            struct DataNode *node = constructNode(2) ;
            node->dtype = 5 ; //operator type
            strcpy(node->name,"opAND");
   
            //insert 2 operands as children
            insertChild(node,(yyvsp[-2].datanode));      
            insertChild(node,(yyvsp[0].datanode));      

            (yyval.datanode) = node ;

         }
#line 2404 "y.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 1243 "fooChecker_debug.yacc" /* yacc.c:1646  */
    {
            #if DEBUGTAG
               printf(" ~RULE: boolexpr --> boolexpr OR boolexpr \n");    //DEBUG
            #endif

            //create operator OR node
            struct DataNode *node = constructNode(2) ;
            node->dtype = 5 ; //operator type
            strcpy(node->name,"opOR");
   
            //insert 2 operands as children
            insertChild(node,(yyvsp[-2].datanode));      
            insertChild(node,(yyvsp[0].datanode));      

            (yyval.datanode) = node ;

         }
#line 2426 "y.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 1262 "fooChecker_debug.yacc" /* yacc.c:1646  */
    {
            #if DEBUGTAG
               printf(" ~RULE: boolexpr --> NOT boolexpr \n");    //DEBUG
            #endif

            //create operator NOT node
            struct DataNode *node = constructNode(1) ;
            node->dtype = 5 ; //operator type
            strcpy(node->name,"opNOT");
   
            //insert 2 operands as children
            insertChild(node,(yyvsp[0].datanode));      

            (yyval.datanode) = node ;
         }
#line 2446 "y.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 1279 "fooChecker_debug.yacc" /* yacc.c:1646  */
    {
            #if DEBUGTAG
               printf(" ~RULE: boolexpr --> expression < expression\n");    //DEBUG
            #endif

            //create operator OR node
            struct DataNode *node = constructNode(2) ;
            node->dtype = 5 ; //operator type
            strcpy(node->name,"opLT");
   
            //insert 2 operands as children
            insertChild(node,(yyvsp[-2].datanode));      
            insertChild(node,(yyvsp[0].datanode));      

            (yyval.datanode) = node ;


         }
#line 2469 "y.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 1299 "fooChecker_debug.yacc" /* yacc.c:1646  */
    {
            #if DEBUGTAG
               printf(" ~RULE: boolexpr --> expression EVAL expression\n");    //DEBUG
            #endif

            //create operator OR node
            struct DataNode *node = constructNode(2) ;
            node->dtype = 5 ; //operator type
            strcpy(node->name,"opEVAL");
   
            //insert 2 operands as children
            insertChild(node,(yyvsp[-2].datanode));      
            insertChild(node,(yyvsp[0].datanode));      

            (yyval.datanode) = node ;

         }
#line 2491 "y.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 1318 "fooChecker_debug.yacc" /* yacc.c:1646  */
    {
            #if DEBUGTAG
               printf(" ~RULE: boolexpr --> expression NEQ expression\n");    //DEBUG
            #endif

            //create operator OR node
            struct DataNode *node = constructNode(2) ;
            node->dtype = 5 ; //operator type
            strcpy(node->name,"opNEQ");
   
            //insert 2 operands as children
            insertChild(node,(yyvsp[-2].datanode));      
            insertChild(node,(yyvsp[0].datanode));      

            (yyval.datanode) = node ;

         }
#line 2513 "y.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 1337 "fooChecker_debug.yacc" /* yacc.c:1646  */
    {
            #if DEBUGTAG
               printf(" ~RULE: boolexpr --> BOOLEAN  \n");    //DEBUG
            #endif
         }
#line 2523 "y.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 1347 "fooChecker_debug.yacc" /* yacc.c:1646  */
    {
            #if DEBUGTAG
               printf(" ~RULE:strexpr--> STRING \n");    //DEBUG
            #endif
            
            (yyval.datanode) = (yyvsp[0].datanode);

            #if DEBUGTAG
               printf("%s is a string \n",(yyvsp[0].datanode->str));
            #endif
         }
#line 2539 "y.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 1363 "fooChecker_debug.yacc" /* yacc.c:1646  */
    {
            #if DEBUGTAG
               printf(" ~RULE:intexpr--> INTEGER \n");    //DEBUG
            #endif
            
            (yyval.datanode) = (yyvsp[0].datanode);

            #if DEBUGTAG
               printf("%d is an integer \n",(yyvsp[0].datanode->ival));
               //printf("It is also an intexpr with address: %p\n",$<datanode>$);
            #endif
         }
#line 2556 "y.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 1378 "fooChecker_debug.yacc" /* yacc.c:1646  */
    {
            #if DEBUGTAG
               printf(" ~RULE:intexpr--> '-' intexpr  prec '*' \n");    //DEBUG
            #endif
            
            (yyval.datanode->dtype) = 2;
            (yyval.datanode->ival) = - (yyvsp[0].datanode->ival);


            #if DEBUGTAG
               printf("negative %d, using unary negation \n",(yyvsp[0].datanode->ival));
            #endif
         }
#line 2574 "y.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 1393 "fooChecker_debug.yacc" /* yacc.c:1646  */
    {
            #if DEBUGTAG
               printf(" ~RULE:intexpr--> intexpr + intexpr \n");    //DEBUG
            #endif
           

            //create operator + node
            struct DataNode *node = constructNode(2) ;
            node->dtype = 5 ; //operator type
            strcpy(node->name,"opPlus");
   
            //insert 2 operands as children
            insertChild(node,(yyvsp[-2].datanode));      
            insertChild(node,(yyvsp[0].datanode));      

            (yyval.datanode) = node ;

            //#if DEBUGTAG
               //printf("%d + %d is %d \n",$<datanode->ival>1, $<datanode->ival>3, $<datanode->ival>$);
               //printf("The address is %p \n",op);
               //printf("The address is %p \n",$<datanode>$);
            //#endif
         }
#line 2602 "y.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 1418 "fooChecker_debug.yacc" /* yacc.c:1646  */
    {
            #if DEBUGTAG
               printf(" ~RULE: intexpr--> intexpr * intexpr \n");    //DEBUG
            #endif
            (yyval.datanode->dtype) = 1;
            (yyval.datanode->ival) = (yyvsp[-2].datanode->ival) * (yyvsp[0].datanode->ival);
            #if DEBUGTAG
               printf("%d * %d is %d \n",(yyvsp[-2].datanode->ival), (yyvsp[0].datanode->ival), (yyval.datanode->ival));
            #endif
         }
#line 2617 "y.tab.c" /* yacc.c:1646  */
    break;


#line 2621 "y.tab.c" /* yacc.c:1646  */
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

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

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
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
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

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

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
                  yystos[*yyssp], yyvsp);
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
#line 1430 "fooChecker_debug.yacc" /* yacc.c:1906  */


 /****** supporting C to carry out parsing ******/


int main()
{
   varContainer = constructNode(2);       //variables
   programContainer = constructNode(4);   //general nodes
   //printf("Beginning syntax checking:\n\n");
   printf("Begin input, and may the foo be with you! \n\n");
   int result = yyparse();
   //printf("\nSyntax checking complete\n\n");
   printf("\nAll hail Lenz\n\n");
   return result;
}


