/*
Final taller de programacion 2025 (Corte de control de primer nivel ) 

Una distribuidora posee un archivo de texto con información correspondiente a las ventas de productos realizadas por distintos distribuidores.
Cada registro del archivo contiene los siguientes datos:

Número de distribuidor (valores entre 1 y 80, puede repetirse).

Código de producto (valores entre 100 y 299).

Stock (entero positivo).

Precio (número real).

A partir de este archivo de texto se solicita realizar las siguientes tareas: 

A) Hacer una sola funcion que genere un archivo binario cuyos registros sean de tipo struct y contengan la siguiente información:

Número de distribuidor.

Cantidad de unidades

Promedio del precio de los productos.

El archivo binario deberá generarse únicamente para aquellos distribuidores que posean más de 10 productos

Ademas Construir una matriz MS de 80x200 donde cada posición de la matriz deberá contener:

'S' si el distribuidor posee ese producto.

'N' si no lo posee.

Luego desde la matriz creada MS :

B) Desarrollar una función que retorne un valor entero, que reciba como parámetro un número de distribuidor ingresado por teclado e indique si dicho distribuidor posee todos los productos de cotillón.

Se considera que los productos de cotillón son aquellos que cumplen con las siguientes condiciones:

Código de producto entre 100 y 200 inclusive.

Código de producto par.

C) Desarrollar una única función que determine:

El producto  que más se repite entre los distribuidores.( max)

El producto de menos se repite entre los distribuidores. ( min )

D) Realizar el main completo
*/
