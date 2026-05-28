/*La municipalidad de General Pueyrredón registra información de los viajes realizados por las líneas de colectivos del partido. Esta se encuentra en el archivo binario VIAJES.DAT, donde cada registro contiene los siguientes datos:

Línea (500 a 594), Número de interno (1 a 80), Turno (1 a 3), Cantidad de pasajeros, KmRecorridos.

Ej 1)
Desarrollar en C subprogramas que a partir de los datos de VIAJES.DAT, de un único recorrido del mismo genere una matriz MP con la cantidad total de pasajeros por línea y turno y un vector VK con los kilómetros totales por línea.

Ej 2)

A partir de las estructuras generadas en el ej 1:

a)

Crear en un subprograma un archivo de texto RESUMEN.TXT con los siguientes datos: Línea (no se repite y solo se deben incluir las líneas que hayan realizado viajes en los tres turnos). TotalPasajeros, TotalKm.
y solo se deben incluir las líneas que hayan realizado viajes en los turnos.
(Leído en el main) pasajeros entre los turnos.

b)
Hallar mediante una función int y luego informar si al menos la mitad de las lineas han llegado a mas de x(leido en el main ) pasajeros entre los 3 turnos .

c)
Hallar en único subprograma para un turno T (leído y validado en el main) dado:

cantidad de líneas que transportaron pasajeros en el turno T
entre dichas líneas, cuál fue la que registró la menor cantidad de pasajeros

Escribir el main completo con la invocación a los subprogramas desarrollados. No desarrollar la carga del archivo VIAJES.DAT.*/
