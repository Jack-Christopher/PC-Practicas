#include <iostream>
#include <stack>

int scoreOfParentheses(std::string s)
{
    std::stack<int> pila;
    
    for (int k = 0; k < s.size(); k++)
    {
        if (s[k] == '(')
        {
            pila.push(0);
        }
        else if (s[k] == ')')
        {
            int tmp = pila.top();
            if (tmp == 0)
            {
                pila.pop();
                int quantity = 1;
                if (!pila.empty() && pila.top() > 0)  // maybe an if
                {
                    quantity += pila.top();
                    pila.pop();
                }
                pila.push(quantity);
            }
            else if (tmp > 0)
            {
                pila.pop(); // the number inside the ()
                pila.pop(); // the '(' symbol
                // pila.push(2*tmp);
                int quantity = 2*tmp;
                if (!pila.empty() && pila.top() > 0)  // maybe an if
                {
                    quantity += pila.top();
                    pila.pop();
                }
                pila.push(quantity);
            }
        }
    }

    return pila.top();   
    
}

int main()
{
    std::string cadena;
    std::cin >> cadena;
    std::cout << scoreOfParentheses(cadena);

    return 0;
}


// Given a balanced parentheses string s, return the score of the string.
// The score of a balanced parentheses string is based on the following rule:

// "()" has score 1.
// AB has score A + B, where A and B are balanced parentheses strings.
// (A) has score 2 * A, where A is a balanced parentheses string.