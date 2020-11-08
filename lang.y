%error-verbose
%debug
%locations

%{
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

int hasMain = 0;
int hasReturn = 0;
struct node* tree = NULL;
struct scope* scope_stack = NULL;
struct symbol_node* symbol_table = NULL;

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

%}

%union {
  char *id;
  char *num;
  char *type;
  char *str;
  struct node *node;
}

%type <node> prog globalList var func paramsList contentList params param content
%type <node> addValue comand print scan return callFunc expression op condition cond callFuncParams

%token <id> ID
%token <type> TYPEINT TYPEFLOAT TYPESTRING
%token <num> INT DEC
%token <str> STR
%token WHILE IF ELSE RETURN PRINT SCAN
%token CGE CGT CLE CLT CNE CEQ 

%%

prog:
  globalList { 
    tree = $1;
    if (hasMain == 0) {
      print_semantic_error(NULL, 7);
    }
  }
;

globalList:
  globalList var { $$ = add_node2('R', $1, $2); }       
| var            { $$ = $1; }                       
| func           { $$ = $1; }                    
| globalList func { $$ = add_node2('R', $1, $2); }                               
;

var:
  TYPEINT ID ';'          { $$ = add_node0('v'); 
                            $$->type = 0;
                            $$->value = (char *) strdup($2);   
                            add_symbol_table($2, 0);  
                            free($1);
                            free($2); 
                          } 
| TYPEINT ID '=' INT ';' {  $$ = add_node0('v'); 
                            $$->type = 0;
                            $$->value = (char *) strdup($2);

                            $$->node1 = add_node0('A');
                            $$->node1->type = 0;
                            $$->node1->node1 = add_node0('V');
                            $$->node1->node1->type = 0;
                            $$->node1->node1->value = (char *) strdup($2);
                            $$->node1->node2 = add_node0('I');
                            $$->node1->node2->type = 0;
                            $$->node1->node2->value = (char *) strdup($4);
                            add_symbol_table($2, 0);
                            free($1);
                            free($2); 
                            free($4); 
                          } 
| TYPEFLOAT ID ';'        { $$ = add_node0('v'); 
                            $$->type = 1;
                            $$->value = (char *) strdup($2);  
                            add_symbol_table($2, 1);
                            free($1);
                            free($2); 
                          } 
| TYPEFLOAT ID '=' INT ';'  {  $$ = add_node0('v'); 
                            $$->type = 1;
                            $$->value = (char *) strdup($2);

                            $$->node1 = add_node0('A');
                            $$->node1->type = 1;
                            $$->node1->node1 = add_node0('V');
                            $$->node1->node1->type = 1;
                            $$->node1->node1->value = (char *) strdup($2);
                            $$->node1->node2 = add_node0('I');
                            $$->node1->node2->type = 0;
                            $$->node1->node2->value = (char *) strdup($4);
                            add_symbol_table($2, 1);
                            free($1);
                            free($2); 
                            free($4); 
                          }
| TYPEFLOAT ID '=' DEC ';'{  $$ = add_node0('v'); 
                            $$->type = 1;
                            $$->value = (char *) strdup($2);

                            $$->node1 = add_node0('A');
                            $$->node1->type = 1;
                            $$->node1->node1 = add_node0('V');
                            $$->node1->node1->type = 1;
                            $$->node1->node1->value = (char *) strdup($2);
                            $$->node1->node2 = add_node0('D');
                            $$->node1->node2->type = 1;
                            $$->node1->node2->value = (char *) strdup($4);
                            add_symbol_table($2, 1);
                            free($1);
                            free($2); 
                            free($4); 
                          }
| TYPESTRING ID ';'       { $$ = add_node0('v'); 
                            $$->type = 2;
                            $$->value = (char *) strdup($2);    
                            add_symbol_table($2, 2);
                            free($1);
                            free($2); 
                          } 
| TYPESTRING ID '=' STR ';' {  $$ = add_node0('v'); 
                            $$->type = 2;
                            $$->value = (char *) strdup($2);

                            $$->node1 = add_node0('A');
                            $$->node1->type = 2;
                            $$->node1->node1 = add_node0('V');
                            $$->node1->node1->type = 2;
                            $$->node1->node1->value = (char *) strdup($2);
                            $$->node1->node2 = add_node0('S');
                            $$->node1->node2->type = 2;
                            $$->node1->node2->value = (char *) strdup($4);
                            add_symbol_table($2, 2);
                            free($1);
                            free($2); 
                            free($4); 
                          }
;

func:
  TYPESTRING ID                                         { 
                                                          add_symbol_table($2, 2); add_scope($2, 2); 
                                                          hasReturn = 0;
                                                        }
  '(' paramsList ')'                                    {;}
  '{' contentList '}'                                   { 
                                                          $$ = add_node2('F', $5, $9); 
                                                          $$->type = 2;
                                                          $$->value = (char *) strdup($2); 
                                                          if (hasReturn == 0) {
                                                            print_semantic_error($2, 8);
                                                          }
                                                          remove_scope();   
                                                          free($1);
                                                          free($2); 
                                                        } 

| TYPEFLOAT ID                                          { add_symbol_table($2, 1); add_scope($2, 1); hasReturn = 0; }
'(' paramsList ')'                                      {;}
'{' contentList '}'                                     {  
                                                          $$ = add_node2('F', $5, $9); 
                                                          $$->type = 1;
                                                          $$->value = (char *) strdup($2);   
                                                          if (hasReturn == 0) {
                                                            print_semantic_error($2, 8);
                                                          }  
                                                          remove_scope();
                                                          free($1);
                                                          free($2);
                                                        } 

| TYPEINT ID                                            { 
                                                          add_symbol_table($2, 0); add_scope($2, 0);
                                                          if (strcmp($2, "main") == 0) {
                                                            hasMain = 1;
                                                          }
                                                          hasReturn = 0;
                                                        }
'(' paramsList ')'                                      {;}
'{' contentList '}'                                     {
                                                          $$ = add_node2('F', $5, $9); 
                                                          $$->type = 0;
                                                          $$->value = (char *) strdup($2);
                                                          if (hasReturn == 0) {
                                                            print_semantic_error($2, 8);
                                                          }
                                                          remove_scope();
                                                          free($1);
                                                          free($2);
                                                        } 
;

paramsList:
  params { $$ = $1; }
|        { $$ = NULL; }
;

params:
  param { $$ = $1; }
| param ',' params { $$ = add_node2('R', $1, $3); }
;

param:
  TYPEINT ID              { $$ = add_node0('P'); 
                            $$->type = 0;
                            $$->value = (char *) strdup($2); 
                            add_symbol_table($2, 0); 
                            free($1);
                            free($2); 
                          } 
| TYPEFLOAT ID            { $$ = add_node0('P'); 
                            $$->type = 1;
                            $$->value = (char *) strdup($2);    
                            add_symbol_table($2, 1);
                            free($1);
                            free($2);  
                          } 
| TYPESTRING ID           { $$ = add_node0('P'); 
                            $$->type = 2;
                            $$->value = (char *) strdup($2);
                            add_symbol_table($2, 2);
                            free($1);
                            free($2);      
                          } 
;

contentList:
  content contentList    { $$ = add_node2('R', $1, $2); }  
|                        { $$ = NULL; }
;

content:
  var         { $$ = $1; }
| addValue    { $$ = $1; }
| comand      { $$ = $1; }
| print       { $$ = $1; }
| scan        { $$ = $1; }
| return      { $$ = $1; }
| callFunc    { $$ = $1; }
;

addValue:
ID '=' expression ';'      { 
                            $$ = add_node0('A');
                            $$->type = get_id_type($1);
                            $$->node1 = add_node0('V');
                            $$->node1->type = get_id_type($1);
                            $$->node1->value = (char *) strdup($1);
                            $$->node2 = $3;
                            if ($$->node1->type != $$->node2->type) {
                              if (!($$->node1->type == 1 && $$->node2->type == 0)) {
                                print_semantic_error($$->node1->value, 4);
                              }
                            }
                            free($1);
                          }
;

expression:
ID                        { $$ = add_node0('V'); 
                            $$->value = (char *) strdup($1);   
                            $$->type = get_id_type($1);
                            free($1);  
                          }
| INT                     { $$ = add_node0('I');
                            $$->type = 0;
                            $$->value = (char *) strdup($1);    
                            free($1); 
                          }
| DEC                     { $$ = add_node0('D'); 
                            $$->type = 1;
                            $$->value = (char *) strdup($1);  
                            free($1);   
                          }
| STR                     { $$ = add_node0('S'); 
                            $$->type = 2;
                            $$->value = (char *) strdup($1);  
                            free($1);   
                          }
| ID op expression        { $$ = add_node0('E');

                            $$->node1 = add_node0('V');
                            $$->node1->value = (char *) strdup($1);
                            $$->node1->type = get_id_type($1);

                            $$->node2 = $2;
                            $$->node3 = $3;
                            build_expression_type($$);
                            free($1);
                          }
| INT op expression       { $$ = add_node0('E');

                            $$->node1 = add_node0('I');
                            $$->node1->type = 0;
                            $$->node1->value = (char *) strdup($1);

                            $$->node2 = $2;
                            $$->node3 = $3;
                            build_expression_type($$);
                            free($1);
                          }
| DEC op expression       { $$ = add_node0('E');

                            $$->node1 = add_node0('D');
                            $$->node1->type = 1;
                            $$->node1->value = (char *) strdup($1);

                            $$->node2 = $2;
                            $$->node3 = $3;
                            build_expression_type($$);
                            free($1);
                          }
| STR op expression       { $$ = add_node0('E');

                            $$->node1 = add_node0('S');
                            $$->node1->type = 2;
                            $$->node1->value = (char *) strdup($1);

                            $$->node2 = $2;
                            $$->node3 = $3;
                            build_expression_type($$);
                            free($1);
                          }
;

op:
  '+'   { $$ = add_node0('B'); 
          $$->value = (char *) strdup("+");     
        }
| '-'   { $$ = add_node0('B'); 
          $$->value = (char *) strdup("-");     
        }
| '/'   { $$ = add_node0('B'); 
          $$->value = (char *) strdup("/");     
        }
| '*'   { $$ = add_node0('B'); 
          $$->value = (char *) strdup("*");     
        }
;

comand:
  IF '(' condition ')' '{' contentList '}'                            { $$ = add_node2('C', $3, $6); }
| IF '(' condition ')' '{' contentList '}' ELSE '{' contentList '}'   { $$ = add_node3('C', $3, $6, $10); }
| WHILE '(' condition ')' '{' contentList '}'                         { $$ = add_node2('W', $3, $6); }
;

condition:
  ID cond ID      { $$ = add_node0('c');

                    $$->node1 = add_node0('V');
                    $$->node1->value = (char *) strdup($1);
                    $$->node1->type = get_id_type($1);

                    $$->node2 = $2;
                    
                    $$->node3 = add_node0('V');
                    $$->node3->value = (char *) strdup($3);
                    $$->node3->type = get_id_type($3);
                    free($1);
                    free($3);
                  }
| ID cond INT     { $$ = add_node0('c');

                    $$->node1 = add_node0('V');
                    $$->node1->value = (char *) strdup($1);
                    $$->node1->type = get_id_type($1);

                    $$->node2 = $2;
                    
                    $$->node3 = add_node0('I');
                    $$->node3->type = 0;
                    $$->node3->value = (char *) strdup($3);
                    free($1);
                    free($3);
                  }
| ID cond DEC     { $$ = add_node0('c');

                    $$->node1 = add_node0('V');
                    $$->node1->value = (char *) strdup($1);
                    $$->node1->type = get_id_type($1);

                    $$->node2 = $2;
                    
                    $$->node3 = add_node0('D');
                    $$->node3->type = 1;
                    $$->node3->value = (char *) strdup($3);
                    free($1);
                    free($3);
                  }
| INT cond ID     { $$ = add_node0('c');

                    $$->node1 = add_node0('I');
                    $$->node1->type = 0;
                    $$->node1->value = (char *) strdup($1);

                    $$->node2 = $2;
                    
                    $$->node3 = add_node0('V');
                    $$->node3->value = (char *) strdup($3);
                    $$->node3->type = get_id_type($3);
                    free($1);
                    free($3);
                  }
| INT cond INT    { $$ = add_node0('c');

                    $$->node1 = add_node0('I');
                    $$->node1->type = 0;
                    $$->node1->value = (char *) strdup($1);

                    $$->node2 = $2;
                    
                    $$->node3 = add_node0('I');
                    $$->node3->type = 0;
                    $$->node3->value = (char *) strdup($3);
                    free($1);
                    free($3);
                  }
| INT cond DEC    { $$ = add_node0('c');

                    $$->node1 = add_node0('I');
                    $$->node1->type = 0;
                    $$->node1->value = (char *) strdup($1);

                    $$->node2 = $2;
                    
                    $$->node3 = add_node0('D');
                    $$->node3->type = 1;
                    $$->node3->value = (char *) strdup($3);
                    free($1);
                    free($3);
                  }
| DEC cond ID     { $$ = add_node0('c');

                    $$->node1 = add_node0('D');
                    $$->node1->type = 2;
                    $$->node1->value = (char *) strdup($1);

                    $$->node2 = $2;
                    
                    $$->node3 = add_node0('V');
                    $$->node3->value = (char *) strdup($3);
                    $$->node3->type = get_id_type($3);
                    free($1);
                    free($3);
                  }
| DEC cond INT    { $$ = add_node0('c');

                    $$->node1 = add_node0('D');
                    $$->node1->type = 2;
                    $$->node1->value = (char *) strdup($1);

                    $$->node2 = $2;
                    
                    $$->node3 = add_node0('I');
                    $$->node3->type = 1;
                    $$->node3->value = (char *) strdup($3);
                    free($1);
                    free($3);
                  }
| DEC cond DEC    { $$ = add_node0('c');

                    $$->node1 = add_node0('D');
                    $$->node1->type = 2;
                    $$->node1->value = (char *) strdup($1);

                    $$->node2 = $2;
                    
                    $$->node3 = add_node0('D');
                    $$->node3->type = 2;
                    $$->node3->value = (char *) strdup($3);
                    free($1);
                    free($3);
                  }
;

cond:
  CGE   { $$ = add_node0('B'); 
          $$->value = (char *) strdup("CGE");     
        }
| CGT   { $$ = add_node0('B'); 
          $$->value = (char *) strdup("CGT");     
        }
| CLE   { $$ = add_node0('B'); 
          $$->value = (char *) strdup("CLE");     
        }
| CLT   { $$ = add_node0('B'); 
          $$->value = (char *) strdup("CLT");     
        }
| CNE   { $$ = add_node0('B'); 
          $$->value = (char *) strdup("CNE");     
        }
| CEQ   { $$ = add_node0('B'); 
          $$->value = (char *) strdup("CEQ");     
        }
;

print:
  PRINT '(' ID ')' ';'    { $$ = add_node0('L');
                            $$->value = (char *) strdup("PRINT");
                            $$->node1 = add_node0('V');
                            $$->node1->value = (char *) strdup($3); 
                            $$->node1->type = get_id_type($3);
                            free($3);    
                          }
| PRINT '(' STR ')' ';'   { $$ = add_node0('L');
                            $$->value = (char *) strdup("PRINT");
                            $$->node1 = add_node0('S');
                            $$->node1->type = 2;
                            $$->node1->value = (char *) strdup($3); 
                            free($3);    
                          }
| PRINT '(' INT ')' ';'   { $$ = add_node0('L');
                            $$->value = (char *) strdup("PRINT");
                            $$->node1 = add_node0('I');
                            $$->node1->type = 0;
                            $$->node1->value = (char *) strdup($3); 
                            free($3);    
                          }
| PRINT '(' DEC ')' ';'   { $$ = add_node0('L');
                            $$->value = (char *) strdup("PRINT");
                            $$->node1 = add_node0('D');
                            $$->node1->type = 1;
                            $$->node1->value = (char *) strdup($3);     
                            free($3);
                          }
;

scan:
  SCAN '(' ID ',' TYPEINT ')' ';'       { $$ = add_node0('L');
                                          $$->type = 0;
                                          $$->value = (char *) strdup("SCAN");
                                          $$->node1 = add_node0('V');
                                          $$->node1->value = (char *) strdup($3);   
                                          $$->node1->type = get_id_type($3);
                                          if ($$->type != $$->node1->type) {
                                            print_semantic_error($$->node1->value, 6);
                                          }
                                          free($3);  
                                          free($5);  
                                        }
| SCAN '(' ID ',' TYPEFLOAT ')' ';'     { $$ = add_node0('L');
                                          $$->type = 1;
                                          $$->value = (char *) strdup("SCAN");
                                          $$->node1 = add_node0('V');
                                          $$->node1->value = (char *) strdup($3); 
                                          $$->node1->type = get_id_type($3); 
                                          if ($$->type != $$->node1->type) {
                                            print_semantic_error($$->node1->value, 6);
                                          }
                                          free($3);  
                                          free($5);     
                                        }
| SCAN '(' ID ',' TYPESTRING ')' ';'    { $$ = add_node0('L');
                                          $$->type = 2;
                                          $$->value = (char *) strdup("SCAN");
                                          $$->node1 = add_node0('V');
                                          $$->node1->value = (char *) strdup($3); 
                                          $$->node1->type = get_id_type($3); 
                                          if ($$->type != $$->node1->type) {
                                            print_semantic_error($$->node1->value, 6);
                                          }
                                          free($3);  
                                          free($5);     
                                        }
;

return:
  RETURN '(' ID ')' ';'   { $$ = add_node0('L');
                            struct scope* scope = get_last_scope();
                            $$->type  = scope->type;
                            $$->value = (char *) strdup("RETURN");
                            $$->node1 = add_node0('V');
                            $$->node1->value = (char *) strdup($3);   
                            $$->node1->type = get_id_type($3); 
                            if ($$->type != $$->node1->type) {
                              print_semantic_error($$->node1->value, 5);
                            }
                            hasReturn = 1;
                            free($3); 
                          }
| RETURN '(' STR ')' ';'  { $$ = add_node0('L');
                            struct scope* scope = get_last_scope();
                            $$->type  = scope->type;
                            $$->value = (char *) strdup("RETURN");
                            $$->node1 = add_node0('S');
                            $$->node1->type = 2;
                            $$->node1->value = (char *) strdup($3); 
                            if ($$->type != $$->node1->type) {
                              print_semantic_error($$->node1->value, 5);
                            } 
                            hasReturn = 1;
                            free($3);   
                          }
| RETURN '(' INT ')' ';'  { $$ = add_node0('L');
                            struct scope* scope = get_last_scope();
                            $$->type  = scope->type;
                            $$->value = (char *) strdup("RETURN");
                            $$->node1 = add_node0('I');
                            $$->node1->type = 0;
                            $$->node1->value = (char *) strdup($3);  
                            if ($$->type != $$->node1->type) {
                              print_semantic_error($$->node1->value, 5);
                            }
                            hasReturn = 1;
                            free($3);   
                          }
| RETURN '(' DEC ')' ';'  { $$ = add_node0('L');
                            struct scope* scope = get_last_scope();
                            $$->type  = scope->type;
                            $$->value = (char *) strdup("RETURN");
                            $$->node1 = add_node0('D');
                            $$->node1->type = 1;
                            $$->node1->value = (char *) strdup($3);  
                            if ($$->type != $$->node1->type) {
                              print_semantic_error($$->node1->value, 5);
                            }
                            hasReturn = 1;
                            free($3);   
                          }
;

callFunc:
  ID '(' callFuncParams ')' ';'           { $$ = add_node1('L', $3);
                                            $$->value = (char *) strdup($1);  
                                            $$->type = get_id_type($1);
                                            free($1);  
                                          }
| ID '=' ID '(' callFuncParams ')' ';'    { $$ = add_node0('A');
                                            $$->node1 = add_node0('V');
                                            $$->node1->value = (char *) strdup($1);
                                            $$->node1->type = get_id_type($1);
                                            $$->node2 = add_node1('L', $5);
                                            $$->node2->value = (char *) strdup($3); 
                                            $$->node2->type = get_id_type($3);

                                            if ($$->node1->type != $$->node2->type) {
                                              if (!($$->node1->type == 1 && $$->node2->type == 0)) {
                                                print_semantic_error($$->node1->value, 4);
                                              }
                                            }


                                            free($1);  
                                            free($3);     
                                          }
| ID '(' ')' ';'                          { $$ = add_node0('L');
                                            $$->value = (char *) strdup($1);  
                                            $$->type = get_id_type($1);
                                            free($1);  
                                          }
| ID '=' ID '(' ')' ';'                    { $$ = add_node0('A');
                                            $$->node1 = add_node0('V');
                                            $$->node1->value = (char *) strdup($1);
                                            $$->node1->type = get_id_type($1);
                                            $$->node2 = add_node0('L');
                                            $$->node2->value = (char *) strdup($3); 
                                            $$->node2->type = get_id_type($3);

                                            if ($$->node1->type != $$->node2->type) {
                                              if (!($$->node1->type == 1 && $$->node2->type == 0)) {
                                                print_semantic_error($$->node1->value, 4);
                                              }
                                            }


                                            free($1);  
                                            free($3);     
                                          }
;

callFuncParams:
  ID                          { $$ = add_node0('V');
                                $$->value = (char *) strdup($1); 
                                $$->type = get_id_type($1);  
                                free($1);  
                              }
| INT                         { $$ = add_node0('I');
                                $$->type = 0;
                                $$->value = (char *) strdup($1);  
                                free($1);   
                              }
| DEC                         { $$ = add_node0('D');
                                $$->type = 1;
                                $$->value = (char *) strdup($1);    
                                free($1); 
                              }
| STR                         { $$ = add_node0('S');
                                $$->type = 2;
                                $$->value = (char *) strdup($1);    
                                free($1); 
                              }
| ID ',' callFuncParams       { $$ = add_node0('R');

                                $$->node1 = add_node0('V');
                                $$->node1->value = (char *) strdup($1);    
                                $$->node1->type = get_id_type($1); 

                                $$->node2 = $3;
                                free($1);
                              }
| INT ',' callFuncParams      { $$ = add_node0('R');

                                $$->node1 = add_node0('I');
                                $$->node1->type = 0;
                                $$->node1->value = (char *) strdup($1); 

                                $$->node2 = $3;  
                                free($1);  
                              }
| DEC ',' callFuncParams      { $$ = add_node0('R');

                                $$->node1 = add_node0('D');
                                $$->node1->type = 1;
                                $$->node1->value = (char *) strdup($1);  

                                $$->node2 = $3;
                                free($1);   
                              }
| STR ',' callFuncParams      { $$ = add_node0('R');

                                $$->node1 = add_node0('S');
                                $$->node1->type = 2;
                                $$->node1->value = (char *) strdup($1);     

                                $$->node2 = $3;
                                free($1);
                              }
;

%%

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


  yylex_destroy();
  free_tree(tree);
  free_symbol_table();
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