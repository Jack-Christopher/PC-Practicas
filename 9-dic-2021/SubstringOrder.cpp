#include <bits/stdc++.h>

std::vector<std::string> get_suffix(std::string s)
{
    std::set<std::string> suffixes;
    int tam = s.size();

    for (int i = 0; i < tam; i++)
        suffixes.insert(s.substr(i, tam - i));

    std::vector<std::string> suffix_array;
    for (auto it = suffixes.begin(); it != suffixes.end(); it++)
        suffix_array.push_back(*it);
    return suffix_array;
}


std::vector<std::pair< int,std::string>> getLongestCommonPrefix(std::vector<std::string> suffix_array)
{
    std::vector<std::pair< int,std::string>> LCP;
    int tam = suffix_array.size();
    int difference;
    LCP.push_back({ 0, suffix_array[0]});

    for (int k = 1; k < tam; k++)
    {
        difference = 0;
        while (suffix_array[k][difference] == suffix_array[k - 1][difference])
            difference++;

        LCP.push_back({ difference, suffix_array[k]});
    }

    return LCP;
}

std::string get_k_smallest(int k, std::vector<std::pair< int,std::string>> LCP)
{
    std::string result = "";
    int tam = LCP.size();
    int counter = 0;
    
    for (int t = 0; t < tam; t++)
    {
        int n = LCP[t].second.size() - LCP[t].first;
        counter += n;
        if ( counter >= k)
        {
            result = LCP[t].second.substr(0, k - (counter - n)+LCP[t].first);
            break;
        }
    }
    return result;
}

int main()
{
    std::string s;
    int k;
    std::cin >> s >> k;
    auto g = get_suffix(s);
    auto p = getLongestCommonPrefix(g);
    std::string result = get_k_smallest(k, p);
    std::cout << result << "\n";

    return 0;
}