def f(P, B, H, W, CASE_LIST):
    RESULTS = []
    for S_i in CASE_LIST[1]:
        if S_i >= P and S_i * CASE_LIST[0] <= B:
            RESULTS.append(S_i * CASE_LIST[0])
    if len(RESULTS) == 0:
        return "stay home"
    else:
        return min(RESULTS)

# read input file from stdin
import fileinput
answers = []
cont = 0
for line in fileinput.input():
    if cont == 0:
        [P, B, H, W] = [int(x) for x in line.split()]
    elif cont == 1:
        price = int(line)
    elif cont == 2:
        hotels = [int(x) for x in line().split()]
        CASE_LIST =[price, hotels]
    cont += 1
    cont 0
    answers.append(f(P, B, H, W, CASE_LIST))


# write output to stdout
for answer in answers:
    print(answer)


