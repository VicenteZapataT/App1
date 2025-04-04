#ifndef UTILS_H
#define UTILS_H

#include "structs.h"

void parseLine(char *line, Pizza *order);
void trim(char *str);

// Funciones de métricas
char* pms(int *size, Pizza *ordenes, int num_ordenes);// Pizza más vendida
char* pls(int *size, Pizza *ordenes, int num_ordenes);//Pizza menos vendida
char* dms(double *amount, Pizza *ordenes, int num_ordenes);//Fecha con más ventas en términos de dinero (junto a la cantidad de dinero recaudado)
char* dls(double *amount, Pizza *ordenes, int num_ordenes);//Fecha con menos ventas en términos de dinero (junto a la cantidad de dinero recaudado)
char* dmsp(int *size, Pizza *ordenes, int num_ordenes);// Fecha con más ventas en términos de cantidad de pizzas (junto a la cantidad de pizzas)
char* dlsp(int *size, Pizza *ordenes, int num_ordenes);//Fecha con menos ventas en términos de cantidad de pizzas (junto a la cantidad de pizzas)
double apo(Pizza*ordenes, int num_ordenes);//Promedio de pizzas por orden
double apd(Pizza *ordenes, int num_ordenes);//Promedio de pizzas por día
char* ims(int *size, Pizza *ordenes, int num_ordenes);//Ingrediente más vendido
void hp(Pizza *ordenes, int num_ordenes);//Cantidad de pizzas por categoría vendidas

#endif
