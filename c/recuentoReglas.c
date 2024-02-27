#include <stdio.h>
#include <stdlib.h>
#include <regex.h>
#include <string.h>

#define MAX_LINE_LENGTH 1000

int main(int argc, char *argv[]) {
    // Verificar si se proporcionó el nombre del archivo como argumento
    if (argc != 2) {
        printf("Uso: %s <nombre_archivo>\n", argv[0]);
        return 1; // Código de error para indicar que algo salió mal
    }

    regex_t regex;
    int value = 0;

    int chars = 0;
    int words = 0;
    int lines = 0;

    char input[MAX_LINE_LENGTH];

    // Abrir el archivo proporcionado como argumento
    FILE *file = fopen(argv[1], "r");

    if (file == NULL) {
        printf("No se pudo abrir el archivo.\n");
        return 1; // Terminar el programa con un código de error
    }

    // Inicializar la expresión regular
    if (regcomp(&regex, "[a-zA-Z]+", REG_EXTENDED) != 0) {
        printf("Error al compilar la expresión regular.\n");
        fclose(file);
        return 1;
    }

    // Leer cada línea del archivo y procesarla
    while (fgets(input, MAX_LINE_LENGTH, file) != NULL) {
        int length = strlen(input);
        chars += length; // Sumar el número de caracteres en la línea

        for (int i = 0; i < length; i++) {
            // Comprobar si el carácter es una letra
            if ((input[i] >= 'a' && input[i] <= 'z') || (input[i] >= 'A' && input[i] <= 'Z')) {
                // Si es una letra, buscar la palabra completa
                int j = i;
                while ((input[j] >= 'a' && input[j] <= 'z') || (input[j] >= 'A' && input[j] <= 'Z')) {
                    j++;
                }
                words++; // Aumentar el contador de palabras
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
