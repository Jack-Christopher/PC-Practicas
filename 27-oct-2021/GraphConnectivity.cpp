
#include <iostream>
#include <stdio.h>
#include <vector>
#include <string.h>

std::vector <int> grafo[30];
bool visitados[30];

void depth_first_search(int u)
{
	visitados[u] = true;
	for(int v=0; v < grafo[u].size(); v++)
		if(visitados[grafo[u][v]] == false)
			depth_first_search(grafo[u][v]);
}

void visitar(int V)
{
	int num = 0;

	for(int i=1; i <= V; i++){
		if(visitados[i] == false){
			num++;
			depth_first_search(i);
		}
	}

	printf("%d\n", num);
}

int main()
{
	int test_cases, V;
	int u, v;
	char c, a, b;
	char input[10];
		
	scanf("%d", &test_cases);	
	while(test_cases--)
	{
		memset(visitados, false, sizeof(visitados));
		std::cin >> c;
		V = c - 'A' + 1;
		while(getchar() != '\n');
		while(gets(input) && sscanf(input, "%c%c", &a, &b) == 2)
		{
			u = a - 'A'+1;
			v = b - 'A'+1;
			grafo[u].push_back(v);
			grafo[v].push_back(u);
		}
		visitar(V);
		
		if(test_cases != 0)
			printf("\n");
		// reseteando el grafo
		for(int i=0; i<30; i++)
			grafo[i].clear();
	}

	return 0;
}