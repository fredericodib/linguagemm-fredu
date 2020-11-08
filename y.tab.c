/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C

   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 51 Franklin Street, Fifth Floor,
   Boston, MA 02110-1301, USA.  */

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
#define YYBISON_VERSION "2.3"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Using locations.  */
#define YYLSP_NEEDED 1



/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     ID = 258,
     TYPEINT = 259,
     TYPEFLOAT = 260,
     TYPESTRING = 261,
     INT = 262,
     DEC = 263,
     STR = 264,
     WHILE = 265,
     IF = 266,
     ELSE = 267,
     RETURN = 268,
     PRINT = 269,
     SCAN = 270,
     CGE = 271,
     CGT = 272,
     CLE = 273,
     CLT = 274,
     CNE = 275,
     CEQ = 276
   };
#endif
/* Tokens.  */
#define ID 258
#define TYPEINT 259
#define TYPEFLOAT 260
#define TYPESTRING 261
#define INT 262
#define DEC 263
#define STR 264
#define WHILE 265
#define IF 266
#define ELSE 267
#define RETURN 268
#define PRINT 269
#define SCAN 270
#define CGE 271
#define CGT 272
#define CLE 273
#define CLT 274
#define CNE 275
#define CEQ 276




/* Copy the first part of user declarations.  */
#line 5 "lang.y"

void yyerror (char *s);
int yylex();
#include "global_variable.h"
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "uthash.h"
#include "utlist.h"
#include "utstring.h"
#include "utstack.h"
extern FILE *yyin;
extern int yylex_destroy(void);

struct node {
  char *value;
  char node_type;
  int type;
  struct node *node1;
  struct node *node2;
  struct node *node3;
};

/*
# node_type
- F -> funcao,
- V -> variavel,
- v -> declaração de variavel,
- P -> Params,
- R -> Regra
- C -> IF
- c -> condição
- W -> While
- I -> inteiro
- D -> decimal
- S -> string
- V -> variavel
- B -> simbolo
- E -> Espressão
- A -> Atribuição
- L -> chama função

# type
- 0 = int
- 1 = float
- 2 = string
- 3 = none
*/

struct scope {
  char *scope_name;
  int type; // 0 = int, 1 = float, 2 = string
  struct scope *next;
};

struct symbol_node {
  char *key; // hash key -> scope_name + @ + id
  char *id; // variável
  char *scope_name; // nome do scopo
  int type; // 0 = int, 1 = float, 2 = string
  UT_hash_handle hh;
};

struct params {
  int type; // 0 = int, 1 = float, 2 = string
  struct params *next;
};

struct func_params {
  struct params *first;
  char *func_name; // nome da  funcao
  int n_params; // numero de parametros 
  UT_hash_handle hh;
};

void add_func_params(char *id);
void add_params(int type);
void print_func_table();
void print_params(struct params *params, int count);
void free_func_table();
void free_params(struct params *params);

int hasMain = 0;
int hasReturn = 0;
struct node* tree = NULL;
struct scope* scope_stack = NULL;
struct symbol_node* symbol_table = NULL;
struct func_params* func_table = NULL;

struct node* add_node3(char node_type, struct node *node1, struct node *node2, struct node *node3);
struct node* add_node2(char node_type, struct node *node1, struct node *node2);
struct node* add_node1(char node_type, struct node *node1);
struct node* add_node0(char node_type);

void add_scope(char* scope_name, int type);
void remove_scope();
struct scope* get_last_scope();

void add_symbol_table(char *id, int type);
struct symbol_node* find_symbol_table(char *id);
char* generate_symbol_key(char *id); // Gera uma chave concatenando scope_name + @ + id
int get_id_type(char *id);

void print_symbol_table();
void free_symbol_table();
void print_tree(struct node *node, int depth);
void free_tree(struct node *node);

void print_semantic_error(char *id, int type);
void build_expression_type(struct node *node);



/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 1
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 1
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif

#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 118 "lang.y"
{
  char *id;
  char *num;
  char *type;
  char *str;
  struct node *node;
}
/* Line 193 of yacc.c.  */
#line 259 "y.tab.c"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

#if ! defined YYLTYPE && ! defined YYLTYPE_IS_DECLARED
typedef struct YYLTYPE
{
  int first_line;
  int first_column;
  int last_line;
  int last_column;
} YYLTYPE;
# define yyltype YYLTYPE /* obsolescent; will be withdrawn */
# define YYLTYPE_IS_DECLARED 1
# define YYLTYPE_IS_TRIVIAL 1
#endif


/* Copy the second part of user declarations.  */


/* Line 216 of yacc.c.  */
#line 284 "y.tab.c"

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
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int i)
#else
static int
YYID (i)
    int i;
#endif
{
  return i;
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
#    if ! defined _ALLOCA_H && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef _STDLIB_H
#      define _STDLIB_H 1
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
#  if (defined __cplusplus && ! defined _STDLIB_H \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef _STDLIB_H
#    define _STDLIB_H 1
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
	 || (defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL \
	     && defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss;
  YYSTYPE yyvs;
    YYLTYPE yyls;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE) + sizeof (YYLTYPE)) \
      + 2 * YYSTACK_GAP_MAXIMUM)

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack)					\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack, Stack, yysize);				\
	Stack = &yyptr->Stack;						\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  11
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   212

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  33
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  27
/* YYNRULES -- Number of rules.  */
#define YYNRULES  92
/* YYNRULES -- Number of states.  */
#define YYNSTATES  202

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   276

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      24,    25,    32,    29,    28,    30,     2,    31,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    22,
       2,    23,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    26,     2,    27,     2,     2,     2,     2,
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
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     5,     8,    10,    12,    15,    19,    25,
      29,    35,    41,    45,    51,    52,    53,    64,    65,    66,
      77,    78,    79,    90,    92,    93,    95,    99,   102,   105,
     108,   111,   112,   114,   116,   118,   120,   122,   124,   126,
     131,   133,   135,   137,   139,   143,   147,   151,   155,   157,
     159,   161,   163,   171,   183,   191,   195,   199,   203,   207,
     211,   215,   219,   223,   227,   229,   231,   233,   235,   237,
     239,   245,   251,   257,   263,   271,   279,   287,   293,   299,
     305,   311,   317,   325,   330,   337,   339,   341,   343,   345,
     349,   353,   357
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      34,     0,    -1,    35,    -1,    35,    36,    -1,    36,    -1,
      37,    -1,    35,    37,    -1,     4,     3,    22,    -1,     4,
       3,    23,     7,    22,    -1,     5,     3,    22,    -1,     5,
       3,    23,     7,    22,    -1,     5,     3,    23,     8,    22,
      -1,     6,     3,    22,    -1,     6,     3,    23,     9,    22,
      -1,    -1,    -1,     6,     3,    38,    24,    44,    25,    39,
      26,    47,    27,    -1,    -1,    -1,     5,     3,    40,    24,
      44,    25,    41,    26,    47,    27,    -1,    -1,    -1,     4,
       3,    42,    24,    44,    25,    43,    26,    47,    27,    -1,
      45,    -1,    -1,    46,    -1,    46,    28,    45,    -1,     4,
       3,    -1,     5,     3,    -1,     6,     3,    -1,    48,    47,
      -1,    -1,    36,    -1,    49,    -1,    52,    -1,    55,    -1,
      56,    -1,    57,    -1,    58,    -1,     3,    23,    50,    22,
      -1,     3,    -1,     7,    -1,     8,    -1,     9,    -1,     3,
      51,    50,    -1,     7,    51,    50,    -1,     8,    51,    50,
      -1,     9,    51,    50,    -1,    29,    -1,    30,    -1,    31,
      -1,    32,    -1,    11,    24,    53,    25,    26,    47,    27,
      -1,    11,    24,    53,    25,    26,    47,    27,    12,    26,
      47,    27,    -1,    10,    24,    53,    25,    26,    47,    27,
      -1,     3,    54,     3,    -1,     3,    54,     7,    -1,     3,
      54,     8,    -1,     7,    54,     3,    -1,     7,    54,     7,
      -1,     7,    54,     8,    -1,     8,    54,     3,    -1,     8,
      54,     7,    -1,     8,    54,     8,    -1,    16,    -1,    17,
      -1,    18,    -1,    19,    -1,    20,    -1,    21,    -1,    14,
      24,     3,    25,    22,    -1,    14,    24,     9,    25,    22,
      -1,    14,    24,     7,    25,    22,    -1,    14,    24,     8,
      25,    22,    -1,    15,    24,     3,    28,     4,    25,    22,
      -1,    15,    24,     3,    28,     5,    25,    22,    -1,    15,
      24,     3,    28,     6,    25,    22,    -1,    13,    24,     3,
      25,    22,    -1,    13,    24,     9,    25,    22,    -1,    13,
      24,     7,    25,    22,    -1,    13,    24,     8,    25,    22,
      -1,     3,    24,    59,    25,    22,    -1,     3,    23,     3,
      24,    59,    25,    22,    -1,     3,    24,    25,    22,    -1,
       3,    23,     3,    24,    25,    22,    -1,     3,    -1,     7,
      -1,     8,    -1,     9,    -1,     3,    28,    59,    -1,     7,
      28,    59,    -1,     8,    28,    59,    -1,     9,    28,    59,
      -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   139,   139,   148,   149,   150,   151,   155,   162,   179,
     186,   203,   220,   227,   247,   252,   247,   265,   268,   265,
     281,   289,   281,   304,   305,   309,   310,   314,   322,   330,
     341,   342,   346,   347,   348,   349,   350,   351,   352,   356,
     373,   378,   383,   388,   393,   404,   415,   426,   440,   443,
     446,   449,   455,   456,   457,   461,   475,   489,   503,   517,
     531,   545,   559,   573,   590,   593,   596,   599,   602,   605,
     611,   618,   625,   632,   642,   654,   666,   681,   694,   707,
     720,   736,   741,   759,   764,   785,   790,   795,   800,   805,
     814,   823,   832
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "ID", "TYPEINT", "TYPEFLOAT",
  "TYPESTRING", "INT", "DEC", "STR", "WHILE", "IF", "ELSE", "RETURN",
  "PRINT", "SCAN", "CGE", "CGT", "CLE", "CLT", "CNE", "CEQ", "';'", "'='",
  "'('", "')'", "'{'", "'}'", "','", "'+'", "'-'", "'/'", "'*'", "$accept",
  "prog", "globalList", "var", "func", "@1", "@2", "@3", "@4", "@5", "@6",
  "paramsList", "params", "param", "contentList", "content", "addValue",
  "expression", "op", "comand", "condition", "cond", "print", "scan",
  "return", "callFunc", "callFuncParams", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,    59,    61,    40,    41,   123,   125,    44,    43,
      45,    47,    42
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    33,    34,    35,    35,    35,    35,    36,    36,    36,
      36,    36,    36,    36,    38,    39,    37,    40,    41,    37,
      42,    43,    37,    44,    44,    45,    45,    46,    46,    46,
      47,    47,    48,    48,    48,    48,    48,    48,    48,    49,
      50,    50,    50,    50,    50,    50,    50,    50,    51,    51,
      51,    51,    52,    52,    52,    53,    53,    53,    53,    53,
      53,    53,    53,    53,    54,    54,    54,    54,    54,    54,
      55,    55,    55,    55,    56,    56,    56,    57,    57,    57,
      57,    58,    58,    58,    58,    59,    59,    59,    59,    59,
      59,    59,    59
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     1,     1,     2,     3,     5,     3,
       5,     5,     3,     5,     0,     0,    10,     0,     0,    10,
       0,     0,    10,     1,     0,     1,     3,     2,     2,     2,
       2,     0,     1,     1,     1,     1,     1,     1,     1,     4,
       1,     1,     1,     1,     3,     3,     3,     3,     1,     1,
       1,     1,     7,    11,     7,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     1,     1,     1,     1,     1,     1,
       5,     5,     5,     5,     7,     7,     7,     5,     5,     5,
       5,     5,     7,     4,     6,     1,     1,     1,     1,     3,
       3,     3,     3
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     0,     0,     2,     4,     5,    20,    17,
      14,     1,     3,     6,     7,     0,     0,     9,     0,     0,
      12,     0,     0,     0,    24,     0,     0,    24,     0,    24,
       8,     0,     0,     0,     0,    23,    25,    10,    11,     0,
      13,     0,    27,    28,    29,    21,     0,    18,    15,     0,
      26,     0,     0,    31,    31,    31,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    32,     0,    31,    33,    34,
      35,    36,    37,    38,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    22,    30,    19,    16,
      40,    41,    42,    43,     0,    85,    86,    87,    88,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    48,    49,    50,    51,
       0,     0,     0,     0,    39,     0,     0,     0,     0,    83,
       0,    64,    65,    66,    67,    68,    69,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    40,    44,    45,    46,    47,    89,    90,
      91,    92,    81,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    31,    31,    77,    79,    80,    78,    70,    72,
      73,    71,     0,     0,     0,    84,     0,     0,     0,     0,
       0,     0,    82,    54,    52,    74,    75,    76,     0,    31,
       0,    53
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     4,     5,    65,     7,    22,    52,    19,    51,    16,
      49,    34,    35,    36,    66,    67,    68,    94,   120,    69,
     104,   137,    70,    71,    72,    73,   100
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -112
static const yytype_int16 yypact[] =
{
      90,     9,    59,    71,    76,    90,  -112,  -112,     0,    19,
      29,  -112,  -112,  -112,  -112,    -4,    58,  -112,    99,    88,
    -112,   104,    91,    92,    93,    94,    95,    93,    98,    93,
    -112,   118,   119,   120,   100,  -112,   101,  -112,  -112,   102,
    -112,   103,  -112,  -112,  -112,  -112,    93,  -112,  -112,   105,
    -112,   106,   107,    15,    15,    15,    85,   121,   123,   127,
     110,   111,   112,   113,   114,  -112,   115,    15,  -112,  -112,
    -112,  -112,  -112,  -112,   116,   117,    37,    -1,     0,    19,
      29,    70,    70,    40,    47,   136,  -112,  -112,  -112,  -112,
       7,     3,     3,     3,   124,   122,   125,   126,   128,   129,
     130,    51,    51,    51,   132,   133,   134,   135,   137,   138,
     139,   140,   141,   142,   143,     2,  -112,  -112,  -112,  -112,
      50,    50,    50,    50,  -112,    57,    57,    57,    57,  -112,
     146,  -112,  -112,  -112,  -112,  -112,  -112,    72,    78,    80,
     144,   147,   150,   152,   153,   154,   155,   156,   157,   158,
      96,   159,   160,     3,  -112,  -112,  -112,  -112,  -112,  -112,
    -112,  -112,  -112,  -112,  -112,  -112,  -112,  -112,  -112,  -112,
    -112,  -112,    15,    15,  -112,  -112,  -112,  -112,  -112,  -112,
    -112,  -112,   161,   162,   163,  -112,   167,   164,   165,   168,
     171,   172,  -112,  -112,   149,  -112,  -112,  -112,   169,    15,
     170,  -112
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -112,  -112,  -112,    84,   177,  -112,  -112,  -112,  -112,  -112,
    -112,    34,   166,  -112,   -54,  -112,  -112,   -30,    12,  -112,
      65,     8,  -112,  -112,  -112,  -112,  -111
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint8 yytable[] =
{
      74,    75,    95,    23,   152,    95,    96,    97,    98,    96,
      97,    98,     8,    87,   158,   159,   160,   161,    56,    57,
      58,    59,    14,    15,    99,    60,    61,   151,    62,    63,
      64,   115,   116,   117,   118,   119,   116,   117,   118,   119,
      90,    17,    18,   106,    91,    92,    93,   107,   108,   109,
     110,    20,    21,   153,   111,   112,   113,    91,    92,    93,
      95,    39,     9,    41,    96,    97,    98,   131,   132,   133,
     134,   135,   136,   101,    10,   163,    11,   102,   103,   164,
     165,   166,    24,   169,     6,   167,   168,   170,   171,    12,
     154,   155,   156,   157,     1,     2,     3,    31,    32,    33,
     182,   183,   184,   121,   122,   123,    25,    26,    76,    77,
     138,   139,    27,    28,    30,    29,    37,    38,   187,   188,
      40,    42,    43,    44,    78,    45,    79,    47,    48,    46,
      80,    53,    54,    55,    81,    82,    83,    84,    85,   114,
       0,     0,    86,    88,    89,   200,   124,   105,     0,     0,
     125,   129,     0,   126,   127,   130,   128,   140,   141,   142,
     143,   198,   144,   145,   146,   147,   148,   149,   162,     0,
     172,   150,   174,   173,   175,   176,   177,   178,   179,   180,
     181,   185,    13,     0,     0,   186,   189,   190,   191,   192,
     195,   193,   194,   196,   197,   199,     0,   201,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    50
};

static const yytype_int16 yycheck[] =
{
      54,    55,     3,     7,   115,     3,     7,     8,     9,     7,
       8,     9,     3,    67,   125,   126,   127,   128,     3,     4,
       5,     6,    22,    23,    25,    10,    11,    25,    13,    14,
      15,    24,    29,    30,    31,    32,    29,    30,    31,    32,
       3,    22,    23,     3,     7,     8,     9,     7,     8,     9,
       3,    22,    23,     3,     7,     8,     9,     7,     8,     9,
       3,    27,     3,    29,     7,     8,     9,    16,    17,    18,
      19,    20,    21,     3,     3,     3,     0,     7,     8,     7,
       8,     3,    24,     3,     0,     7,     8,     7,     8,     5,
     120,   121,   122,   123,     4,     5,     6,     4,     5,     6,
       4,     5,     6,    91,    92,    93,     7,     8,    23,    24,
     102,   103,    24,     9,    22,    24,    22,    22,   172,   173,
      22,     3,     3,     3,     3,    25,     3,    25,    25,    28,
       3,    26,    26,    26,    24,    24,    24,    24,    24,     3,
      -1,    -1,    27,    27,    27,   199,    22,    82,    -1,    -1,
      28,    22,    -1,    28,    28,    25,    28,    25,    25,    25,
      25,    12,    25,    25,    25,    25,    25,    25,    22,    -1,
      26,    28,    22,    26,    22,    22,    22,    22,    22,    22,
      22,    22,     5,    -1,    -1,    25,    25,    25,    25,    22,
      22,    27,    27,    22,    22,    26,    -1,    27,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    46
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     4,     5,     6,    34,    35,    36,    37,     3,     3,
       3,     0,    36,    37,    22,    23,    42,    22,    23,    40,
      22,    23,    38,     7,    24,     7,     8,    24,     9,    24,
      22,     4,     5,     6,    44,    45,    46,    22,    22,    44,
      22,    44,     3,     3,     3,    25,    28,    25,    25,    43,
      45,    41,    39,    26,    26,    26,     3,     4,     5,     6,
      10,    11,    13,    14,    15,    36,    47,    48,    49,    52,
      55,    56,    57,    58,    47,    47,    23,    24,     3,     3,
       3,    24,    24,    24,    24,    24,    27,    47,    27,    27,
       3,     7,     8,     9,    50,     3,     7,     8,     9,    25,
      59,     3,     7,     8,    53,    53,     3,     7,     8,     9,
       3,     7,     8,     9,     3,    24,    29,    30,    31,    32,
      51,    51,    51,    51,    22,    28,    28,    28,    28,    22,
      25,    16,    17,    18,    19,    20,    21,    54,    54,    54,
      25,    25,    25,    25,    25,    25,    25,    25,    25,    25,
      28,    25,    59,     3,    50,    50,    50,    50,    59,    59,
      59,    59,    22,     3,     7,     8,     3,     7,     8,     3,
       7,     8,    26,    26,    22,    22,    22,    22,    22,    22,
      22,    22,     4,     5,     6,    22,    25,    47,    47,    25,
      25,    25,    22,    27,    27,    22,    22,    22,    12,    26,
      47,    27
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
   Once GCC version 2 has supplanted version 1, this can go.  */

#define YYFAIL		goto yyerrlab

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      yytoken = YYTRANSLATE (yychar);				\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
#  define YY_LOCATION_PRINT(File, Loc)			\
     fprintf (File, "%d.%d-%d.%d",			\
	      (Loc).first_line, (Loc).first_column,	\
	      (Loc).last_line,  (Loc).last_column)
# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
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
		  Type, Value, Location); \
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
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
    YYLTYPE const * const yylocationp;
#endif
{
  if (!yyvaluep)
    return;
  YYUSE (yylocationp);
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
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep, yylocationp)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
    YYLTYPE const * const yylocationp;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  YY_LOCATION_PRINT (yyoutput, *yylocationp);
  YYFPRINTF (yyoutput, ": ");
  yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *bottom, yytype_int16 *top)
#else
static void
yy_stack_print (bottom, top)
    yytype_int16 *bottom;
    yytype_int16 *top;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; bottom <= top; ++bottom)
    YYFPRINTF (stderr, " %d", *bottom);
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
yy_reduce_print (YYSTYPE *yyvsp, YYLTYPE *yylsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yylsp, yyrule)
    YYSTYPE *yyvsp;
    YYLTYPE *yylsp;
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
      fprintf (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       , &(yylsp[(yyi + 1) - (yynrhs)])		       );
      fprintf (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, yylsp, Rule); \
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

/* Copy into YYRESULT an error message about the unexpected token
   YYCHAR while in state YYSTATE.  Return the number of bytes copied,
   including the terminating null byte.  If YYRESULT is null, do not
   copy anything; just return the number of bytes that would be
   copied.  As a special case, return 0 if an ordinary "syntax error"
   message will do.  Return YYSIZE_MAXIMUM if overflow occurs during
   size calculation.  */
static YYSIZE_T
yysyntax_error (char *yyresult, int yystate, int yychar)
{
  int yyn = yypact[yystate];

  if (! (YYPACT_NINF < yyn && yyn <= YYLAST))
    return 0;
  else
    {
      int yytype = YYTRANSLATE (yychar);
      YYSIZE_T yysize0 = yytnamerr (0, yytname[yytype]);
      YYSIZE_T yysize = yysize0;
      YYSIZE_T yysize1;
      int yysize_overflow = 0;
      enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
      char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
      int yyx;

# if 0
      /* This is so xgettext sees the translatable formats that are
	 constructed on the fly.  */
      YY_("syntax error, unexpected %s");
      YY_("syntax error, unexpected %s, expecting %s");
      YY_("syntax error, unexpected %s, expecting %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
# endif
      char *yyfmt;
      char const *yyf;
      static char const yyunexpected[] = "syntax error, unexpected %s";
      static char const yyexpecting[] = ", expecting %s";
      static char const yyor[] = " or %s";
      char yyformat[sizeof yyunexpected
		    + sizeof yyexpecting - 1
		    + ((YYERROR_VERBOSE_ARGS_MAXIMUM - 2)
		       * (sizeof yyor - 1))];
      char const *yyprefix = yyexpecting;

      /* Start YYX at -YYN if negative to avoid negative indexes in
	 YYCHECK.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;

      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yycount = 1;

      yyarg[0] = yytname[yytype];
      yyfmt = yystpcpy (yyformat, yyunexpected);

      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
	if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	  {
	    if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
	      {
		yycount = 1;
		yysize = yysize0;
		yyformat[sizeof yyunexpected - 1] = '\0';
		break;
	      }
	    yyarg[yycount++] = yytname[yyx];
	    yysize1 = yysize + yytnamerr (0, yytname[yyx]);
	    yysize_overflow |= (yysize1 < yysize);
	    yysize = yysize1;
	    yyfmt = yystpcpy (yyfmt, yyprefix);
	    yyprefix = yyor;
	  }

      yyf = YY_(yyformat);
      yysize1 = yysize + yystrlen (yyf);
      yysize_overflow |= (yysize1 < yysize);
      yysize = yysize1;

      if (yysize_overflow)
	return YYSIZE_MAXIMUM;

      if (yyresult)
	{
	  /* Avoid sprintf, as that infringes on the user's name space.
	     Don't have undefined behavior even if the translation
	     produced a string with the wrong number of "%s"s.  */
	  char *yyp = yyresult;
	  int yyi = 0;
	  while ((*yyp = *yyf) != '\0')
	    {
	      if (*yyp == '%' && yyf[1] == 's' && yyi < yycount)
		{
		  yyp += yytnamerr (yyp, yyarg[yyi++]);
		  yyf += 2;
		}
	      else
		{
		  yyp++;
		  yyf++;
		}
	    }
	}
      return yysize;
    }
}
#endif /* YYERROR_VERBOSE */


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep, YYLTYPE *yylocationp)
#else
static void
yydestruct (yymsg, yytype, yyvaluep, yylocationp)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
    YYLTYPE *yylocationp;
#endif
{
  YYUSE (yyvaluep);
  YYUSE (yylocationp);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
	break;
    }
}


/* Prevent warnings from -Wmissing-prototypes.  */

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



/* The look-ahead symbol.  */
int yychar;

/* The semantic value of the look-ahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;
/* Location data for the look-ahead symbol.  */
YYLTYPE yylloc;



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
  int yyn;
  int yyresult;
  /* Number of tokens to shift before error messages enabled.  */
  int yyerrstatus;
  /* Look-ahead token as an internal (translated) token number.  */
  int yytoken = 0;
#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

  /* Three stacks and their tools:
     `yyss': related to states,
     `yyvs': related to semantic values,
     `yyls': related to locations.

     Refer to the stacks thru separate pointers, to allow yyoverflow
     to reallocate them elsewhere.  */

  /* The state stack.  */
  yytype_int16 yyssa[YYINITDEPTH];
  yytype_int16 *yyss = yyssa;
  yytype_int16 *yyssp;

  /* The semantic value stack.  */
  YYSTYPE yyvsa[YYINITDEPTH];
  YYSTYPE *yyvs = yyvsa;
  YYSTYPE *yyvsp;

  /* The location stack.  */
  YYLTYPE yylsa[YYINITDEPTH];
  YYLTYPE *yyls = yylsa;
  YYLTYPE *yylsp;
  /* The locations where the error started and ended.  */
  YYLTYPE yyerror_range[2];

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N), yylsp -= (N))

  YYSIZE_T yystacksize = YYINITDEPTH;

  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;
  YYLTYPE yyloc;

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY;		/* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */

  yyssp = yyss;
  yyvsp = yyvs;
  yylsp = yyls;
#if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
  /* Initialize the default location before parsing starts.  */
  yylloc.first_line   = yylloc.last_line   = 1;
  yylloc.first_column = yylloc.last_column = 0;
#endif

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
	YYLTYPE *yyls1 = yyls;

	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow (YY_("memory exhausted"),
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),
		    &yyls1, yysize * sizeof (*yylsp),
		    &yystacksize);
	yyls = yyls1;
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
	YYSTACK_RELOCATE (yyss);
	YYSTACK_RELOCATE (yyvs);
	YYSTACK_RELOCATE (yyls);
#  undef YYSTACK_RELOCATE
	if (yyss1 != yyssa)
	  YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;
      yylsp = yyls + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
		  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
	YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     look-ahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to look-ahead token.  */
  yyn = yypact[yystate];
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a look-ahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid look-ahead symbol.  */
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
      if (yyn == 0 || yyn == YYTABLE_NINF)
	goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the look-ahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token unless it is eof.  */
  if (yychar != YYEOF)
    yychar = YYEMPTY;

  yystate = yyn;
  *++yyvsp = yylval;
  *++yylsp = yylloc;
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

  /* Default location.  */
  YYLLOC_DEFAULT (yyloc, (yylsp - yylen), yylen);
  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:
#line 139 "lang.y"
    { 
    tree = (yyvsp[(1) - (1)].node);
    if (hasMain == 0) {
      print_semantic_error(NULL, 7);
    }
  }
    break;

  case 3:
#line 148 "lang.y"
    { (yyval.node) = add_node2('R', (yyvsp[(1) - (2)].node), (yyvsp[(2) - (2)].node)); }
    break;

  case 4:
#line 149 "lang.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 5:
#line 150 "lang.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 6:
#line 151 "lang.y"
    { (yyval.node) = add_node2('R', (yyvsp[(1) - (2)].node), (yyvsp[(2) - (2)].node)); }
    break;

  case 7:
#line 155 "lang.y"
    { (yyval.node) = add_node0('v'); 
                            (yyval.node)->type = 0;
                            (yyval.node)->value = (char *) strdup((yyvsp[(2) - (3)].id));   
                            add_symbol_table((yyvsp[(2) - (3)].id), 0);  
                            free((yyvsp[(1) - (3)].type));
                            free((yyvsp[(2) - (3)].id)); 
                          }
    break;

  case 8:
#line 162 "lang.y"
    {  (yyval.node) = add_node0('v'); 
                            (yyval.node)->type = 0;
                            (yyval.node)->value = (char *) strdup((yyvsp[(2) - (5)].id));

                            (yyval.node)->node1 = add_node0('A');
                            (yyval.node)->node1->type = 0;
                            (yyval.node)->node1->node1 = add_node0('V');
                            (yyval.node)->node1->node1->type = 0;
                            (yyval.node)->node1->node1->value = (char *) strdup((yyvsp[(2) - (5)].id));
                            (yyval.node)->node1->node2 = add_node0('I');
                            (yyval.node)->node1->node2->type = 0;
                            (yyval.node)->node1->node2->value = (char *) strdup((yyvsp[(4) - (5)].num));
                            add_symbol_table((yyvsp[(2) - (5)].id), 0);
                            free((yyvsp[(1) - (5)].type));
                            free((yyvsp[(2) - (5)].id)); 
                            free((yyvsp[(4) - (5)].num)); 
                          }
    break;

  case 9:
#line 179 "lang.y"
    { (yyval.node) = add_node0('v'); 
                            (yyval.node)->type = 1;
                            (yyval.node)->value = (char *) strdup((yyvsp[(2) - (3)].id));  
                            add_symbol_table((yyvsp[(2) - (3)].id), 1);
                            free((yyvsp[(1) - (3)].type));
                            free((yyvsp[(2) - (3)].id)); 
                          }
    break;

  case 10:
#line 186 "lang.y"
    {  (yyval.node) = add_node0('v'); 
                            (yyval.node)->type = 1;
                            (yyval.node)->value = (char *) strdup((yyvsp[(2) - (5)].id));

                            (yyval.node)->node1 = add_node0('A');
                            (yyval.node)->node1->type = 1;
                            (yyval.node)->node1->node1 = add_node0('V');
                            (yyval.node)->node1->node1->type = 1;
                            (yyval.node)->node1->node1->value = (char *) strdup((yyvsp[(2) - (5)].id));
                            (yyval.node)->node1->node2 = add_node0('I');
                            (yyval.node)->node1->node2->type = 0;
                            (yyval.node)->node1->node2->value = (char *) strdup((yyvsp[(4) - (5)].num));
                            add_symbol_table((yyvsp[(2) - (5)].id), 1);
                            free((yyvsp[(1) - (5)].type));
                            free((yyvsp[(2) - (5)].id)); 
                            free((yyvsp[(4) - (5)].num)); 
                          }
    break;

  case 11:
#line 203 "lang.y"
    {  (yyval.node) = add_node0('v'); 
                            (yyval.node)->type = 1;
                            (yyval.node)->value = (char *) strdup((yyvsp[(2) - (5)].id));

                            (yyval.node)->node1 = add_node0('A');
                            (yyval.node)->node1->type = 1;
                            (yyval.node)->node1->node1 = add_node0('V');
                            (yyval.node)->node1->node1->type = 1;
                            (yyval.node)->node1->node1->value = (char *) strdup((yyvsp[(2) - (5)].id));
                            (yyval.node)->node1->node2 = add_node0('D');
                            (yyval.node)->node1->node2->type = 1;
                            (yyval.node)->node1->node2->value = (char *) strdup((yyvsp[(4) - (5)].num));
                            add_symbol_table((yyvsp[(2) - (5)].id), 1);
                            free((yyvsp[(1) - (5)].type));
                            free((yyvsp[(2) - (5)].id)); 
                            free((yyvsp[(4) - (5)].num)); 
                          }
    break;

  case 12:
#line 220 "lang.y"
    { (yyval.node) = add_node0('v'); 
                            (yyval.node)->type = 2;
                            (yyval.node)->value = (char *) strdup((yyvsp[(2) - (3)].id));    
                            add_symbol_table((yyvsp[(2) - (3)].id), 2);
                            free((yyvsp[(1) - (3)].type));
                            free((yyvsp[(2) - (3)].id)); 
                          }
    break;

  case 13:
#line 227 "lang.y"
    {  (yyval.node) = add_node0('v'); 
                            (yyval.node)->type = 2;
                            (yyval.node)->value = (char *) strdup((yyvsp[(2) - (5)].id));

                            (yyval.node)->node1 = add_node0('A');
                            (yyval.node)->node1->type = 2;
                            (yyval.node)->node1->node1 = add_node0('V');
                            (yyval.node)->node1->node1->type = 2;
                            (yyval.node)->node1->node1->value = (char *) strdup((yyvsp[(2) - (5)].id));
                            (yyval.node)->node1->node2 = add_node0('S');
                            (yyval.node)->node1->node2->type = 2;
                            (yyval.node)->node1->node2->value = (char *) strdup((yyvsp[(4) - (5)].str));
                            add_symbol_table((yyvsp[(2) - (5)].id), 2);
                            free((yyvsp[(1) - (5)].type));
                            free((yyvsp[(2) - (5)].id)); 
                            free((yyvsp[(4) - (5)].str)); 
                          }
    break;

  case 14:
#line 247 "lang.y"
    { 
                                                          add_symbol_table((yyvsp[(2) - (2)].id), 2); add_scope((yyvsp[(2) - (2)].id), 2); 
                                                          hasReturn = 0;
                                                          add_func_params((yyvsp[(2) - (2)].id));
                                                        }
    break;

  case 15:
#line 252 "lang.y"
    {;}
    break;

  case 16:
#line 253 "lang.y"
    { 
                                                          (yyval.node) = add_node2('F', (yyvsp[(5) - (10)].node), (yyvsp[(9) - (10)].node)); 
                                                          (yyval.node)->type = 2;
                                                          (yyval.node)->value = (char *) strdup((yyvsp[(2) - (10)].id)); 
                                                          if (hasReturn == 0) {
                                                            print_semantic_error((yyvsp[(2) - (10)].id), 8);
                                                          }
                                                          remove_scope();   
                                                          free((yyvsp[(1) - (10)].type));
                                                          free((yyvsp[(2) - (10)].id)); 
                                                        }
    break;

  case 17:
#line 265 "lang.y"
    { add_symbol_table((yyvsp[(2) - (2)].id), 1); add_scope((yyvsp[(2) - (2)].id), 1); hasReturn = 0;
                                                          add_func_params((yyvsp[(2) - (2)].id)); 
                                                        }
    break;

  case 18:
#line 268 "lang.y"
    {;}
    break;

  case 19:
#line 269 "lang.y"
    {  
                                                          (yyval.node) = add_node2('F', (yyvsp[(5) - (10)].node), (yyvsp[(9) - (10)].node)); 
                                                          (yyval.node)->type = 1;
                                                          (yyval.node)->value = (char *) strdup((yyvsp[(2) - (10)].id));   
                                                          if (hasReturn == 0) {
                                                            print_semantic_error((yyvsp[(2) - (10)].id), 8);
                                                          }  
                                                          remove_scope();
                                                          free((yyvsp[(1) - (10)].type));
                                                          free((yyvsp[(2) - (10)].id));
                                                        }
    break;

  case 20:
#line 281 "lang.y"
    { 
                                                          add_symbol_table((yyvsp[(2) - (2)].id), 0); add_scope((yyvsp[(2) - (2)].id), 0);
                                                          if (strcmp((yyvsp[(2) - (2)].id), "main") == 0) {
                                                            hasMain = 1;
                                                          }
                                                          hasReturn = 0;
                                                          add_func_params((yyvsp[(2) - (2)].id));
                                                        }
    break;

  case 21:
#line 289 "lang.y"
    {;}
    break;

  case 22:
#line 290 "lang.y"
    {
                                                          (yyval.node) = add_node2('F', (yyvsp[(5) - (10)].node), (yyvsp[(9) - (10)].node)); 
                                                          (yyval.node)->type = 0;
                                                          (yyval.node)->value = (char *) strdup((yyvsp[(2) - (10)].id));
                                                          if (hasReturn == 0) {
                                                            print_semantic_error((yyvsp[(2) - (10)].id), 8);
                                                          }
                                                          remove_scope();
                                                          free((yyvsp[(1) - (10)].type));
                                                          free((yyvsp[(2) - (10)].id));
                                                        }
    break;

  case 23:
#line 304 "lang.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 24:
#line 305 "lang.y"
    { (yyval.node) = NULL; }
    break;

  case 25:
#line 309 "lang.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 26:
#line 310 "lang.y"
    { (yyval.node) = add_node2('R', (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node)); }
    break;

  case 27:
#line 314 "lang.y"
    { (yyval.node) = add_node0('P'); 
                            (yyval.node)->type = 0;
                            (yyval.node)->value = (char *) strdup((yyvsp[(2) - (2)].id)); 
                            add_symbol_table((yyvsp[(2) - (2)].id), 0); 
                            add_params(0);
                            free((yyvsp[(1) - (2)].type));
                            free((yyvsp[(2) - (2)].id)); 
                          }
    break;

  case 28:
#line 322 "lang.y"
    { (yyval.node) = add_node0('P'); 
                            (yyval.node)->type = 1;
                            (yyval.node)->value = (char *) strdup((yyvsp[(2) - (2)].id));    
                            add_symbol_table((yyvsp[(2) - (2)].id), 1);
                            add_params(1);
                            free((yyvsp[(1) - (2)].type));
                            free((yyvsp[(2) - (2)].id));  
                          }
    break;

  case 29:
#line 330 "lang.y"
    { (yyval.node) = add_node0('P'); 
                            (yyval.node)->type = 2;
                            (yyval.node)->value = (char *) strdup((yyvsp[(2) - (2)].id));
                            add_symbol_table((yyvsp[(2) - (2)].id), 2);
                            add_params(2);
                            free((yyvsp[(1) - (2)].type));
                            free((yyvsp[(2) - (2)].id));      
                          }
    break;

  case 30:
#line 341 "lang.y"
    { (yyval.node) = add_node2('R', (yyvsp[(1) - (2)].node), (yyvsp[(2) - (2)].node)); }
    break;

  case 31:
#line 342 "lang.y"
    { (yyval.node) = NULL; }
    break;

  case 32:
#line 346 "lang.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 33:
#line 347 "lang.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 34:
#line 348 "lang.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 35:
#line 349 "lang.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 36:
#line 350 "lang.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 37:
#line 351 "lang.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 38:
#line 352 "lang.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 39:
#line 356 "lang.y"
    { 
                            (yyval.node) = add_node0('A');
                            (yyval.node)->type = get_id_type((yyvsp[(1) - (4)].id));
                            (yyval.node)->node1 = add_node0('V');
                            (yyval.node)->node1->type = get_id_type((yyvsp[(1) - (4)].id));
                            (yyval.node)->node1->value = (char *) strdup((yyvsp[(1) - (4)].id));
                            (yyval.node)->node2 = (yyvsp[(3) - (4)].node);
                            if ((yyval.node)->node1->type != (yyval.node)->node2->type) {
                              if (!((yyval.node)->node1->type == 1 && (yyval.node)->node2->type == 0)) {
                                print_semantic_error((yyval.node)->node1->value, 4);
                              }
                            }
                            free((yyvsp[(1) - (4)].id));
                          }
    break;

  case 40:
#line 373 "lang.y"
    { (yyval.node) = add_node0('V'); 
                            (yyval.node)->value = (char *) strdup((yyvsp[(1) - (1)].id));   
                            (yyval.node)->type = get_id_type((yyvsp[(1) - (1)].id));
                            free((yyvsp[(1) - (1)].id));  
                          }
    break;

  case 41:
#line 378 "lang.y"
    { (yyval.node) = add_node0('I');
                            (yyval.node)->type = 0;
                            (yyval.node)->value = (char *) strdup((yyvsp[(1) - (1)].num));    
                            free((yyvsp[(1) - (1)].num)); 
                          }
    break;

  case 42:
#line 383 "lang.y"
    { (yyval.node) = add_node0('D'); 
                            (yyval.node)->type = 1;
                            (yyval.node)->value = (char *) strdup((yyvsp[(1) - (1)].num));  
                            free((yyvsp[(1) - (1)].num));   
                          }
    break;

  case 43:
#line 388 "lang.y"
    { (yyval.node) = add_node0('S'); 
                            (yyval.node)->type = 2;
                            (yyval.node)->value = (char *) strdup((yyvsp[(1) - (1)].str));  
                            free((yyvsp[(1) - (1)].str));   
                          }
    break;

  case 44:
#line 393 "lang.y"
    { (yyval.node) = add_node0('E');

                            (yyval.node)->node1 = add_node0('V');
                            (yyval.node)->node1->value = (char *) strdup((yyvsp[(1) - (3)].id));
                            (yyval.node)->node1->type = get_id_type((yyvsp[(1) - (3)].id));

                            (yyval.node)->node2 = (yyvsp[(2) - (3)].node);
                            (yyval.node)->node3 = (yyvsp[(3) - (3)].node);
                            build_expression_type((yyval.node));
                            free((yyvsp[(1) - (3)].id));
                          }
    break;

  case 45:
#line 404 "lang.y"
    { (yyval.node) = add_node0('E');

                            (yyval.node)->node1 = add_node0('I');
                            (yyval.node)->node1->type = 0;
                            (yyval.node)->node1->value = (char *) strdup((yyvsp[(1) - (3)].num));

                            (yyval.node)->node2 = (yyvsp[(2) - (3)].node);
                            (yyval.node)->node3 = (yyvsp[(3) - (3)].node);
                            build_expression_type((yyval.node));
                            free((yyvsp[(1) - (3)].num));
                          }
    break;

  case 46:
#line 415 "lang.y"
    { (yyval.node) = add_node0('E');

                            (yyval.node)->node1 = add_node0('D');
                            (yyval.node)->node1->type = 1;
                            (yyval.node)->node1->value = (char *) strdup((yyvsp[(1) - (3)].num));

                            (yyval.node)->node2 = (yyvsp[(2) - (3)].node);
                            (yyval.node)->node3 = (yyvsp[(3) - (3)].node);
                            build_expression_type((yyval.node));
                            free((yyvsp[(1) - (3)].num));
                          }
    break;

  case 47:
#line 426 "lang.y"
    { (yyval.node) = add_node0('E');

                            (yyval.node)->node1 = add_node0('S');
                            (yyval.node)->node1->type = 2;
                            (yyval.node)->node1->value = (char *) strdup((yyvsp[(1) - (3)].str));

                            (yyval.node)->node2 = (yyvsp[(2) - (3)].node);
                            (yyval.node)->node3 = (yyvsp[(3) - (3)].node);
                            build_expression_type((yyval.node));
                            free((yyvsp[(1) - (3)].str));
                          }
    break;

  case 48:
#line 440 "lang.y"
    { (yyval.node) = add_node0('B'); 
          (yyval.node)->value = (char *) strdup("+");     
        }
    break;

  case 49:
#line 443 "lang.y"
    { (yyval.node) = add_node0('B'); 
          (yyval.node)->value = (char *) strdup("-");     
        }
    break;

  case 50:
#line 446 "lang.y"
    { (yyval.node) = add_node0('B'); 
          (yyval.node)->value = (char *) strdup("/");     
        }
    break;

  case 51:
#line 449 "lang.y"
    { (yyval.node) = add_node0('B'); 
          (yyval.node)->value = (char *) strdup("*");     
        }
    break;

  case 52:
#line 455 "lang.y"
    { (yyval.node) = add_node2('C', (yyvsp[(3) - (7)].node), (yyvsp[(6) - (7)].node)); }
    break;

  case 53:
#line 456 "lang.y"
    { (yyval.node) = add_node3('C', (yyvsp[(3) - (11)].node), (yyvsp[(6) - (11)].node), (yyvsp[(10) - (11)].node)); }
    break;

  case 54:
#line 457 "lang.y"
    { (yyval.node) = add_node2('W', (yyvsp[(3) - (7)].node), (yyvsp[(6) - (7)].node)); }
    break;

  case 55:
#line 461 "lang.y"
    { (yyval.node) = add_node0('c');

                    (yyval.node)->node1 = add_node0('V');
                    (yyval.node)->node1->value = (char *) strdup((yyvsp[(1) - (3)].id));
                    (yyval.node)->node1->type = get_id_type((yyvsp[(1) - (3)].id));

                    (yyval.node)->node2 = (yyvsp[(2) - (3)].node);
                    
                    (yyval.node)->node3 = add_node0('V');
                    (yyval.node)->node3->value = (char *) strdup((yyvsp[(3) - (3)].id));
                    (yyval.node)->node3->type = get_id_type((yyvsp[(3) - (3)].id));
                    free((yyvsp[(1) - (3)].id));
                    free((yyvsp[(3) - (3)].id));
                  }
    break;

  case 56:
#line 475 "lang.y"
    { (yyval.node) = add_node0('c');

                    (yyval.node)->node1 = add_node0('V');
                    (yyval.node)->node1->value = (char *) strdup((yyvsp[(1) - (3)].id));
                    (yyval.node)->node1->type = get_id_type((yyvsp[(1) - (3)].id));

                    (yyval.node)->node2 = (yyvsp[(2) - (3)].node);
                    
                    (yyval.node)->node3 = add_node0('I');
                    (yyval.node)->node3->type = 0;
                    (yyval.node)->node3->value = (char *) strdup((yyvsp[(3) - (3)].num));
                    free((yyvsp[(1) - (3)].id));
                    free((yyvsp[(3) - (3)].num));
                  }
    break;

  case 57:
#line 489 "lang.y"
    { (yyval.node) = add_node0('c');

                    (yyval.node)->node1 = add_node0('V');
                    (yyval.node)->node1->value = (char *) strdup((yyvsp[(1) - (3)].id));
                    (yyval.node)->node1->type = get_id_type((yyvsp[(1) - (3)].id));

                    (yyval.node)->node2 = (yyvsp[(2) - (3)].node);
                    
                    (yyval.node)->node3 = add_node0('D');
                    (yyval.node)->node3->type = 1;
                    (yyval.node)->node3->value = (char *) strdup((yyvsp[(3) - (3)].num));
                    free((yyvsp[(1) - (3)].id));
                    free((yyvsp[(3) - (3)].num));
                  }
    break;

  case 58:
#line 503 "lang.y"
    { (yyval.node) = add_node0('c');

                    (yyval.node)->node1 = add_node0('I');
                    (yyval.node)->node1->type = 0;
                    (yyval.node)->node1->value = (char *) strdup((yyvsp[(1) - (3)].num));

                    (yyval.node)->node2 = (yyvsp[(2) - (3)].node);
                    
                    (yyval.node)->node3 = add_node0('V');
                    (yyval.node)->node3->value = (char *) strdup((yyvsp[(3) - (3)].id));
                    (yyval.node)->node3->type = get_id_type((yyvsp[(3) - (3)].id));
                    free((yyvsp[(1) - (3)].num));
                    free((yyvsp[(3) - (3)].id));
                  }
    break;

  case 59:
#line 517 "lang.y"
    { (yyval.node) = add_node0('c');

                    (yyval.node)->node1 = add_node0('I');
                    (yyval.node)->node1->type = 0;
                    (yyval.node)->node1->value = (char *) strdup((yyvsp[(1) - (3)].num));

                    (yyval.node)->node2 = (yyvsp[(2) - (3)].node);
                    
                    (yyval.node)->node3 = add_node0('I');
                    (yyval.node)->node3->type = 0;
                    (yyval.node)->node3->value = (char *) strdup((yyvsp[(3) - (3)].num));
                    free((yyvsp[(1) - (3)].num));
                    free((yyvsp[(3) - (3)].num));
                  }
    break;

  case 60:
#line 531 "lang.y"
    { (yyval.node) = add_node0('c');

                    (yyval.node)->node1 = add_node0('I');
                    (yyval.node)->node1->type = 0;
                    (yyval.node)->node1->value = (char *) strdup((yyvsp[(1) - (3)].num));

                    (yyval.node)->node2 = (yyvsp[(2) - (3)].node);
                    
                    (yyval.node)->node3 = add_node0('D');
                    (yyval.node)->node3->type = 1;
                    (yyval.node)->node3->value = (char *) strdup((yyvsp[(3) - (3)].num));
                    free((yyvsp[(1) - (3)].num));
                    free((yyvsp[(3) - (3)].num));
                  }
    break;

  case 61:
#line 545 "lang.y"
    { (yyval.node) = add_node0('c');

                    (yyval.node)->node1 = add_node0('D');
                    (yyval.node)->node1->type = 2;
                    (yyval.node)->node1->value = (char *) strdup((yyvsp[(1) - (3)].num));

                    (yyval.node)->node2 = (yyvsp[(2) - (3)].node);
                    
                    (yyval.node)->node3 = add_node0('V');
                    (yyval.node)->node3->value = (char *) strdup((yyvsp[(3) - (3)].id));
                    (yyval.node)->node3->type = get_id_type((yyvsp[(3) - (3)].id));
                    free((yyvsp[(1) - (3)].num));
                    free((yyvsp[(3) - (3)].id));
                  }
    break;

  case 62:
#line 559 "lang.y"
    { (yyval.node) = add_node0('c');

                    (yyval.node)->node1 = add_node0('D');
                    (yyval.node)->node1->type = 2;
                    (yyval.node)->node1->value = (char *) strdup((yyvsp[(1) - (3)].num));

                    (yyval.node)->node2 = (yyvsp[(2) - (3)].node);
                    
                    (yyval.node)->node3 = add_node0('I');
                    (yyval.node)->node3->type = 1;
                    (yyval.node)->node3->value = (char *) strdup((yyvsp[(3) - (3)].num));
                    free((yyvsp[(1) - (3)].num));
                    free((yyvsp[(3) - (3)].num));
                  }
    break;

  case 63:
#line 573 "lang.y"
    { (yyval.node) = add_node0('c');

                    (yyval.node)->node1 = add_node0('D');
                    (yyval.node)->node1->type = 2;
                    (yyval.node)->node1->value = (char *) strdup((yyvsp[(1) - (3)].num));

                    (yyval.node)->node2 = (yyvsp[(2) - (3)].node);
                    
                    (yyval.node)->node3 = add_node0('D');
                    (yyval.node)->node3->type = 2;
                    (yyval.node)->node3->value = (char *) strdup((yyvsp[(3) - (3)].num));
                    free((yyvsp[(1) - (3)].num));
                    free((yyvsp[(3) - (3)].num));
                  }
    break;

  case 64:
#line 590 "lang.y"
    { (yyval.node) = add_node0('B'); 
          (yyval.node)->value = (char *) strdup("CGE");     
        }
    break;

  case 65:
#line 593 "lang.y"
    { (yyval.node) = add_node0('B'); 
          (yyval.node)->value = (char *) strdup("CGT");     
        }
    break;

  case 66:
#line 596 "lang.y"
    { (yyval.node) = add_node0('B'); 
          (yyval.node)->value = (char *) strdup("CLE");     
        }
    break;

  case 67:
#line 599 "lang.y"
    { (yyval.node) = add_node0('B'); 
          (yyval.node)->value = (char *) strdup("CLT");     
        }
    break;

  case 68:
#line 602 "lang.y"
    { (yyval.node) = add_node0('B'); 
          (yyval.node)->value = (char *) strdup("CNE");     
        }
    break;

  case 69:
#line 605 "lang.y"
    { (yyval.node) = add_node0('B'); 
          (yyval.node)->value = (char *) strdup("CEQ");     
        }
    break;

  case 70:
#line 611 "lang.y"
    { (yyval.node) = add_node0('L');
                            (yyval.node)->value = (char *) strdup("PRINT");
                            (yyval.node)->node1 = add_node0('V');
                            (yyval.node)->node1->value = (char *) strdup((yyvsp[(3) - (5)].id)); 
                            (yyval.node)->node1->type = get_id_type((yyvsp[(3) - (5)].id));
                            free((yyvsp[(3) - (5)].id));    
                          }
    break;

  case 71:
#line 618 "lang.y"
    { (yyval.node) = add_node0('L');
                            (yyval.node)->value = (char *) strdup("PRINT");
                            (yyval.node)->node1 = add_node0('S');
                            (yyval.node)->node1->type = 2;
                            (yyval.node)->node1->value = (char *) strdup((yyvsp[(3) - (5)].str)); 
                            free((yyvsp[(3) - (5)].str));    
                          }
    break;

  case 72:
#line 625 "lang.y"
    { (yyval.node) = add_node0('L');
                            (yyval.node)->value = (char *) strdup("PRINT");
                            (yyval.node)->node1 = add_node0('I');
                            (yyval.node)->node1->type = 0;
                            (yyval.node)->node1->value = (char *) strdup((yyvsp[(3) - (5)].num)); 
                            free((yyvsp[(3) - (5)].num));    
                          }
    break;

  case 73:
#line 632 "lang.y"
    { (yyval.node) = add_node0('L');
                            (yyval.node)->value = (char *) strdup("PRINT");
                            (yyval.node)->node1 = add_node0('D');
                            (yyval.node)->node1->type = 1;
                            (yyval.node)->node1->value = (char *) strdup((yyvsp[(3) - (5)].num));     
                            free((yyvsp[(3) - (5)].num));
                          }
    break;

  case 74:
#line 642 "lang.y"
    { (yyval.node) = add_node0('L');
                                          (yyval.node)->type = 0;
                                          (yyval.node)->value = (char *) strdup("SCAN");
                                          (yyval.node)->node1 = add_node0('V');
                                          (yyval.node)->node1->value = (char *) strdup((yyvsp[(3) - (7)].id));   
                                          (yyval.node)->node1->type = get_id_type((yyvsp[(3) - (7)].id));
                                          if ((yyval.node)->type != (yyval.node)->node1->type) {
                                            print_semantic_error((yyval.node)->node1->value, 6);
                                          }
                                          free((yyvsp[(3) - (7)].id));  
                                          free((yyvsp[(5) - (7)].type));  
                                        }
    break;

  case 75:
#line 654 "lang.y"
    { (yyval.node) = add_node0('L');
                                          (yyval.node)->type = 1;
                                          (yyval.node)->value = (char *) strdup("SCAN");
                                          (yyval.node)->node1 = add_node0('V');
                                          (yyval.node)->node1->value = (char *) strdup((yyvsp[(3) - (7)].id)); 
                                          (yyval.node)->node1->type = get_id_type((yyvsp[(3) - (7)].id)); 
                                          if ((yyval.node)->type != (yyval.node)->node1->type) {
                                            print_semantic_error((yyval.node)->node1->value, 6);
                                          }
                                          free((yyvsp[(3) - (7)].id));  
                                          free((yyvsp[(5) - (7)].type));     
                                        }
    break;

  case 76:
#line 666 "lang.y"
    { (yyval.node) = add_node0('L');
                                          (yyval.node)->type = 2;
                                          (yyval.node)->value = (char *) strdup("SCAN");
                                          (yyval.node)->node1 = add_node0('V');
                                          (yyval.node)->node1->value = (char *) strdup((yyvsp[(3) - (7)].id)); 
                                          (yyval.node)->node1->type = get_id_type((yyvsp[(3) - (7)].id)); 
                                          if ((yyval.node)->type != (yyval.node)->node1->type) {
                                            print_semantic_error((yyval.node)->node1->value, 6);
                                          }
                                          free((yyvsp[(3) - (7)].id));  
                                          free((yyvsp[(5) - (7)].type));     
                                        }
    break;

  case 77:
#line 681 "lang.y"
    { (yyval.node) = add_node0('L');
                            struct scope* scope = get_last_scope();
                            (yyval.node)->type  = scope->type;
                            (yyval.node)->value = (char *) strdup("RETURN");
                            (yyval.node)->node1 = add_node0('V');
                            (yyval.node)->node1->value = (char *) strdup((yyvsp[(3) - (5)].id));   
                            (yyval.node)->node1->type = get_id_type((yyvsp[(3) - (5)].id)); 
                            if ((yyval.node)->type != (yyval.node)->node1->type) {
                              print_semantic_error((yyval.node)->node1->value, 5);
                            }
                            hasReturn = 1;
                            free((yyvsp[(3) - (5)].id)); 
                          }
    break;

  case 78:
#line 694 "lang.y"
    { (yyval.node) = add_node0('L');
                            struct scope* scope = get_last_scope();
                            (yyval.node)->type  = scope->type;
                            (yyval.node)->value = (char *) strdup("RETURN");
                            (yyval.node)->node1 = add_node0('S');
                            (yyval.node)->node1->type = 2;
                            (yyval.node)->node1->value = (char *) strdup((yyvsp[(3) - (5)].str)); 
                            if ((yyval.node)->type != (yyval.node)->node1->type) {
                              print_semantic_error((yyval.node)->node1->value, 5);
                            } 
                            hasReturn = 1;
                            free((yyvsp[(3) - (5)].str));   
                          }
    break;

  case 79:
#line 707 "lang.y"
    { (yyval.node) = add_node0('L');
                            struct scope* scope = get_last_scope();
                            (yyval.node)->type  = scope->type;
                            (yyval.node)->value = (char *) strdup("RETURN");
                            (yyval.node)->node1 = add_node0('I');
                            (yyval.node)->node1->type = 0;
                            (yyval.node)->node1->value = (char *) strdup((yyvsp[(3) - (5)].num));  
                            if ((yyval.node)->type != (yyval.node)->node1->type) {
                              print_semantic_error((yyval.node)->node1->value, 5);
                            }
                            hasReturn = 1;
                            free((yyvsp[(3) - (5)].num));   
                          }
    break;

  case 80:
#line 720 "lang.y"
    { (yyval.node) = add_node0('L');
                            struct scope* scope = get_last_scope();
                            (yyval.node)->type  = scope->type;
                            (yyval.node)->value = (char *) strdup("RETURN");
                            (yyval.node)->node1 = add_node0('D');
                            (yyval.node)->node1->type = 1;
                            (yyval.node)->node1->value = (char *) strdup((yyvsp[(3) - (5)].num));  
                            if ((yyval.node)->type != (yyval.node)->node1->type) {
                              print_semantic_error((yyval.node)->node1->value, 5);
                            }
                            hasReturn = 1;
                            free((yyvsp[(3) - (5)].num));   
                          }
    break;

  case 81:
#line 736 "lang.y"
    { (yyval.node) = add_node1('L', (yyvsp[(3) - (5)].node));
                                            (yyval.node)->value = (char *) strdup((yyvsp[(1) - (5)].id));  
                                            (yyval.node)->type = get_id_type((yyvsp[(1) - (5)].id));
                                            free((yyvsp[(1) - (5)].id));  
                                          }
    break;

  case 82:
#line 741 "lang.y"
    { (yyval.node) = add_node0('A');
                                            (yyval.node)->node1 = add_node0('V');
                                            (yyval.node)->node1->value = (char *) strdup((yyvsp[(1) - (7)].id));
                                            (yyval.node)->node1->type = get_id_type((yyvsp[(1) - (7)].id));
                                            (yyval.node)->node2 = add_node1('L', (yyvsp[(5) - (7)].node));
                                            (yyval.node)->node2->value = (char *) strdup((yyvsp[(3) - (7)].id)); 
                                            (yyval.node)->node2->type = get_id_type((yyvsp[(3) - (7)].id));

                                            if ((yyval.node)->node1->type != (yyval.node)->node2->type) {
                                              if (!((yyval.node)->node1->type == 1 && (yyval.node)->node2->type == 0)) {
                                                print_semantic_error((yyval.node)->node1->value, 4);
                                              }
                                            }


                                            free((yyvsp[(1) - (7)].id));  
                                            free((yyvsp[(3) - (7)].id));     
                                          }
    break;

  case 83:
#line 759 "lang.y"
    { (yyval.node) = add_node0('L');
                                            (yyval.node)->value = (char *) strdup((yyvsp[(1) - (4)].id));  
                                            (yyval.node)->type = get_id_type((yyvsp[(1) - (4)].id));
                                            free((yyvsp[(1) - (4)].id));  
                                          }
    break;

  case 84:
#line 764 "lang.y"
    { (yyval.node) = add_node0('A');
                                            (yyval.node)->node1 = add_node0('V');
                                            (yyval.node)->node1->value = (char *) strdup((yyvsp[(1) - (6)].id));
                                            (yyval.node)->node1->type = get_id_type((yyvsp[(1) - (6)].id));
                                            (yyval.node)->node2 = add_node0('L');
                                            (yyval.node)->node2->value = (char *) strdup((yyvsp[(3) - (6)].id)); 
                                            (yyval.node)->node2->type = get_id_type((yyvsp[(3) - (6)].id));

                                            if ((yyval.node)->node1->type != (yyval.node)->node2->type) {
                                              if (!((yyval.node)->node1->type == 1 && (yyval.node)->node2->type == 0)) {
                                                print_semantic_error((yyval.node)->node1->value, 4);
                                              }
                                            }


                                            free((yyvsp[(1) - (6)].id));  
                                            free((yyvsp[(3) - (6)].id));     
                                          }
    break;

  case 85:
#line 785 "lang.y"
    { (yyval.node) = add_node0('V');
                                (yyval.node)->value = (char *) strdup((yyvsp[(1) - (1)].id)); 
                                (yyval.node)->type = get_id_type((yyvsp[(1) - (1)].id));  
                                free((yyvsp[(1) - (1)].id));  
                              }
    break;

  case 86:
#line 790 "lang.y"
    { (yyval.node) = add_node0('I');
                                (yyval.node)->type = 0;
                                (yyval.node)->value = (char *) strdup((yyvsp[(1) - (1)].num));  
                                free((yyvsp[(1) - (1)].num));   
                              }
    break;

  case 87:
#line 795 "lang.y"
    { (yyval.node) = add_node0('D');
                                (yyval.node)->type = 1;
                                (yyval.node)->value = (char *) strdup((yyvsp[(1) - (1)].num));    
                                free((yyvsp[(1) - (1)].num)); 
                              }
    break;

  case 88:
#line 800 "lang.y"
    { (yyval.node) = add_node0('S');
                                (yyval.node)->type = 2;
                                (yyval.node)->value = (char *) strdup((yyvsp[(1) - (1)].str));    
                                free((yyvsp[(1) - (1)].str)); 
                              }
    break;

  case 89:
#line 805 "lang.y"
    { (yyval.node) = add_node0('R');

                                (yyval.node)->node1 = add_node0('V');
                                (yyval.node)->node1->value = (char *) strdup((yyvsp[(1) - (3)].id));    
                                (yyval.node)->node1->type = get_id_type((yyvsp[(1) - (3)].id)); 

                                (yyval.node)->node2 = (yyvsp[(3) - (3)].node);
                                free((yyvsp[(1) - (3)].id));
                              }
    break;

  case 90:
#line 814 "lang.y"
    { (yyval.node) = add_node0('R');

                                (yyval.node)->node1 = add_node0('I');
                                (yyval.node)->node1->type = 0;
                                (yyval.node)->node1->value = (char *) strdup((yyvsp[(1) - (3)].num)); 

                                (yyval.node)->node2 = (yyvsp[(3) - (3)].node);  
                                free((yyvsp[(1) - (3)].num));  
                              }
    break;

  case 91:
#line 823 "lang.y"
    { (yyval.node) = add_node0('R');

                                (yyval.node)->node1 = add_node0('D');
                                (yyval.node)->node1->type = 1;
                                (yyval.node)->node1->value = (char *) strdup((yyvsp[(1) - (3)].num));  

                                (yyval.node)->node2 = (yyvsp[(3) - (3)].node);
                                free((yyvsp[(1) - (3)].num));   
                              }
    break;

  case 92:
#line 832 "lang.y"
    { (yyval.node) = add_node0('R');

                                (yyval.node)->node1 = add_node0('S');
                                (yyval.node)->node1->type = 2;
                                (yyval.node)->node1->value = (char *) strdup((yyvsp[(1) - (3)].str));     

                                (yyval.node)->node2 = (yyvsp[(3) - (3)].node);
                                free((yyvsp[(1) - (3)].str));
                              }
    break;


/* Line 1267 of yacc.c.  */
#line 2683 "y.tab.c"
      default: break;
    }
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;
  *++yylsp = yyloc;

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
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
      {
	YYSIZE_T yysize = yysyntax_error (0, yystate, yychar);
	if (yymsg_alloc < yysize && yymsg_alloc < YYSTACK_ALLOC_MAXIMUM)
	  {
	    YYSIZE_T yyalloc = 2 * yysize;
	    if (! (yysize <= yyalloc && yyalloc <= YYSTACK_ALLOC_MAXIMUM))
	      yyalloc = YYSTACK_ALLOC_MAXIMUM;
	    if (yymsg != yymsgbuf)
	      YYSTACK_FREE (yymsg);
	    yymsg = (char *) YYSTACK_ALLOC (yyalloc);
	    if (yymsg)
	      yymsg_alloc = yyalloc;
	    else
	      {
		yymsg = yymsgbuf;
		yymsg_alloc = sizeof yymsgbuf;
	      }
	  }

	if (0 < yysize && yysize <= yymsg_alloc)
	  {
	    (void) yysyntax_error (yymsg, yystate, yychar);
	    yyerror (yymsg);
	  }
	else
	  {
	    yyerror (YY_("syntax error"));
	    if (yysize != 0)
	      goto yyexhaustedlab;
	  }
      }
#endif
    }

  yyerror_range[0] = yylloc;

  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse look-ahead token after an
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
		      yytoken, &yylval, &yylloc);
	  yychar = YYEMPTY;
	}
    }

  /* Else will try to reuse look-ahead token after shifting the error
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

  yyerror_range[0] = yylsp[1-yylen];
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
      if (yyn != YYPACT_NINF)
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

      yyerror_range[0] = *yylsp;
      yydestruct ("Error: popping",
		  yystos[yystate], yyvsp, yylsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  *++yyvsp = yylval;

  yyerror_range[1] = yylloc;
  /* Using YYLLOC is tempting, but would change the location of
     the look-ahead.  YYLOC is available though.  */
  YYLLOC_DEFAULT (yyloc, (yyerror_range - 1), 2);
  *++yylsp = yyloc;

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

#ifndef yyoverflow
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEOF && yychar != YYEMPTY)
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval, &yylloc);
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp, yylsp);
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


#line 843 "lang.y"


int main(int argc, char **argv) {
  ++argv, --argc;
  if(argc > 0)
      yyin = fopen( argv[0], "r" );
  else
      yyin = stdin;
  
  printf("\n\n########## Parser Sintatico ##########\n");
  yyparse();
  printf("\n\n########## Arvore Sintatica ##########\n");
  print_tree(tree, 0);
  printf("\n\n########## Tabela de Símbolos ##########\n");
  print_symbol_table();
  printf("\n\n########## Tabela de Parametros ##########\n");
  print_func_table();


  yylex_destroy();
  free_tree(tree);
  free_symbol_table();
  free_func_table();
  return 0;
}

struct node* add_node3(char node_type, struct node *node1, struct node *node2, struct node *node3){
  struct node* node = (struct node*)calloc(1, sizeof(struct node));

  node->node_type = node_type;
  node->node1 = node1;
  node->node2 = node2;
  node->node3 = node3;
  node->type = 3;

  return node;
}

struct node* add_node2(char node_type, struct node *node1, struct node *node2){
  struct node* node = (struct node*)calloc(1, sizeof(struct node));

  node->node_type = node_type;
  node->node1 = node1;
  node->node2 = node2;
  node->type = 3;

  return node;
}

struct node* add_node1(char node_type, struct node *node1){
  struct node* node = (struct node*)calloc(1, sizeof(struct node));

  node->node_type = node_type;
  node->node1 = node1;
  node->type = 3;

  return node;
}

struct node* add_node0(char node_type){
  struct node* node = (struct node*)calloc(1, sizeof(struct node));

  node->node_type = node_type;
  node->type = 3;

  return node;
}

void print_tree(struct node *node, int depth) {
  int i;

  if(node == NULL) return;

  if(node->node_type == 'R') {
    print_tree(node->node1, depth);
    print_tree(node->node2, depth);
    print_tree(node->node3, depth);
    return;
  }

  // printf("profundidade: %d\t", depth);
  for(i=0;i<depth;i++)  {
    printf("-");
  }


  switch (node->node_type) {
    case 'V':
      printf("<Variavel> %s, tipo: %d\n", node->value, node->type);
      print_tree(node->node1, depth+1);
      break;
    case 'v':
      printf("<Declaração de Variavel> %s, tipo: %d\n", node->value, node->type);
      print_tree(node->node1, depth+1);
      break;
    case 'A':
      printf("<Atribuição> (tipo: %d) %s = \n", node->type, node->node1->value);
      print_tree(node->node2, depth+1);
      break;
    case 'I':
      printf("<Inteiro> %s\n", node->value);
      break;
    case 'D':
      printf("<Decimal> %s\n", node->value);
      break;
    case 'S':
      printf("<String> %s\n", node->value);
      break;
    case 'P':
      printf("<Parametro> %s, tipo: %d\n", node->value, node->type);
      break;
    case 'B':
      printf("<Simbolo> %s\n", node->value);
      break;
    case 'F':
      printf("<Função> %s, tipo: %d\n", node->value, node->type);

      for(i=0;i<depth;i++)  {
        printf("-");
      }
      printf("INICIO PARAMETROS\n");
      print_tree(node->node1, depth+1);
      for(i=0;i<depth;i++)  {
        printf("-");
      }
      printf("FIM PARAMETROS\n");

      for(i=0;i<depth;i++)  {
        printf("-");
      }
      printf("INICIO FUNÇÃO -  %s\n", node->value);
      print_tree(node->node2, depth+1);
      for(i=0;i<depth;i++)  {
        printf("-");
      }
      printf("FIM FUNÇÃO - %s\n\n", node->value);
      break;
    case 'E':
      printf("<EXPRESSION> tipo: %d\n", node->type);
      print_tree(node->node1, depth);
      print_tree(node->node2, depth+1);
      print_tree(node->node3, depth+1);
      break;
    case 'C':
      printf("<IF>\n");

      for(i=0;i<depth;i++)  {
        printf("-");
      }
      printf("IF - INICIO CONDIÇÃO\n");
      print_tree(node->node1, depth+1);
      for(i=0;i<depth;i++)  {
        printf("-");
      }
      printf("IF - FIM CONDIÇÃO\n");

      for(i=0;i<depth;i++)  {
        printf("-");
      }
      printf("IF - INICIO BLOCO\n");
      print_tree(node->node2, depth+1);
      for(i=0;i<depth;i++)  {
        printf("-");
      }
      printf("IF - FIM BLOCO\n");
      if (node->node3) {
        printf("ELSE - INICIO BLOCO\n");
        print_tree(node->node3, depth+1);
        for(i=0;i<depth;i++)  {
          printf("-");
        }
        printf("ELSE - FIM BLOCO\n");
      }
      break;
    case 'W':
      printf("<WHILE>\n");

      for(i=0;i<depth;i++)  {
        printf("-");
      }
      printf("WHILE - INICIO CONDIÇÃO\n");
      print_tree(node->node1, depth+1);
      for(i=0;i<depth;i++)  {
        printf("-");
      }
      printf("WHILE - FIM CONDIÇÃO\n");

      for(i=0;i<depth;i++)  {
        printf("-");
      }
      printf("WHILE - INICIO BLOCO\n");
      print_tree(node->node2, depth+1);
      for(i=0;i<depth;i++)  {
        printf("-");
      }
      printf("WHILE - FIM BLOCO\n");
      break;
    case 'c':
      printf("<CONDIÇÃO>\n");
      print_tree(node->node1, depth);
      print_tree(node->node2, depth);
      print_tree(node->node3, depth);
      break;
    case 'L':
      if (strcmp(node->value, "PRINT") == 0) {
        printf("<PRINT>\n");
        print_tree(node->node1, depth+1);
      } else if (strcmp(node->value, "SCAN") == 0) {
        printf("<SCAN> tipo: %d\n", node->type);
        print_tree(node->node1, depth+1);
      } else if (strcmp(node->value, "RETURN") == 0) {
        printf("<RETURN> tipo: %d\n", node->type);
        print_tree(node->node1, depth+1);
      } else {
        printf("<CHAMA FUNÇÃO> %s\n", node->value);
        for(i=0;i<depth;i++)  {
          printf("-");
        }
        printf("INICIO PARAMETROS\n");
        print_tree(node->node1, depth+1);
        for(i=0;i<depth;i++)  {
          printf("-");
        }
        printf("FIM PARAMETROS\n");
      }
      break;
    defaut:
      break;
  }
}

void add_func_params(char *id) {
  struct func_params* func_params = (struct func_params*)calloc(1, sizeof(struct func_params));
  char* func_name = (char *) strdup(id);
  func_params->func_name = (char *) strdup(id);
  func_params->n_params = 0;

  HASH_ADD_STR(func_table, func_name, func_params);
  free(func_name);
}

void add_params(int type) {
  struct params* new_params = (struct params*)calloc(1, sizeof(struct params));
  struct params* params;
  struct func_params* func_params;
  new_params->type = type;

  struct scope* last_scope;
  last_scope = get_last_scope();

  HASH_FIND_STR(func_table, last_scope->scope_name, func_params);

  func_params->n_params = func_params->n_params + 1;

  params = func_params->first;
  if (params == NULL) {
    func_params->first = new_params;
  } else {
    while(params->next != NULL) {
      params = params->next;
    }
    params->next = new_params;
  }
}

void print_func_table() {
  struct func_params *s;
  for(s=func_table; s != NULL; s=s->hh.next) {
    printf("funcao: %s, numero de parametros: %d\n", s->func_name, s->n_params);
    if (s->first) {
      print_params(s->first, 1);
    }
  }
}
void print_params(struct params *params, int count) {
  printf("-- PARAMETRO %d, tipo: %d\n", count, params->type);
  if (params->next) {
    print_params(params->next, count + 1);
  }
}

void free_func_table() {
  struct func_params *s;
  for(s=func_table; s != NULL; s=s->hh.next) {
    free(s->func_name);
    if (s->first) {
      free_params(s->first);
    }
  }
}
void free_params(struct params *params) {
  if (params != NULL) {
    free_params(params->next);
    free(params);
  }
}

void add_symbol_table(char *id, int type) {
  struct symbol_node* symbol_node = (struct symbol_node*)calloc(1, sizeof(struct symbol_node));

  struct symbol_node* symbol_node_check;
  symbol_node_check = find_symbol_table(id);
  if (symbol_node_check != NULL) {
    print_semantic_error(id, 9);
  }

  struct scope* last_scope;
  last_scope = get_last_scope();
  char* key;

  key = generate_symbol_key(id);
  symbol_node->id = (char *) strdup(id);
  symbol_node->type = type;
  symbol_node->key = (char *) strdup(key);
  if (last_scope != NULL && last_scope->scope_name != NULL) {
    symbol_node->scope_name = (char *) strdup(last_scope->scope_name);
  }

  free(key);




  HASH_ADD_STR(symbol_table, key, symbol_node);
}

struct symbol_node* find_symbol_table(char *id) {
  struct symbol_node* symbol_node;
  char* key;

  key = generate_symbol_key(id);
  HASH_FIND_STR(symbol_table, key, symbol_node);
  if (symbol_node == NULL) {
    free(key);
    int size = 2;
    size += strlen(id);
    key = malloc(size);
    strcpy(key, "@");
    strcat(key, id);
    HASH_FIND_STR(symbol_table, key, symbol_node);
  }

  if (symbol_node == NULL) {
    return NULL;
  }

  free(key);
  return symbol_node;
}

int get_id_type(char *id) {
  struct symbol_node* symbol_node;
  symbol_node = find_symbol_table(id);
  if (symbol_node == NULL) {
    print_semantic_error(id, 1);
  }
  return symbol_node->type;
}

char* generate_symbol_key(char *id) {
  struct scope* last_scope;
  last_scope = get_last_scope();
  char* key;
  int size = 2;
  size += strlen(id);

  if (last_scope != NULL && last_scope->scope_name != NULL) {
    size += strlen(last_scope->scope_name);
  }
  if (last_scope != NULL && last_scope->scope_name != NULL) {
    key = malloc(size);
    strcpy(key, last_scope->scope_name);
    strcat(key, "@");
  } else {
    key = malloc(size);
    strcpy(key, "@");
  }
  strcat(key, id);
  
  return key;
}

void print_symbol_table() {
  struct symbol_node *s;
  for(s=symbol_table; s != NULL; s=s->hh.next) {
    if (s->scope_name) {
      printf("Simbolo: %s, Tipo: %d, Scopo: %s, key: %s\n", s->id, s->type, s->scope_name, s->key);
    } else {
      printf("Simbolo: %s, Tipo: %d, Scopo: Global, key: %s\n", s->id, s->type, s->key);
    }
  }
  printf("\n");
}

void free_symbol_table() {
  struct symbol_node *s, *tmp;

  HASH_ITER(hh, symbol_table, s, tmp) {
    HASH_DEL(symbol_table, s);
    if (s->scope_name != NULL) {
      free(s->scope_name);
    }
    if (s->key != NULL) {
      free(s->key);
    }
    if (s != NULL) {
      free(s);
    }
  }
}

void free_tree(struct node *node) {
  if(node == NULL) return;

  free_tree(node->node1);
  free_tree(node->node2);
  free_tree(node->node3);

  node->node1 = NULL;
  node->node2 = NULL;
  node->node3 = NULL;

  if (node->value) {
    free(node->value);
  }
  free(node);
}

void add_scope(char* scope_name, int type) {
  struct scope* new_scope = (struct scope*)calloc(1, sizeof(struct scope));
  struct scope* last_scope;

  new_scope->type = type;
  new_scope->scope_name = (char *) strdup(scope_name);

  last_scope = get_last_scope();
  if (last_scope == NULL) {
    scope_stack = new_scope;
  } else {
    last_scope->next = new_scope;
  }
}

struct scope* get_last_scope() {
  struct scope* scope;
  scope = scope_stack;

  if (scope == NULL) {
    return scope;
  }

  if (scope->next == NULL) {
    return scope;
  }

  while(scope->next != NULL) {
    scope = scope->next;
  }

  return scope;
}

void remove_scope() {
  struct scope* scope;
  scope = scope_stack;

  if (scope == NULL) {
    return;
  }

  if (scope->next == NULL) {
    scope_stack = NULL;
    free(scope->scope_name);
    free(scope);
    return;
  }

  while(scope->next->next != NULL) {
    scope = scope->next;
  }
  
  if (scope->next && scope->next->scope_name) {
    free(scope->next->scope_name);
  }
  if (scope->next) {
    free(scope->next);
  }
  scope->next = NULL;
}

void print_semantic_error(char *id, int type) {
   printf("\n######## ERRO ########\n");
  switch (type) {
    // 1) Utilização de uma variável não declarada.
    case 1: 
      printf("Variavel %s não foi declarada, linha: %d\n", id, line);
      break;
    // Utilização de qualquer símbolo diferente de "+" em uma operação entre strings.
    case 2: 
      printf("Operações entre strings só aceitam o operador de concatenação (+), linha: %d\n", line);
      break;
    // Qualquer operação entre uma string e uma variável/valor do tipo inteiro ou float.
    case 3: 
      printf("Strings só podem fazer operações com outras strings, linha: %d\n", line);
      break;
    // Atribuir um valor incorreto a variavel
    case 4: 
      printf("A variavel %s deve receber um valor de  tipo compatível, linha: %d\n", id, line);
      break;
    // Retorno de funcao
    case 5: 
      printf("O retorno %s não corresponde ao tipo da função, linha: %d\n", id, line);
      break;
    // Scan
    case 6: 
      printf("O scan da variavel %s não corresponde ao tipo da função, linha: %d\n", id, line);
      break;
    // main
    case 7: 
      printf("O programa não possui uma função main do tipo inteiro\n");
      break;
    // possui return
    case 8: 
      printf("A função %s, não possui return\n", id);
      break;
    // variável já existe
    case 9: 
      printf("ID %s, já foi declarado, linha: %d\n", id, line);
      break;

  }
  exit(1);
}

void build_expression_type(struct node *node) {
  if (node->node1->type == node->node3->type) {
    node->type = node->node1->type;
    if (node->node1->type == 2 && node->node3->type == 2 && strcmp(node->node2->value, "+") != 0) {
      print_semantic_error(node->node1->value, 2);
    }
  } else if (node->node1->type == 2) {
    print_semantic_error(node->node1->value, 3);
  } else if (node->node3->type == 2) {
    print_semantic_error(node->node3->value, 3);
  } else {
    node->type = 1;
  }
}

void yyerror (char *s) {fprintf (stderr, "%s, linha: %d\n", s,line); exit(1);} 
