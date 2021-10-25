#include <iostream>

void maximum_sum(int array[], int n, int k)
{
    int maximum_sum = 0;
    int temp_sum = 0;
    int index_first = 0;
    //fill k-block
    for (int p = 0; p < k; p++)
        temp_sum += array[p];
    maximum_sum = temp_sum;

    for (int p = 0; p < n-k; p++)
    {
        temp_sum += array[p+k];
        temp_sum -= array[index_first];
        index_first++;
        if (temp_sum > maximum_sum)
            maximum_sum = temp_sum;
    }

    std::cout << maximum_sum << std::endl;
}

int main()
{
    int array[] = { -4, -3, 1, 2, 3};
    int n = sizeof(array) / sizeof(array[0]);
    int k;
    std::cin >> k;
    maximum_sum( array, n, k);

    return 0;
}