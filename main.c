#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utils.h"

int main(int argc, char *argv[]) {
    //validacion
    if (argc < 3) {
        printf("Uso: %s archivo.csv metrica1 metrica2 ...\n", argv[0]);
        return 1;
    }
    

    // Leer archivo CSV
    FILE *file = fopen(argv[1], "r");
    //validacion
    if (!file) {
        perror("Error abriendo el archivo");
        return 1;
    }

    char line[MAX_LINE_LENGTH];
    fgets(line, sizeof(line), file); // Saltar titulos

    Pizza ordenes[MAX_ORDERS];
    int order_count = 0;
    double amount = 0;

    while (fgets(line, sizeof(line), file) && order_count < MAX_ORDERS) {
        parseLine(line, &ordenes[order_count]);
        order_count++;
    }
    fclose(file); //cierra el csv

    // Procesar metricas en orden q lo ponen asignar el i al argv en orden
    for (int i = 2; i < argc; i++) {
        int size;
        char *result = NULL;

        if (strcmp(argv[i], "pms") == 0) {
            result = pms(&size, ordenes, order_count);
            printf("Pizza mas vendida: %s (%d unidades)\n", result, size);
        } else if (strcmp(argv[i], "pls") == 0) {
            result = pls(&size, ordenes, order_count);
            printf("Pizza menos vendida: %s (%d unidades)\n", result, size);
        } else if (strcmp(argv[i], "dms") == 0) {
            result = dms(&amount, ordenes, order_count);
            printf("Fecha con mas ventas en dinero: %s ($%.2f)\n", result, amount);
        } else if (strcmp(argv[i], "dls") == 0) {
            result = dls(&amount, ordenes, order_count);
            printf("Fecha con menos ventas en dinero: %s ($%.2f)\n", result, amount);
        } else if (strcmp(argv[i], "dmsp") == 0) {
            result = dmsp(&size, ordenes, order_count);
            printf("Fecha con mas ventas en cantidad de pizzas: %s (%d pizzas)\n", result, size);
        } else if (strcmp(argv[i], "dlsp") == 0) {
            result = dlsp(&size, ordenes, order_count);
            printf("Fecha con menos ventas en cantidad de pizzas: %s (%d pizzas)\n", result, size);
        } else if (strcmp(argv[i], "apo") == 0) {
            double avg = apo(ordenes, order_count);
            printf("Promedio de pizzas por orden: %.2f\n", avg);
        } else if (strcmp(argv[i], "apd") == 0) {
            double avg = apd(ordenes, order_count);
            printf("Promedio de pizzas por dia: %.2f\n", avg);
        } else if (strcmp(argv[i], "ims") == 0) {
            result = ims(&size, ordenes, order_count);
            printf("Ingrediente mas vendido: %s (%d unidades)\n", result, size);
        } else if (strcmp(argv[i], "hp") == 0) {
            printf("Cantidad de pizzas por categoria vendidas:\n");
            hp(ordenes, order_count);
        }
        if (result) free(result);
    }

    return 0;
}