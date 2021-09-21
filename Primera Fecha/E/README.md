# Problema E

[ 🔙 Volver ](../)

[ 📄 Problema](../E/E.pdf) 

[ 💻 Codigo](../E/E.cpp)

## Resumen del problema

- Tenemos el mapa de un escape room que tiene una salida, paredes, objetos y posiciones donde pueden estar los usuarios
- Basado en el mapa debemos proveer información de la casilla, si esta es la posición del usuario, le tenemos que decir a donde moverse
- Existe una preferencia a donde moverse en caso de empate

## Solución del problema

- Para la solución del problema debemos realizar una busqueda en amplitud empezando en la salida
- Basicamente esto nos calcula la distancia de cada celda que se puede alcanzar a la salida
- En cada query solo respondemos la opción más viable de acuerdo a la preferencia
- Las celdas que no cuenten con distancia son inaccesibles y por ende no tienen solución