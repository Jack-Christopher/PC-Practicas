#include <bits/stdc++.h>

int factorizacion(int n)
{
    std::set<int> factores;
    for (int i = 2; i * i <= n; i++)
    {
        while(n%i == 0)
        {
            factores.insert(i);
            n /= i;
        }
    }
    if (n > 1)
        factores.insert(n);
    return factores.size();
}

int main()
{
    int n;
    while (true)
    {
        std::cin >> n;
        if (n == 0)
            break;
        std::cout << n<<" : "<< factorizacion(n) << std::endl;       
    }

    return 0;
}