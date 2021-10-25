#include <iostream>
#include <set>

void print_sorted_squared_array( int array[], int n)
{
    std::multiset<int> squared_numbers;
    for( int k = 0; k < n; k++)
        squared_numbers.insert( array[k] * array[k]);
    //print multiset
    for( std::multiset<int>::iterator it = squared_numbers.begin(); it != squared_numbers.end(); it++)
        std::cout << *it << " ";
}

int main()
{
    // int array[] = { -4, -3, 1, 5, 6, 2, -1, 4, -2 };
    int array[] = { -4, -3, 1, 2, 3};
    int n = sizeof(array) / sizeof(array[0]);
    print_sorted_squared_array( array, n);
    
    return 0;
}