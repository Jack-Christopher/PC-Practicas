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

std::string gcdOfStrings(std::string str1, std::string str2) 
{
    std::vector<int> divisors1 = divisores(str1.size());
    std::vector<int> divisors2 = divisores(str2.size());
    std::vector<int> divisors;
    // keep elements that are in both vectors
    std::set_intersection(divisors1.begin(), divisors1.end(), divisors2.begin(), divisors2.end(), std::back_inserter(divisors));
    //se revirte la cadena (las mas grandes primero)
    std::reverse(divisors.begin(), divisors.end());

    bool first, second;
    std::string sub1, sub2;
    for (int k = 0; k < divisors.size(); k++)
    {
        sub1 = str1.substr(0, divisors[k]);
        sub2 = str2.substr(0, divisors[k]);
        if (sub1 != sub2)
            continue;

        first = process(str1, sub1);
        second = process(str2, sub2);
        if (first && second)
            return sub1;
    }

    return "";
}

int main()
{
    std::string s1, s2;
    std::cin >> s1 >> s2;
    std::cout << gcdOfStrings(s1, s2);

    return 0;
}