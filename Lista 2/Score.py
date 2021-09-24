T = int(input())

answers = []
for test_case in range(T):
    case = input()
    result = 0
    higher = 0
    for i in range(len(case)):
        if case[i] == 'O':
            higher += 1
            result += higher
        elif case[i] == 'X':
            higher = 0
    answers.append(result)

for answer in answers:
    print(answer)

    