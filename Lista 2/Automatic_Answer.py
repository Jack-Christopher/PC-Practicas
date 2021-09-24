n = int(input())

def question(n):
    n = n*567
    n = n/9
    n = n+7492
    n = n*235
    n = n/47
    n = n-498
    n = abs(n)//10
    n = n%10
    return n


answers = []
for test_case in range(n):
    n = int(input())
    answers.append(question(n))

for answer in answers:
    print(int(answer))

