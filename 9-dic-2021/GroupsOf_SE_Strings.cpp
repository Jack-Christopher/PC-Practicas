#include <bits/stdc++.h>

void specialSort(std::string &s)
{
    int tam = s.size();
    //empezando desde cero
    std::vector<char> odd;
    std::vector<char> even;
    for (int i = 0; i < tam; i++)
    {
        if (i % 2 == 0)
            even.push_back(s[i]);
        else
            odd.push_back(s[i]);
    }
    std::sort(odd.begin(), odd.end());
    std::sort(even.begin(), even.end());
    std::string aux = "";

    for (int i = 0; i < tam; i++)
    {
        if (i % 2 == 0)
            aux += even[i/2];
        else
            aux += odd[i/2];
    }
    s = aux;
}

int numSpecialEquivGroups(std::vector<std::string>& words) 
{
    int tam = words.size();
    std::map<std::string, int> aux;
    for (int i = 0; i < tam; i++)
        specialSort(words[i]);

    for (int i = 0; i < tam; i++)
    {
        if (aux.find(words[i]) == aux.end())
            aux[words[i]] = 1;
        else
            aux[words[i]]++;
    }

    // for (auto it = aux.begin(); it != aux.end(); it++)
    //     std::cout << it->first << " " << it->second << std::endl;
    
    return aux.size();
}

int main()
{
    // std::vector<std::string> words = {"abcd","cdab","cbad","xyzz","zzxy","zzyx"};
    std::vector<std::string> words = {"abc","acb","bac","bca","cab","cba"};
    std::cout << numSpecialEquivGroups(words) << std::endl;
        
    return 0;
}