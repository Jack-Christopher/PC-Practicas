#include <iostream>
#include <vector>

std::vector<int> threeNumbers(std::vector<int> numbers, int target) 
{
    std::vector<int> result ={-1, -1, -1};
    int i = 0, j = 1, k = numbers.size() - 1;
    while ( (i<j) && (j<k))
    {
        if (numbers[i] + numbers[j] + numbers[k] == target)
        {
            result[0] = i;
            result[1] = j;
            result[2] = k;
            return result;
        }
        if (numbers[i] + numbers[j] + numbers[k] < target)
        {
            j++;
            if (j == k)
            {
                i++;
                j = i + 1;
            }
        }
        else
        {
            k--;
            if (j == k)
            {
                i++;
                j = i + 1;
            }
        }
    }
    result = {-1, -1, -1};
    return result;
}



int main()
{

    std::vector<int> numbers = {1, 2, 4, 5, 12};
    int target = 19;
    std::vector<int> result = threeNumbers(numbers, target);
    for (int i = 0; i < result.size(); i++)
    {
        std::cout << result[i] << " ";
    }


    return 0;
}