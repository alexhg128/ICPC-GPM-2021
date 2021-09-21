# Problema J

[ 🔙 Volver ](../)

[ 📄 Problema](../J/J.pdf) 

[ 💻 Codigo](../J/J.java)

## Resumen del problema

- Se recibe el organigrama de una empresa
- Todos los empleados reenvian sus correos hasta que el correo llega a alguien sin empleados a cargo
- Es nuestro trabajo calcular cantas veces se reenvian los correos
- Se presenta el resultado en terminos del inverso multiplicativo de N

## Solución del problema

- Para solucionar el problema, se realiza una busqueda en profundidad empezando de las hojas del arbol (empleados no jefes de ningún otro empleado)
- Con la busqueda determinamos la distancia de cada nodo a la hoja mas cercana (la hoja tiene distancia de 1)
- Calculamos la suma de todas las distancias
- Obtenemos el inverso multiplicativo del modulo
- Obtenemos el resultado final multiplicando la suma por el inverso y aplicando el modulo