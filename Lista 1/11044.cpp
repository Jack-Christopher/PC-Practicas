#include <iostream>
#include <vector>

int main()
{
    int t;
    int n, m;

    std::vector<int> answers;
    std::cin>> t;
    
    for (int k = 0; k < t; k++)
    {
        std::cin>> n >> m;
        answers.push_back(int(n/3) * int(m/3));
    }

    for (int k = 0; k < answers.size(); k++)
    {
        std::cout<< answers[k] << "\n";
    }


    return 0;
}