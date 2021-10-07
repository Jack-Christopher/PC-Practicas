#include <iostream>
#include <set>

int main()
{
    int n;
    while (std::cin >> n)
    {
        if (n == 0)
            break;

        // BST bst;
        std::multiset<int> ms;
        std::multiset<int>::iterator it;

        int quantity;
        long long int suma = 0;
        for (int p = 0; p < n; p++)
        {
            std::cin >> quantity;
            int value;
            for (int k = 0; k < quantity; k++)
            {
                std::cin >> value;
                ms.insert(value);
            }
            // std::cout<< "inserted\n";
            int min = *ms.begin();
            ms.erase(ms.begin());
            // std::cout<< "max: " << max << "\n";
            it = ms.end();
            it--;
            int max = *it;
            ms.erase(it);
            // std::cout<< "min: " << min << "\n";
            // std::cout<<"abs:" <<abs(max - min)<< "\t";
            suma += abs(max - min);
        }
        std::cout << suma << std::endl;
    }

    return 0;
}




