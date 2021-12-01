#include <bits/stdc++.h>


void factorizacion(int n)
{
    int count = 0;
    std::vector<int> factores;
    int sqrt_n = sqrt(n);
    while(n%2 == 0)
    {
        if (count != 0)
        {
            std::cout << " x ";            
        }
        std::cout << 2;
        n /= 2;
        count++;
    }


    for (int i = 2; i <= sqrt_n; i++)
    {
        while(n%i == 0)
        {
            if (count != 0)
            {
                std::cout << " x ";            
            }
            std::cout << i;
            n /= i;
            count++;
        }
    }
    if (n > 1)
    {
        if (count != 0)
        {
            std::cout << " x ";
        }
        std::cout <<  n ;
    }
}

int main()
{
    int n;
    while(true)
    {
        scanf("%d", &n);
        if(n == 0)
            break;

        printf("%d = ", n);

        if (n < 0)
        {
            printf("-1 x ");
            n *= -1;
        }
        factorizacion(n);
        printf("\n"); 
    }

    return 0;
}