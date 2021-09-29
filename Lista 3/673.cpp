#include <iostream>
#include <stack>
void print_stack(std::stack<char> &s)
{
    std::stack<char> aux = s;
    while (!aux.empty())
    {
        std::cout << aux.top() << " ";
        aux.pop();
    }
}


bool is_balanced(std::string s)
{
    std::stack<char> stack;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '(' || s[i] == '[' )
        {
            stack.push(s[i]);
        }
        else if (s[i] == ')' || s[i] == ']')
        {
            if (stack.empty())
            {
                return false;
            }
            else if (s[i] == ')' && stack.top() == '(' || s[i] == ']' && stack.top() == '[')
            {
                stack.pop();
            }
            else
                return false;
        }
    }
    
    if (stack.empty())
        return true;    
    else
        return false;        
}

int main()
{
    int n;
    std::cin >> n;
    std::cin.ignore();
    std::stack<char> pila;

    std::string cadena;
    for (int k = 0; k < n; k++)
    {
        std::getline(std::cin, cadena);
        // std::cout<< "--"<< cadena << "--" << std::endl;
        if (is_balanced(cadena))
            std::cout << "Yes\n";
        else
            std::cout << "No\n";
    }

    return 0;
}