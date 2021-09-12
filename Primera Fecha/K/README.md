# Problema L

[ 🔙 Volver ](../)

[ 📄 Problema](../K/K.pdf) 

[ 💻 Codigo](../K/K.py)

## Resumen del problema

- Jaimie desea invitar a entre 1 y 5 amigos a su fiesta de cumpleaños
- Todos los invitados más Jaimie deben recibir la misma cantidad de biscuits
- Sabiendo el número de biscuits, ¿Cuántos niños habrá en la fiesta?
- El número de biscuits puede ser extremadamente grande por lo que usar operaciones modulares queda descartado

## Solución del problema

- Para solucionar el problema, debemos usar las propiedades de los números sobre una cadena:

        Un número es divisible entre 2 si su último digito es 0, 2, 4, 6 u 8 (excepto 0)

        Un número es divisible entre 3 si la suma de sus digitos es divisible entre 3 (e.g. 27 -> 2+7 = 9)

        Un número es divisible entre 4 si sus últimos 2 digitos son divisibles entre 4 (excepto 0)

        Un número es divisible entre 5 si su último digito es 0 o 5 (excepto 0)

        Un número es divisible entre 6 si es divisible por 2 y 3

```python
if n[len(n) - 1] in ['0','2','4','6','8']:
    # Divisible by 2

while len(str(sum)) > 1:
    prev = str(sum)
    sum = 0
    for el in prev:
        sum += int(el)
if sum in [3, 6, 9]:
    # Divisible by 3

if int(n[len(n)-2:len(n)]) % 4 == 0:
    # Divisible by 4

if n[len(n) - 1] in ['0','5']:
    # Divisible by 5

if by2 and by3:
    # Divisible by 6
```