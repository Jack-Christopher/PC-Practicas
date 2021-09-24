#include <iostream>
#include <bits/stdc++.h>

int main()
{
    int t;
    std::cin >> t;

    while (t--)
    {
        int n, x_i;
        std::cin >> n;
        int min = INT_MAX, max = INT_MIN;
        while (n--)
        {
            std::cin >> x_i;
            if (x_i > max)
                max = x_i;
            if (x_i < min)
                min = x_i;
        }
        std::cout << 2 *(max - min) << std::endl;
    }

    return 0;
}