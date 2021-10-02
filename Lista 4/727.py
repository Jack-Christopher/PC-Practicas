import sys

def precedence(character):
    if character == "*" or character == "/":
        return 2
    elif character == "+" or character == "-":
        return 1
    else:
        return 0

def isOperand(character):
    if character not in "+-*/()":
        return True
    else:
        return False

"""
initially push some special character say # into the stack
   for each character ch from infix expression, do
      if ch is alphanumeric character, then
         add ch to postfix expression
      else if ch = opening parenthesis (, then
         push ( into stack
      else if ch = closing parenthesis ), then
         while stack is not empty and stack top ≠ (,
            do pop and add item from stack to postfix expression
         done
         pop ( also from the stack
      else
         while stack is not empty AND precedence of ch <= precedence of stack top element, do
            pop and add into postfix expression
         done
         push the newly coming character.
   done
   while the stack contains some remaining characters, do
      pop and add to the postfix expression
   done
   return postfix
"""

def from_infix_to_posix(expression):
    stack = ["#"]
    output = ""
    for index in range(len(expression)):
        if expression[index].isnumeric():
            output += expression[index]
        elif expression[index] == "(":
            stack.append("(")
        elif expression[index] == ")":
            while stack[-1] != "#"  and stack[-1] != "(":
                output += stack.pop()
            stack.pop()
        else:
            if precedence(stack[-1]) < precedence(expression[index]):
                stack.append(expression[index])
            else:
                while stack[-1] != '#' and precedence(stack[-1]) >= precedence(expression[index]):
                    output += stack.pop()
                stack.append(expression[index])
    while stack[-1] != "#":
        output += stack.pop()
    
    return output
    
    
        
n = int(input())
answers = []
input()
for t in range(n-1):
    # print("t:"+str(t))
    expresion = ""
    while True:
        item = input()
        if item == '':
            break
        else:
            expresion += item
    answers.append(from_infix_to_posix(expresion))

# print("last")
expresion = ""
for line in sys.stdin:
    expresion += line.split()[0]
answers.append(from_infix_to_posix(expresion))

print(answers[0])
for i in range(1, len(answers)):
    print()
    print(answers[i])
        
            
        
# print(answers)