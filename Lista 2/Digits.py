import sys

def X_i(number): #number: string
    answer = 0
    while number != "1":  
        number = str(len(number))
        answer += 1    

    return answer+1


answers = []
for line in sys.stdin:
    if line.startswith("END"):
        break
    else:
        resultado = X_i(line.replace('\n',''))
        answers.append(resultado)



for answer in answers:
    print(answer)