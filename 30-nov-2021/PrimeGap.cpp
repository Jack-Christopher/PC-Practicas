#include <bits/stdc++.h>

std::vector<int> criba(1299709, 1);

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

void build_criba()
{
    criba[0] = criba[1] = false;
    for (int i=2; i<1299709; ++i) 
    {
        if (criba[i]) 
        {
            for (int h=2; h*i<1299709; ++h) 
                criba[i*h] = 0;
        }
    }  
}


int prime_gap(int n)
{
    if (es_primo(n))
        return 0;
    int temp1 = n;
    int temp2 = n;
    while (!criba[temp1])
        temp1++;
    while (!criba[temp2])
        temp2--;
    return temp1 - temp2;
}

int main()
{
    build_criba();
    int n;
    while(true)
    {
        std::cin >> n;
        if(n == 0)
            break;
        std::cout << prime_gap(n) << std::endl;
    }

    return 0;
}