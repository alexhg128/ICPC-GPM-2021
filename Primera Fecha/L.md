# Problema L

## Resumen del problema

- Se recibe un número N el cuál representa 2^n
- Se debe describir la potencia de 2 en la notación requerida por el problema.

## Solución del problema

- Se crea una función recursiva donde el caso base sea ```n = 1``` y dependiendo de si es par o impar imprimir la notación y llamarse así misma.

```java
public static String rec(long x){
    if(x == 1){
        return "2";
    }else if (x % 2 == 1){
        return ("(2*" + rec(x-1) + ")");
    }else{
        return ("(" + rec(x/2) + ")^2");
    }
}
```

## Notas

- No corre en Python.
- Se puede solucionar con programación dinámica, pero la versión recursiva es aceptada.