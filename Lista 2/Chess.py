from math import ceil

t = int(input())

for k in range(t):
    [c, m, n] = [x for x in input().split()]
    m = int(m)
    n = int(n)
    
    if (c == "r"):
        answer = min (m, n)

    elif (c == "k"):
        answer = ceil((m*n)/2)

    elif (c == "K"):
        answer = (((m + 1)/2) * ((n + 1)/2))
        answer = (ceil(max(m,n)/2)*ceil(min(m,n)/2))

    elif (c == "Q"):
        answer = min (m, n)

    print(answer)
