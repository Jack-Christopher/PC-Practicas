#include  <iostream>


void f(int n)
{
    bool aux[n-1];
    int lista[n];
    for (int i = 0; i < n; i++)
    {
        aux[i] = false;
        std::cin >> lista[i];
    }

    if ( n == 1)
    {
        std::cout << "Jolly" << std::endl;
        return;
    }
    for (int k = 1; k < n; k++)
    {
        int dif = abs(lista[k] - lista[k-1]);
        if (dif > n-1 || dif == 0 || aux[dif-1] == true)
        {
            std::cout << "Not jolly" << std::endl;
            return;
        }
        else
        {
            aux[dif-1] = true;
        }
    }
    std::cout << "Jolly" << std::endl;
}


int main()
{
    int n;
    while (std::cin>> n)
    {
        f(n);
    }

    return 0;
}