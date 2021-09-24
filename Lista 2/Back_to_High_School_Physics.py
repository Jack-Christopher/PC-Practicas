import sys
answers = []

for line in sys.stdin:
    x = [int(x) for x in line.split()]
    if (len(x) == 2):
        [a, b] = x
        answers.append(2*a*b)
    else:
        break
    
for answer in answers:
    print(answer)
