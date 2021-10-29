#include <iostream>
#include <vector>
#include <map>

std::string rareSort(std::vector <std::string> entradas)
{
    std::map <char, std::vector <char> > grafo;
	std::map <char, int> aristas;
    std::string resultado;
    int min;
	
    for (int i = 0; i < entradas.size() - 1; ++i)
    {
        // se evalua solo hasta el indice de la menor cadena
        min = std::min(entradas[i].size(), entradas[i + 1].size());
		for (int j = 0; j < min; ++j)
        {
            // donde aparece la diferencia es donde se muestra el orden entre las letras
			if (entradas[i][j] != entradas[i + 1][j])
            {
                // si aun no esta en el grafo
				if (aristas.find(entradas[i][j]) == aristas.end())
					aristas[entradas[i][j]] = 0;

				grafo[entradas[i][j]].push_back(entradas[i + 1][j]);
				++aristas[entradas[i + 1][j]];
				break;
			}
        }
    }
	
	while (true) 
    {
		char start = '.';
		for (auto & a : aristas)
        {
            // no depende de otros nodos
			if (a.second == 0)
            {
				a.second = -1;
				start = a.first;
				break;
			}
        }

		if (start == '.')
			break;

		for (auto a : grafo[start])
			aristas[a]--;

		resultado = resultado + start;
	}
    return resultado;
}


int main(void)
{
	std::vector <std::string> entradas;
    std::string line;

	while (std::cin>> line)
    {
		if (line == "#")
			break;
		entradas.push_back(line);
	}

    std::string resultado = rareSort(entradas);
	std::cout << resultado << std::endl;

	return 0;
}
