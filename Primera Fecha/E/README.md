# Problema E

[ 馃敊 Volver ](../)

[ 馃搫 Problema](../E/E.pdf) 

[ 馃捇 Codigo](../E/E.cpp)

## Resumen del problema

- Tenemos el mapa de un escape room que tiene una salida, paredes, objetos y posiciones donde pueden estar los usuarios
- Basado en el mapa debemos proveer informaci贸n de la casilla, si esta es la posici贸n del usuario, le tenemos que decir a donde moverse
- Existe una preferencia a donde moverse en caso de empate

## Soluci贸n del problema

- Para la soluci贸n del problema debemos realizar una busqueda en amplitud empezando en la salida
- Basicamente esto nos calcula la distancia de cada celda que se puede alcanzar a la salida
- En cada query solo respondemos la opci贸n m谩s viable de acuerdo a la preferencia
- Las celdas que no cuenten con distancia son inaccesibles y por ende no tienen soluci贸n