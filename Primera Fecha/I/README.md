# Problema I

[ 🔙 Volver ](../)

[ 📄 Problema](../I/I.pdf) 

[ 💻 Codigo](../I/I.cpp)

## Resumen del problema

- Estre problema nos brinda una lista de ciudades que estan en el km X de una carretera que solo puede ir de izquierda a derecha.

- Todas las ciudades envian un equipo a la última ciudad. El costo es igual a la distancia que se recorre.

- Si colocamos una máquina teleportadora que tiene un costo por usarse, ¿es posible que podamos reducir el costo de transladar a todos los equipos?

## Solución del problema

- Recorremos la lista de ciudades para calcular la distancia local recorrida ```T += (cities[n - 1] - cities[i])```.

- Recorremos de nuevo la lista de ciudades para encontrar si una combinación de I y J logran reducir la distancia total.

```c++
for(int i = 0; i < cities.size(); i++) {
    T += (cities[n - 1] - cities[i]);
}
```

- Para cada ciudad i encontramos la ciudad j más lejana en la que podemos poner la maquina (```cities[i]+k```). Esto lo hacemos realizando una busqueda binaria en el vector ordenado. En C++ podemos usar la función ```lower_bound``` que hace la busqueda binaria y regresa el iterador en la posición exacta donde se encontro, el siguiente mayor si no se encuentra o ```cities.end()``` si no se encuentra y todos son menores.

- Para dicha combinación encontramos D (el número de ciudades que usaran la maquina multiplicado por la distancia ahorrada ```cities[j] - cities[i]```), C (el número de ciudades que usaran la maquina multiplicado por el costo de usar la máquina) y calculamos Tij = T - D + C.

```c++
for(int i = 0; i < cities.size() - 1; i++) {
    long long C = (i + 1) * t;
    long long L = cities[i] + k;

    vector<long long>::iterator low = lower_bound(cities.begin(), cities.end(), L);
    long long pos = low - cities.begin();
    int j = 0;
    if(pos ==  cities.size()) {
        j = cities.size() - 1;
    } else if(cities[pos] == L) {
        j = pos;
    } else  {
        j = pos - 1;
    }

    long long D = (cities[j] - cities[i]) * (i + 1);
    long long TLOC = T - D + C;
    if(TLOC < TLO) {
        TLO = TLOC;
        I = i;
        J = j;
    }
}
```

- Guardamos el valor minimo de Tij y si es menor que T, imprimimos i, j y Tij, de lo contrario imprimimos -1.

- Gracias a la busqueda binaria la complejidad del programa termina siendo ```O(nlogn)```