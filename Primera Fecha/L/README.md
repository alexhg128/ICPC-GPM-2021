# Problema L

[ 馃敊 Volver ](../)

[ 馃搫 Problema](../L/L.pdf) 

[ 馃捇 Codigo](../L/L.java)

## Resumen del problema

- Se recibe un n煤mero N el cu谩l representa 2^n
- Se debe describir la potencia de 2 en la notaci贸n requerida por el problema.

## Soluci贸n del problema

- Se crea una funci贸n recursiva donde el caso base sea ```n = 1``` y dependiendo de si es par o impar imprimir la notaci贸n y llamarse as铆 misma.

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
- Se puede solucionar con programaci贸n din谩mica, pero la versi贸n recursiva es aceptada.