/*
Enunciado de practica para final de taller de programacion CORTE DE CONTROL SEGUNDO NIVEL 

Un supermercado registra sus ventas diarias en un archivo de texto denominado SUPERVENTAS.TXT, el cual contiene un registro por cada venta realizada con el siguiente formato:

Código de sucursal (entero entre 1 y 20) 

Código de producto (entero entre 500 y 699) 

Cantidad vendida

Precio unitario

El archivo SUPERVENTAS.TXT se encuentra ordenado por código de sucursal y, dentro de cada sucursal, por código de producto.

 Parte A – Generación de archivo binario

A partir del archivo de texto SUPERVENTAS.TXT, se solicita generar un archivo binario denominado RESUMEN.DAT, donde cada registro represente el total vendido de un producto en una sucursal.

Cada registro del archivo binario deberá tener el siguiente formato:

typedef struct {
    int codSucursal;
    int codProducto;
    int cantidadTotalVendida;
    float importeTotal;
} VentaResumen;


El archivo binario debe generarse utilizando la técnica de corte de control de dos niveles:

Primer nivel: código de sucursal

Segundo nivel: código de producto

Parte B – Carga de matriz

A partir del archivo binario RESUMEN.DAT, se deberá cargar una matriz , donde:

Las filas representen las sucursales (1 a 20)

Las columnas representen los productos (500 a 699)

Cada celda de la matriz almacene la cantidad total vendida de ese producto en esa sucursal

Si una combinación sucursal–producto no posee ventas, la celda correspondiente debe inicializarse en cero.

Ejemplo conceptual:

matriz[sucursal][producto] = cantidad total vendida

Parte C – Procesamiento de la matriz

Utilizando exclusivamente la matriz cargada, informar por pantalla:

Usar un subprograma para :

1) Informar la cantidad total vendida por cada sucursal.

2 )La sucursal que obtuvo la mayor cantidad total vendida y La sucursal que obtuvo la menor cantidad total vendida ( todo en una misma funcion ) .

3 ) El producto que alcanzó la mayor cantidad vendida, considerando todas las sucursales. y el producto que alcanzó la menor cantidad vendida, considerando todas las sucursales.

Parte D – Informes adicionales

Mostrar por pantalla, de manera clara y ordenada:

Para cada sucursal:

El detalle de los productos vendidos y su cantidad total.

Totales generales del supermercado.

Parte E – Programa principal

Realizar el main() completo, incluyendo:

Declaración de estructuras

Apertura y cierre de archivos

Lectura del archivo de texto

Generación del archivo binario

Inicialización y carga de la matriz

Procesamiento de máximos y mínimos

Emisión de informes solicitados

El programa debe estar correctamente modularizado y comentado.
*/
