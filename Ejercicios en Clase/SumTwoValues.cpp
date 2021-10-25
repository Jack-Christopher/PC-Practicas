#include <iostream>
#include <vector>
#include <unordered_map>


void SumOfNumbers(std::vector<int> numbers, int target)
{
    std::unordered_map<int, int> hash_table;

    for (int k = 0; k < numbers.size(); k++)
    {
        // int value = numbers[k];
        // int diff = target - value;

        if(hash_table.count(target - numbers[k]) > 0)
        {
			std::cout << k + 1 << " " << hash_table[target - numbers[k]] << "\n";
			return;
		}
		hash_table[numbers[k]] = k + 1;
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

    SumOfNumbers(numbers, x);

    return 0;
}