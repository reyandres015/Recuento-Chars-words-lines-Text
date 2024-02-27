/* just like Unix wc */
%{
#include <stdio.h>
int chars = 0;
int words = 0;
int lines = 0;
extern FILE *yyin; // Declaración externa de yyin para leer desde un archivo
%}

%%
[a-zA-Z]+  { words++; chars += yyleng; }
\n         { chars++; lines++; }
.          { chars++; }
%%

int main(int argc, char **argv)
{
    if (argc != 2) {
        printf("Uso: %s archivo\n", argv[0]);
        return 1;
    }

    FILE *file = fopen(argv[1], "r");
    if (file == NULL) {
        perror("Error al abrir el archivo");
        return 1;
    }

    yyin = file; // Establecer yyin para que lea desde el archivo proporcionado
    yylex();
    printf("%8d lines;%8d words; %8d chars;\n", lines, words, chars);

    fclose(file); // Cerrar el archivo después de usarlo
    return 0;
}
