#include <iostream>
#include <vector>

int main()
{
    int pos, a, b, c;
    std::vector<int> v;
    
    while (std::cin >> pos >> a >> b >> c)
    {
        if ((pos ==0 && a == 0) && (b == 0 && c == 0) )
            break;
        int n = 1080; // las 3 vueltas que da el candado

        n += 9* ((pos - a +40) % 40);
        n += 9* ((b - a +40) % 40);
        n += 9* ((b - c +40) % 40);
        
        v.push_back(n);
    }

    for (int k = 0; k < v.size(); k++)
    {
        std::cout << v[k] << "\n";
    }
    
    return 0;
}