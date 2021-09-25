def f(price, weeks, N, B):
    result = None
    if B  >= price * N:
        for k in weeks:
            if k >= N:
                result = price * N
                break
    return result


# read input file from stdin
import sys

answers = []
for line in sys.stdin:
#    print("line: ", line)
    [N, B, H, W] = [int(x) for x in line.split()]
    temp_answers = []
    for k in range(H):
        precio = int(input())
        available_beds = [int(x) for x in input().split()]
        result = f(precio, available_beds, N, B)
        if result is not None:
            temp_answers.append(result)
    if len(temp_answers) > 0:
        resultado = min(temp_answers)
    else:
        resultado = "stay home"
    answers.append(resultado)

# write output to stdout
for answer in answers:
    print(answer)


