import sys 

def mines_adjacent(x, y, board):
    
    for i in range(x-1, x+2):
        for j in range(y-1, y+2):
            
            if i >= 0 and i < len(board) and j >= 0 and j < len(board[i]):
                
                if (i != x or j != y):
                    
                    if board[i][j] != '*':
                        
                        
                        board[i][j] += 1

    

answers = []
for line in sys.stdin:
    [m, n] = [int(x) for x in line.split()]
    if  m == 0 and n == 0:
        break
    matriz = []
    for i in range(m):
        matriz.append( [x for x in input()] )

    mines = []
    for i in range(m):
        for j in range(n):
            if matriz[i][j] == '*':
                mines.append([i,j])
            elif matriz[i][j] == '.':
                matriz[i][j] = 0
            
    for mine in mines:
        mines_adjacent(mine[0], mine[1], matriz)
    answers.append(matriz)


print( "Field #1:")
for i in range(len(answers[0])):
    for j in range(len(answers[0][i])):
        print(answers[0][i][j], end = "")
    print()


for k in range(1, len(answers)):    
    print()
    print( "Field #" + str(k+1) +":")
    for i in range(len(answers[k])):
        for j in range(len(answers[k][i])):
            print(answers[k][i][j], end = "")
        print()
