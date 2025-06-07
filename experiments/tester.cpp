#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main(int argc, char *argv[]) {
    if (argc < 3) {
        fprintf(stderr, "Uso: %s <entero> <archivo_salida>\n", argv[0]);
        return 1;
    }

    char *endptr;
    int argumento = strtol(argv[1], &endptr, 10);
    if (*endptr != '\0') {
        fprintf(stderr, "Argumento inválido: debe ser un número entero\n");
        return 1;
    }

    FILE *salida = fopen(argv[2], "a");  // Abrir archivo para agregar contenido
    if (!salida) {
        perror("No se pudo abrir el archivo de salida");
        return 1;
    }

    for (int exp = 1; exp <= 7; exp++) {
        int i = (int)pow(10, exp);

        char comando[256];
        snprintf(comando, sizeof(comando),
                 "./a datasets/%d.bin %d %d", i, argumento, i);

        FILE *fp = popen(comando, "r");
        if (!fp) {
            fprintf(stderr, "Error al ejecutar: %s\n", comando);
            continue;
        }

        int c;
        while ((c = fgetc(fp)) != EOF) {
            if (c != '\n') {  // Omitimos saltos de línea si quieres todo en una línea
                fputc(c, salida);
                fflush(salida);  // Escribimos inmediatamente en el archivo
            }
        }

        pclose(fp);
    }

    fclose(salida);
    return 0;
}
