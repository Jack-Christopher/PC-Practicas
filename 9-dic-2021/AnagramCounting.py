import sys

def factorial(n):
	if n <= 1:
		return 1
	else:
		return n* factorial(n-1)

for line in sys.stdin:
    tam = len(line) -1
    letters = {}
    for i in range(tam):
        if line[i] in letters:
            letters[line[i]] += 1
        else:
            letters[line[i]] = 1
    temp = factorial(tam)
    for item in letters:
        temp = temp // factorial(letters[item])
    
    print(temp)