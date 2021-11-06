#include <iostream>
#include <vector>
#include <queue>

int latencia[20005];
std::vector< std::vector<std::pair<int, int>> > adjacency_matrix;

void Dijkstra(int s, int n)
{
    for(int i = 0; i<n; i++) latencia[i] = 2147483647;  // 2147483647 es el valor maximo de int
    latencia[s] = 0;
    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>> > p_queue;
    p_queue.push( std::pair<int, int>(latencia[s], s) );
    std::pair<int, int> p;
    int t, u;
    while(!p_queue.empty()){
        p = p_queue.top();
        p_queue.pop();
        t = p.first;
        u = p.second;
        if(t > latencia[u] ) 
            continue;
        for(int i = 0; i<adjacency_matrix[u].size(); i++)
        {
            if(latencia[adjacency_matrix[u][i].first] > latencia[u] + adjacency_matrix[u][i].second)
            {
                latencia[adjacency_matrix[u][i].first] = latencia[u] + adjacency_matrix[u][i].second;
                p_queue.push( std::pair<int, int>(latencia[adjacency_matrix[u][i].first], adjacency_matrix[u][i].first) );
            }
        }
    }
}

int main()
{
    int n_cases;
    scanf("%d", &n_cases);
    int n, m, s, t;
    for (int k = 0; k < n_cases; k++)
    {
        scanf("%d %d %d %d", &n, &m, &s, &t);

        adjacency_matrix.assign(n, std::vector<std::pair<int,int>>(0));
        int x, y, l;
        for(int i = 0; i<m; i++)
        {
            scanf("%d%d%d", &x, &y, &l);
            adjacency_matrix[x].push_back( std::pair<int, int>(y, l) );
            adjacency_matrix[y].push_back( std::pair<int, int>(x, l) );
        }

        Dijkstra(s, n);
        printf("Case #%d: ", k+1);

        if(latencia[t] != 2147483647) 
            printf("%d\n", latencia[t]);
        else 
            printf("unreachable\n");
        
    }
    return 0;
}
