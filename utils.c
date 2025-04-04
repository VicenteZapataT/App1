#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utils.h"
#include <limits.h>  
#include <float.h>   

// Función para eliminar espacios y comillas (ojo con ingredientes)
void trim(char *str) {
    int i, j;
    for (i = 0; str[i] == ' ' || str[i] == '"'; i++);
    for (j = strlen(str) - 1; j > i && (str[j] == ' ' || str[j] == '"'); j--);
    str[j + 1] = '\0';
    memmove(str, str + i, j - i + 2);
}

// Función para parsear una línea CSV en un struct Pizza
void parseLine(char *line, Pizza *order) {
    char *token;
    int campo = 0;
    order->ingredients_count = 0;

    char buffer[MAX_LINE_LENGTH];
    int buf_index = 0;
    int inside_quotes = 0;
    char *ptr = line;

    while (*ptr) {
        if (*ptr == '"') {
            inside_quotes = !inside_quotes;
            ptr++;
            continue;
        }

        if (*ptr == ',' && !inside_quotes) {
            buffer[buf_index] = '\0';
            token = buffer;
            trim(token);

            switch (campo) {
                case 0: order->pizza_id = atoi(token); break;
                case 1: order->order_id = atoi(token); break;
                case 2: strncpy(order->pizza_name_id, token, MAX_PIZZA_NAME_LENGTH - 1); break;
                case 3: order->quantity = atof(token); break;
                case 4: strncpy(order->order_date, token, 10); break;
                case 5: strncpy(order->order_time, token, 8); break;
                case 6: order->unit_price = atof(token); break;
                case 7: order->total_price = atof(token); break;
                case 8: order->pizza_size = token[0]; break;
                case 9: strncpy(order->pizza_category, token, MAX_PIZZA_NAME_LENGTH - 1); break;
                case 10:
                    {
                        char *ingredient = strtok(token, ",");
                        while (ingredient != NULL && order->ingredients_count < MAX_INGREDIENTS_COUNT) {
                            trim(ingredient);
                            strncpy(order->pizza_ingredients[order->ingredients_count], ingredient, MAX_INGREDIENTS_LENGTH - 1);
                            order->ingredients_count++;
                            ingredient = strtok(NULL, ",");
                        }
                    }
                    break;
                case 11: strncpy(order->pizza_name, token, MAX_PIZZA_NAME_LENGTH - 1); break;
            }
            campo++;
            buf_index = 0;
        } else {
            buffer[buf_index++] = *ptr;
        }
        ptr++;
    }
}

// Función para encontrar la pizza más vendida (pms)
char* pms(int *size, Pizza *ordenes, int num_ordenes) {
    char *p_mas_vendida = malloc(MAX_PIZZA_NAME_LENGTH);
    int max_count = 0;

    for (int i = 0; i < num_ordenes; i++) {
        int count = 0;
        for (int j = 0; j < num_ordenes; j++) {
            if (strcmp(ordenes[i].pizza_name_id, ordenes[j].pizza_name_id) == 0) {
                count += ordenes[j].quantity;
            }
        }
        if (count > max_count) {
            max_count = count;
            strcpy(p_mas_vendida, ordenes[i].pizza_name_id);
        }
    }

    *size = max_count;
    return p_mas_vendida;
}

char* pls(int *size, Pizza *ordenes, int num_ordenes) {
    char *p_menos_vendida = malloc(MAX_PIZZA_NAME_LENGTH);
    int min_count = INT_MAX;

    for (int i = 0; i < num_ordenes; i++) {
        int count = 0;
        for (int j = 0; j < num_ordenes; j++) {
            if (strcmp(ordenes[i].pizza_name_id, ordenes[j].pizza_name_id) == 0) {
                count += ordenes[j].quantity;
            }
        }
        if (count < min_count) {
            min_count = count;
            strcpy(p_menos_vendida, ordenes[i].pizza_name_id);
        }
    }

    *size = min_count;
    return p_menos_vendida;
}
char* dms(double *amount, Pizza *ordenes, int num_ordenes) {
    char *mejor_dia = malloc(11);
    double max_venta = 0.0;

    for (int i = 0; i < num_ordenes; i++) {
        double venta_diaria = 0.0;
        for (int j = 0; j < num_ordenes; j++) {
            if (strcmp(ordenes[i].order_date, ordenes[j].order_date) == 0) {
                venta_diaria += ordenes[j].total_price;
            }
        }
        if (venta_diaria > max_venta) {
            max_venta = venta_diaria;
            strcpy(mejor_dia, ordenes[i].order_date);
        }
    }

    *amount = max_venta;
    return mejor_dia;
}
char* dls(double *amount, Pizza *ordenes, int num_ordenes) {
    char *peor_dia = malloc(11);
    double min_venta = DBL_MAX;

    for (int i = 0; i < num_ordenes; i++) {
        double venta_diaria = 0.0;
        for (int j = 0; j < num_ordenes; j++) {
            if (strcmp(ordenes[i].order_date, ordenes[j].order_date) == 0) {
                venta_diaria += ordenes[j].total_price;
            }
        }
        if (venta_diaria < min_venta) {
            min_venta = venta_diaria;
            strcpy(peor_dia, ordenes[i].order_date);
        }
    }

    *amount = min_venta;
    return peor_dia;
}
char* dmsp(int *size, Pizza *ordenes, int num_ordenes) {
    char *mejor_dia = malloc(11);
    int max_pizzas = 0;

    for (int i = 0; i < num_ordenes; i++) {
        int pizza_dia = 0;
        for (int j = 0; j < num_ordenes; j++) {
            if (strcmp(ordenes[i].order_date, ordenes[j].order_date) == 0) {
                pizza_dia += ordenes[j].quantity;
            }
        }
        if (pizza_dia > max_pizzas) {
            max_pizzas = pizza_dia;
            strcpy(mejor_dia, ordenes[i].order_date);
        }
    }

    *size = max_pizzas;
    return mejor_dia;
}
char* dlsp(int *size, Pizza *ordenes, int num_ordenes) {
    char *peor_dia = malloc(11);
    int min_pizzas = INT_MAX;

    for (int i = 0; i < num_ordenes; i++) {
        int pizza_dia = 0;
        for (int j = 0; j < num_ordenes; j++) {
            if (strcmp(ordenes[i].order_date, ordenes[j].order_date) == 0) {
                pizza_dia += ordenes[j].quantity;
            }
        }
        if (pizza_dia < min_pizzas) {
            min_pizzas = pizza_dia;
            strcpy(peor_dia, ordenes[i].order_date);
        }
    }

    *size = min_pizzas;
    return peor_dia;
}