# Conteo lineas, palabras y caracteres.

Este repositorio contiene dos implementaciones para contar líneas, palabras y caracteres en un archivo de texto.

La primera implementación se encuentra en el directorio c/ y está escrita en C. El archivo principal es recuentoReglas.c. Este programa lee un archivo de texto llamado archivo.txt y cuenta el número de líneas, palabras y caracteres en el archivo. Utiliza expresiones regulares para identificar las palabras.

La segunda implementación se encuentra en el directorio flex/ y está escrita en Flex (un generador de analizadores léxicos). El archivo principal es conteo-flex-bison.l. Este programa también lee un archivo de texto y cuenta el número de líneas, palabras y caracteres. Utiliza reglas de coincidencia de patrones para identificar las palabras y las líneas.

## Ejecución Codigo Flex
```bash
flex conteo-flex-bison-l
gcc -o lex.yy.c -lfl
./calc
```

Al ejecutar calc, el programa realiza el conteo de archivo.txt

### Salida

```
20363 lines;  300294 words;  1666229 chars;
```

## Ejecución Codigo C
Alli especificamos el nombre del archivo C y el nombre del ejecutable.
```bash
gcc -o recuentoReglas recuentoReglas.c
```

### Salida
```
20363 lines
300294 words
1666229 chars
```

## Conclusiones
Se analizó un archivo de 1’666.229 caracteres en C y en Flex y se determinó que C es mucho más rápido con una duración de 0.012s, mientras que Flex tuvo una duración 0.023s. Esto se debe a que C se reconoce por su eficiencia y control directo permitiendo una gestión precisa de recurso del sistema, en cambio Flex tiene un propósito diferente y se utiliza en distintos contextos siendo un generadorde analizadores léxicos que divide el código por cada token, lo que le toma un poco más de tiempo en analizar.