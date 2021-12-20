#include <bits/stdc++.h>

int main()
{
    int N, T;
    std::cin>> N>> T;

    std::map<int, std::set<int>> m;

    int c_i, t_i;
    for (int k = 0; k < N; k++)
    {
        std::cin>> c_i>> t_i;
        m[t_i].insert(c_i);
    }

    int sum = 0;
    int counter = 0;
    // traverse m
    for (auto it = m.begin(); it != m.end(); it++)
    {
        /2/traverse s in reverse
        for (auto it2 = it->second.rbegin(); it2 != it->second.rend(); it2++)
        {
            if (counter <= it->first)
            {
                counter++;
                sum += *it2;
            }
        }
    }       
    std::cout<< sum<< "\n";
    

    return 0;
}