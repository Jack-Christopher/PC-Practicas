#include <bits/stdc++.h>

struct aspersor
{
    double left;
    double right;
    int position;
    int radius;
    aspersor(double l, double r, int p, int rd)
    {
        left = l;
        right = r;
        position = p;
        radius = rd;
    }
};



int main()
{
    int n;
    double l, w, x, r, temp;
    std::vector<aspersor> aspersores;

    while (std::cin>> n>> l>> w)
    {
        for (int k = 0; k < n; k++)
        {
            
            std::cin>> x>> r;
            temp = sqrt(r*r-w*w/4.0);
            if (temp > 0)
                aspersores.push_back(aspersor(x-temp, x+temp, x, r));
        }
        std::sort(aspersores.begin(), aspersores.end(), [](const aspersor &a, const aspersor &b){return a.left < b.left;});

        double actual = 0, mejor = 0;
        int total = 0;

        for( int i = 0; i < n; i++ ) 
        {
            if( aspersores[i].left <= actual ) 
            {
                if( aspersores[i].right > mejor )
                    mejor = aspersores[i].right;
            }
            else 
            {
                if( mejor == actual || mejor >= l )
                    break;
                i--;
                actual = mejor;
                total++;
            }
        }
        if( mejor != actual )
            total++;

        if( mejor >= l ) 
            std::cout << total << '\n';
        else 
            std::cout << -1 << '\n';
        aspersores.clear();
    }

    return 0;
}