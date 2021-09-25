from math import ceil
T = int(input())



answers = []
for case in range(T):
    N = int(input())
    calls = [int(x) for x in input().split()]
    Mile = 0
    Juice = 0
    for call in calls:
        Mile += (call // 30 +1) *10 
        Juice += (call // 60 +1) *15

    temp = []
    if Mile < Juice:
        temp.append("Mile")
        temp.append(Mile)
    elif Mile > Juice:
        temp.append("Juice")
        temp.append(Juice)
    else:
        temp.append("Mile Juice")
        temp.append(Mile)
    answers.append(temp)


for k in range( len(answers) ):
    num = str(k+1) +":"
    print("Case", num, answers[k][0], answers[k][1])