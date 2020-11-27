/* A Bison parser, made by GNU Bison 3.7.4.  */

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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30704

/* Bison version string.  */
#define YYBISON_VERSION "3.7.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 5 "lang.y"

void yyerror (const char *s);
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

struct current_params {
  struct params *first;
  int n_params; // numero de parametros 
};
struct current_params *current_params;


void add_func_params(char *id);
void add_params(int type);
void print_func_table();
void print_params(struct params *params, int count);
void free_func_table();
void free_params(struct params *params);
void add_current_params(int type);
void free_current_params();
void compare_params(char *id);

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


#line 194 "lang.tab.c"

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

#include "lang.tab.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_ID = 3,                         /* ID  */
  YYSYMBOL_TYPEINT = 4,                    /* TYPEINT  */
  YYSYMBOL_TYPEFLOAT = 5,                  /* TYPEFLOAT  */
  YYSYMBOL_TYPESTRING = 6,                 /* TYPESTRING  */
  YYSYMBOL_INT = 7,                        /* INT  */
  YYSYMBOL_DEC = 8,                        /* DEC  */
  YYSYMBOL_STR = 9,                        /* STR  */
  YYSYMBOL_WHILE = 10,                     /* WHILE  */
  YYSYMBOL_IF = 11,                        /* IF  */
  YYSYMBOL_ELSE = 12,                      /* ELSE  */
  YYSYMBOL_RETURN = 13,                    /* RETURN  */
  YYSYMBOL_PRINT = 14,                     /* PRINT  */
  YYSYMBOL_SCAN = 15,                      /* SCAN  */
  YYSYMBOL_CGE = 16,                       /* CGE  */
  YYSYMBOL_CGT = 17,                       /* CGT  */
  YYSYMBOL_CLE = 18,                       /* CLE  */
  YYSYMBOL_CLT = 19,                       /* CLT  */
  YYSYMBOL_CNE = 20,                       /* CNE  */
  YYSYMBOL_CEQ = 21,                       /* CEQ  */
  YYSYMBOL_22_ = 22,                       /* ';'  */
  YYSYMBOL_23_ = 23,                       /* '='  */
  YYSYMBOL_24_ = 24,                       /* '('  */
  YYSYMBOL_25_ = 25,                       /* ')'  */
  YYSYMBOL_26_ = 26,                       /* '{'  */
  YYSYMBOL_27_ = 27,                       /* '}'  */
  YYSYMBOL_28_ = 28,                       /* ','  */
  YYSYMBOL_29_ = 29,                       /* '+'  */
  YYSYMBOL_30_ = 30,                       /* '-'  */
  YYSYMBOL_31_ = 31,                       /* '/'  */
  YYSYMBOL_32_ = 32,                       /* '*'  */
  YYSYMBOL_YYACCEPT = 33,                  /* $accept  */
  YYSYMBOL_prog = 34,                      /* prog  */
  YYSYMBOL_globalList = 35,                /* globalList  */
  YYSYMBOL_var = 36,                       /* var  */
  YYSYMBOL_func = 37,                      /* func  */
  YYSYMBOL_38_1 = 38,                      /* $@1  */
  YYSYMBOL_39_2 = 39,                      /* $@2  */
  YYSYMBOL_40_3 = 40,                      /* $@3  */
  YYSYMBOL_41_4 = 41,                      /* $@4  */
  YYSYMBOL_42_5 = 42,                      /* $@5  */
  YYSYMBOL_43_6 = 43,                      /* $@6  */
  YYSYMBOL_paramsList = 44,                /* paramsList  */
  YYSYMBOL_params = 45,                    /* params  */
  YYSYMBOL_param = 46,                     /* param  */
  YYSYMBOL_contentList = 47,               /* contentList  */
  YYSYMBOL_content = 48,                   /* content  */
  YYSYMBOL_addValue = 49,                  /* addValue  */
  YYSYMBOL_expression = 50,                /* expression  */
  YYSYMBOL_op = 51,                        /* op  */
  YYSYMBOL_comand = 52,                    /* comand  */
  YYSYMBOL_condition = 53,                 /* condition  */
  YYSYMBOL_cond = 54,                      /* cond  */
  YYSYMBOL_print = 55,                     /* print  */
  YYSYMBOL_scan = 56,                      /* scan  */
  YYSYMBOL_return = 57,                    /* return  */
  YYSYMBOL_callFunc = 58,                  /* callFunc  */
  YYSYMBOL_callFuncParams = 59             /* callFuncParams  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




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

#if 1

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
#endif /* 1 */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL \
             && defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
  YYLTYPE yyls_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE) \
             + YYSIZEOF (YYLTYPE)) \
      + 2 * YYSTACK_GAP_MAXIMUM)

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
#define YYFINAL  11
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   212

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  33
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  27
/* YYNRULES -- Number of rules.  */
#define YYNRULES  92
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  202

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   276


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
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
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   149,   149,   158,   159,   160,   161,   165,   172,   189,
     196,   213,   230,   237,   257,   262,   257,   275,   278,   275,
     291,   299,   291,   314,   315,   319,   320,   324,   332,   340,
     351,   352,   356,   357,   358,   359,   360,   361,   362,   366,
     383,   388,   393,   398,   403,   414,   425,   436,   450,   453,
     456,   459,   465,   466,   467,   471,   485,   499,   513,   527,
     541,   555,   569,   583,   600,   603,   606,   609,   612,   615,
     621,   628,   635,   642,   652,   664,   676,   691,   704,   717,
     730,   746,   754,   773,   781,   803,   809,   815,   821,   827,
     837,   847,   857
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if 1
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "ID", "TYPEINT",
  "TYPEFLOAT", "TYPESTRING", "INT", "DEC", "STR", "WHILE", "IF", "ELSE",
  "RETURN", "PRINT", "SCAN", "CGE", "CGT", "CLE", "CLT", "CNE", "CEQ",
  "';'", "'='", "'('", "')'", "'{'", "'}'", "','", "'+'", "'-'", "'/'",
  "'*'", "$accept", "prog", "globalList", "var", "func", "$@1", "$@2",
  "$@3", "$@4", "$@5", "$@6", "paramsList", "params", "param",
  "contentList", "content", "addValue", "expression", "op", "comand",
  "condition", "cond", "print", "scan", "return", "callFunc",
  "callFuncParams", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_int16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,    59,    61,    40,    41,   123,   125,    44,    43,
      45,    47,    42
};
#endif

#define YYPACT_NINF (-112)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
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

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int8 yydefact[] =
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

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -112,  -112,  -112,    84,   177,  -112,  -112,  -112,  -112,  -112,
    -112,    34,   166,  -112,   -54,  -112,  -112,   -30,    12,  -112,
      65,     8,  -112,  -112,  -112,  -112,  -111
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     4,     5,    65,     7,    22,    52,    19,    51,    16,
      49,    34,    35,    36,    66,    67,    68,    94,   120,    69,
     104,   137,    70,    71,    72,    73,   100
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
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
static const yytype_int8 yystos[] =
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

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
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

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
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


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

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

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF

/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)                                \
    do                                                                  \
      if (N)                                                            \
        {                                                               \
          (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;        \
          (Current).first_column = YYRHSLOC (Rhs, 1).first_column;      \
          (Current).last_line    = YYRHSLOC (Rhs, N).last_line;         \
          (Current).last_column  = YYRHSLOC (Rhs, N).last_column;       \
        }                                                               \
      else                                                              \
        {                                                               \
          (Current).first_line   = (Current).last_line   =              \
            YYRHSLOC (Rhs, 0).last_line;                                \
          (Current).first_column = (Current).last_column =              \
            YYRHSLOC (Rhs, 0).last_column;                              \
        }                                                               \
    while (0)
#endif

#define YYRHSLOC(Rhs, K) ((Rhs)[K])


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


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

# ifndef YY_LOCATION_PRINT
#  if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL

/* Print *YYLOCP on YYO.  Private, do not rely on its existence. */

YY_ATTRIBUTE_UNUSED
static int
yy_location_print_ (FILE *yyo, YYLTYPE const * const yylocp)
{
  int res = 0;
  int end_col = 0 != yylocp->last_column ? yylocp->last_column - 1 : 0;
  if (0 <= yylocp->first_line)
    {
      res += YYFPRINTF (yyo, "%d", yylocp->first_line);
      if (0 <= yylocp->first_column)
        res += YYFPRINTF (yyo, ".%d", yylocp->first_column);
    }
  if (0 <= yylocp->last_line)
    {
      if (yylocp->first_line < yylocp->last_line)
        {
          res += YYFPRINTF (yyo, "-%d", yylocp->last_line);
          if (0 <= end_col)
            res += YYFPRINTF (yyo, ".%d", end_col);
        }
      else if (0 <= end_col && yylocp->first_column < end_col)
        res += YYFPRINTF (yyo, "-%d", end_col);
    }
  return res;
 }

#   define YY_LOCATION_PRINT(File, Loc)          \
  yy_location_print_ (File, &(Loc))

#  else
#   define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#  endif
# endif /* !defined YY_LOCATION_PRINT */


# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value, Location); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
{
  FILE *yyoutput = yyo;
  YYUSE (yyoutput);
  YYUSE (yylocationp);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yykind < YYNTOKENS)
    YYPRINT (yyo, yytoknum[yykind], *yyvaluep);
# endif
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  YY_LOCATION_PRINT (yyo, *yylocationp);
  YYFPRINTF (yyo, ": ");
  yy_symbol_value_print (yyo, yykind, yyvaluep, yylocationp);
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
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp, YYLTYPE *yylsp,
                 int yyrule)
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
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)],
                       &(yylsp[(yyi + 1) - (yynrhs)]));
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, yylsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
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


/* Context of a parse error.  */
typedef struct
{
  yy_state_t *yyssp;
  yysymbol_kind_t yytoken;
  YYLTYPE *yylloc;
} yypcontext_t;

/* Put in YYARG at most YYARGN of the expected tokens given the
   current YYCTX, and return the number of tokens stored in YYARG.  If
   YYARG is null, return the number of expected tokens (guaranteed to
   be less than YYNTOKENS).  Return YYENOMEM on memory exhaustion.
   Return 0 if there are more than YYARGN expected tokens, yet fill
   YYARG up to YYARGN. */
static int
yypcontext_expected_tokens (const yypcontext_t *yyctx,
                            yysymbol_kind_t yyarg[], int yyargn)
{
  /* Actual size of YYARG. */
  int yycount = 0;
  int yyn = yypact[+*yyctx->yyssp];
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
        if (yycheck[yyx + yyn] == yyx && yyx != YYSYMBOL_YYerror
            && !yytable_value_is_error (yytable[yyx + yyn]))
          {
            if (!yyarg)
              ++yycount;
            else if (yycount == yyargn)
              return 0;
            else
              yyarg[yycount++] = YY_CAST (yysymbol_kind_t, yyx);
          }
    }
  if (yyarg && yycount == 0 && 0 < yyargn)
    yyarg[0] = YYSYMBOL_YYEMPTY;
  return yycount;
}




#ifndef yystrlen
# if defined __GLIBC__ && defined _STRING_H
#  define yystrlen(S) (YY_CAST (YYPTRDIFF_T, strlen (S)))
# else
/* Return the length of YYSTR.  */
static YYPTRDIFF_T
yystrlen (const char *yystr)
{
  YYPTRDIFF_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
# endif
#endif

#ifndef yystpcpy
# if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#  define yystpcpy stpcpy
# else
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
# endif
#endif

#ifndef yytnamerr
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
#endif


static int
yy_syntax_error_arguments (const yypcontext_t *yyctx,
                           yysymbol_kind_t yyarg[], int yyargn)
{
  /* Actual size of YYARG. */
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
  if (yyctx->yytoken != YYSYMBOL_YYEMPTY)
    {
      int yyn;
      if (yyarg)
        yyarg[yycount] = yyctx->yytoken;
      ++yycount;
      yyn = yypcontext_expected_tokens (yyctx,
                                        yyarg ? yyarg + 1 : yyarg, yyargn - 1);
      if (yyn == YYENOMEM)
        return YYENOMEM;
      else
        yycount += yyn;
    }
  return yycount;
}

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return -1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return YYENOMEM if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYPTRDIFF_T *yymsg_alloc, char **yymsg,
                const yypcontext_t *yyctx)
{
  enum { YYARGS_MAX = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat: reported tokens (one for the "unexpected",
     one per "expected"). */
  yysymbol_kind_t yyarg[YYARGS_MAX];
  /* Cumulated lengths of YYARG.  */
  YYPTRDIFF_T yysize = 0;

  /* Actual size of YYARG. */
  int yycount = yy_syntax_error_arguments (yyctx, yyarg, YYARGS_MAX);
  if (yycount == YYENOMEM)
    return YYENOMEM;

  switch (yycount)
    {
#define YYCASE_(N, S)                       \
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
#undef YYCASE_
    }

  /* Compute error message size.  Don't count the "%s"s, but reserve
     room for the terminator.  */
  yysize = yystrlen (yyformat) - 2 * yycount + 1;
  {
    int yyi;
    for (yyi = 0; yyi < yycount; ++yyi)
      {
        YYPTRDIFF_T yysize1
          = yysize + yytnamerr (YY_NULLPTR, yytname[yyarg[yyi]]);
        if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
          yysize = yysize1;
        else
          return YYENOMEM;
      }
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return -1;
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
          yyp += yytnamerr (yyp, yytname[yyarg[yyi++]]);
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


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep, YYLTYPE *yylocationp)
{
  YYUSE (yyvaluep);
  YYUSE (yylocationp);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Location data for the lookahead symbol.  */
YYLTYPE yylloc
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
  = { 1, 1, 1, 1 }
# endif
;
/* Number of syntax errors so far.  */
int yynerrs;




/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

    /* The location stack: array, bottom, top.  */
    YYLTYPE yylsa[YYINITDEPTH];
    YYLTYPE *yyls = yylsa;
    YYLTYPE *yylsp = yyls;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;
  YYLTYPE yyloc;

  /* The locations where the error started and ended.  */
  YYLTYPE yyerror_range[3];

  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYPTRDIFF_T yymsg_alloc = sizeof yymsgbuf;

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N), yylsp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */
  yylsp[0] = yylloc;
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
  YY_STACK_PRINT (yyss, yyssp);

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
        YYLTYPE *yyls1 = yyls;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yyls1, yysize * YYSIZEOF (*yylsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
        yyls = yyls1;
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
        YYSTACK_RELOCATE (yyls_alloc, yyls);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;
      yylsp = yyls + yysize - 1;

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

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      yyerror_range[1] = yylloc;
      goto yyerrlab1;
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
  *++yylsp = yylloc;

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

  /* Default location. */
  YYLLOC_DEFAULT (yyloc, (yylsp - yylen), yylen);
  yyerror_range[1] = yyloc;
  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 2: /* prog: globalList  */
#line 149 "lang.y"
             { 
    tree = (yyvsp[0].node);
    if (hasMain == 0) {
      print_semantic_error(NULL, 7);
    }
  }
#line 1740 "lang.tab.c"
    break;

  case 3: /* globalList: globalList var  */
#line 158 "lang.y"
                 { (yyval.node) = add_node2('R', (yyvsp[-1].node), (yyvsp[0].node)); }
#line 1746 "lang.tab.c"
    break;

  case 4: /* globalList: var  */
#line 159 "lang.y"
                 { (yyval.node) = (yyvsp[0].node); }
#line 1752 "lang.tab.c"
    break;

  case 5: /* globalList: func  */
#line 160 "lang.y"
                 { (yyval.node) = (yyvsp[0].node); }
#line 1758 "lang.tab.c"
    break;

  case 6: /* globalList: globalList func  */
#line 161 "lang.y"
                  { (yyval.node) = add_node2('R', (yyvsp[-1].node), (yyvsp[0].node)); }
#line 1764 "lang.tab.c"
    break;

  case 7: /* var: TYPEINT ID ';'  */
#line 165 "lang.y"
                          { (yyval.node) = add_node0('v'); 
                            (yyval.node)->type = 0;
                            (yyval.node)->value = (char *) strdup((yyvsp[-1].id));   
                            add_symbol_table((yyvsp[-1].id), 0);  
                            free((yyvsp[-2].type));
                            free((yyvsp[-1].id)); 
                          }
#line 1776 "lang.tab.c"
    break;

  case 8: /* var: TYPEINT ID '=' INT ';'  */
#line 172 "lang.y"
                         {  (yyval.node) = add_node0('v'); 
                            (yyval.node)->type = 0;
                            (yyval.node)->value = (char *) strdup((yyvsp[-3].id));

                            (yyval.node)->node1 = add_node0('A');
                            (yyval.node)->node1->type = 0;
                            (yyval.node)->node1->node1 = add_node0('V');
                            (yyval.node)->node1->node1->type = 0;
                            (yyval.node)->node1->node1->value = (char *) strdup((yyvsp[-3].id));
                            (yyval.node)->node1->node2 = add_node0('I');
                            (yyval.node)->node1->node2->type = 0;
                            (yyval.node)->node1->node2->value = (char *) strdup((yyvsp[-1].num));
                            add_symbol_table((yyvsp[-3].id), 0);
                            free((yyvsp[-4].type));
                            free((yyvsp[-3].id)); 
                            free((yyvsp[-1].num)); 
                          }
#line 1798 "lang.tab.c"
    break;

  case 9: /* var: TYPEFLOAT ID ';'  */
#line 189 "lang.y"
                          { (yyval.node) = add_node0('v'); 
                            (yyval.node)->type = 1;
                            (yyval.node)->value = (char *) strdup((yyvsp[-1].id));  
                            add_symbol_table((yyvsp[-1].id), 1);
                            free((yyvsp[-2].type));
                            free((yyvsp[-1].id)); 
                          }
#line 1810 "lang.tab.c"
    break;

  case 10: /* var: TYPEFLOAT ID '=' INT ';'  */
#line 196 "lang.y"
                            {  (yyval.node) = add_node0('v'); 
                            (yyval.node)->type = 1;
                            (yyval.node)->value = (char *) strdup((yyvsp[-3].id));

                            (yyval.node)->node1 = add_node0('A');
                            (yyval.node)->node1->type = 1;
                            (yyval.node)->node1->node1 = add_node0('V');
                            (yyval.node)->node1->node1->type = 1;
                            (yyval.node)->node1->node1->value = (char *) strdup((yyvsp[-3].id));
                            (yyval.node)->node1->node2 = add_node0('I');
                            (yyval.node)->node1->node2->type = 0;
                            (yyval.node)->node1->node2->value = (char *) strdup((yyvsp[-1].num));
                            add_symbol_table((yyvsp[-3].id), 1);
                            free((yyvsp[-4].type));
                            free((yyvsp[-3].id)); 
                            free((yyvsp[-1].num)); 
                          }
#line 1832 "lang.tab.c"
    break;

  case 11: /* var: TYPEFLOAT ID '=' DEC ';'  */
#line 213 "lang.y"
                          {  (yyval.node) = add_node0('v'); 
                            (yyval.node)->type = 1;
                            (yyval.node)->value = (char *) strdup((yyvsp[-3].id));

                            (yyval.node)->node1 = add_node0('A');
                            (yyval.node)->node1->type = 1;
                            (yyval.node)->node1->node1 = add_node0('V');
                            (yyval.node)->node1->node1->type = 1;
                            (yyval.node)->node1->node1->value = (char *) strdup((yyvsp[-3].id));
                            (yyval.node)->node1->node2 = add_node0('D');
                            (yyval.node)->node1->node2->type = 1;
                            (yyval.node)->node1->node2->value = (char *) strdup((yyvsp[-1].num));
                            add_symbol_table((yyvsp[-3].id), 1);
                            free((yyvsp[-4].type));
                            free((yyvsp[-3].id)); 
                            free((yyvsp[-1].num)); 
                          }
#line 1854 "lang.tab.c"
    break;

  case 12: /* var: TYPESTRING ID ';'  */
#line 230 "lang.y"
                          { (yyval.node) = add_node0('v'); 
                            (yyval.node)->type = 2;
                            (yyval.node)->value = (char *) strdup((yyvsp[-1].id));    
                            add_symbol_table((yyvsp[-1].id), 2);
                            free((yyvsp[-2].type));
                            free((yyvsp[-1].id)); 
                          }
#line 1866 "lang.tab.c"
    break;

  case 13: /* var: TYPESTRING ID '=' STR ';'  */
#line 237 "lang.y"
                            {  (yyval.node) = add_node0('v'); 
                            (yyval.node)->type = 2;
                            (yyval.node)->value = (char *) strdup((yyvsp[-3].id));

                            (yyval.node)->node1 = add_node0('A');
                            (yyval.node)->node1->type = 2;
                            (yyval.node)->node1->node1 = add_node0('V');
                            (yyval.node)->node1->node1->type = 2;
                            (yyval.node)->node1->node1->value = (char *) strdup((yyvsp[-3].id));
                            (yyval.node)->node1->node2 = add_node0('S');
                            (yyval.node)->node1->node2->type = 2;
                            (yyval.node)->node1->node2->value = (char *) strdup((yyvsp[-1].str));
                            add_symbol_table((yyvsp[-3].id), 2);
                            free((yyvsp[-4].type));
                            free((yyvsp[-3].id)); 
                            free((yyvsp[-1].str)); 
                          }
#line 1888 "lang.tab.c"
    break;

  case 14: /* $@1: %empty  */
#line 257 "lang.y"
                                                        { 
                                                          add_symbol_table((yyvsp[0].id), 2); add_scope((yyvsp[0].id), 2); 
                                                          hasReturn = 0;
                                                          add_func_params((yyvsp[0].id));
                                                        }
#line 1898 "lang.tab.c"
    break;

  case 15: /* $@2: %empty  */
#line 262 "lang.y"
                                                        {;}
#line 1904 "lang.tab.c"
    break;

  case 16: /* func: TYPESTRING ID $@1 '(' paramsList ')' $@2 '{' contentList '}'  */
#line 263 "lang.y"
                                                        { 
                                                          (yyval.node) = add_node2('F', (yyvsp[-5].node), (yyvsp[-1].node)); 
                                                          (yyval.node)->type = 2;
                                                          (yyval.node)->value = (char *) strdup((yyvsp[-8].id)); 
                                                          if (hasReturn == 0) {
                                                            print_semantic_error((yyvsp[-8].id), 8);
                                                          }
                                                          remove_scope();   
                                                          free((yyvsp[-9].type));
                                                          free((yyvsp[-8].id)); 
                                                        }
#line 1920 "lang.tab.c"
    break;

  case 17: /* $@3: %empty  */
#line 275 "lang.y"
                                                        { add_symbol_table((yyvsp[0].id), 1); add_scope((yyvsp[0].id), 1); hasReturn = 0;
                                                          add_func_params((yyvsp[0].id)); 
                                                        }
#line 1928 "lang.tab.c"
    break;

  case 18: /* $@4: %empty  */
#line 278 "lang.y"
                                                        {;}
#line 1934 "lang.tab.c"
    break;

  case 19: /* func: TYPEFLOAT ID $@3 '(' paramsList ')' $@4 '{' contentList '}'  */
#line 279 "lang.y"
                                                        {  
                                                          (yyval.node) = add_node2('F', (yyvsp[-5].node), (yyvsp[-1].node)); 
                                                          (yyval.node)->type = 1;
                                                          (yyval.node)->value = (char *) strdup((yyvsp[-8].id));   
                                                          if (hasReturn == 0) {
                                                            print_semantic_error((yyvsp[-8].id), 8);
                                                          }  
                                                          remove_scope();
                                                          free((yyvsp[-9].type));
                                                          free((yyvsp[-8].id));
                                                        }
#line 1950 "lang.tab.c"
    break;

  case 20: /* $@5: %empty  */
#line 291 "lang.y"
                                                        { 
                                                          add_symbol_table((yyvsp[0].id), 0); add_scope((yyvsp[0].id), 0);
                                                          if (strcmp((yyvsp[0].id), "main") == 0) {
                                                            hasMain = 1;
                                                          }
                                                          hasReturn = 0;
                                                          add_func_params((yyvsp[0].id));
                                                        }
#line 1963 "lang.tab.c"
    break;

  case 21: /* $@6: %empty  */
#line 299 "lang.y"
                                                        {;}
#line 1969 "lang.tab.c"
    break;

  case 22: /* func: TYPEINT ID $@5 '(' paramsList ')' $@6 '{' contentList '}'  */
#line 300 "lang.y"
                                                        {
                                                          (yyval.node) = add_node2('F', (yyvsp[-5].node), (yyvsp[-1].node)); 
                                                          (yyval.node)->type = 0;
                                                          (yyval.node)->value = (char *) strdup((yyvsp[-8].id));
                                                          if (hasReturn == 0) {
                                                            print_semantic_error((yyvsp[-8].id), 8);
                                                          }
                                                          remove_scope();
                                                          free((yyvsp[-9].type));
                                                          free((yyvsp[-8].id));
                                                        }
#line 1985 "lang.tab.c"
    break;

  case 23: /* paramsList: params  */
#line 314 "lang.y"
         { (yyval.node) = (yyvsp[0].node); }
#line 1991 "lang.tab.c"
    break;

  case 24: /* paramsList: %empty  */
#line 315 "lang.y"
         { (yyval.node) = NULL; }
#line 1997 "lang.tab.c"
    break;

  case 25: /* params: param  */
#line 319 "lang.y"
        { (yyval.node) = (yyvsp[0].node); }
#line 2003 "lang.tab.c"
    break;

  case 26: /* params: param ',' params  */
#line 320 "lang.y"
                   { (yyval.node) = add_node2('R', (yyvsp[-2].node), (yyvsp[0].node)); }
#line 2009 "lang.tab.c"
    break;

  case 27: /* param: TYPEINT ID  */
#line 324 "lang.y"
                          { (yyval.node) = add_node0('P'); 
                            (yyval.node)->type = 0;
                            (yyval.node)->value = (char *) strdup((yyvsp[0].id)); 
                            add_symbol_table((yyvsp[0].id), 0); 
                            add_params(0);
                            free((yyvsp[-1].type));
                            free((yyvsp[0].id)); 
                          }
#line 2022 "lang.tab.c"
    break;

  case 28: /* param: TYPEFLOAT ID  */
#line 332 "lang.y"
                          { (yyval.node) = add_node0('P'); 
                            (yyval.node)->type = 1;
                            (yyval.node)->value = (char *) strdup((yyvsp[0].id));    
                            add_symbol_table((yyvsp[0].id), 1);
                            add_params(1);
                            free((yyvsp[-1].type));
                            free((yyvsp[0].id));  
                          }
#line 2035 "lang.tab.c"
    break;

  case 29: /* param: TYPESTRING ID  */
#line 340 "lang.y"
                          { (yyval.node) = add_node0('P'); 
                            (yyval.node)->type = 2;
                            (yyval.node)->value = (char *) strdup((yyvsp[0].id));
                            add_symbol_table((yyvsp[0].id), 2);
                            add_params(2);
                            free((yyvsp[-1].type));
                            free((yyvsp[0].id));      
                          }
#line 2048 "lang.tab.c"
    break;

  case 30: /* contentList: content contentList  */
#line 351 "lang.y"
                         { (yyval.node) = add_node2('R', (yyvsp[-1].node), (yyvsp[0].node)); }
#line 2054 "lang.tab.c"
    break;

  case 31: /* contentList: %empty  */
#line 352 "lang.y"
                         { (yyval.node) = NULL; }
#line 2060 "lang.tab.c"
    break;

  case 32: /* content: var  */
#line 356 "lang.y"
              { (yyval.node) = (yyvsp[0].node); }
#line 2066 "lang.tab.c"
    break;

  case 33: /* content: addValue  */
#line 357 "lang.y"
              { (yyval.node) = (yyvsp[0].node); }
#line 2072 "lang.tab.c"
    break;

  case 34: /* content: comand  */
#line 358 "lang.y"
              { (yyval.node) = (yyvsp[0].node); }
#line 2078 "lang.tab.c"
    break;

  case 35: /* content: print  */
#line 359 "lang.y"
              { (yyval.node) = (yyvsp[0].node); }
#line 2084 "lang.tab.c"
    break;

  case 36: /* content: scan  */
#line 360 "lang.y"
              { (yyval.node) = (yyvsp[0].node); }
#line 2090 "lang.tab.c"
    break;

  case 37: /* content: return  */
#line 361 "lang.y"
              { (yyval.node) = (yyvsp[0].node); }
#line 2096 "lang.tab.c"
    break;

  case 38: /* content: callFunc  */
#line 362 "lang.y"
              { (yyval.node) = (yyvsp[0].node); }
#line 2102 "lang.tab.c"
    break;

  case 39: /* addValue: ID '=' expression ';'  */
#line 366 "lang.y"
                           { 
                            (yyval.node) = add_node0('A');
                            (yyval.node)->type = get_id_type((yyvsp[-3].id));
                            (yyval.node)->node1 = add_node0('V');
                            (yyval.node)->node1->type = get_id_type((yyvsp[-3].id));
                            (yyval.node)->node1->value = (char *) strdup((yyvsp[-3].id));
                            (yyval.node)->node2 = (yyvsp[-1].node);
                            if ((yyval.node)->node1->type != (yyval.node)->node2->type) {
                              if (!((yyval.node)->node1->type == 1 && (yyval.node)->node2->type == 0)) {
                                print_semantic_error((yyval.node)->node1->value, 4);
                              }
                            }
                            free((yyvsp[-3].id));
                          }
#line 2121 "lang.tab.c"
    break;

  case 40: /* expression: ID  */
#line 383 "lang.y"
                          { (yyval.node) = add_node0('V'); 
                            (yyval.node)->value = (char *) strdup((yyvsp[0].id));   
                            (yyval.node)->type = get_id_type((yyvsp[0].id));
                            free((yyvsp[0].id));  
                          }
#line 2131 "lang.tab.c"
    break;

  case 41: /* expression: INT  */
#line 388 "lang.y"
                          { (yyval.node) = add_node0('I');
                            (yyval.node)->type = 0;
                            (yyval.node)->value = (char *) strdup((yyvsp[0].num));    
                            free((yyvsp[0].num)); 
                          }
#line 2141 "lang.tab.c"
    break;

  case 42: /* expression: DEC  */
#line 393 "lang.y"
                          { (yyval.node) = add_node0('D'); 
                            (yyval.node)->type = 1;
                            (yyval.node)->value = (char *) strdup((yyvsp[0].num));  
                            free((yyvsp[0].num));   
                          }
#line 2151 "lang.tab.c"
    break;

  case 43: /* expression: STR  */
#line 398 "lang.y"
                          { (yyval.node) = add_node0('S'); 
                            (yyval.node)->type = 2;
                            (yyval.node)->value = (char *) strdup((yyvsp[0].str));  
                            free((yyvsp[0].str));   
                          }
#line 2161 "lang.tab.c"
    break;

  case 44: /* expression: ID op expression  */
#line 403 "lang.y"
                          { (yyval.node) = add_node0('E');

                            (yyval.node)->node1 = add_node0('V');
                            (yyval.node)->node1->value = (char *) strdup((yyvsp[-2].id));
                            (yyval.node)->node1->type = get_id_type((yyvsp[-2].id));

                            (yyval.node)->node2 = (yyvsp[-1].node);
                            (yyval.node)->node3 = (yyvsp[0].node);
                            build_expression_type((yyval.node));
                            free((yyvsp[-2].id));
                          }
#line 2177 "lang.tab.c"
    break;

  case 45: /* expression: INT op expression  */
#line 414 "lang.y"
                          { (yyval.node) = add_node0('E');

                            (yyval.node)->node1 = add_node0('I');
                            (yyval.node)->node1->type = 0;
                            (yyval.node)->node1->value = (char *) strdup((yyvsp[-2].num));

                            (yyval.node)->node2 = (yyvsp[-1].node);
                            (yyval.node)->node3 = (yyvsp[0].node);
                            build_expression_type((yyval.node));
                            free((yyvsp[-2].num));
                          }
#line 2193 "lang.tab.c"
    break;

  case 46: /* expression: DEC op expression  */
#line 425 "lang.y"
                          { (yyval.node) = add_node0('E');

                            (yyval.node)->node1 = add_node0('D');
                            (yyval.node)->node1->type = 1;
                            (yyval.node)->node1->value = (char *) strdup((yyvsp[-2].num));

                            (yyval.node)->node2 = (yyvsp[-1].node);
                            (yyval.node)->node3 = (yyvsp[0].node);
                            build_expression_type((yyval.node));
                            free((yyvsp[-2].num));
                          }
#line 2209 "lang.tab.c"
    break;

  case 47: /* expression: STR op expression  */
#line 436 "lang.y"
                          { (yyval.node) = add_node0('E');

                            (yyval.node)->node1 = add_node0('S');
                            (yyval.node)->node1->type = 2;
                            (yyval.node)->node1->value = (char *) strdup((yyvsp[-2].str));

                            (yyval.node)->node2 = (yyvsp[-1].node);
                            (yyval.node)->node3 = (yyvsp[0].node);
                            build_expression_type((yyval.node));
                            free((yyvsp[-2].str));
                          }
#line 2225 "lang.tab.c"
    break;

  case 48: /* op: '+'  */
#line 450 "lang.y"
        { (yyval.node) = add_node0('B'); 
          (yyval.node)->value = (char *) strdup("+");     
        }
#line 2233 "lang.tab.c"
    break;

  case 49: /* op: '-'  */
#line 453 "lang.y"
        { (yyval.node) = add_node0('B'); 
          (yyval.node)->value = (char *) strdup("-");     
        }
#line 2241 "lang.tab.c"
    break;

  case 50: /* op: '/'  */
#line 456 "lang.y"
        { (yyval.node) = add_node0('B'); 
          (yyval.node)->value = (char *) strdup("/");     
        }
#line 2249 "lang.tab.c"
    break;

  case 51: /* op: '*'  */
#line 459 "lang.y"
        { (yyval.node) = add_node0('B'); 
          (yyval.node)->value = (char *) strdup("*");     
        }
#line 2257 "lang.tab.c"
    break;

  case 52: /* comand: IF '(' condition ')' '{' contentList '}'  */
#line 465 "lang.y"
                                                                      { (yyval.node) = add_node2('C', (yyvsp[-4].node), (yyvsp[-1].node)); }
#line 2263 "lang.tab.c"
    break;

  case 53: /* comand: IF '(' condition ')' '{' contentList '}' ELSE '{' contentList '}'  */
#line 466 "lang.y"
                                                                      { (yyval.node) = add_node3('C', (yyvsp[-8].node), (yyvsp[-5].node), (yyvsp[-1].node)); }
#line 2269 "lang.tab.c"
    break;

  case 54: /* comand: WHILE '(' condition ')' '{' contentList '}'  */
#line 467 "lang.y"
                                                                      { (yyval.node) = add_node2('W', (yyvsp[-4].node), (yyvsp[-1].node)); }
#line 2275 "lang.tab.c"
    break;

  case 55: /* condition: ID cond ID  */
#line 471 "lang.y"
                  { (yyval.node) = add_node0('c');

                    (yyval.node)->node1 = add_node0('V');
                    (yyval.node)->node1->value = (char *) strdup((yyvsp[-2].id));
                    (yyval.node)->node1->type = get_id_type((yyvsp[-2].id));

                    (yyval.node)->node2 = (yyvsp[-1].node);
                    
                    (yyval.node)->node3 = add_node0('V');
                    (yyval.node)->node3->value = (char *) strdup((yyvsp[0].id));
                    (yyval.node)->node3->type = get_id_type((yyvsp[0].id));
                    free((yyvsp[-2].id));
                    free((yyvsp[0].id));
                  }
#line 2294 "lang.tab.c"
    break;

  case 56: /* condition: ID cond INT  */
#line 485 "lang.y"
                  { (yyval.node) = add_node0('c');

                    (yyval.node)->node1 = add_node0('V');
                    (yyval.node)->node1->value = (char *) strdup((yyvsp[-2].id));
                    (yyval.node)->node1->type = get_id_type((yyvsp[-2].id));

                    (yyval.node)->node2 = (yyvsp[-1].node);
                    
                    (yyval.node)->node3 = add_node0('I');
                    (yyval.node)->node3->type = 0;
                    (yyval.node)->node3->value = (char *) strdup((yyvsp[0].num));
                    free((yyvsp[-2].id));
                    free((yyvsp[0].num));
                  }
#line 2313 "lang.tab.c"
    break;

  case 57: /* condition: ID cond DEC  */
#line 499 "lang.y"
                  { (yyval.node) = add_node0('c');

                    (yyval.node)->node1 = add_node0('V');
                    (yyval.node)->node1->value = (char *) strdup((yyvsp[-2].id));
                    (yyval.node)->node1->type = get_id_type((yyvsp[-2].id));

                    (yyval.node)->node2 = (yyvsp[-1].node);
                    
                    (yyval.node)->node3 = add_node0('D');
                    (yyval.node)->node3->type = 1;
                    (yyval.node)->node3->value = (char *) strdup((yyvsp[0].num));
                    free((yyvsp[-2].id));
                    free((yyvsp[0].num));
                  }
#line 2332 "lang.tab.c"
    break;

  case 58: /* condition: INT cond ID  */
#line 513 "lang.y"
                  { (yyval.node) = add_node0('c');

                    (yyval.node)->node1 = add_node0('I');
                    (yyval.node)->node1->type = 0;
                    (yyval.node)->node1->value = (char *) strdup((yyvsp[-2].num));

                    (yyval.node)->node2 = (yyvsp[-1].node);
                    
                    (yyval.node)->node3 = add_node0('V');
                    (yyval.node)->node3->value = (char *) strdup((yyvsp[0].id));
                    (yyval.node)->node3->type = get_id_type((yyvsp[0].id));
                    free((yyvsp[-2].num));
                    free((yyvsp[0].id));
                  }
#line 2351 "lang.tab.c"
    break;

  case 59: /* condition: INT cond INT  */
#line 527 "lang.y"
                  { (yyval.node) = add_node0('c');

                    (yyval.node)->node1 = add_node0('I');
                    (yyval.node)->node1->type = 0;
                    (yyval.node)->node1->value = (char *) strdup((yyvsp[-2].num));

                    (yyval.node)->node2 = (yyvsp[-1].node);
                    
                    (yyval.node)->node3 = add_node0('I');
                    (yyval.node)->node3->type = 0;
                    (yyval.node)->node3->value = (char *) strdup((yyvsp[0].num));
                    free((yyvsp[-2].num));
                    free((yyvsp[0].num));
                  }
#line 2370 "lang.tab.c"
    break;

  case 60: /* condition: INT cond DEC  */
#line 541 "lang.y"
                  { (yyval.node) = add_node0('c');

                    (yyval.node)->node1 = add_node0('I');
                    (yyval.node)->node1->type = 0;
                    (yyval.node)->node1->value = (char *) strdup((yyvsp[-2].num));

                    (yyval.node)->node2 = (yyvsp[-1].node);
                    
                    (yyval.node)->node3 = add_node0('D');
                    (yyval.node)->node3->type = 1;
                    (yyval.node)->node3->value = (char *) strdup((yyvsp[0].num));
                    free((yyvsp[-2].num));
                    free((yyvsp[0].num));
                  }
#line 2389 "lang.tab.c"
    break;

  case 61: /* condition: DEC cond ID  */
#line 555 "lang.y"
                  { (yyval.node) = add_node0('c');

                    (yyval.node)->node1 = add_node0('D');
                    (yyval.node)->node1->type = 2;
                    (yyval.node)->node1->value = (char *) strdup((yyvsp[-2].num));

                    (yyval.node)->node2 = (yyvsp[-1].node);
                    
                    (yyval.node)->node3 = add_node0('V');
                    (yyval.node)->node3->value = (char *) strdup((yyvsp[0].id));
                    (yyval.node)->node3->type = get_id_type((yyvsp[0].id));
                    free((yyvsp[-2].num));
                    free((yyvsp[0].id));
                  }
#line 2408 "lang.tab.c"
    break;

  case 62: /* condition: DEC cond INT  */
#line 569 "lang.y"
                  { (yyval.node) = add_node0('c');

                    (yyval.node)->node1 = add_node0('D');
                    (yyval.node)->node1->type = 2;
                    (yyval.node)->node1->value = (char *) strdup((yyvsp[-2].num));

                    (yyval.node)->node2 = (yyvsp[-1].node);
                    
                    (yyval.node)->node3 = add_node0('I');
                    (yyval.node)->node3->type = 1;
                    (yyval.node)->node3->value = (char *) strdup((yyvsp[0].num));
                    free((yyvsp[-2].num));
                    free((yyvsp[0].num));
                  }
#line 2427 "lang.tab.c"
    break;

  case 63: /* condition: DEC cond DEC  */
#line 583 "lang.y"
                  { (yyval.node) = add_node0('c');

                    (yyval.node)->node1 = add_node0('D');
                    (yyval.node)->node1->type = 2;
                    (yyval.node)->node1->value = (char *) strdup((yyvsp[-2].num));

                    (yyval.node)->node2 = (yyvsp[-1].node);
                    
                    (yyval.node)->node3 = add_node0('D');
                    (yyval.node)->node3->type = 2;
                    (yyval.node)->node3->value = (char *) strdup((yyvsp[0].num));
                    free((yyvsp[-2].num));
                    free((yyvsp[0].num));
                  }
#line 2446 "lang.tab.c"
    break;

  case 64: /* cond: CGE  */
#line 600 "lang.y"
        { (yyval.node) = add_node0('B'); 
          (yyval.node)->value = (char *) strdup("CGE");     
        }
#line 2454 "lang.tab.c"
    break;

  case 65: /* cond: CGT  */
#line 603 "lang.y"
        { (yyval.node) = add_node0('B'); 
          (yyval.node)->value = (char *) strdup("CGT");     
        }
#line 2462 "lang.tab.c"
    break;

  case 66: /* cond: CLE  */
#line 606 "lang.y"
        { (yyval.node) = add_node0('B'); 
          (yyval.node)->value = (char *) strdup("CLE");     
        }
#line 2470 "lang.tab.c"
    break;

  case 67: /* cond: CLT  */
#line 609 "lang.y"
        { (yyval.node) = add_node0('B'); 
          (yyval.node)->value = (char *) strdup("CLT");     
        }
#line 2478 "lang.tab.c"
    break;

  case 68: /* cond: CNE  */
#line 612 "lang.y"
        { (yyval.node) = add_node0('B'); 
          (yyval.node)->value = (char *) strdup("CNE");     
        }
#line 2486 "lang.tab.c"
    break;

  case 69: /* cond: CEQ  */
#line 615 "lang.y"
        { (yyval.node) = add_node0('B'); 
          (yyval.node)->value = (char *) strdup("CEQ");     
        }
#line 2494 "lang.tab.c"
    break;

  case 70: /* print: PRINT '(' ID ')' ';'  */
#line 621 "lang.y"
                          { (yyval.node) = add_node0('L');
                            (yyval.node)->value = (char *) strdup("PRINT");
                            (yyval.node)->node1 = add_node0('V');
                            (yyval.node)->node1->value = (char *) strdup((yyvsp[-2].id)); 
                            (yyval.node)->node1->type = get_id_type((yyvsp[-2].id));
                            free((yyvsp[-2].id));    
                          }
#line 2506 "lang.tab.c"
    break;

  case 71: /* print: PRINT '(' STR ')' ';'  */
#line 628 "lang.y"
                          { (yyval.node) = add_node0('L');
                            (yyval.node)->value = (char *) strdup("PRINT");
                            (yyval.node)->node1 = add_node0('S');
                            (yyval.node)->node1->type = 2;
                            (yyval.node)->node1->value = (char *) strdup((yyvsp[-2].str)); 
                            free((yyvsp[-2].str));    
                          }
#line 2518 "lang.tab.c"
    break;

  case 72: /* print: PRINT '(' INT ')' ';'  */
#line 635 "lang.y"
                          { (yyval.node) = add_node0('L');
                            (yyval.node)->value = (char *) strdup("PRINT");
                            (yyval.node)->node1 = add_node0('I');
                            (yyval.node)->node1->type = 0;
                            (yyval.node)->node1->value = (char *) strdup((yyvsp[-2].num)); 
                            free((yyvsp[-2].num));    
                          }
#line 2530 "lang.tab.c"
    break;

  case 73: /* print: PRINT '(' DEC ')' ';'  */
#line 642 "lang.y"
                          { (yyval.node) = add_node0('L');
                            (yyval.node)->value = (char *) strdup("PRINT");
                            (yyval.node)->node1 = add_node0('D');
                            (yyval.node)->node1->type = 1;
                            (yyval.node)->node1->value = (char *) strdup((yyvsp[-2].num));     
                            free((yyvsp[-2].num));
                          }
#line 2542 "lang.tab.c"
    break;

  case 74: /* scan: SCAN '(' ID ',' TYPEINT ')' ';'  */
#line 652 "lang.y"
                                        { (yyval.node) = add_node0('L');
                                          (yyval.node)->type = 0;
                                          (yyval.node)->value = (char *) strdup("SCAN");
                                          (yyval.node)->node1 = add_node0('V');
                                          (yyval.node)->node1->value = (char *) strdup((yyvsp[-4].id));   
                                          (yyval.node)->node1->type = get_id_type((yyvsp[-4].id));
                                          if ((yyval.node)->type != (yyval.node)->node1->type) {
                                            print_semantic_error((yyval.node)->node1->value, 6);
                                          }
                                          free((yyvsp[-4].id));  
                                          free((yyvsp[-2].type));  
                                        }
#line 2559 "lang.tab.c"
    break;

  case 75: /* scan: SCAN '(' ID ',' TYPEFLOAT ')' ';'  */
#line 664 "lang.y"
                                        { (yyval.node) = add_node0('L');
                                          (yyval.node)->type = 1;
                                          (yyval.node)->value = (char *) strdup("SCAN");
                                          (yyval.node)->node1 = add_node0('V');
                                          (yyval.node)->node1->value = (char *) strdup((yyvsp[-4].id)); 
                                          (yyval.node)->node1->type = get_id_type((yyvsp[-4].id)); 
                                          if ((yyval.node)->type != (yyval.node)->node1->type) {
                                            print_semantic_error((yyval.node)->node1->value, 6);
                                          }
                                          free((yyvsp[-4].id));  
                                          free((yyvsp[-2].type));     
                                        }
#line 2576 "lang.tab.c"
    break;

  case 76: /* scan: SCAN '(' ID ',' TYPESTRING ')' ';'  */
#line 676 "lang.y"
                                        { (yyval.node) = add_node0('L');
                                          (yyval.node)->type = 2;
                                          (yyval.node)->value = (char *) strdup("SCAN");
                                          (yyval.node)->node1 = add_node0('V');
                                          (yyval.node)->node1->value = (char *) strdup((yyvsp[-4].id)); 
                                          (yyval.node)->node1->type = get_id_type((yyvsp[-4].id)); 
                                          if ((yyval.node)->type != (yyval.node)->node1->type) {
                                            print_semantic_error((yyval.node)->node1->value, 6);
                                          }
                                          free((yyvsp[-4].id));  
                                          free((yyvsp[-2].type));     
                                        }
#line 2593 "lang.tab.c"
    break;

  case 77: /* return: RETURN '(' ID ')' ';'  */
#line 691 "lang.y"
                          { (yyval.node) = add_node0('L');
                            struct scope* scope = get_last_scope();
                            (yyval.node)->type  = scope->type;
                            (yyval.node)->value = (char *) strdup("RETURN");
                            (yyval.node)->node1 = add_node0('V');
                            (yyval.node)->node1->value = (char *) strdup((yyvsp[-2].id));   
                            (yyval.node)->node1->type = get_id_type((yyvsp[-2].id)); 
                            if ((yyval.node)->type != (yyval.node)->node1->type) {
                              print_semantic_error((yyval.node)->node1->value, 5);
                            }
                            hasReturn = 1;
                            free((yyvsp[-2].id)); 
                          }
#line 2611 "lang.tab.c"
    break;

  case 78: /* return: RETURN '(' STR ')' ';'  */
#line 704 "lang.y"
                          { (yyval.node) = add_node0('L');
                            struct scope* scope = get_last_scope();
                            (yyval.node)->type  = scope->type;
                            (yyval.node)->value = (char *) strdup("RETURN");
                            (yyval.node)->node1 = add_node0('S');
                            (yyval.node)->node1->type = 2;
                            (yyval.node)->node1->value = (char *) strdup((yyvsp[-2].str)); 
                            if ((yyval.node)->type != (yyval.node)->node1->type) {
                              print_semantic_error((yyval.node)->node1->value, 5);
                            } 
                            hasReturn = 1;
                            free((yyvsp[-2].str));   
                          }
#line 2629 "lang.tab.c"
    break;

  case 79: /* return: RETURN '(' INT ')' ';'  */
#line 717 "lang.y"
                          { (yyval.node) = add_node0('L');
                            struct scope* scope = get_last_scope();
                            (yyval.node)->type  = scope->type;
                            (yyval.node)->value = (char *) strdup("RETURN");
                            (yyval.node)->node1 = add_node0('I');
                            (yyval.node)->node1->type = 0;
                            (yyval.node)->node1->value = (char *) strdup((yyvsp[-2].num));  
                            if ((yyval.node)->type != (yyval.node)->node1->type) {
                              print_semantic_error((yyval.node)->node1->value, 5);
                            }
                            hasReturn = 1;
                            free((yyvsp[-2].num));   
                          }
#line 2647 "lang.tab.c"
    break;

  case 80: /* return: RETURN '(' DEC ')' ';'  */
#line 730 "lang.y"
                          { (yyval.node) = add_node0('L');
                            struct scope* scope = get_last_scope();
                            (yyval.node)->type  = scope->type;
                            (yyval.node)->value = (char *) strdup("RETURN");
                            (yyval.node)->node1 = add_node0('D');
                            (yyval.node)->node1->type = 1;
                            (yyval.node)->node1->value = (char *) strdup((yyvsp[-2].num));  
                            if ((yyval.node)->type != (yyval.node)->node1->type) {
                              print_semantic_error((yyval.node)->node1->value, 5);
                            }
                            hasReturn = 1;
                            free((yyvsp[-2].num));   
                          }
#line 2665 "lang.tab.c"
    break;

  case 81: /* callFunc: ID '(' callFuncParams ')' ';'  */
#line 746 "lang.y"
                                          { (yyval.node) = add_node1('L', (yyvsp[-2].node));
                                            (yyval.node)->value = (char *) strdup((yyvsp[-4].id));  
                                            (yyval.node)->type = get_id_type((yyvsp[-4].id));

                                            compare_params((yyvsp[-4].id));
                                            free_current_params();
                                            free((yyvsp[-4].id));  
                                          }
#line 2678 "lang.tab.c"
    break;

  case 82: /* callFunc: ID '=' ID '(' callFuncParams ')' ';'  */
#line 754 "lang.y"
                                          { (yyval.node) = add_node0('A');
                                            (yyval.node)->node1 = add_node0('V');
                                            (yyval.node)->node1->value = (char *) strdup((yyvsp[-6].id));
                                            (yyval.node)->node1->type = get_id_type((yyvsp[-6].id));
                                            (yyval.node)->node2 = add_node1('L', (yyvsp[-2].node));
                                            (yyval.node)->node2->value = (char *) strdup((yyvsp[-4].id)); 
                                            (yyval.node)->node2->type = get_id_type((yyvsp[-4].id));

                                            if ((yyval.node)->node1->type != (yyval.node)->node2->type) {
                                              if (!((yyval.node)->node1->type == 1 && (yyval.node)->node2->type == 0)) {
                                                print_semantic_error((yyval.node)->node1->value, 4);
                                              }
                                            }

                                            compare_params((yyvsp[-4].id));
                                            free_current_params();
                                            free((yyvsp[-6].id));  
                                            free((yyvsp[-4].id));     
                                          }
#line 2702 "lang.tab.c"
    break;

  case 83: /* callFunc: ID '(' ')' ';'  */
#line 773 "lang.y"
                                          { (yyval.node) = add_node0('L');
                                            (yyval.node)->value = (char *) strdup((yyvsp[-3].id));  
                                            (yyval.node)->type = get_id_type((yyvsp[-3].id));

                                            compare_params((yyvsp[-3].id));
                                            free_current_params();
                                            free((yyvsp[-3].id));  
                                          }
#line 2715 "lang.tab.c"
    break;

  case 84: /* callFunc: ID '=' ID '(' ')' ';'  */
#line 781 "lang.y"
                                           { (yyval.node) = add_node0('A');
                                            (yyval.node)->node1 = add_node0('V');
                                            (yyval.node)->node1->value = (char *) strdup((yyvsp[-5].id));
                                            (yyval.node)->node1->type = get_id_type((yyvsp[-5].id));
                                            (yyval.node)->node2 = add_node0('L');
                                            (yyval.node)->node2->value = (char *) strdup((yyvsp[-3].id)); 
                                            (yyval.node)->node2->type = get_id_type((yyvsp[-3].id));

                                            if ((yyval.node)->node1->type != (yyval.node)->node2->type) {
                                              if (!((yyval.node)->node1->type == 1 && (yyval.node)->node2->type == 0)) {
                                                print_semantic_error((yyval.node)->node1->value, 4);
                                              }
                                            }

                                            compare_params((yyvsp[-3].id));
                                            free_current_params();
                                            free((yyvsp[-5].id));  
                                            free((yyvsp[-3].id));     
                                          }
#line 2739 "lang.tab.c"
    break;

  case 85: /* callFuncParams: ID  */
#line 803 "lang.y"
                              { (yyval.node) = add_node0('V');
                                (yyval.node)->value = (char *) strdup((yyvsp[0].id)); 
                                (yyval.node)->type = get_id_type((yyvsp[0].id));  
                                add_current_params((yyval.node)->type); 
                                free((yyvsp[0].id));  
                              }
#line 2750 "lang.tab.c"
    break;

  case 86: /* callFuncParams: INT  */
#line 809 "lang.y"
                              { (yyval.node) = add_node0('I');
                                (yyval.node)->type = 0;
                                (yyval.node)->value = (char *) strdup((yyvsp[0].num));  
                                add_current_params((yyval.node)->type); 
                                free((yyvsp[0].num));   
                              }
#line 2761 "lang.tab.c"
    break;

  case 87: /* callFuncParams: DEC  */
#line 815 "lang.y"
                              { (yyval.node) = add_node0('D');
                                (yyval.node)->type = 1;
                                (yyval.node)->value = (char *) strdup((yyvsp[0].num));    
                                add_current_params((yyval.node)->type); 
                                free((yyvsp[0].num)); 
                              }
#line 2772 "lang.tab.c"
    break;

  case 88: /* callFuncParams: STR  */
#line 821 "lang.y"
                              { (yyval.node) = add_node0('S');
                                (yyval.node)->type = 2;
                                (yyval.node)->value = (char *) strdup((yyvsp[0].str));  
                                add_current_params((yyval.node)->type);  
                                free((yyvsp[0].str)); 
                              }
#line 2783 "lang.tab.c"
    break;

  case 89: /* callFuncParams: ID ',' callFuncParams  */
#line 827 "lang.y"
                              { (yyval.node) = add_node0('R');

                                (yyval.node)->node1 = add_node0('V');
                                (yyval.node)->node1->value = (char *) strdup((yyvsp[-2].id));    
                                (yyval.node)->node1->type = get_id_type((yyvsp[-2].id)); 

                                (yyval.node)->node2 = (yyvsp[0].node);
                                add_current_params((yyval.node)->node1->type);
                                free((yyvsp[-2].id));
                              }
#line 2798 "lang.tab.c"
    break;

  case 90: /* callFuncParams: INT ',' callFuncParams  */
#line 837 "lang.y"
                              { (yyval.node) = add_node0('R');

                                (yyval.node)->node1 = add_node0('I');
                                (yyval.node)->node1->type = 0;
                                (yyval.node)->node1->value = (char *) strdup((yyvsp[-2].num)); 

                                (yyval.node)->node2 = (yyvsp[0].node);  
                                add_current_params((yyval.node)->node1->type);
                                free((yyvsp[-2].num));  
                              }
#line 2813 "lang.tab.c"
    break;

  case 91: /* callFuncParams: DEC ',' callFuncParams  */
#line 847 "lang.y"
                              { (yyval.node) = add_node0('R');

                                (yyval.node)->node1 = add_node0('D');
                                (yyval.node)->node1->type = 1;
                                (yyval.node)->node1->value = (char *) strdup((yyvsp[-2].num));  

                                (yyval.node)->node2 = (yyvsp[0].node);
                                add_current_params((yyval.node)->node1->type);
                                free((yyvsp[-2].num));   
                              }
#line 2828 "lang.tab.c"
    break;

  case 92: /* callFuncParams: STR ',' callFuncParams  */
#line 857 "lang.y"
                              { (yyval.node) = add_node0('R');

                                (yyval.node)->node1 = add_node0('S');
                                (yyval.node)->node1->type = 2;
                                (yyval.node)->node1->value = (char *) strdup((yyvsp[-2].str));     

                                (yyval.node)->node2 = (yyvsp[0].node);
                                add_current_params((yyval.node)->node1->type);
                                free((yyvsp[-2].str));
                              }
#line 2843 "lang.tab.c"
    break;


#line 2847 "lang.tab.c"

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
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;
  *++yylsp = yyloc;

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
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      {
        yypcontext_t yyctx
          = {yyssp, yytoken, &yylloc};
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = yysyntax_error (&yymsg_alloc, &yymsg, &yyctx);
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == -1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = YY_CAST (char *,
                             YYSTACK_ALLOC (YY_CAST (YYSIZE_T, yymsg_alloc)));
            if (yymsg)
              {
                yysyntax_error_status
                  = yysyntax_error (&yymsg_alloc, &yymsg, &yyctx);
                yymsgp = yymsg;
              }
            else
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = YYENOMEM;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == YYENOMEM)
          goto yyexhaustedlab;
      }
    }

  yyerror_range[1] = yylloc;
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
                      yytoken, &yylval, &yylloc);
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

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;

      yyerror_range[1] = *yylsp;
      yydestruct ("Error: popping",
                  YY_ACCESSING_SYMBOL (yystate), yyvsp, yylsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  yyerror_range[2] = yylloc;
  ++yylsp;
  YYLLOC_DEFAULT (*yylsp, yyerror_range, 2);

  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

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


#if 1
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturn;
#endif


/*-------------------------------------------------------.
| yyreturn -- parsing is finished, clean up and return.  |
`-------------------------------------------------------*/
yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval, &yylloc);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp, yylsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
  return yyresult;
}

#line 869 "lang.y"


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
    default:
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

void add_current_params(int type) {
  struct params* new_params = (struct params*)calloc(1, sizeof(struct params));
  struct params* params;
  new_params->type = type;

  if (current_params == NULL) {
    current_params = (struct current_params*)calloc(1, sizeof(struct current_params));
    current_params->n_params = 1;
  } else {
    current_params->n_params = current_params->n_params + 1;
  }

  if (current_params->first == NULL) {
    current_params->first = new_params;
  } else {
    params = current_params->first;
    current_params->first = new_params;
    new_params->next = params;
  }
}

void free_current_params() {
  if (current_params != NULL) {
    free_params(current_params->first);
    free(current_params);
    current_params = NULL;
  }
}

void compare_params(char *id) {
  struct func_params* func_params;
  HASH_FIND_STR(func_table, id, func_params);

  struct params* params1;
  struct params* params2;

  if (current_params == NULL) {
    if (func_params->n_params != 0) {
      print_semantic_error(id, 10);
    }
  } else {
    if (func_params->n_params != current_params->n_params) {
      print_semantic_error(id, 10);
    }
    params1 = current_params->first;
    params2 = func_params->first;
    if (params1->type != params2->type) {
      print_semantic_error(id, 10);
    }
    while (params1->next != NULL) {
      params1 = params1->next;
      params2 = params2->next;
      if (params1->type != params2->type) {
        print_semantic_error(id, 10);
      }
    }
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
      printf("Simbolo: %s, Tipo: %d, Escopo: %s, key: %s\n", s->id, s->type, s->scope_name, s->key);
    } else {
      printf("Simbolo: %s, Tipo: %d, Escopo: Global, key: %s\n", s->id, s->type, s->key);
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
    // parametros n compativel
    case 10: 
      printf("parametros não compativeis na chamada da funcao: %s, linha: %d\n", id, line);
      break;

  }
  printf("\n\n########## Tabela de Símbolos ##########\n");
  print_symbol_table();
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

void yyerror (const char *s) {
  printf("\n######## ERRO ########\n");
  fprintf (stderr, "%s, linha: %d, posição: %d\n", s,line,word_position);
} 
