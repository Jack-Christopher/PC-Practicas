#include <iostream>
#include <vector>

void SumOfNumbers(std::vector<int> numbers, int target)
{
    int start = 0, end = numbers.size() - 1;
    while (start < end)
    {
        if (numbers[start] + numbers[end] == target)
        {
            std::cout << "[" << start << ", " << end << "] positions\n";
            return;
        }
        else if (numbers[start] + numbers[end] < target)
        {
            start++;
        }
        else
        {
            end--;
        }
    }
    std::cout << "IMPOSIBLE" << std::endl;
}



int main()
{
    std::vector<int> numbers = {1, 2, 7, 9, 11, 15};
    // std::vector<int> numbers = {-1, 1, 2, 3, 5};
    int target = 11;
    SumOfNumbers(numbers, target);

    return 0;
}