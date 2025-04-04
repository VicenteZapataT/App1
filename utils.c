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