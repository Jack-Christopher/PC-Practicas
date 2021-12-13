#include <bits/stdc++.h>
 
int main()
{
    std::string s;
    int k;
    std::cin >> s >> k;
    // Se crea un std::map para cada letra minuscula o mayuscula
    // que aparezca y como valor las subcadenas que pueda tener
    std::map<char, std::multiset<std::string>> substring_map;
    for (int i = 0; i < s.size(); i++)
    {
        for (int j = i; j < s.size(); j++)
        {
            substring_map[s[i]].insert(s.substr(i, j - i + 1));
        }
    }
 
    int counter = 0;
    // se busca por cada letra en el map
    // si se encuentra una subcadena que ocupe el puesto k 
    for (auto it = substring_map.begin(); it != substring_map.end(); it++)
    {
        int tam = it->second.size();
        if (counter + tam < k ) 
        {
            counter += tam;
        }
        else
        {
            int idx = 0;
            for (auto it2 = it->second.begin(); it2 != it->second.end(); it2++)
            {
                if (idx == k - counter-1)
                {
                    std::cout << *it2 << std::endl;
                    break;
                }
                idx++;
            }
            break;
        }
    }
    return 0;
}