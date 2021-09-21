# Problema H

[ 🔙 Volver ](../)

[ 📄 Problema](../H/H.pdf) 

[ 💻 Codigo](../H/H.cpp)

## Resumen del problema

- Se descubre una nueva forma de comprimir un juego ("el bit 2")
- Si soportamos hasta tantos bits por palabra
- Cual es la longitud minima de la cadena comprimida

## Solución del problema

- Para solucionar el problema, debemos tener en cuenta las ventanas o las secuencias que podemos sustituir por 2
- Debemos evitar secuencias sobrepuestas, por ejemplo con la secuencia 0000 y tamaño de bits 2, las compresiones correctas serian 020 o 22 y no 222
- Como solucion recorremos todos los bits posibles de 2 a B y en cada uno recorremos las secuencias posibles
- Hacemos uso de un HashMap para guardar las secuencias que ya aparecieron, guardamos el numero de ocurrencias y el ultimo indice en el que aparecio
- Si encontramos otra vez la misma secuencia y no se sobrepone aumentamos el numero de ocurrencias
- Encontramos la secuencia que se repite más y calculamos el resultado para esa secuencia
- Repetimos para cada bit posible de 2 a B y seleccionamos la longitud menor