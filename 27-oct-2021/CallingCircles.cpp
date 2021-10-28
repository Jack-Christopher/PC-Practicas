#include <iostream>
#include <cstdio>
#include <map>


int main() 
{
    int n, m, test_cases = 0;

    while(std::cin >> n >> m) 
    {
        if(n==0 && m==0)
            break;
        if(test_cases > 0)
            std::cout<< "\n";

        // Cabecera
        printf("Calling circles for data set %d:\n", ++test_cases);

        std::map<std::string, int> name_map;
        int tam = 0, i, j, k;
        int graph[26][26] = {}; // conexiones entre personas (circulo de llamadas)
        int x, y;
        int usado[26] = {};
        std::string nombre[26], a, b; // nombres

        while(m--) 
        {
            std::cin >> a >> b;
            x = name_map[a];
            if(x == 0)
                name_map[a] = ++tam, x = tam, nombre[tam] = a;
            y = name_map[b];
            if(y == 0)
                name_map[b] = ++tam, y = tam, nombre[tam] = b;
            graph[x][y] = 1;
        }
        
        for(i = 1; i <= tam; i++)
            graph[i][i] = 1;

        // Establecer conexiones entre personas con transitividad
        // si A llama a B y B llama a C, entonces A y C estan conectados
        for(k = 1; k <= tam; k++) 
            for(i = 1; i <= tam; i++) 
                for(j = 1; j <= tam; j++) 
                    if(graph[i][k] == 1 && graph[k][j] == 1)
                        graph[i][j] = 1;

        for(i = 1; i <= tam; i++) 
        {
            if(!usado[i]) 
            {
                int counter = 0;
                for(j = 1; j <= tam; j++) 
                {
                    if((!usado[j]) && graph[i][j] && graph[j][i]) 
                    {
                        usado[j] = 1;
                        usado[i] = 1;
                        if(counter)
                            printf(", ");
                        printf("%s", nombre[j].c_str());
                        counter++;
                    }
                }
                std::cout << "\n";
            }
        }
    }
    return 0;
}