import sys

def factorial(n):
    ans = 1
    for i in range(1, n+1):
        ans *= i
    return ans

for line in sys.stdin:
    n = int(line)
    print(str(n) + "!")
    print(factorial(n))
    