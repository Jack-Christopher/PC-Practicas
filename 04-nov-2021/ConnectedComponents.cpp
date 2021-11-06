#include <iostream>
#include <list>
#include <set>

class Graph{
public:
    int v;
    std::list<int> *l;
    Graph(int V){
        v=V;
        l=new std::list<int> [v];
    }
    void addEdge(int u,int v){
        l[u].push_back(v);
        l[v].push_back(u);
    }

    void dfsUtil(int src,bool visited[],std::set<int>& s){
        s.insert(src);
        visited[src]=true;
        for(auto it=l[src].begin();it!=l[src].end();it++){
            if(!visited[*it]){
                dfsUtil(*it,visited,s);
            }
        }
    }
    
    void dfs(int v)
    {
        int counter=0;
        bool visited[v]={false};
        int c=1;
        for(int i=0;i<v;i++)
        {
            if(!visited[i])
            {
                counter++;
                std::set<int>s;
                dfsUtil(i,visited,s);
                for(auto j=s.begin();j!=s.end();j++)
                    std::cout<<char(*j +'a')<<",";
    
                std::cout<<"\n";
                c++;
            }
        }
        std::cout<<counter<<" connected components\n";
        std::cout<<"\n";
    }
};


int main()
{
    int N;
    int V, E;
    int a, b;
    char a_, b_;

    std::cin >> N;

    for (int k = 0; k < N; k++)
    {
        Graph g(26);
        std::cin >> V >> E;
        
        for (int i = 0; i < E; i++)
        {
            std::cin >> a_ >> b_;
            // convert letter to number
            a = a_ - 'a';
            b = b_ - 'a';
            g.addEdge(a, b);
        }

        // print all connected components
        std::cout<< "Case #"<< k + 1 << ":\n";
        g.dfs(V);
    }

    return 0;
}
