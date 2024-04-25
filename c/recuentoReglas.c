/**
 * @file recuentoReglas.c
 * @brief This program reads a file and counts the number of lines, words, and characters in the file.
 */

#include <stdio.h>
#include <stdlib.h>
#include <regex.h>
#include <string.h>

#define MAX_LINE_LENGTH 1000

int main()
{
    char archivo[] = "archivo.txt"; // Nombre del archivo a leer

    regex_t regex;
    int value = 0;

    int chars = 0;
    int words = 0;
    int lines = 0;

    char input[MAX_LINE_LENGTH];

    // Abrir el archivo
    FILE *file = fopen(archivo, "r");

    if (file == NULL)
    {
        printf("No se pudo abrir el archivo.\n");
        return 1; // Terminar el programa con un código de error
    }

    // Inicializar la expresión regular
    if (regcomp(&regex, "[a-zA-Z]+", REG_EXTENDED) != 0)
    {
        printf("Error al compilar la expresión regular.\n");
        fclose(file);
        return 1;
    }

    // Leer cada línea del archivo y procesarla
    while (fgets(input, MAX_LINE_LENGTH, file) != NULL)
    {
        int length = strlen(input);
        chars += length; // Sumar el número de caracteres en la línea

        for (int i = 0; i < length; i++)
        {
            // Comprobar si el carácter es una letra
            if ((input[i] >= 'a' && input[i] <= 'z') || (input[i] >= 'A' && input[i] <= 'Z'))
            {
                // Si es una letra, buscar la palabra completa
                int j = i;
                while ((input[j] >= 'a' && input[j] <= 'z') || (input[j] >= 'A' && input[j] <= 'Z'))
                {
                    j++;
                }
                words++;   // Aumentar el contador de palabras
                i = j - 1; // Actualizar el índice
            }
        }

        lines++; // Aumentar el contador de líneas
    }

    fclose(file); // Cerrar el archivo después de leerlo

    // Liberar la expresión regular
    regfree(&regex);

    printf("%d lines\n", lines);
    printf("%d words\n", words);
    printf("%d chars\n", chars);

    return 0;
}
