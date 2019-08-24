/* A Bison parser, made by GNU Bison 2.7.  */

/* Bison implementation for Yacc-like parsers in C
   
      Copyright (C) 1984, 1989-1990, 2000-2012 Free Software Foundation, Inc.
   
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
#define YYBISON_VERSION "2.7"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
/* Line 371 of yacc.c  */
#line 1 "Sintactico.y"


	#include <stdio.h>
	#include <stdlib.h>
	#include <string.h>
	#include "headers/errors.h"

	/*VARIABLES*/
	extern char *yytext;
	extern FILE *yyin;
	extern int yylineno;
	extern int noerror;
	extern int flag;
	int tipoError = 0;
	int linea = 0;
	
/* Line 371 of yacc.c  */
#line 85 "Sintactico.tab.c"

# ifndef YY_NULL
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULL nullptr
#  else
#   define YY_NULL 0
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
   by #include "Sintactico.tab.h".  */
#ifndef YY_YY_SINTACTICO_TAB_H_INCLUDED
# define YY_YY_SINTACTICO_TAB_H_INCLUDED
/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     PROGRAM = 258,
     PRINT = 259,
     TIPO_INTEGER = 260,
     TIPO_LOGICAL = 261,
     TIPO_STRING = 262,
     TIPO_NUMERIC = 263,
     FOR = 264,
     WHILE = 265,
     DO_IF = 266,
     IF = 267,
     THEN = 268,
     ELSE = 269,
     SCAN = 270,
     RETURN = 271,
     VOID = 272,
     IMPORT = 273,
     SWITCH = 274,
     CASE = 275,
     BREAK = 276,
     ASIGNA = 277,
     INCREMENTO = 278,
     DECREMENTO = 279,
     MOD = 280,
     MAYOR_IGUAL = 281,
     MENOR_IGUAL = 282,
     DIFERENTE = 283,
     IGUAL = 284,
     AND = 285,
     OR = 286,
     VALOR_LOGICAL = 287,
     VALOR_STRING = 288,
     VALOR_NUMERIC = 289,
     VALOR_INTEGER = 290,
     IDENTIFICADOR = 291,
     ESPECIFICADOR_STRING = 292,
     ESPECIFICADOR_NUMERIC = 293,
     ESPECIFICADOR_LOGICAL = 294,
     ESPECIFICADOR_INTEGER = 295,
     MATH = 296,
     IO = 297
   };
#endif


#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE yylval;

#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */

#endif /* !YY_YY_SINTACTICO_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

/* Line 390 of yacc.c  */
#line 193 "Sintactico.tab.c"

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
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
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
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
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

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(N) (N)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int yyi)
#else
static int
YYID (yyi)
    int yyi;
#endif
{
  return yyi;
}
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
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
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
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
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
#   if ! defined malloc && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
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
# define YYSTACK_RELOCATE(Stack_alloc, Stack)				\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack_alloc, Stack, yysize);			\
	Stack = &yyptr->Stack_alloc;					\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

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
      while (YYID (0))
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  8
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   405

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  59
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  86
/* YYNRULES -- Number of rules.  */
#define YYNRULES  191
/* YYNRULES -- Number of states.  */
#define YYNSTATES  412

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   297

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    53,     2,     2,    51,     2,     2,     2,
      45,    46,    56,    54,    50,    55,     2,    57,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    52,    49,
      43,     2,    44,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,    58,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    47,     2,    48,     2,     2,     2,     2,
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
      35,    36,    37,    38,    39,    40,    41,    42
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     7,    10,    12,    17,    19,    21,    22,
      28,    29,    35,    36,    42,    43,    49,    58,    59,    68,
      69,    79,    80,    90,    91,   101,   102,   112,   113,   123,
     126,   127,   136,   148,   149,   158,   159,   169,   170,   180,
     181,   191,   192,   202,   203,   213,   214,   227,   228,   241,
     242,   255,   256,   269,   270,   281,   282,   295,   297,   298,
     303,   306,   307,   313,   314,   320,   322,   323,   327,   329,
     331,   332,   336,   338,   343,   347,   351,   356,   359,   363,
     366,   369,   372,   373,   375,   377,   379,   381,   383,   385,
     387,   389,   393,   397,   399,   405,   409,   410,   415,   416,
     423,   424,   431,   436,   437,   442,   443,   449,   455,   456,
     462,   463,   470,   476,   484,   485,   492,   497,   500,   502,
     509,   511,   513,   515,   517,   519,   521,   523,   525,   533,
     545,   555,   563,   571,   579,   580,   589,   590,   599,   600,
     609,   613,   617,   621,   623,   627,   629,   633,   635,   638,
     639,   644,   648,   652,   654,   658,   662,   664,   668,   674,
     676,   678,   680,   681,   686,   688,   690,   692,   694,   696,
     701,   703,   705,   707,   709,   711,   716,   718,   720,   722,
     724,   726,   728,   730,   732,   734,   736,   738,   740,   742,
     744,   746
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
      60,     0,    -1,    61,    68,    75,    -1,    62,    61,    -1,
      62,    -1,    18,    43,    63,    44,    -1,    41,    -1,    42,
      -1,    -1,    64,     1,    43,    63,    44,    -1,    -1,    18,
      65,     1,    63,    44,    -1,    -1,    18,    43,    63,    66,
       1,    -1,    -1,    18,    43,    67,     1,    44,    -1,    17,
       3,    45,    89,    46,    47,    99,    48,    -1,    -1,    69,
       3,    45,    89,    46,    47,    99,    48,    -1,    -1,    17,
      70,     1,    45,    89,    46,    47,    99,    48,    -1,    -1,
      17,     3,    71,     1,    89,    46,    47,    99,    48,    -1,
      -1,    17,     3,    45,    89,    72,     1,    47,    99,    48,
      -1,    -1,    17,     3,    45,    89,    46,    73,     1,    99,
      48,    -1,    -1,    17,     3,    45,    89,    46,    47,    99,
      74,     1,    -1,    76,    75,    -1,    -1,    17,    36,    45,
      89,    46,    47,    99,    48,    -1,   141,    36,    45,    89,
      46,    47,    99,    16,   140,    49,    48,    -1,    -1,    77,
      36,    45,    89,    46,    47,    99,    48,    -1,    -1,    17,
      78,     1,    45,    89,    46,    47,    99,    48,    -1,    -1,
      17,    36,    79,     1,    89,    46,    47,    99,    48,    -1,
      -1,    17,    36,    45,    89,    80,     1,    47,    99,    48,
      -1,    -1,    17,    36,    45,    89,    46,    81,     1,    99,
      48,    -1,    -1,    17,    36,    45,    89,    46,    47,    99,
      82,     1,    -1,    -1,   141,    83,     1,    45,    89,    46,
      47,    99,    16,   140,    49,    48,    -1,    -1,   141,    36,
      84,     1,    89,    46,    47,    99,    16,   140,    49,    48,
      -1,    -1,   141,    36,    45,    89,    85,     1,    47,    99,
      16,   140,    49,    48,    -1,    -1,   141,    36,    45,    89,
      46,    86,     1,    99,    16,   140,    49,    48,    -1,    -1,
     141,    36,    45,    89,    46,    47,    99,    87,     1,    48,
      -1,    -1,   141,    36,    45,    89,    46,    47,    99,    16,
     140,    49,    88,     1,    -1,    90,    -1,    -1,   141,    36,
      50,    90,    -1,   141,    36,    -1,    -1,   141,    91,     1,
      50,    90,    -1,    -1,   141,    36,    50,    92,     1,    -1,
      94,    -1,    -1,   140,    50,    94,    -1,   140,    -1,    96,
      -1,    -1,   140,    51,    96,    -1,   140,    -1,   139,   130,
      49,    98,    -1,   139,   130,    49,    -1,   139,    49,    98,
      -1,    49,   130,    49,    98,    -1,   139,    49,    -1,    49,
     130,    49,    -1,    36,    23,    -1,    36,    24,    -1,   100,
      99,    -1,    -1,   101,    -1,   106,    -1,   109,    -1,   112,
      -1,   113,    -1,   118,    -1,   128,    -1,   129,    -1,   141,
     102,    49,    -1,    36,    50,   102,    -1,    36,    -1,    36,
      22,   140,    50,   102,    -1,    36,    22,   140,    -1,    -1,
     141,   102,   103,     1,    -1,    -1,   104,     1,    22,   140,
      50,   102,    -1,    -1,    36,    22,   105,     1,    50,   102,
      -1,    36,    22,   140,    49,    -1,    -1,   107,    22,   140,
      49,    -1,    -1,    36,   108,     1,   140,    49,    -1,    36,
      45,    93,    46,    49,    -1,    -1,   110,    45,    93,    46,
      49,    -1,    -1,    36,    45,    93,    46,   111,     1,    -1,
       4,    45,    95,    46,    49,    -1,    15,    45,   142,    50,
      36,    46,    49,    -1,    -1,     4,    45,   114,     1,    46,
      49,    -1,     4,    45,    95,    46,    -1,   116,   115,    -1,
     116,    -1,    20,   117,    52,    99,    21,    49,    -1,    35,
      -1,    33,    -1,   119,    -1,   120,    -1,   121,    -1,   122,
      -1,   123,    -1,   124,    -1,    12,    45,   130,    46,    47,
      99,    48,    -1,    12,    45,   130,    46,    47,    99,    48,
      14,    47,    99,    48,    -1,    11,    47,    99,    48,    12,
      45,   130,    46,    49,    -1,     9,    45,    97,    46,    47,
      99,    48,    -1,    10,    45,   130,    46,    47,    99,    48,
      -1,    19,    45,   130,    46,    47,   115,    48,    -1,    -1,
      12,    45,   130,    46,    47,    99,   125,     1,    -1,    -1,
      12,    45,   130,    46,   126,     1,    99,    48,    -1,    -1,
      12,    45,   127,     1,    46,    47,    99,    48,    -1,    36,
      23,    49,    -1,    36,    24,    49,    -1,   130,   144,   131,
      -1,   131,    -1,   131,   143,   132,    -1,   132,    -1,    45,
     130,    46,    -1,   138,    -1,    53,   138,    -1,    -1,    45,
     133,     1,    46,    -1,   134,    54,   135,    -1,   134,    55,
     135,    -1,   135,    -1,   135,    56,   136,    -1,   135,    57,
     136,    -1,   136,    -1,    45,   134,    46,    -1,    45,   134,
      46,    58,    35,    -1,    34,    -1,    35,    -1,    36,    -1,
      -1,    45,   137,     1,    46,    -1,    33,    -1,    32,    -1,
      34,    -1,    35,    -1,    36,    -1,    36,    45,    93,    46,
      -1,   101,    -1,   106,    -1,    33,    -1,    32,    -1,   134,
      -1,    36,    45,    93,    46,    -1,     7,    -1,     6,    -1,
       5,    -1,     8,    -1,    40,    -1,    39,    -1,    38,    -1,
      37,    -1,    26,    -1,    27,    -1,    29,    -1,    28,    -1,
      43,    -1,    44,    -1,    30,    -1,    31,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    38,    38,    42,    42,    43,    44,    44,    46,    46,
      47,    47,    48,    48,    49,    49,    55,    57,    57,    58,
      58,    59,    59,    60,    60,    61,    61,    62,    62,    68,
      68,    69,    70,    72,    72,    73,    73,    74,    74,    75,
      75,    76,    76,    77,    77,    79,    79,    80,    80,    81,
      81,    82,    82,    83,    83,    84,    84,    90,    90,    91,
      92,    94,    94,    95,    95,   100,   100,   101,   102,   105,
     105,   106,   106,   109,   110,   111,   112,   113,   114,   117,
     117,   121,   121,   122,   122,   122,   122,   122,   122,   122,
     122,   128,   130,   131,   133,   134,   136,   136,   137,   137,
     138,   138,   143,   145,   145,   146,   146,   151,   153,   153,
     154,   154,   160,   161,   163,   163,   164,   170,   171,   172,
     173,   174,   182,   182,   182,   182,   182,   182,   184,   185,
     186,   187,   188,   189,   191,   191,   192,   192,   193,   193,
     199,   200,   206,   206,   207,   207,   208,   208,   208,   209,
     209,   212,   212,   212,   213,   213,   213,   214,   214,   214,
     214,   214,   215,   215,   222,   222,   222,   222,   222,   223,
     226,   226,   228,   228,   228,   229,   231,   231,   231,   231,
     232,   232,   232,   232,   233,   233,   233,   233,   233,   233,
     234,   234
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "PROGRAM", "PRINT", "TIPO_INTEGER",
  "TIPO_LOGICAL", "TIPO_STRING", "TIPO_NUMERIC", "FOR", "WHILE", "DO_IF",
  "IF", "THEN", "ELSE", "SCAN", "RETURN", "VOID", "IMPORT", "SWITCH",
  "CASE", "BREAK", "ASIGNA", "INCREMENTO", "DECREMENTO", "MOD",
  "MAYOR_IGUAL", "MENOR_IGUAL", "DIFERENTE", "IGUAL", "AND", "OR",
  "VALOR_LOGICAL", "VALOR_STRING", "VALOR_NUMERIC", "VALOR_INTEGER",
  "IDENTIFICADOR", "ESPECIFICADOR_STRING", "ESPECIFICADOR_NUMERIC",
  "ESPECIFICADOR_LOGICAL", "ESPECIFICADOR_INTEGER", "MATH", "IO", "'<'",
  "'>'", "'('", "')'", "'{'", "'}'", "';'", "','", "'$'", "':'", "'!'",
  "'+'", "'-'", "'*'", "'/'", "'^'", "$accept", "axioma", "cabeceras",
  "cabecera", "libreria", "$@1", "$@2", "$@3", "$@4", "main", "$@5", "$@6",
  "$@7", "$@8", "$@9", "$@10", "funciones", "funcion", "$@11", "$@12",
  "$@13", "$@14", "$@15", "$@16", "$@17", "$@18", "$@19", "$@20", "$@21",
  "$@22", "parametros", "parametro", "$@23", "$@24", "argumentosFuncion",
  "argumentoFuncion", "argumentosImprimir", "argumentoImprimir",
  "argumentoFor", "actualizacion", "instrucciones", "instruccion",
  "declaracion", "varios", "$@25", "$@26", "$@27", "asignacion", "$@28",
  "$@29", "llamaFuncion", "$@30", "$@31", "imprimir", "leer", "$@32",
  "casos", "caso", "valorSwitch", "control", "if", "if-else", "do-if",
  "for", "while", "switch", "$@33", "$@34", "$@35", "incremento",
  "decremento", "condiciones", "q", "w", "$@36", "aritmetica", "termino",
  "factor", "$@37", "valorl", "variableControl", "valor", "tipo",
  "especificador", "relacional", "logico", YY_NULL
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,    60,    62,    40,    41,   123,   125,    59,
      44,    36,    58,    33,    43,    45,    42,    47,    94
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    59,    60,    61,    61,    62,    63,    63,    64,    62,
      65,    62,    66,    62,    67,    62,    68,    69,    68,    70,
      68,    71,    68,    72,    68,    73,    68,    74,    68,    75,
      75,    76,    76,    77,    76,    78,    76,    79,    76,    80,
      76,    81,    76,    82,    76,    83,    76,    84,    76,    85,
      76,    86,    76,    87,    76,    88,    76,    89,    89,    90,
      90,    91,    90,    92,    90,    93,    93,    94,    94,    95,
      95,    96,    96,    97,    97,    97,    97,    97,    97,    98,
      98,    99,    99,   100,   100,   100,   100,   100,   100,   100,
     100,   101,   102,   102,   102,   102,   103,   101,   104,   102,
     105,   102,   106,   107,   106,   108,   106,   109,   110,   109,
     111,   109,   112,   113,   114,   112,   112,   115,   115,   116,
     117,   117,   118,   118,   118,   118,   118,   118,   119,   120,
     121,   122,   123,   124,   125,   119,   126,   119,   127,   119,
     128,   129,   130,   130,   131,   131,   132,   132,   132,   133,
     132,   134,   134,   134,   135,   135,   135,   136,   136,   136,
     136,   136,   137,   136,   138,   138,   138,   138,   138,   138,
     139,   139,   140,   140,   140,   140,   141,   141,   141,   141,
     142,   142,   142,   142,   143,   143,   143,   143,   143,   143,
     144,   144
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     3,     2,     1,     4,     1,     1,     0,     5,
       0,     5,     0,     5,     0,     5,     8,     0,     8,     0,
       9,     0,     9,     0,     9,     0,     9,     0,     9,     2,
       0,     8,    11,     0,     8,     0,     9,     0,     9,     0,
       9,     0,     9,     0,     9,     0,    12,     0,    12,     0,
      12,     0,    12,     0,    10,     0,    12,     1,     0,     4,
       2,     0,     5,     0,     5,     1,     0,     3,     1,     1,
       0,     3,     1,     4,     3,     3,     4,     2,     3,     2,
       2,     2,     0,     1,     1,     1,     1,     1,     1,     1,
       1,     3,     3,     1,     5,     3,     0,     4,     0,     6,
       0,     6,     4,     0,     4,     0,     5,     5,     0,     5,
       0,     6,     5,     7,     0,     6,     4,     2,     1,     6,
       1,     1,     1,     1,     1,     1,     1,     1,     7,    11,
       9,     7,     7,     7,     0,     8,     0,     8,     0,     8,
       3,     3,     3,     1,     3,     1,     3,     1,     2,     0,
       4,     3,     3,     1,     3,     3,     1,     3,     5,     1,
       1,     1,     0,     4,     1,     1,     1,     1,     1,     4,
       1,     1,     1,     1,     1,     4,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1
};

/* YYDEFACT[STATE-NAME] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       8,    10,     0,    17,     4,     0,    14,     0,     1,    19,
      30,     0,     3,     0,     6,     7,    12,     0,     0,    21,
       0,   178,   177,   176,   179,    35,     2,    30,     0,    45,
       0,     0,     5,     0,     0,     0,    58,     0,     0,    37,
       0,    29,     0,    47,     0,    58,     0,    13,    15,    11,
      23,    57,    61,    58,    58,    58,     0,     0,    58,    58,
       0,     0,     0,     9,    25,     0,    60,     0,     0,     0,
      39,    58,    58,     0,    49,    58,    58,     0,    82,     0,
       0,    63,     0,     0,     0,    41,     0,     0,     0,     0,
      51,     0,     0,     0,    82,     0,     0,     0,     0,     0,
       0,     0,   105,    27,    82,    83,    84,     0,    85,     0,
      86,    87,    88,   122,   123,   124,   125,   126,   127,    89,
      90,    98,    82,    82,    59,     0,     0,    82,    82,    82,
       0,     0,     0,     0,    82,    82,     0,     0,     0,     0,
       0,    70,   103,     0,    82,   138,     0,     0,     0,     0,
       0,    66,     0,    16,     0,    81,     0,    66,    93,    96,
       0,     0,     0,    64,    62,     0,     0,    43,    82,    82,
      82,    82,     0,    53,    82,    82,    82,    82,    18,   173,
     172,   159,   160,   161,   162,     0,    69,     0,   174,   153,
     156,    72,   105,     0,     0,   170,   171,     0,   165,   164,
     166,   167,   168,   149,     0,     0,   143,   145,   147,     0,
       0,     0,   183,   182,   181,   180,     0,     0,     0,   140,
     141,     0,    65,    68,     0,    28,     0,     0,   100,    98,
      91,     0,     0,    26,    24,    22,    20,    31,     0,     0,
       0,     0,     0,    34,     0,     0,     0,     0,     0,     0,
      66,   161,     0,     0,   116,     0,     0,     0,     0,     0,
       0,     0,     0,    77,     0,    66,     0,     0,   148,   190,
     191,     0,     0,   184,   185,   187,   186,   188,   189,     0,
       0,     0,   136,     0,     0,   102,   110,     0,     0,   104,
       0,     0,    95,    92,    97,     0,    44,    42,    40,    38,
      36,     0,     0,     0,     0,     0,     0,     0,   157,     0,
     112,     0,   151,   152,   154,   155,    71,    78,    82,     0,
      75,    74,     0,   146,     0,    82,   142,   144,     0,     0,
      82,     0,     0,     0,   107,     0,    67,   106,   109,     0,
      98,     0,    55,    54,     0,     0,     0,     0,   175,     0,
     163,   115,    76,     0,    79,    80,    73,   169,   150,     0,
       0,    82,   134,    82,     0,     0,     0,   118,   111,    98,
      94,    98,    32,     0,     0,     0,     0,     0,   158,   131,
     132,     0,     0,   128,     0,     0,   113,   121,   120,     0,
     133,   117,   101,    99,    56,    52,    50,    48,    46,     0,
     139,     0,   135,   137,    82,   130,    82,     0,     0,     0,
     129,   119
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     3,     4,    16,     5,     7,    33,    17,    10,
      11,    20,    37,    65,    79,   154,    26,    27,    28,    40,
      56,    86,   130,   238,    44,    60,    91,   136,   245,   373,
      50,    51,    67,   125,   221,   222,   185,   186,   194,   320,
     103,   104,   105,   159,   231,   160,   291,   106,   107,   152,
     108,   109,   335,   110,   111,   187,   366,   367,   389,   112,
     113,   114,   115,   116,   117,   118,   384,   331,   210,   119,
     120,   205,   206,   207,   267,   188,   189,   190,   253,   208,
     197,   223,   121,   216,   279,   272
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -254
static const yytype_int16 yypact[] =
{
      -5,   -36,    21,    10,     4,    38,    61,    41,  -254,    45,
      55,    52,  -254,    36,  -254,  -254,    44,    89,    61,    47,
      98,  -254,  -254,  -254,  -254,    74,  -254,    55,    80,    84,
      77,    61,  -254,   142,   103,   105,   205,   168,   132,   146,
     197,  -254,   176,   177,   222,   205,   181,  -254,  -254,  -254,
     182,  -254,   190,   205,   205,   205,   226,   184,   205,   205,
     229,   187,   188,  -254,   186,   234,   189,   236,   192,   194,
     195,   205,   205,   196,   198,   205,   205,   199,   126,   242,
     200,   205,   201,   202,   203,   206,   244,   208,   209,   210,
     211,   247,   213,   214,   126,   207,   216,   217,   218,   219,
     221,   223,    -8,   215,   126,  -254,  -254,   248,  -254,   227,
    -254,  -254,  -254,  -254,  -254,  -254,  -254,  -254,  -254,  -254,
    -254,   220,   126,   126,  -254,   270,   205,   126,   126,   126,
     272,   228,   230,   231,   126,   126,   273,   232,   233,   235,
     237,    11,    18,   147,   126,   147,   180,   147,   118,   238,
     239,   118,   275,  -254,   280,  -254,   118,   118,   -14,   240,
     282,   243,   245,  -254,  -254,   246,   249,   250,   126,   126,
     126,   126,   251,   268,   126,   126,   126,   126,  -254,  -254,
    -254,  -254,  -254,   241,   154,   254,  -254,   289,   121,   116,
    -254,   252,   274,   147,   255,  -254,  -254,   125,  -254,  -254,
    -254,  -254,   257,   147,   173,    27,   158,  -254,  -254,   256,
     291,    40,  -254,  -254,  -254,  -254,   258,    63,   260,  -254,
    -254,   259,  -254,   261,   118,  -254,   264,   269,   118,   220,
    -254,   294,   284,  -254,  -254,  -254,  -254,  -254,   306,   266,
     271,   276,   277,  -254,   118,   315,   301,   302,   304,   305,
     118,  -254,   149,   321,   278,   283,   154,   154,   154,   154,
     118,   -11,   279,   287,    35,   118,    96,   327,  -254,  -254,
    -254,   285,   147,  -254,  -254,  -254,  -254,  -254,  -254,   147,
     318,   288,   286,   295,   290,  -254,   292,   118,   293,  -254,
     296,   334,   297,  -254,  -254,   118,  -254,  -254,  -254,  -254,
    -254,   299,   298,   118,   118,   118,   118,   303,   281,   307,
    -254,   308,   116,   116,  -254,  -254,  -254,   287,   126,   170,
    -254,   287,   309,  -254,   310,   126,   158,  -254,   313,   312,
     126,   335,   314,   320,  -254,   337,  -254,  -254,  -254,   300,
     220,   311,   316,  -254,   317,   319,   322,   323,  -254,   328,
    -254,  -254,  -254,   325,  -254,  -254,  -254,  -254,  -254,   326,
     147,   126,   329,   126,   330,    -3,   332,   320,  -254,   220,
    -254,   220,  -254,   342,   333,   336,   338,   339,  -254,  -254,
    -254,   109,   340,   348,   343,   341,  -254,  -254,  -254,   324,
    -254,  -254,  -254,  -254,  -254,  -254,  -254,  -254,  -254,   344,
    -254,   331,  -254,  -254,   126,  -254,   126,   346,   347,   345,
    -254,  -254
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -254,  -254,   350,  -254,     0,  -254,  -254,  -254,  -254,  -254,
    -254,  -254,  -254,  -254,  -254,  -254,   355,  -254,  -254,  -254,
    -254,  -254,  -254,  -254,  -254,  -254,  -254,  -254,  -254,  -254,
      53,   -75,  -254,  -254,  -146,    64,  -254,    92,  -254,  -253,
     -94,  -254,   262,  -225,  -254,  -254,  -254,   263,  -254,  -254,
    -254,  -254,  -254,  -254,  -254,  -254,    -2,  -254,  -254,  -254,
    -254,  -254,  -254,  -254,  -254,  -254,  -254,  -254,  -254,  -254,
    -254,  -144,    97,    91,  -254,   191,   -60,   -44,  -254,   179,
    -254,  -139,    42,  -254,  -254,  -254
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -115
static const yytype_int16 yytable[] =
{
     140,   211,   191,   217,   293,    -8,   124,     6,   228,   218,
     155,   227,  -114,     1,   148,   149,   150,   226,    35,   269,
     270,     8,     1,    21,    22,    23,    24,     9,   161,   162,
     387,    46,   388,   165,   166,   167,   229,   151,   317,    13,
     172,   173,    18,   179,   180,   181,   182,   183,    19,   261,
     209,   164,    29,   264,   192,    30,   184,   269,   270,   266,
      21,    22,    23,    24,   352,   269,   270,   193,   356,    29,
     269,   270,    25,   271,   239,   240,   241,   242,    52,    31,
     246,   247,   248,   249,   321,   288,   282,    52,    32,   292,
      34,   -33,    36,   269,   270,    52,    52,    52,    62,    38,
      52,    52,    14,    15,   307,   301,    68,    69,    70,   284,
      39,    73,    74,    52,    52,   370,    42,    52,    52,   322,
      43,   191,    45,    52,    87,    88,   269,   270,    92,    93,
      95,    21,    22,    23,    24,    96,    97,    98,    99,   269,
     270,   100,   323,    47,   392,   101,   393,    48,  -103,    49,
     179,   180,   181,   182,   183,   399,   341,   198,   199,   200,
     201,   202,   102,   184,   344,   345,   346,   347,    52,    53,
     203,  -108,   258,   259,   263,   256,   257,    54,   204,   198,
     199,   200,   201,   202,   273,   274,   275,   276,   181,   182,
     251,    55,   203,   354,   355,   308,   312,   313,    57,   184,
     204,   277,   278,   256,   257,   198,   199,   200,   201,   202,
      21,    22,    23,    24,   314,   315,   381,   212,   213,   214,
     215,    58,    59,    61,   353,    63,    66,    71,    64,    72,
      75,   359,    76,    78,    77,    80,   362,    82,    83,    81,
      84,    85,    89,   122,    90,   131,    94,   123,   137,   127,
     128,   126,   141,   129,   132,   133,   158,   134,   135,   138,
     139,   142,   143,   153,   145,   144,   146,   382,   147,   385,
     156,   163,   157,   168,   174,   169,   224,   170,   171,   175,
     176,   225,   177,   232,   244,   178,   250,   219,   220,   230,
     255,   233,   281,   234,   235,   294,   148,   236,   237,   243,
     254,   262,   265,   260,   280,   286,   295,   296,   283,   285,
     407,   287,   408,   289,   297,   290,   302,   303,   304,   298,
     305,   306,   309,   319,   299,   300,   318,   310,   324,   311,
     328,   332,   325,   330,   329,   339,   363,   333,   368,   349,
     365,   334,   337,   394,   402,   338,   343,   340,   342,   348,
     369,   336,   316,   350,    12,   357,   358,   351,   360,   361,
     364,   371,   401,   378,   372,   391,   374,   409,   375,   326,
     327,   376,   377,   379,   380,   252,   404,   383,   406,   386,
     390,   395,    41,   268,   396,     0,   397,   398,   400,   403,
       0,     0,     0,   405,   411,   410,     0,     0,     0,     0,
       0,     0,     0,     0,   195,   196
};

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-254)))

#define yytable_value_is_error(Yytable_value) \
  YYID (0)

static const yytype_int16 yycheck[] =
{
      94,   145,   141,   147,   229,     1,    81,    43,    22,   148,
     104,   157,     1,    18,    22,    23,    24,   156,    18,    30,
      31,     0,    18,     5,     6,     7,     8,    17,   122,   123,
      33,    31,    35,   127,   128,   129,    50,    45,    49,     1,
     134,   135,     1,    32,    33,    34,    35,    36,     3,   193,
     144,   126,    10,   197,    36,     3,    45,    30,    31,   203,
       5,     6,     7,     8,   317,    30,    31,    49,   321,    27,
      30,    31,    17,    46,   168,   169,   170,   171,    36,    43,
     174,   175,   176,   177,    49,   224,    46,    45,    44,   228,
       1,    36,    45,    30,    31,    53,    54,    55,    45,     1,
      58,    59,    41,    42,   250,   244,    53,    54,    55,    46,
      36,    58,    59,    71,    72,   340,    36,    75,    76,   265,
      36,   260,    45,    81,    71,    72,    30,    31,    75,    76,
       4,     5,     6,     7,     8,     9,    10,    11,    12,    30,
      31,    15,    46,     1,   369,    19,   371,    44,    22,    44,
      32,    33,    34,    35,    36,    46,   295,    32,    33,    34,
      35,    36,    36,    45,   303,   304,   305,   306,   126,     1,
      45,    45,    56,    57,    49,    54,    55,    45,    53,    32,
      33,    34,    35,    36,    26,    27,    28,    29,    34,    35,
      36,    45,    45,    23,    24,    46,   256,   257,     1,    45,
      53,    43,    44,    54,    55,    32,    33,    34,    35,    36,
       5,     6,     7,     8,   258,   259,   360,    37,    38,    39,
      40,    45,    45,     1,   318,    44,    36,     1,    46,    45,
       1,   325,    45,    47,    46,     1,   330,     1,    46,    50,
      46,    46,    46,     1,    46,     1,    47,    47,     1,    47,
      47,    50,    45,    47,    46,    46,    36,    47,    47,    46,
      46,    45,    45,    48,    45,    47,    45,   361,    45,   363,
      22,     1,    45,     1,     1,    47,     1,    47,    47,    47,
      47,     1,    47,     1,    16,    48,    45,    49,    49,    49,
       1,    48,     1,    48,    48,     1,    22,    48,    48,    48,
      46,    46,    45,    51,    48,    46,    22,     1,    50,    49,
     404,    50,   406,    49,    48,    46,     1,    16,    16,    48,
      16,    16,     1,    36,    48,    48,    47,    49,     1,    46,
      12,    36,    47,    47,    46,     1,     1,    47,     1,    58,
      20,    49,    49,     1,     1,    49,    48,    50,    49,    46,
      50,   287,   260,    46,     4,    46,    46,    49,    45,    47,
      46,    50,    14,    35,    48,   367,    49,    21,    49,   272,
     279,    49,    49,    48,    48,   184,    52,    48,    47,    49,
      48,    48,    27,   204,    48,    -1,    48,    48,    48,    48,
      -1,    -1,    -1,    49,    49,    48,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   142,   142
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    18,    60,    61,    62,    64,    43,    65,     0,    17,
      68,    69,    61,     1,    41,    42,    63,    67,     1,     3,
      70,     5,     6,     7,     8,    17,    75,    76,    77,   141,
       3,    43,    44,    66,     1,    63,    45,    71,     1,    36,
      78,    75,    36,    36,    83,    45,    63,     1,    44,    44,
      89,    90,   141,     1,    45,    45,    79,     1,    45,    45,
      84,     1,    89,    44,    46,    72,    36,    91,    89,    89,
      89,     1,    45,    89,    89,     1,    45,    46,    47,    73,
       1,    50,     1,    46,    46,    46,    80,    89,    89,    46,
      46,    85,    89,    89,    47,     4,     9,    10,    11,    12,
      15,    19,    36,    99,   100,   101,   106,   107,   109,   110,
     112,   113,   118,   119,   120,   121,   122,   123,   124,   128,
     129,   141,     1,    47,    90,    92,    50,    47,    47,    47,
      81,     1,    46,    46,    47,    47,    86,     1,    46,    46,
      99,    45,    45,    45,    47,    45,    45,    45,    22,    23,
      24,    45,   108,    48,    74,    99,    22,    45,    36,   102,
     104,    99,    99,     1,    90,    99,    99,    99,     1,    47,
      47,    47,    99,    99,     1,    47,    47,    47,    48,    32,
      33,    34,    35,    36,    45,    95,    96,   114,   134,   135,
     136,   140,    36,    49,    97,   101,   106,   139,    32,    33,
      34,    35,    36,    45,    53,   130,   131,   132,   138,    99,
     127,   130,    37,    38,    39,    40,   142,   130,   140,    49,
      49,    93,    94,   140,     1,     1,   140,    93,    22,    50,
      49,   103,     1,    48,    48,    48,    48,    48,    82,    99,
      99,    99,    99,    48,    16,    87,    99,    99,    99,    99,
      45,    36,   134,   137,    46,     1,    54,    55,    56,    57,
      51,   130,    46,    49,   130,    45,   130,   133,   138,    30,
      31,    46,   144,    26,    27,    28,    29,    43,    44,   143,
      48,     1,    46,    50,    46,    49,    46,    50,   140,    49,
      46,   105,   140,   102,     1,    22,     1,    48,    48,    48,
      48,   140,     1,    16,    16,    16,    16,    93,    46,     1,
      49,    46,   135,   135,   136,   136,    96,    49,    47,    36,
      98,    49,    93,    46,     1,    47,   131,   132,    12,    46,
      47,   126,    36,    47,    49,   111,    94,    49,    49,     1,
      50,   140,    49,    48,   140,   140,   140,   140,    46,    58,
      46,    49,    98,    99,    23,    24,    98,    46,    46,    99,
      45,    47,    99,     1,    46,    20,   115,   116,     1,    50,
     102,    50,    48,    88,    49,    49,    49,    49,    35,    48,
      48,   130,    99,    48,   125,    99,    49,    33,    35,   117,
      48,   115,   102,   102,     1,    48,    48,    48,    48,    46,
      48,    14,     1,    48,    52,    49,    47,    99,    99,    21,
      48,    49
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  However,
   YYFAIL appears to be in use.  Nevertheless, it is formally deprecated
   in Bison 2.4.2's NEWS entry, where a plan to phase it out is
   discussed.  */

#define YYFAIL		goto yyerrlab
#if defined YYFAIL
  /* This is here to suppress warnings from the GCC cpp's
     -Wunused-macros.  Normally we don't worry about that warning, but
     some users do, and we want to make it easy for users to remove
     YYFAIL uses, which will produce warnings from Bison 2.5.  */
#endif

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
      YYERROR;							\
    }								\
while (YYID (0))

/* Error token number */
#define YYTERROR	1
#define YYERRCODE	256


/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */
#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
        break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
#else
static void
yy_stack_print (yybottom, yytop)
    yytype_int16 *yybottom;
    yytype_int16 *yytop;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
} while (YYID (0))

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
#ifndef	YYINITDEPTH
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
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
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
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
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
  YYSIZE_T yysize0 = yytnamerr (YY_NULL, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULL;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - Assume YYFAIL is not used.  It's too flawed to consider.  See
       <http://lists.gnu.org/archive/html/bison-patches/2009-12/msg00024.html>
       for details.  YYERROR is fine as it does not invoke this
       function.
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
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULL, yytname[yyx]);
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

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
        break;
    }
}




/* The lookahead symbol.  */
int yychar;


#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval YY_INITIAL_VALUE(yyval_default);

/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       `yyss': related to states.
       `yyvs': related to semantic values.

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
      yychar = YYLEX;
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
     `$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 8:
/* Line 1792 of yacc.c  */
#line 46 "Sintactico.y"
    { tipoError = 1; }
    break;

  case 10:
/* Line 1792 of yacc.c  */
#line 47 "Sintactico.y"
    { tipoError = 2; }
    break;

  case 12:
/* Line 1792 of yacc.c  */
#line 48 "Sintactico.y"
    { tipoError = 3; linea = yylineno - 1; }
    break;

  case 14:
/* Line 1792 of yacc.c  */
#line 49 "Sintactico.y"
    { tipoError = 9; }
    break;

  case 17:
/* Line 1792 of yacc.c  */
#line 57 "Sintactico.y"
    { tipoError = 14; imprimeError("syntax error", yylineno); }
    break;

  case 19:
/* Line 1792 of yacc.c  */
#line 58 "Sintactico.y"
    { tipoError = 4; }
    break;

  case 21:
/* Line 1792 of yacc.c  */
#line 59 "Sintactico.y"
    { tipoError = 5; }
    break;

  case 23:
/* Line 1792 of yacc.c  */
#line 60 "Sintactico.y"
    { tipoError = 6; }
    break;

  case 25:
/* Line 1792 of yacc.c  */
#line 61 "Sintactico.y"
    { tipoError = 7; linea = yylineno - 1; }
    break;

  case 27:
/* Line 1792 of yacc.c  */
#line 62 "Sintactico.y"
    { tipoError = 8; linea = yylineno - 1; }
    break;

  case 33:
/* Line 1792 of yacc.c  */
#line 72 "Sintactico.y"
    { tipoError = 14; imprimeError("syntax error", yylineno); }
    break;

  case 35:
/* Line 1792 of yacc.c  */
#line 73 "Sintactico.y"
    { tipoError = 10; }
    break;

  case 37:
/* Line 1792 of yacc.c  */
#line 74 "Sintactico.y"
    { tipoError = 5; }
    break;

  case 39:
/* Line 1792 of yacc.c  */
#line 75 "Sintactico.y"
    { tipoError = 6; }
    break;

  case 41:
/* Line 1792 of yacc.c  */
#line 76 "Sintactico.y"
    { tipoError = 7; linea = yylineno - 1; }
    break;

  case 43:
/* Line 1792 of yacc.c  */
#line 77 "Sintactico.y"
    { tipoError = 8; }
    break;

  case 45:
/* Line 1792 of yacc.c  */
#line 79 "Sintactico.y"
    { tipoError = 10; }
    break;

  case 47:
/* Line 1792 of yacc.c  */
#line 80 "Sintactico.y"
    { tipoError = 5; }
    break;

  case 49:
/* Line 1792 of yacc.c  */
#line 81 "Sintactico.y"
    { tipoError = 6; }
    break;

  case 51:
/* Line 1792 of yacc.c  */
#line 82 "Sintactico.y"
    { tipoError = 7; linea = yylineno - 1; }
    break;

  case 53:
/* Line 1792 of yacc.c  */
#line 83 "Sintactico.y"
    {tipoError = 12; linea = yylineno - 1;}
    break;

  case 55:
/* Line 1792 of yacc.c  */
#line 84 "Sintactico.y"
    { tipoError = 8; }
    break;

  case 61:
/* Line 1792 of yacc.c  */
#line 94 "Sintactico.y"
    {tipoError = 10; }
    break;

  case 63:
/* Line 1792 of yacc.c  */
#line 95 "Sintactico.y"
    {tipoError = 11; }
    break;

  case 96:
/* Line 1792 of yacc.c  */
#line 136 "Sintactico.y"
    { tipoError = 13; linea = yylineno - 1; }
    break;

  case 98:
/* Line 1792 of yacc.c  */
#line 137 "Sintactico.y"
    { tipoError = 18; }
    break;

  case 100:
/* Line 1792 of yacc.c  */
#line 138 "Sintactico.y"
    { tipoError = 16; linea = yylineno; }
    break;

  case 103:
/* Line 1792 of yacc.c  */
#line 145 "Sintactico.y"
    { tipoError = 10; imprimeError("syntax error", yylineno); }
    break;

  case 105:
/* Line 1792 of yacc.c  */
#line 146 "Sintactico.y"
    { tipoError = 17; linea = yylineno; }
    break;

  case 108:
/* Line 1792 of yacc.c  */
#line 153 "Sintactico.y"
    { tipoError = 10; imprimeError("syntax error", yylineno); }
    break;

  case 110:
/* Line 1792 of yacc.c  */
#line 154 "Sintactico.y"
    { tipoError = 13; linea = yylineno; }
    break;

  case 114:
/* Line 1792 of yacc.c  */
#line 163 "Sintactico.y"
    { tipoError = 20; linea = yylineno; }
    break;

  case 116:
/* Line 1792 of yacc.c  */
#line 164 "Sintactico.y"
    { tipoError = 13; imprimeError("syntax error", yylineno - 1); }
    break;

  case 134:
/* Line 1792 of yacc.c  */
#line 191 "Sintactico.y"
    { tipoError = 8; }
    break;

  case 136:
/* Line 1792 of yacc.c  */
#line 192 "Sintactico.y"
    { tipoError = 7; }
    break;

  case 138:
/* Line 1792 of yacc.c  */
#line 193 "Sintactico.y"
    { tipoError = 19; linea = yylineno;}
    break;

  case 149:
/* Line 1792 of yacc.c  */
#line 209 "Sintactico.y"
    { tipoError = 19; linea = yylineno; }
    break;

  case 150:
/* Line 1792 of yacc.c  */
#line 209 "Sintactico.y"
    { yyerrok; }
    break;

  case 162:
/* Line 1792 of yacc.c  */
#line 215 "Sintactico.y"
    { tipoError = 16; linea = yylineno; }
    break;


/* Line 1792 of yacc.c  */
#line 2001 "Sintactico.tab.c"
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

  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
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

  /* Do not reclaim the symbols of the rule which action triggered
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
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

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
  /* Do not reclaim the symbols of the rule which action triggered
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
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}


/* Line 2055 of yacc.c  */
#line 236 "Sintactico.y"


yyerror(char* mensaje){

    imprimeError(mensaje, linea);

}

int main( int argc, char const *argv[] )
{
	
	flag = 0;
	yyin = fopen( argv[ 1 ], "r" );

	yyparse();

	switch(flag){
		case 0: puts("COMPILACION EXITOSA.\n");
				break;
		case 1: printf( "\nErrores: %d\n", noerror );
	  			puts( "COMPILACION FALLIDA." );
	  			break;
	}

  	return 0;
}

int imprimeError(char* mensaje, int linea)
{
    flag = 1;
    noerror++;

    if(linea == 0)
        linea = yylineno;
    

    if( strlen( yytext ) != 0){
        printf( "<%s> linea: %d - token '%s' invalido. ", mensaje, linea, yytext );

        tokenEsperado(tipoError);
    }
    else
        printf( "<%s> linea: %d - Se esperaba una '}' final de la linea.\n", mensaje, linea );
     return 0;
}