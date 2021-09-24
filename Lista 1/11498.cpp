#include <iostream>
std::string getAnswer(int N, int M, int x, int y) 
{
    std::string answer = "";

    if (x == N || y == M)
        answer = "divisa";
    
    else if (x > N )
    {
        if (y > M)
            answer = "NE";
        else
            answer = "SE";
    }
    else 
    {
        if (y > M)
            answer = "NO";
        else
            answer = "SO";
    }

    return answer;
}


int main()
{
    int K;
    while (std::cin>> K && K != 0)
    {
        int N, M;
        std::cin>> N >> M;

        while (K--)
        {
            int x, y;
            std::cin>> x >> y;
            std::cout<< getAnswer(N, M, x, y) << std::endl;
        }
    }


    return 0;
}