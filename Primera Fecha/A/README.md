# Problema A

[ 🔙 Volver ](../)

[ 📄 Problema](../A/A.pdf) 

[ 💻 Codigo](../A/A.cpp)

## Resumen del problema

- El problema nos dice que tenemos que sembrar unos triangulos que fueron cortados
- Para llenarlos requerimos cierta cantidad de semillas
- En la tienda hay varias presentaciones de semillas, debemos encontrar la combinación que minimiza el costo

## Solución del problema

- Para resolver este problema primero se calcula el area de los triangulos usando la formula de Heron
- Luego se calcula la cantidad de semillas
- Se utiliza el algoritmo del problema de la mochila para encontrar la versión más optima
- No necesariamente debe quedar la cantidad exacta, podemos comprar de más si sale más barato
- Debemos tener cuidado de los casos en los que no hay triangulos o en los que no hay bolsas disponibles