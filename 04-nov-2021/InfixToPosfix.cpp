#include <bits/stdc++.h>

bool IsOperator(char c)  
{  
    if(c == '+' || c == '-' || c == '*' || c == '/' || c == '^' )  
        return true;     
    return false;  
}  

bool IsOperand(char c)  
{  
    if( c >= 'A' && c <= 'Z')  /* Define the character in between A to Z. If not, it returns False.*/  
        return true;  
    if (c >= 'a' && c <= 'z')  // Define the character in between a to z. If not, it returns False. */  
        return true;  
    if(c >= '0' && c <= '9')   // Define the character in between 0 to 9. If not, it returns False. */  
        return true;  
    return false;  
}  

int precedence(char op)  
{  
    if(op == '+' || op == '-')                   /* it defines the lowest precedence */  
        return 1;  
    if (op == '*' || op == '/')  
        return 2;  
    if(op == '^')                                  /* exponent operator has the highest precedence */
        return 3;       
    return 0; 
} 

bool eqlOrhigher (char op1, char op2)  
{  
    int p1 = precedence(op1);  
    int p2 = precedence(op2);  
    if (p1 == p2)  
    {  
        if (op1 == '^' )  
            return false;  
        return true;  
    }  
    return  (p1>p2 ? true : false);  
}  

std::string InfixToPostfix(std::string infix)  
{  
    std::stack<char> S;
    std::string postfix ="";    
    char ch;  

    S.push( '(' );  
    infix += ')';  

    for(int i = 0; i<infix.length(); i++)  
    {  
        ch = infix[i];  

        if(ch == ' ')  
            continue;  
        else if(ch == '(')  
            S.push(ch);  
        else if(IsOperand(ch))  
            postfix += ch;  
        else if(IsOperator(ch))  
        {  
            while(!S.empty() && eqlOrhigher(S.top(), ch))  
            {  
                postfix += S.top();  
                S.pop();  
            }  
            S.push(ch);  
        }  
        else if(ch == ')')  
        {  
            while(!S.empty() && S.top() != '(')  
            {  
                postfix += S.top();  
                S.pop();  
            }  
        S.pop();  
        }  
    }  
    return postfix;  
}  



int main()
{
    int N;
    std::string cadena;
    std::cin >> N;

    while (N--)
    {
        std::cin >> cadena;
        std::cout<< InfixToPostfix(cadena) << "\n";
    }

    return 0;
}