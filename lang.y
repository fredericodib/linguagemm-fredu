%error-verbose
%debug
%locations

%{
void yyerror (char *s);
int yylex();
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
- E -> Espreção
- A -> Atribuição
- D -> Declaration
- L -> chama função

# type
- 0 = int
- 1 = float
- 2 = string
- 3 = none
*/

struct node* tree = NULL;

struct node* add_node3(char node_type, struct node *node1, struct node *node2, struct node *node3);
struct node* add_node2(char node_type, struct node *node1, struct node *node2);
struct node* add_node1(char node_type, struct node *node1);
struct node* add_node0(char node_type);
void print_tree(struct node *node, int depth);

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
  globalList { tree = $1; }
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
                          } 
| TYPEINT ID '=' INT ';' {  $$ = add_node0('v'); 
                            $$->type = 0;
                            $$->value = (char *) strdup($2);

                            $$->node1 = add_node0('A');
                            $$->node1->node1 = add_node0('V');
                            $$->node1->node1->type = 0;
                            $$->node1->node1->value = (char *) strdup($2);
                            $$->node1->node2 = add_node0('I');
                            $$->node1->node2->type = 0;
                            $$->node1->node2->value = (char *) strdup($4);
                          } 
| TYPEFLOAT ID ';'        { $$ = add_node0('v'); 
                            $$->type = 1;
                            $$->value = (char *) strdup($2);     
                          } 
| TYPEFLOAT ID '=' INT ';'  {  $$ = add_node0('v'); 
                            $$->type = 1;
                            $$->value = (char *) strdup($2);

                            $$->node1 = add_node0('A');
                            $$->node1->node1 = add_node0('V');
                            $$->node1->node1->type = 1;
                            $$->node1->node1->value = (char *) strdup($2);
                            $$->node1->node2 = add_node0('I');
                            $$->node1->node2->type = 0;
                            $$->node1->node2->value = (char *) strdup($4);
                          }
| TYPEFLOAT ID '=' DEC ';'{  $$ = add_node0('v'); 
                            $$->type = 1;
                            $$->value = (char *) strdup($2);

                            $$->node1 = add_node0('A');
                            $$->node1->node1 = add_node0('V');
                            $$->node1->node1->type = 1;
                            $$->node1->node1->value = (char *) strdup($2);
                            $$->node1->node2 = add_node0('D');
                            $$->node1->node2->type = 1;
                            $$->node1->node2->value = (char *) strdup($4);
                          }
| TYPESTRING ID ';'       { $$ = add_node0('v'); 
                            $$->type = 2;
                            $$->value = (char *) strdup($2);     
                          } 
| TYPESTRING ID '=' STR ';' {  $$ = add_node0('v'); 
                            $$->type = 2;
                            $$->value = (char *) strdup($2);

                            $$->node1 = add_node0('A');
                            $$->node1->node1 = add_node0('V');
                            $$->node1->node1->type = 2;
                            $$->node1->node1->value = (char *) strdup($2);
                            $$->node1->node2 = add_node0('S');
                            $$->node1->node2->type = 2;
                            $$->node1->node2->value = (char *) strdup($4);
                          }
;

func:
  TYPESTRING ID '(' paramsList ')' '{' contentList '}' { 
                                                          $$ = add_node2('F', $4, $7); 
                                                          $$->type = 2;
                                                          $$->value = (char *) strdup($2);     
                                                        } 
| TYPEFLOAT ID '(' paramsList ')' '{' contentList '}'  {  
                                                          $$ = add_node2('F', $4, $7); 
                                                          $$->type = 1;
                                                          $$->value = (char *) strdup($2);     
                                                        } 
| TYPEINT ID '(' paramsList ')' '{' contentList '}'     {    
                                                          $$ = add_node2('F', $4, $7); 
                                                          $$->type = 0;
                                                          $$->value = (char *) strdup($2);     
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
                          } 
| TYPEFLOAT ID            { $$ = add_node0('P'); 
                            $$->type = 1;
                            $$->value = (char *) strdup($2);     
                          } 
| TYPESTRING ID           { $$ = add_node0('P'); 
                            $$->type = 2;
                            $$->value = (char *) strdup($2);     
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
                            $$->node1 = add_node0('V');
                            $$->node1->value = (char *) strdup($1);
                            $$->node2 = $3;
                          }
;

expression:
ID                        { $$ = add_node0('V'); 
                            $$->value = (char *) strdup($1);     
                          }
| INT                     { $$ = add_node0('I');
                            $$->type = 0;
                            $$->value = (char *) strdup($1);     
                          }
| DEC                     { $$ = add_node0('D'); 
                            $$->type = 1;
                            $$->value = (char *) strdup($1);     
                          }
| STR                     { $$ = add_node0('S'); 
                            $$->type = 2;
                            $$->value = (char *) strdup($1);     
                          }
| ID op expression        { $$ = add_node0('E');

                            $$->node1 = add_node0('V');
                            $$->node1->value = (char *) strdup($1);

                            $$->node2 = $2;
                            $$->node3 = $3;
                          }
| INT op expression       { $$ = add_node0('E');

                            $$->node1 = add_node0('I');
                            $$->node1->type = 0;
                            $$->node1->value = (char *) strdup($1);

                            $$->node2 = $2;
                            $$->node3 = $3;
                          }
| DEC op expression       { $$ = add_node0('E');

                            $$->node1 = add_node0('D');
                            $$->node1->type = 1;
                            $$->node1->value = (char *) strdup($1);

                            $$->node2 = $2;
                            $$->node3 = $3;
                          }
| STR op expression       { $$ = add_node0('E');

                            $$->node1 = add_node0('S');
                            $$->node1->type = 2;
                            $$->node1->value = (char *) strdup($1);

                            $$->node2 = $2;
                            $$->node3 = $3;
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

                    $$->node2 = $2;
                    
                    $$->node3 = add_node0('V');
                    $$->node3->value = (char *) strdup($1);
                  }
| ID cond INT     { $$ = add_node0('c');

                    $$->node1 = add_node0('V');
                    $$->node1->value = (char *) strdup($1);

                    $$->node2 = $2;
                    
                    $$->node3 = add_node0('I');
                    $$->node3->type = 0;
                    $$->node3->value = (char *) strdup($1);
                  }
| ID cond DEC     { $$ = add_node0('c');

                    $$->node1 = add_node0('V');
                    $$->node1->value = (char *) strdup($1);

                    $$->node2 = $2;
                    
                    $$->node3 = add_node0('D');
                    $$->node3->type = 1;
                    $$->node3->value = (char *) strdup($1);
                  }
| INT cond ID     { $$ = add_node0('c');

                    $$->node1 = add_node0('I');
                    $$->node3->type = 0;
                    $$->node1->value = (char *) strdup($1);

                    $$->node2 = $2;
                    
                    $$->node3 = add_node0('V');
                    $$->node3->value = (char *) strdup($1);
                  }
| INT cond INT    { $$ = add_node0('c');

                    $$->node1 = add_node0('I');
                    $$->node3->type = 0;
                    $$->node1->value = (char *) strdup($1);

                    $$->node2 = $2;
                    
                    $$->node3 = add_node0('I');
                    $$->node3->type = 0;
                    $$->node3->value = (char *) strdup($1);
                  }
| INT cond DEC    { $$ = add_node0('c');

                    $$->node1 = add_node0('I');
                    $$->node3->type = 0;
                    $$->node1->value = (char *) strdup($1);

                    $$->node2 = $2;
                    
                    $$->node3 = add_node0('D');
                    $$->node3->type = 1;
                    $$->node3->value = (char *) strdup($1);
                  }
| DEC cond ID     { $$ = add_node0('c');

                    $$->node1 = add_node0('D');
                    $$->node3->type = 2;
                    $$->node1->value = (char *) strdup($1);

                    $$->node2 = $2;
                    
                    $$->node3 = add_node0('V');
                    $$->node3->value = (char *) strdup($1);
                  }
| DEC cond INT    { $$ = add_node0('c');

                    $$->node1 = add_node0('D');
                    $$->node3->type = 2;
                    $$->node1->value = (char *) strdup($1);

                    $$->node2 = $2;
                    
                    $$->node3 = add_node0('I');
                    $$->node3->type = 1;
                    $$->node3->value = (char *) strdup($1);
                  }
| DEC cond DEC    { $$ = add_node0('c');

                    $$->node1 = add_node0('D');
                    $$->node3->type = 2;
                    $$->node1->value = (char *) strdup($1);

                    $$->node2 = $2;
                    
                    $$->node3 = add_node0('D');
                    $$->node3->type = 2;
                    $$->node3->value = (char *) strdup($1);
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
                          }
| PRINT '(' STR ')' ';'   { $$ = add_node0('L');
                            $$->value = (char *) strdup("PRINT");
                            $$->node1 = add_node0('S');
                            $$->node1->type = 2;
                            $$->node1->value = (char *) strdup($3);     
                          }
| PRINT '(' INT ')' ';'   { $$ = add_node0('L');
                            $$->value = (char *) strdup("PRINT");
                            $$->node1 = add_node0('I');
                            $$->node1->type = 0;
                            $$->node1->value = (char *) strdup($3);     
                          }
| PRINT '(' DEC ')' ';'   { $$ = add_node0('L');
                            $$->value = (char *) strdup("PRINT");
                            $$->node1 = add_node0('D');
                            $$->node1->type = 1;
                            $$->node1->value = (char *) strdup($3);     
                          }
;

scan:
  SCAN '(' ID ',' TYPEINT ')' ';'       { $$ = add_node0('L');
                                          $$->type = 0;
                                          $$->value = (char *) strdup("SCAN");
                                          $$->node1 = add_node0('V');
                                          $$->node1->value = (char *) strdup($3);     
                                        }
| SCAN '(' ID ',' TYPEFLOAT ')' ';'     { $$ = add_node0('L');
                                          $$->type = 1;
                                          $$->value = (char *) strdup("SCAN");
                                          $$->node1 = add_node0('V');
                                          $$->node1->value = (char *) strdup($3);     
                                        }
| SCAN '(' ID ',' TYPESTRING ')' ';'    { $$ = add_node0('L');
                                          $$->type = 2;
                                          $$->value = (char *) strdup("SCAN");
                                          $$->node1 = add_node0('V');
                                          $$->node1->value = (char *) strdup($3);     
                                        }
;

return:
  RETURN '(' ID ')' ';'   { $$ = add_node0('L');
                            $$->value = (char *) strdup("RETURN");
                            $$->node1 = add_node0('V');
                            $$->node1->value = (char *) strdup($3);     
                          }
| RETURN '(' STR ')' ';'  { $$ = add_node0('L');
                            $$->value = (char *) strdup("RETURN");
                            $$->node1 = add_node0('S');
                            $$->node1->type = 2;
                            $$->node1->value = (char *) strdup($3);     
                          }
| RETURN '(' INT ')' ';'  { $$ = add_node0('L');
                            $$->value = (char *) strdup("RETURN");
                            $$->node1 = add_node0('I');
                            $$->node1->type = 0;
                            $$->node1->value = (char *) strdup($3);     
                          }
| RETURN '(' DEC ')' ';'  { $$ = add_node0('L');
                            $$->value = (char *) strdup("RETURN");
                            $$->node1 = add_node0('D');
                            $$->node1->type = 1;
                            $$->node1->value = (char *) strdup($3);     
                          }
;

callFunc:
  ID '(' callFuncParams ')' ';'           { $$ = add_node1('L', $3);
                                            $$->value = (char *) strdup($1);    
                                          }
| ID '=' ID '(' callFuncParams ')' ';'    { $$ = add_node0('A');
                                            $$->node1 = add_node0('V');
                                            $$->node1->value = (char *) strdup($1);
                                            $$->node2 = add_node1('L', $5);
                                            $$->node2->value = (char *) strdup($3);    
                                          }
;

callFuncParams:
  ID                          { $$ = add_node0('V');
                                $$->value = (char *) strdup($1);     
                              }
| INT                         { $$ = add_node0('I');
                                $$->type = 0;
                                $$->value = (char *) strdup($1);     
                              }
| DEC                         { $$ = add_node0('D');
                                $$->type = 1;
                                $$->value = (char *) strdup($1);     
                              }
| STR                         { $$ = add_node0('S');
                                $$->type = 2;
                                $$->value = (char *) strdup($1);     
                              }
| ID ',' callFuncParams       { $$ = add_node1('R', $3);

                                $$->node1 = add_node0('V');
                                $$->node1->value = (char *) strdup($1);     
                              }
| INT ',' callFuncParams      { $$ = add_node1('R', $3);

                                $$->node1 = add_node0('I');
                                $$->node1->type = 0;
                                $$->node1->value = (char *) strdup($1);     
                              }
| DEC ',' callFuncParams      { $$ = add_node1('R', $3);

                                $$->node1 = add_node0('D');
                                $$->node1->type = 1;
                                $$->node1->value = (char *) strdup($1);     
                              }
| STR ',' callFuncParams      { $$ = add_node1('R', $3);

                                $$->node1 = add_node0('S');
                                $$->node1->type = 2;
                                $$->node1->value = (char *) strdup($1);     
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
  printf("\n\n########## Arvore Binaria ##########\n");
  print_tree(tree, 0);
  yylex_destroy();
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
      printf("<Atribuição> %s = \n", node->node1->value);
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
      printf("<EXPRESSION>\n");
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
        printf("<CHAMA FUNÇÃO> %s", node->value);
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

void yyerror (char *s) {fprintf (stderr, "%s\n", s); exit(1);} 