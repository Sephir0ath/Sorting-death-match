#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Uso: %s <entero>\n", argv[0]);
        return 1;
    }

    char *endptr;
    int argumento = strtol(argv[1], &endptr, 10);
    if (*endptr != '\0') {
        fprintf(stderr, "Argumento inválido: debe ser un número entero\n");
        return 1;
    }

    int i;
    for (int exp = 1; exp <= 7; exp++) {
        i = (int)pow(10, exp);

        char i_str[32];
        sprintf(i_str, "%d", i);

        char comando[256];
        snprintf(comando, sizeof(comando),
                 "./c %d 100 %d 1000000000 datasets/%s.bin",
                 argumento, i, i_str);

        printf("Ejecutando: %s\n", comando);
        int resultado = system(comando);

        if (resultado != 0) {
            fprintf(stderr, "Error al ejecutar el comando: %s\n", comando);
        }
    }

    return 0;
}
