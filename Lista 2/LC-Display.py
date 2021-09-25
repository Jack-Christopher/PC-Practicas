import sys

def print_numbers(number):
    for i in range(len (number)):
        for j in range(len (number[i])):
            print(number[i][j], end='')
        print()


space = [
    [' '],
    [' '],
    [' '],
    [' '],
    [' ']
]

numbers =[
    [
        [' ', '-', ' ' ],
        ['|', ' ', '|' ],
        [' ', ' ', ' ' ],
        ['|', ' ', '|' ],
        [' ', '-', ' ' ]
    ],
    [
        [' ', ' ', ' ' ],
        [' ', ' ', '|' ],
        [' ', ' ', ' ' ],
        [' ', ' ', '|' ],
        [' ', ' ', ' ' ]
    ],
    [
        [' ', '-', ' ' ],
        [' ', ' ', '|' ],
        [' ', '-', ' ' ],
        ['|', ' ', ' ' ],
        [' ', '-', ' ' ]
    ],
    [
        [' ', '-', ' ' ],
        [' ', ' ', '|' ],
        [' ', '-', ' ' ],
        [' ', ' ', '|' ],
        [' ', '-', ' ' ]
    ],
    [
        [' ', ' ', ' ' ],
        ['|', ' ', '|' ],
        [' ', '-', ' ' ],
        [' ', ' ', '|' ],
        [' ', ' ', ' ' ]
    ],
    [
        [' ', '-', ' ' ],
        ['|', ' ', ' ' ],
        [' ', '-', ' ' ],
        [' ', ' ', '|' ],
        [' ', '-', ' ' ]
    ],
    [
        [' ', '-', ' ' ],
        ['|', ' ', ' ' ],
        [' ', '-', ' ' ],
        ['|', ' ', '|' ],
        [' ', '-', ' ' ]
    ],
    [
        [' ', '-', ' ' ],
        [' ', ' ', '|' ],
        [' ', ' ', ' ' ],
        [' ', ' ', '|' ],
        [' ', ' ', ' ' ]
    ],
    [
        [' ', '-', ' ' ],
        ['|', ' ', '|' ],
        [' ', '-', ' ' ],
        ['|', ' ', '|' ],
        [' ', '-', ' ' ]
    ],
    [
        [' ', '-', ' ' ],
        ['|', ' ', '|' ],
        [' ', '-', ' ' ],
        [' ', ' ', '|' ],
        [' ', '-', ' ' ]
    ]
]

def get_wider(number_to_print, col):   
    result = []
    for n_line in range(5):
        line = []
        line.append(number_to_print[n_line][0])
        for n_col in range(col - 2):
            line.append(number_to_print[n_line][1])
        line.append(number_to_print[n_line][2])
        result.append(line)           
        
    return result

def get_higher(number_to_print, row):
    result = []
    result.append(number_to_print[0])
    for n_line in range((row - 3)//2):
        result.append(number_to_print[1])
    result.append(number_to_print[2])
    for n_line in range((row - 3)//2):
        result.append(number_to_print[3])
    result.append(number_to_print[4])

    return result

    
    
def draw_number(number, s):
    row = 2*s + 3
    col = s + 2
    
    number_to_print = numbers[number]
    number_to_print = get_wider(number_to_print, col)
    number_to_print = get_higher(number_to_print, row)
    
    # print_numbers(number_to_print)

    return number_to_print



def join_numbers(lista):
    result = []
    for row in range(len(lista[0])):
        line = []
        for number in lista:
            line += number[row]
            line += [" "]
        line = line[:-1]
        result.append(line)
    
    return result


for line in sys.stdin:
    line = line.replace("\n", "")
    if line == "0 0":
        break
    [s, num ] = [x for x in line.split()]
    numbers_to_print = [ int(x) for x in num]
    numbers_to_print =  [draw_number(x, int(s)) for x in numbers_to_print]
    numbers_to_print = join_numbers(numbers_to_print)
    print_numbers(numbers_to_print)
    print()

