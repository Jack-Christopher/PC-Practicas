#include <iostream>
#include <stack>

int f(std::string s)
{
    int n = 0;
    std::stack<char> pila;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '(')
        {
            pila.push(s[i]);
        }
        else if (s[i] == ')')
        {
            if (pila.empty())
                n++;            
            else if (pila.top() == '(')
                pila.pop();
        }
    }

    while (!pila.empty())
    {
        n++;
        pila.pop();
    }
    return n;
}

int main()
{
    std::string s;
    std::cin >> s;
    printf("%d", f(s));

    return 0;
}