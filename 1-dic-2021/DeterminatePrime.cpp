#include<bits/stdc++.h>

bool criba[32005];
std::vector <int> primos;

void seive()
{
    memset(criba, true, sizeof(criba));

    for(int i = 4; i < 32005; i += 2) 
        criba[i] = false;

    criba[0] = criba[1] = false;

    for(int i = 3; i * i < 32005; i+=2)
    {
        if(criba[i])
        {
            for(int j = i * i; j < 32005; j += (2 * i)) 
                criba[j] = false;
        }
    }

    for(int i = 1; i < 32005; i++){
        if(criba[i]) primos.push_back(i);
    }
}


void imprimir_intervalo(int inicio, int fin)
{
    std::cout << primos[inicio];
    for(int i = inicio + 1; i < fin; i++){
        std::cout << " " << primos[i];
    }
    std::cout << " " << primos[fin] << std::endl;
}

int main() 
{

    seive();

    int tc, num, t = 1, choose;

    int inicio, fin;
    while (std::cin >> inicio >> fin)
    {

        if(inicio == 0 && fin == 0) 
            break;

        if(inicio > fin) 
            std::swap(inicio, fin);

        int i = 0;

        while (primos[i] < inicio)    
            i++;

        //recorrido omitiendo numeros pares
        while (primos[i + 2] <= fin)
        {
            // que sea equidistante
            if(primos[i + 2] - primos[i + 1] == primos[i + 1] - primos[i])
            {
                int inicio_idx = i;
                int fin_idx = i + 2;
                int diferencia = primos[i + 1] - primos[i];

                while (i + 3 < primos.size() && primos[i + 3] - primos[i + 2] == diferencia)
                {
                    fin_idx++;
                    i++;
                }

                if(primos[fin_idx] <= fin)
                {
                    if(inicio_idx == 0 || primos[inicio_idx] - primos[inicio_idx - 1] != diferencia){
                        imprimir_intervalo(inicio_idx, fin_idx);
                    }
                }
                else
                    break;
            }
            i++;
        }

    }

    return 0;
}