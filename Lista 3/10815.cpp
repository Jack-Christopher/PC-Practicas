#include <iostream>
#include <set>


int main()
{
    std::string word, temp;
    std::set<std::string> words;

    while (std::cin >> word)
    {
        for (int i = 0; i < word.size(); ++i)
        {
            char c = tolower(word[i]);
            if (c >= 'a' && c <= 'z')
                temp += c;
            else if (temp != "")
            {
                words.insert(temp);
                temp = "";
            }
        }
        if (temp != "")
            words.insert(temp);
        temp = "";

    }
    
    //iterate over a set in c++
    for (auto it = words.begin(); it != words.end(); ++it)
    {
        std::cout << *it << std::endl;

    }

    return 0;
}