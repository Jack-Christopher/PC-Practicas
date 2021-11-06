#include <bits/stdc++.h>

int main()
{
    int N, number;
    std::string command;

    std::cin >> N;
    std::stack<int> regalos;
    std::multiset<int> regalos_ordenados;

    while (N--)
    {
        std::cin >> command;

        if (command == "PUSH")
        {
            std::cin >> number;
            regalos.push(number);
            regalos_ordenados.insert(number);
        }
        else if ( command == "POP")
        {
            if (regalos.empty())
                std::cout << "EMPTY" << std::endl;
            else
            {
                regalos_ordenados.erase(regalos.top());
                regalos.pop();
            }
        }
        else if (command == "MIN")
        {
            if (regalos_ordenados.empty())
                std::cout << "EMPTY" << std::endl;
            else
                std::cout << *regalos_ordenados.begin() << std::endl;
        }
    }

    return 0;
}