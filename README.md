Versão do flex:
flex 2.5.35 Apple(flex-32)

Versão do Bison:
bison (GNU Bison) 2.3

Versão do GCC:
Apple clang version 11.0.3 (clang-1103.0.32.62)
Target: x86_64-apple-darwin19.2.0
Thread model: posix

Instruções de Copilação:
lex lang.l
yacc -d lang.y
gcc -g lex.yy.c y.tab.c -ll -o lang

Instruções de Execução:
./lang input_correto1.txt
./lang input_correto2.txt

./lang input_erro_lexico1.txt
./lang input_erro_lexico2.txt
./lang input_erro_sintatico1.txt
./lang input_erro_sintatico2.txt
