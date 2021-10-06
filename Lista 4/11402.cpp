#include <iostream>
#include <vector>
#include <math.h>

class SumSegmentTree
{
private:
    int n;
    std::vector<int> tree;
    std::vector<bool> arreglo;

public:
    SumSegmentTree(std::vector<bool> &arreglo)
    {
        this->arreglo = arreglo;
        n = arreglo.size();
        int x = (int)(ceil(log2(n)));
        int max_size = 2*(int)pow(2, x) - 1;
        tree.resize(max_size);
        build(0, 0, n - 1);
    }

    void build(int node, int start, int end)
    {
        if (start == end)
        {
            tree[node] = arreglo[start];
            return;
        }
        int mid = (start + end) / 2;
        build(2 * node+1, start, mid);
        build(2 * node + 2, mid + 1, end);
        tree[node] = tree[2 * node+1] + tree[2 * node + 2];
    }

    int query(int node, int start, int end, int i, int j)
    {
        if (start > j || end < i)
            return 0;
        if (start >= i && end <= j)
            return tree[node];
        int mid = (start + end) / 2;
        return query(2 * node+1, start, mid, i, j) + query(2 * node + 2, mid + 1, end, i, j);
    }

    int query (int start, int end)
    {
        return query(0, 0, n - 1, start, end);
    }

    void update(int node, int start, int end, int i, int val)
    {
        if (start > i || end < i)
            return;
        if (start == end)
        {
            tree[node] = val;
            return;
        }
        int mid = (start + end) / 2;
        update(2 * node+1, start, mid, i, val);
        update(2 * node + 2, mid + 1, end, i, val);
        tree[node] = tree[2 * node+1] + tree[2 * node + 2];
    }

    // option 0: change all elements in range to cero
    // option 1: change all elements in range to one
    // option 2: change all elements in range to its inverse (0 -> 1, 1 -> 0)

    void update_range(int start, int end, int option)
    {
        for (int k = start; k <= end; k++)
        {
            if (option == 0)
                arreglo[k] = 0;
            else if (option == 1)
                arreglo[k] = 1;
            else if (option == 2)
                arreglo[k] = !arreglo[k];
            update(0, 0, n - 1, k, arreglo[k]);
        }
        
    }

    // void print()
    // {
    //     for (int i = 0; i < tree.size(); i++)
    //         std::cout << tree[i] << " ";
    //     std::cout << std::endl;
    // }
    // void print_array()
    // {
    //     int i, j, h = std::ceil(log2(n));
    //     for(i=0 ; i<=h ; ++i)
    //     {
    //         for(j=0 ; j<pow(2, i) ; ++j)
    //             std::cout<<tree[int(pow(2, i)-1 + j)]<<' ';
    //         std::cout<<std::endl;
    //     }
    // }
};

std::vector<bool> fromStringToVector(std::string s)
{
    std::vector<bool> v;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '1')
            v.push_back(true);
        else
            v.push_back(false);
    }
    return v;
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
        std::vector<bool> arreglo;

        for (int i = 0; i < m; i++)
        {
            int T;
            std::string pirate;
            std::cin>> T;
            std::cin>> pirate;
            for (int t = 0; t < T; t++)
                description += pirate;
        }

        arreglo = fromStringToVector(description);
        SumSegmentTree sst(arreglo);

        int Q, a, b;
        char query;
        std::cin>> Q;
        for (int p = 0; p < Q; p++)
        {
            std::cin>> query >> a >> b; 
            if (query == 'F')
                sst.update_range(a, b, 1);
            else if (query == 'E')
                sst.update_range(a, b, 0);
            else if (query == 'I')
                sst.update_range(a, b, 2);
            else if (query == 'S')
                answers.push_back(sst.query(a, b));
        }        
        
        std::cout<< "Case "<< k+1<< ":\n";
        for (int r = 0; r < answers.size(); r++)
            std::cout<< "Q"<< r+1<< ": "<< answers[r]<< "\n";
    }

    return 0;
}
