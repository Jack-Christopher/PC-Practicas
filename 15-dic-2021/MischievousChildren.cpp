#include <bits/stdc++.h>

long long int  factorial(int n)
{
    long long int fact = 1;
    for (int i = 1; i <= n; i++)
    {
        fact = fact * i;
    }
    return fact;
}

std::map<char, int> get_unique_chars(std::string s)
{
    std::map<char, int> m;
    for (char c : s)
    {
        if (m.find(c) == m.end())
            m[c] = 1;
        else
            m[c]++;
    }
    return m;
}

long long int solve(std::map<char, int> map, int tam)
{
    long long int ans = factorial(tam);
    long long int temp = 1;
    for (auto it = map.begin(); it != map.end(); it++)
    {
        temp *= factorial(it->second);
        // std::cout << it->first << " " << it->second << " " << temp << std::endl;
    }
    // std::cout << "temp " << temp << std::endl;
    // std::cout<<"ans "<<ans<<std::endl;

    return ans / temp;
}


int main()
{
    int n;
    std::cin >> n;
    std::string cadena;
    std::map<char, int> map;

    for (int k = 0; k < n; k++)
    {
        std::cin >> cadena;
        map = get_unique_chars(cadena);
        std::cout << "Data set " << k + 1 << ": " << solve(map, cadena.size()) << std::endl;
    }

    return 0;
}