## 2 ultimo numero es par
## 3 sumar digitos y que se dividan entre 3
## 4 ultimos 2 digitos sean divisible entre 4
## 5 ultimo digito es 5 o 0
## 6 divisible entre 2 y 3
## -1 si ninguno cumple

t = int(input())
for i in range(t):
    n = input()
    
    comp = []

    if len(n) == 1 and n[0] == '0':
        print(-1)
        continue
    by2 = False
    if n[len(n) - 1] in ['0','2','4','6','8']:
        comp.append('2')
        by2 = True

    prev = n
    sum = n

    while len(str(sum)) > 1:
        prev = str(sum)
        sum = 0
        for el in prev:
            sum += int(el)
    by3 = False
    if sum in [3, 6, 9]:
        comp.append('3')
        by3 = True
    if int(n[len(n)-2:len(n)]) % 4 == 0:
        comp.append('4')
    if n[len(n) - 1] in ['0','5']:
        comp.append('5')
    if by2 and by3:
        comp.append('6')

    if len(comp) == 0:
        print(-1)
    else:
        for x in range(len(comp) - 1):
            print(comp[x] + ' ', end='')
        print(comp[len(comp) - 1])
    
    
        