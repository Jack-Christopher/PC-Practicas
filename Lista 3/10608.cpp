#include <iostream>
#include <vector>

void print_array(int *array, int size)
{
    std::cout << "[";
    for (int i = 0; i < size; i++)
    {
        std::cout << array[i] << " ";
    }
    std::cout << "]\n";
}

class DisjointSet
{
private:
    std::vector<int> parent;
    std::vector<int> rank;  
public:
    DisjointSet(int size)
    {
        parent.resize(size);
        rank.resize(size);
        for (int i = 0; i < size; i++)
        {
            parent[i] = i;
            rank[i] = 1;
        }
    }

    int find(int x)
    {
        if (parent[x] != x)
        {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }

    void union_sets(int x, int y)
    {
        int x_root = find(x);
        int y_root = find(y);
        if (x_root == y_root)
        {
            return;
        }

        if (rank[x_root] < rank[y_root])
        {
            int temp = x_root;
            x_root = y_root;
            y_root = temp;
        }
        parent[y_root] = x_root;
        rank[x_root] += rank[y_root];    
    }

    int max_set_size()
    {
        int max_size = 0;
        for (int k = 0; k < rank.size(); k++)
        {
            if (rank[k] > max_size)
                max_size = rank[k];
        }
        return max_size;
    }
};

int main()
{
    int t;
    std::cin >> t;

    for (int k = 0; k < t; k++)
    {
        int n, m;
        std::cin >> n >> m;

        DisjointSet ds(n);
        
        for (int i = 0; i < m; i++)
        {
            int a, b;
            std::cin >> a >> b;

            ds.union_sets(a-1, b-1); 
        }

        std::cout << ds.max_set_size() << "\n";
    }


    return 0;
}