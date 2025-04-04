# App1

## Autores
- Vicente Zapata (Vizapata@alumnos.uai.cl)
- Renato Galleguillos (Regalleguillos@alumnos.uai.cl)
- José Pablo Bernal (Josbernal@alumnos.uai.cl)

## Tarea 1: Pizzería en C

### Objetivo
Desarrollar un programa en C que lea un archivo CSV con datos de ventas de una pizzería y calcule varias métricas a partir de estos datos. Las métricas solicitadas incluyen análisis sobre las pizzas más y menos vendidas, fechas con más y menos ventas, y otros análisis relacionados con el rendimiento de ventas de la pizzería.

### Requerimientos
El programa debe:

- Recibir un archivo CSV como entrada.
- Calcular y mostrar las métricas solicitadas por el usuario.
- Usar punteros a funciones para implementar las métricas.
- Estar dividido en varios archivos fuente para modularidad.

### Instrucciones de Compilación
1. Descargar la carpeta "App1".
2. Añadir la carpeta "App1" al área de trabajo.
3. Abrir la terminal en la dirección de la carpeta.
4. Ejecutar el Makefile para compilar el programa:

```bash
make
```
5. Para limpiar los archivos generados por la compilación (archivos .o y el ejecutable), ejecutar:
```bash
make clean
```

## Instrucciones de Uso
Para ejecutar el programa, usa el siguiente formato:
```bash
./app1 archivo.csv metrica1 metrica2 ... metricaN
```
### Ejemplo de ejecución:
```bash
./app1 ventas.csv pms pls dms
```
Donde:
- **`ventas.csv`** es el archivo con los datos de ventas.

- **`pms`**, **`pls`**, **`dms`** son las métricas que se desean calcular. Puedes especificar varias métricas separadas por espacios.

## Formato del Archivo CSV
El archivo CSV debe tener el siguiente formato:
```csv
pizza_id,order_id,pizza_name_id,quantity,order_date,order_time,unit_price,total_price,pizza_size,pizza_category,pizza_ingredients,pizza_name
1.00,1.00,hawaiian_m,1.00,1/1/2015,11:38:36,13.25,13.25,M,Classic,"Sliced Ham, Pineapple, Mozzarella Cheese",The Hawaiian Pizza
2.00,2.00,classic_dlx_m,1.00,1/1/2015,11:57:40,16.00,16.00,M,Classic,"Pepperoni, Mushrooms, Red Onions, Red Peppers, Bacon",The Classic Deluxe Pizza
3.00,2.00,five_cheese_l,1.00,1/1/2015,11:57:40,18.50,18.50,L,Veggie,"Mozzarella Cheese, Provolone Cheese, Smoked Gouda Cheese, Romano Cheese, Blue Cheese, Garlic",The Five Cheese Pizza

```
## Métricas Disponibles
Estas son las métricas que puedes calcular al ejecutar el programa:
1. **`pms`**: Pizza más vendida.
2. **`pls`**: Pizza menos vendida.
3. **`dms`**: Fecha con más ventas en términos de dinero.
4. **`dls`**: Fecha con menos ventas en términos de dinero.
5. **`dmsp`**: Fecha con más ventas en términos de cantidad de pizzas.
6. **`dlsp`**: Fecha con menos ventas en términos de cantidad de pizzas.
7. **`apo`**: Promedio de pizzas por orden.
8. **`apd`**: Promedio de pizzas por día.
9. **`ims`**: Ingrediente más vendido.
10. **`hp`**: Cantidad de pizzas por categoría vendidas.
    
## Ejemplo de Uso
Si ejecutas el programa con las métricas pms (pizza más vendida) y pls (pizza menos vendida), obtendrás algo similar a lo siguiente:
```bash
$ ./app1 ventas.csv pms pls
Pizza más vendida: The Hawaiian Pizza
Pizza menos vendida: The Classic Deluxe Pizza
```
## Estructura del Proyecto
- **`src/`**: Contiene los archivos fuente **`.c`** y los archivos de cabecera **`.h`**.
- **`Makefile`**: Archivo para compilar el programa y manejar las dependencias.