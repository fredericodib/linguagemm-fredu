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

void printError(char *word, char *message) {
    printf("\n######### ERROR #########\n");
    printf("Palavra: %s\n", word);
    printf("Mensagem do erro: %s\n", message);
    printf("Line: %d\n", line);
    printf("Posição: %d\n", word_position);
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

or "||"
and "&&"

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
    word_position += strlen(yytext);
    printf("typeInt (%s)\n", yytext);
    yylval.type = (char *) strdup(yytext);
    return TYPEINT;
}

{typeFloat} { 
    word_position += strlen(yytext);
    printf("typeFloat (%s)\n", yytext);
    yylval.type = (char *) strdup(yytext);
    return TYPEFLOAT;
}

{typeString} { 
    word_position += strlen(yytext);
    printf("typeString (%s)\n", yytext);
    yylval.type = (char *) strdup(yytext);
    return TYPESTRING;
}

{dec} { 
    word_position += strlen(yytext);
    printf("dec (%s)\n", yytext); 
    yylval.num = (char *) strdup(yytext);
    return DEC;
}

{num} { 
    word_position += strlen(yytext);
    printf("num (%s)\n", yytext); 
    yylval.num = (char *) strdup(yytext);
    return INT;
}

{str} {
    word_position += strlen(yytext);
    printf("STR (%s)\n", yytext); 
    yylval.str = (char *) strdup(yytext);
    return STR;
}

"/*" { 
    word_position += strlen(yytext);
    BEGIN(C_COMMENT); 
}
<C_COMMENT>"*/" { 
    word_position += strlen(yytext);
    BEGIN(INITIAL); 
}

<C_COMMENT>. { 
    word_position += strlen(yytext);
}

{plus} {
    word_position += strlen(yytext);
    printf("plus (%s)\n", yytext);
    return '+';
}

{minus} {
    word_position += strlen(yytext);
    printf("minus (%s)\n", yytext);
    return '-';
}

{mult} {
    word_position += strlen(yytext);
    printf("mult (%s)\n", yytext);
    return '*';
}

{div} {
    word_position += strlen(yytext);
    printf("div (%s)\n", yytext);
    return '/';
}

{or} {
    word_position += strlen(yytext);
    printf("or (%s)\n", yytext);
    return OR;
}

{and} {
    word_position += strlen(yytext);
    printf("or (%s)\n", yytext);
    return AND;
}

{eq} {
    word_position += strlen(yytext);
    printf("eq (%s)\n", yytext);
    return '=';
}

{ceq} {
    word_position += strlen(yytext);
    printf("ceq (%s)\n", yytext);
    return CEQ;
}
{cne} {
    word_position += strlen(yytext);
    printf("cne (%s)\n", yytext);
    return CNE;
}
{clt} {
    word_position += strlen(yytext);
    printf("clt (%s)\n", yytext);
    return CLT;
}
{cle} {
    word_position += strlen(yytext);
    printf("cle (%s)\n", yytext);
    return CLE;
}
{cgt} {
    word_position += strlen(yytext);
    printf("cgt (%s)\n", yytext);
    return CGT;
}
{cge} {
    word_position += strlen(yytext);
    printf("cge (%s)\n", yytext);
    return CGE;
}

{if} {
    word_position += strlen(yytext);
    printf("if (%s)\n", yytext);
    return IF;
}
{while} {
    word_position += strlen(yytext);
    printf("while (%s)\n", yytext);
    return WHILE;
}
{else} {
    word_position += strlen(yytext);
    printf("else (%s)\n", yytext);
    return ELSE;
}
{return} {
    word_position += strlen(yytext);
    printf("return (%s)\n", yytext);
    return RETURN;
}
{print} {
    word_position += strlen(yytext);
    printf("print (%s)\n", yytext);
    return PRINT;
}
{scan} {
    word_position += strlen(yytext);
    printf("scan (%s)\n", yytext);
    return SCAN;
}

"," {
    word_position += strlen(yytext);
    printf(",\n");
    return ',';
}
";" {
    word_position += strlen(yytext);
    printf(";\n");
    return ';';
}
"{" {
    word_position += strlen(yytext);
    printf("{\n");
    return '{';
}
"}" {
    word_position += strlen(yytext);
    printf("}\n");
    return '}';
}
"(" {
    word_position += strlen(yytext);
    printf("(\n");
    return '(';
}
")" {
    word_position += strlen(yytext);
    printf(")\n");
    return ')';
}

{eql} {
    line++;
    word_position = 1;
}

\t* {word_position += strlen(yytext);}

" "* {word_position += strlen(yytext);}

{id} {
    word_position += strlen(yytext);
    printf("id (%s)\n", yytext);
    yylval.id = (char *) strdup(yytext);
    return ID;
}

. { 
    printError(yytext, "Simbolo nao permitido");
    word_position += strlen(yytext);
    exit(1);
}

%%
