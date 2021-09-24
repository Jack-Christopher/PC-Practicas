#include <iostream>
#include <vector>

int main()
{
    std::vector<std::string> vec;
    std::string text;

    while (std::getline(std::cin, text))
    {
        vec.push_back(text);
    }

    for (int k = 0; k < vec.size(); k++)
    {
        std::cout << vec[k] << "\n";
    }

    return 0;
}