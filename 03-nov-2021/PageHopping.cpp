#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>


void FloydWarshall(std::vector<std::vector<int>>& graph)
{
    for (int k = 1; k <= 100; ++k)
            for (int i = 1; i <= 100; ++i)
                for (int j = 1; j <= 100; ++j)
                    graph[i][j] = std::min(graph[i][j], graph[i][k] + graph[k][j]);
}
int main()
{    
    int counter = 1;   
    int a, b;
    while (std::cin >> a >> b, !(a == 0 && b == 0))
    {
        std::vector<std::vector<int> > adjacency_matrix(101, std::vector<int>(101, 1000));

        do {
            adjacency_matrix[a][b] = 1;
        } while (std::cin >> a >> b, !(a == 0 && b == 0));

        // Floyd-Warshall 
        FloydWarshall(adjacency_matrix);

        int sum = 0, count = 0;
        for (int i = 1; i <= 100; ++i)
            for (int j = 1; j <= 100; ++j)
                if (i != j && adjacency_matrix[i][j] != 1000)
                {
                    sum += adjacency_matrix[i][j];
                    ++count;
                }
            
        std::cout << "Case " << counter++ << ": average length between pages = " << std::setprecision(3) << std::fixed << (double)sum / count << " clicks\n";
    }
    return 0;
}