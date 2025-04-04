#ifndef STRUCTS_H
#define STRUCTS_H

#define MAX_PIZZA_NAME_LENGTH 50
#define MAX_INGREDIENTS_COUNT 10
#define MAX_INGREDIENTS_LENGTH 50
#define MAX_LINE_LENGTH 1024
#define MAX_ORDERS 1000

typedef struct {
    int pizza_id;
    int order_id;
    char pizza_name_id[MAX_PIZZA_NAME_LENGTH];
    double quantity;
    char order_date[11];
    char order_time[9];
    double unit_price;
    double total_price;
    char pizza_size;
    char pizza_category[MAX_PIZZA_NAME_LENGTH];
    char pizza_ingredients[MAX_INGREDIENTS_COUNT][MAX_INGREDIENTS_LENGTH];
    int ingredients_count;
    char pizza_name[MAX_PIZZA_NAME_LENGTH];
} Pizza;

#endif