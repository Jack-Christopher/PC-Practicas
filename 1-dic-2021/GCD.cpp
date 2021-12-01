#include <bits/stdc++.h>

int GCD(int a, int b)
{
    int r;
    while (b != 0)
    {
        r = a % b;
        a = b;
        b = r;   
    }

    return a;
}

int res(int N)
{
    int G=0;
    for(int i=1;i<N;i++)
    {
        for(int j=i+1;j<=N;j++)
        {
           G+=GCD(i,j);
        }
    }
    return G;
}

int main()
{
    int n;
    while (true)
    {
        std::cin >> n;
        if (n == 0)
            break;
        std::cout << res(n) << std::endl;
    }
    return 0;
}