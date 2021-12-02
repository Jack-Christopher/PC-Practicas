#include <bits/stdc++.h>

std::set<std::string> repeated;

std::vector<std::string> get_suffix(std::string &s)
{
    std::vector<std::string> suffix_array;
    int tam = s.size();

    for (int i = 0; i < tam; i++)
        suffix_array.push_back(s.substr(i, tam));   
    
    std::sort(suffix_array.begin(), suffix_array.end());
    
    return suffix_array;
}


void getLongestCommonPrefix(std::vector<std::string> &suffix_array)
{
    int tam = suffix_array.size();
    int difference;   

    for (int k = 1; k < tam; k++)
    {
        difference = 0;
        while (suffix_array[k][difference] == suffix_array[k - 1][difference])
        {
            difference++;
            repeated.insert(suffix_array[k].substr(0, difference));
        }
    }
}



int main()
{
    int n, tam;
    std::cin >> n;
    std::string s;
    std::vector<std::string> suffixes;
    

    for (int i = 0; i < n; i++)
    {
        std::cin >> s;
        
        suffixes = get_suffix(s);
        getLongestCommonPrefix(suffixes);
        std::cout<< repeated.size() << std::endl;
        repeated.clear();
    }

    return 0;
}