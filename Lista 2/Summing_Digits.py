def f(n):
    n = str(n)
    sum = 0
    for i in n:
        sum += int(i)
    return sum


def g(n):
    n = str(n)
    while len(n) > 1:
        n = str(f(n))
    return int(n)

lista = []
while(True):
    n = int(input())
    if n == 0:
        break
    lista.append(n)

for item in lista:
    print(g(item))
    

