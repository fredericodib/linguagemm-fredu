%option noyywrap
%option nounput
%option noinput

%{
#include "lang.tab.h"
#include "global_variable.h"
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

int line = 1;
int word_position = 1;
int errors_num = 0;
int simble_table_index = 0;

struct ErrorStruct {
    char word[50];
    char message[100];
    int line;
    int word_position;
};

struct Simble {
    char id[50];
    int line;
};

struct ErrorStruct errors[700];
struct Simble simbleTable[700];

void printError() {
    printf("\n######### ERROR #########\n");
    printf("Número do erro: %d\n", errors_num);
    printf("Palavra: %s\n", errors[errors_num-1].word);
    printf("Mensagem do erro: %s\n", errors[errors_num-1].message);
    printf("Line: %d\n", errors[errors_num-1].line);
    printf("Posição: %d\n", errors[errors_num-1].word_position);
    printf("##################\n\n");
}

%}

%x C_COMMENT


eql \n
letter [a-zA-Z]
digit [0-9]
id {letter}({letter}|{digit})*
num {digit}+
dec {digit}+"."{digit}+

plus "+"
minus "-"
mult "*"
div "/"

str \"(\\.|[^"\\])*\"

eq "="

ceq "=="
cne "!="
clt "<"
cle "<="
cgt ">"
cge ">="

if "if"
while "while"
else "else"
return "return"
print "print"
scan "scan"

typeInt "int"
typeFloat "float"
typeString "string"

%%

{typeInt} { 
    word_position += 1;
    printf("typeInt (%s)\n", yytext);
    yylval.type = (char *) strdup(yytext);
    return TYPEINT;
}

{typeFloat} { 
    word_position += 1;
    printf("typeFloat (%s)\n", yytext);
    yylval.type = (char *) strdup(yytext);
    return TYPEFLOAT;
}

{typeString} { 
    word_position += 1;
    printf("typeString (%s)\n", yytext);
    yylval.type = (char *) strdup(yytext);
    return TYPESTRING;
}

{num}+{letter}+({letter}|{digit})* {
    strcpy(errors[errors_num].word, yytext);
    strcpy(errors[errors_num].message, "id iniciado com numero");
    errors[errors_num].line = line;
    errors[errors_num].word_position = word_position;
    errors_num++;
    printError();
    word_position += 1;
    exit(1);
}

{dec} { 
    word_position += 1;
    printf("dec (%s)\n", yytext); 
    yylval.num = (char *) strdup(yytext);
    return DEC;
}

{num} { 
    word_position += 1;
    printf("num (%s)\n", yytext); 
    yylval.num = (char *) strdup(yytext);
    return INT;
}

{str} {
    word_position += 1;
    printf("STR (%s)\n", yytext); 
    yylval.str = (char *) strdup(yytext);
    return STR;
}

"/*" { 
    word_position += 1;
    BEGIN(C_COMMENT); 
}
<C_COMMENT>"*/" { 
    word_position += 1;
    BEGIN(INITIAL); 
}

<C_COMMENT>. { 
    word_position += 1;
}

{plus} {
    word_position += 1;
    printf("plus (%s)\n", yytext);
    return '+';
}

{minus} {
    word_position += 1;
    printf("minus (%s)\n", yytext);
    return '-';
}

{mult} {
    word_position += 1;
    printf("mult (%s)\n", yytext);
    return '*';
}

{div} {
    word_position += 1;
    printf("div (%s)\n", yytext);
    return '/';
}

{eq} {
    word_position += 1;
    printf("eq (%s)\n", yytext);
    return '=';
}

{ceq} {
    word_position += 1;
    printf("ceq (%s)\n", yytext);
    return CEQ;
}
{cne} {
    word_position += 1;
    printf("cne (%s)\n", yytext);
    return CNE;
}
{clt} {
    word_position += 1;
    printf("clt (%s)\n", yytext);
    return CLT;
}
{cle} {
    word_position += 1;
    printf("cle (%s)\n", yytext);
    return CLE;
}
{cgt} {
    word_position += 1;
    printf("cgt (%s)\n", yytext);
    return CGT;
}
{cge} {
    word_position += 1;
    printf("cge (%s)\n", yytext);
    return CGE;
}

{if} {
    word_position += 1;
    printf("if (%s)\n", yytext);
    return IF;
}
{while} {
    word_position += 1;
    printf("while (%s)\n", yytext);
    return WHILE;
}
{else} {
    word_position += 1;
    printf("else (%s)\n", yytext);
    return ELSE;
}
{return} {
    word_position += 1;
    printf("return (%s)\n", yytext);
    return RETURN;
}
{print} {
    word_position += 1;
    printf("print (%s)\n", yytext);
    return PRINT;
}
{scan} {
    word_position += 1;
    printf("scan (%s)\n", yytext);
    return SCAN;
}

"," {
    word_position += 1;
    printf(",\n");
    return ',';
}
";" {
    word_position += 1;
    printf(";\n");
    return ';';
}
"{" {
    word_position += 1;
    printf("{\n");
    return '{';
}
"}" {
    word_position += 1;
    printf("}\n");
    return '}';
}
"(" {
    word_position += 1;
    printf("(\n");
    return '(';
}
")" {
    word_position += 1;
    printf(")\n");
    return ')';
}

{eql} {
    line++;
    word_position = 1;
}

\t* {}

" "* {}

{id} {
    word_position += 1;
    printf("id (%s)\n", yytext);
    strcpy(simbleTable[simble_table_index].id, yytext);
    simbleTable[simble_table_index].line = line;
    simble_table_index += 1;
    yylval.id = (char *) strdup(yytext);
    return ID;
}

. { 
    strcpy(errors[errors_num].word, yytext);
    strcpy(errors[errors_num].message, "Simbolo nao permitido");
    errors[errors_num].line = line;
    errors[errors_num].word_position = word_position;
    errors_num++;
    printError();
    word_position += 1;
    exit(1);
}

%%
