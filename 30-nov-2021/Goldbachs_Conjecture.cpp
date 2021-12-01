#include <bits/stdc++.h>

bool es_primo(int n)
{
    //using pow
    if (n == 2)
        return true;
    if (n % 2 == 0)
        return false;
    for (int i = 3; i * i <= n; i += 2)
        if (n % i == 0)
            return false;
    return true;
}

int GC(int n)
{
    for (int k = 3; k < n-3; k += 2)
        if (es_primo(k) && es_primo(n-k))
            return k;
}

int main()
{
    int n, k;

    while (true)
    {
        std::cin >> n;
        if (n == 0)
            break;
        k = GC(n);
        std::cout << n<< " = " << k << " + " << n-k << std::endl;
    }

    return 0;
}