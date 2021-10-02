#include <iostream>
#include <vector>
#include <stack>

int main()
{
    int N, M, number;
    std::vector<int> aux;
    bool isOK = true;
    std::vector<std::string> answers;

    std::cin>> N;
    while (N != 0)
    {
        isOK = true;
        while (isOK)
        {
            aux.clear();
            std::stack<int> coaches;
            for (int k = 0; k < N; k++)
            {
                std::cin>> number;
                if (number == 0)
                {
                    answers.push_back("next");
                    isOK = false;
                    break;
                }
                aux.push_back(number);
            }

            // std::cout<< "ok";

            if (isOK)
            {
                int counter = 0;
                for (int k = 0; k < N; k++)
                {
                    coaches.push(k+1);
                    
                    while (!coaches.empty() && coaches.top() == aux[counter])
                    {
                        coaches.pop();
                        counter++;
                    }
                }
                // std::cout<< "ok++";

                if (coaches.empty())
                    answers.push_back("Yes");
                else
                    answers.push_back("No");
            }
        }
        std::cin>> N;
    }


    for (int k = 0; k < answers.size(); k++)
    {
        if (answers[k] != "next")
            std::cout<< answers[k]<<"\n";
        else
            std::cout<< "\n";
    }

    return 0;
}