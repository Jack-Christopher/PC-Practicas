#include <iostream>
#include <vector>
#include <queue>

struct Arista
{
    int y, t;
};

std::vector<Arista> edges[1005];
int distancias[1005];

int main()
{
    int test_cases;
    std::cin >> test_cases;
    
    while (test_cases--)
    {
        int N, E;
        std::cin >> N >> E;
        
        for (int i = 0; i < N; ++i)
        {
            edges[i].clear();
            distancias[i] = 1000000000;
        }
        
        Arista a;
        while (E--)
        {
            int x;
            std::cin >> x >> a.y >> a.t;
            // Lista de Adyacencia
            edges[x].push_back(a);
        }
        
        for (int t = 0; t < N - 1; ++t)
        {
            for (int j = 0; j < N; ++j)
            {
                for (int e = 0; e < edges[j].size(); ++e)
                {
                    distancias[edges[j][e].y] = std::min(distancias[edges[j][e].y], distancias[j] + edges[j][e].t);
                }
            }
        }
        
        bool hayBucle = false;
        
        for (int j = 0; j < N; ++j)
            for (int e = 0; e < edges[j].size(); ++e)
                hayBucle = hayBucle | distancias[edges[j][e].y] > distancias[j] + edges[j][e].t; // contiene bucle negativo

        std::cout << (hayBucle ? "possible\n" : "not possible\n");
    }
}