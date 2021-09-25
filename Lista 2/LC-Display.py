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
        [' ', '|', ' ' ],
        [' ', ' ', ' ' ],
        [' ', '|', ' ' ],
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

def increment_number(number_to_print, s):
    col = s+2
    row = 2*s+3
    number_to_print = numbers[number_to_print]
    print_number(number_to_print)
    number_ = number_to_print[0]
    for i in range(s):
        number_.append(number_to_print[1])
        
    

    return number_to_print

    




def draw_number(number, s):
    col = s
    row = 2*s+3

    number_to_print= increment_number(number, s)


    for k in range(row):
        for m in range(col):
            print(number_to_print[k][m], end='')
        print()


# draw_number(int(input()), 1)

def print_number(number):
    for i in range(len (number)):
        for j in range(len (number[i])):
            print(number[i][j], end='')
        print()

print_number(increment_number(int(input()), 2))
