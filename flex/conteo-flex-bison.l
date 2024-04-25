/**
 * @file conteo-flex-bison.l
 * @brief This file contains the Lex code for counting characters, words, and lines in a text file.
 */

/* just like Unix wc */
%{
#include <stdio.h>
int chars = 0;
int words = 0;
int lines = 0;
%}

%%
[a-zA-Z]+  { words++; chars += yyleng; }
\n         { chars++; lines++; }
.          { chars++; }
%%

/**
 * @brief The main function reads a text file and counts the number of lines, words, and characters.
 * 
 * @return 0 if the program executed successfully, 1 otherwise.
 */
int main()
{
    char archivo[] = "archivo.txt"; // Nombre del archivo a leer

    FILE *file = fopen(archivo, "r");
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
