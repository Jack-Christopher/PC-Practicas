#include <string.h>
#include <iostream>
#include <map>
#include <vector>
#include <queue>


char papers[100005];

int main() 
{
    int t, cases = 0;
    int n, m, i, j;
    std::cin>> t;

    while(t--) 
    {
        std::cin>> n >> m;
        
        while(getchar() != '\n');
        std::map<std::string, int> erdos_numbers;
        std::map<std::string, int>::iterator it;

        std::vector<short> g[5005];
        int temporal[5005];
        
        erdos_numbers["Erdos, P."] = 0; // colaboracion consigo mismo
        int erdos_numbers_size = 0;
        
        while(n--) 
        {
            gets(papers);
            int index = 0, temp_index = 0;
            for(i = 1; papers[i]; i++) 
            {
                if((papers[i] == ',' || papers[i] == ':') && papers[i-1] == '.') // indicador de fin de nombre de colaborador
                {
                    char temp = papers[i];
                    papers[i] = '\0';
                    it = erdos_numbers.find(papers+index);
                    if(it == erdos_numbers.end()) 
                    {
                        erdos_numbers[papers+index] = ++erdos_numbers_size;
                        temporal[temp_index++] = erdos_numbers_size;
                    }
                    else 
                        temporal[temp_index++] = it->second;

                    papers[i] = temp;
                    index = i+2;
                    if(papers[i] == ':')
                        break;
                }
            }
            for(i = 0; i < temp_index; i++) 
            {
                for(j = i+1; j < temp_index; j++) 
                {
                    g[temporal[i]].push_back(temporal[j]);
                    g[temporal[j]].push_back(temporal[i]);
                }
            }
        }

        int used[5005] = {}, dp[5005] = {}, x;
        used[0] = 1, dp[0] = 0;
        std::queue<int> queue;
        queue.push(0);
        while(!queue.empty()) 
        {
            x = queue.front(), queue.pop();
            for(std::vector<short>::iterator it = g[x].begin(); it != g[x].end(); it++) 
            {
                if(used[*it] == 0) 
                {
                    dp[*it] = dp[x]+1;
                    used[*it] = 1;
                    queue.push(*it);
                }
            }
        }


        std::cout<< "Scenario "<< ++cases<< "\n";
        while(m--) 
        {
            gets(papers);
            it = erdos_numbers.find(papers);
            std::cout<< papers<< " ";
            if(it == erdos_numbers.end())
                std::cout<< "infinity\n";
            else if(!used[it->second])
                std::cout<< "infinity\n";
            else  
                std::cout<< dp[it->second]<< "\n";
        }
    }
    return 0;
}