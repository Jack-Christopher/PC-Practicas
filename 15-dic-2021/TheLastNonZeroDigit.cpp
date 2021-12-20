#include <bits/stdc++.h>

int permutacion(int n, int m)
{
    long long int ans = 1;
    for (int k = n; k > n-m; k--)
    {
        ans *= k;
        while(ans%10 == 0)
            ans /= 10;
        ans %= 1000000000;
    }

    return ans%10;
}

int main()
{
    int n, m;
    // read input
    while(std::cin >> n >> m)
    {
        std::cout << permutacion(n, m) << std::endl;
    }

    return 0;
}