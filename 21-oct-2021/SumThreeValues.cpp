#include <iostream>
#include <vector>
#include <unordered_map>


void threeNumbers(std::vector<int> numbers, int target) 
{
    std::unordered_map<int, std::vector<int>> hash_table;

    for (int k = 0; k < numbers.size(); k++)
    {
        hash_table[numbers[k]].push_back(k+1);
    }

    for (int k = 0; k < numbers.size(); k++)
    {
        for (int p = 0; p < numbers.size(); p++)
        {
            if (k != p)
            {
                int value = target - numbers[k] - numbers[p];
                
                auto result = hash_table.find(value);

                if (result != hash_table.end())
                {
                    for ( int t = 0; t < result->second.size(); t++)
                    {
                        if (result->second[t] != k+1 && result->second[t] != p+1)
                        {
                            std::cout<< k+1 << " " << p+1 << " " << result->second[t] << std::endl;
                            return;
                        }
                    }
                    // std::cout<< k << " " << p << " " << value << std::endl;
                }
            }           
        }
    }
    std::cout<< "IMPOSSIBLE" << std::endl;
}

int main()
{

    int n, x;
    std::cin >> n >> x;
    std::vector<int> numbers;

    for (int k = 0; k < n; k++)
    {
        int number;
        std::cin >> number;
        numbers.push_back(number);
    }
    threeNumbers(numbers, x);

    return 0;
}