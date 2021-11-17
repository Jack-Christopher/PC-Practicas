#include <bits/stdc++.h>


bool process(std::string text,std::string pattern)
{
    int s = pattern.size();
    for (int i = 0; i < text.size(); i++)
    {
        if (text[i] != pattern[i%s])
            return false;
    }
    return true;
}

std::vector<int> divisores(int number)
{
    std::vector<int> divisors;
    for(int i = 1; i <= number; i++)
    {
        if(number % i == 0)
            divisors.push_back(i);
    }
    return divisors;
}

int aux_kmp(std::string text)
{
    std::vector<int> divisors = divisores(text.size());

    for (int k = 0; k < divisors.size(); k++)
    {
        if (process(text, text.substr(0, divisors[k])) == true)
            return divisors[k];
    }
}

int main()
{
    int N;
    std::cin>>N;
    std::string text;

    while(N--)
    {
        std::cin>>text;        
        std::cout<< aux_kmp(text);

        if (N)
            std::cout<<"\n\n";
        else
            std::cout<<"\n";
    }

    return 0;
}




