#include <iostream>
#include <vector>

void apply_hartals( std::vector<bool> &dias, int h_i)
{
    for (int k = h_i-1; k < dias.size(); k += h_i)
    {
        if (k%7 != 5 && k%7 != 6)
            dias[k] = true;
    }
}


int main()
{
    int T;
    std::cin >> T;
    
    while (T--)
    {
        int N, P;
        std::cin >> N >> P;
        std::vector<bool> dias(N, false);

        int h_i;
        while (P--)
        {
            std::cin >> h_i;
            // std::cout<< "ok";
            apply_hartals(dias, h_i);
        }
        int total = 0;
        for (int i = 0; i < dias.size(); i++)
        {
            if (dias[i])
            {
                // std::cout << i+1 << " ";
                total++;
            }
        }
        std::cout << /*"total: "<<*/total << std::endl;

    }


    return 0;
}