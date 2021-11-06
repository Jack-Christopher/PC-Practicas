#include <iostream>
#include <algorithm>
#include <vector>

// std::vector<std::vector<int>> adjacency_matrix;

// std::vector<int> p; // Vector del representante de cada nodo (p[i] es el representante de i)

// Dado un nodo nos devuelve su representante y a la vez hacemos una compresión de caminos
int findSet(int i, std::vector<int> &p) 
{
    if (p[i] != i) 
        p[i] = findSet(p[i], p); //buscamos el representante de la componente
    return p[i];
}

// Dados el número de nodos del grafo (n), y el conjunto de aristas (edges) donde edge[i] =
// {peso del arco, nodo, nodo}, devuelve el coste del mínimo árbol generador.
int Kruskal(int n, std::vector <std::vector<int>>& edges, std::vector<int> &p)
{
    std::sort(edges.begin(), edges.end()); // Ordenamos de menor a mayor los arcos según su peso

    p = std::vector<int>(n);
    for (int i = 0; i < n; ++i) 
        p[i] = i; // el representante de cada nodo es él mismo
        
    int answer = 0; // variable donde acumulamos los pesos de los arcos que cogemos

    for (int i = 0; i < edges.size(); ++i){
        std::vector<int> arc = edges[i]; 

        int u = arc[2];
        int v = arc[1];
        int w = arc[0];

        int pu = findSet(u, p); // representante del nodo u
        int pv = findSet(v, p); // representante del nodo v

        if (pu != pv){ // si no tienen el mismo representante, u y v forman parte de
                       // componentes conexas distintas, por lo que cogemos el arco
            answer += w;
            p[pu] = pv; // actualizamos representantes
        }
    }

    return answer;
}


std::vector<std::vector<int>> edges;

int main()
{
    int m, n;
    int x, y, z;
    std::vector<int> p;
    int suma;
    while (true)
    {
        suma = 0;
        scanf("%d %d", &m, &n);
        if (n == 0 && m == 0)
            break;
        for (int k = 0; k < n; k++)
        {
            scanf("%d %d %d", &x, &y, &z);
            edges.push_back({z, x, y});
            suma += z;
        }
        printf("%d\n", (suma-Kruskal(m, edges, p)));
        p.clear();
        edges.clear();
    }
    return 0;
}