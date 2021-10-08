#include <bits/stdc++.h> 
#include <iostream>
#include <vector>
#include <bitset>
#include <math.h>


void change(std::bitset<1024000> *bs, int a, int b, int option)
{
    int longitud = b-a+1;
    std::string init (longitud, '1');        
    std::bitset<1024000> aux (init);
    // std::cout<< "aux: " << aux << std::endl;

    if (option == 1)
    {
        aux<<= a;
        // std::cout<< "aux: " << aux << std::endl;
        *bs |= aux;
        // std::cout<< "after OR: \n";
    }
    else if ( option == 0)
    {
        aux<<= a;
        aux = ~aux;
        // std::cout<< "aux: " << aux << std::endl;
        *bs &= aux;
        // std::cout<< "after AND: \n";
    }
    else if (option == -1)
    {   
        aux<<= a;
        // std::cout<< "aux: " << aux << std::endl;
        *bs ^= aux;
        // std::cout<< "after XOR: \n";
    }
    // std::cout << bs->to_string() << "\n\n";
}

int count( std::bitset<1024000> *bs, int a, int b)
{
    int longitud = b-a+1;
    std::string init (longitud, '1');        
    std::bitset<1024000> aux (init);

    aux<<= a;
    aux &= *bs;
    // std::cout<< "S_aux: " << aux << std::endl;
    return aux.count();
}

int main()
{
    // test_cases
    int n;
    std::cin>> n;
    // numero de pares de valores
    for (int k = 0; k < n; k++)
    {
        int m;
        std::cin>> m;
            
        // respuestas
        std::string description = "";
        std::vector<int> answers;

        for (int i = 0; i < m; i++)
        {
            int T;
            std::string pirate;
            std::cin>> T;
            std::cin>> pirate;
            for (int t = 0; t < T; t++)
                description += pirate;
        }
        // std::cout<< "Descripcion: \t" << description << "\n";
        // 101010101010001000
        std::reverse(description.begin(), description.end());
        // std::cout<< "Descripcion: \t" << description << "\n";
        std::bitset<1024000> arreglo(description);

        int Q, a, b;
        char query;
        std::cin>> Q;
        for (int p = 0; p < Q; p++)
        {
            std::cin>> query >> a >> b; 
            if (query == 'F')
                change(&arreglo, a, b, 1);
            else if (query == 'E')
                change(&arreglo, a, b, 0);
            else if (query == 'I')
                change(&arreglo, a, b, -1);
            else if (query == 'S')
                answers.push_back(count(&arreglo, a, b));
        }        
        
        std::cout<< "Case "<< k+1<< ":\n";
        for (int r = 0; r < answers.size(); r++)
            std::cout<< "Q"<< r+1<< ": "<< answers[r]<< "\n";
    }

    return 0;
}
