#include <bits/stdc++.h>

std::vector<std::vector<std::string>> groupAnagrams(std::vector<std::string>& strs) 
{
    std::vector<std::string> aux = strs;
    // apply function  sort to all elements of strs
    std::for_each(strs.begin(), strs.end(), [](std::string& str) {
        std::sort(str.begin(), str.end());
    });

    std::vector<std::vector<std::string>> result;
    std::map<std::string, std::vector<int>> elements_map;

    for (int k = 0; k < strs.size(); k++)
    {
        elements_map[strs[k]].push_back(k);
    }

    for (auto it = elements_map.begin(); it != elements_map.end(); it++)
    {
        std::vector<std::string> aux_vector;
        for (auto it2 = it->second.begin(); it2 != it->second.end(); it2++)
        {
            aux_vector.push_back(aux[*it2]);
        }
        result.push_back(aux_vector);
    }

    return result;
}

int main()
{

    std::vector<std::string> strs = {"eat", "tea", "tan", "ate", "nat", "bat"};

    auto res = groupAnagrams(strs);

    for (auto& v : res)
    {
        for (auto& s : v)
        {
            std::cout << s << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}