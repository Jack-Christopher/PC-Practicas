#include <bits/stdc++.h>

bool es_multiplo(std::string s) 
{
    int suma_par = 0;
    int suma_impar = 0;
    for (int i = 0; i < s.size(); i++) 
    {
        if (i % 2 == 0) 
        {
            suma_impar += s[i] - '0';
        }
        else 
        {
            suma_par += s[i] - '0';
        }
    }
    if ((suma_par-suma_impar)%11 == 0) 
        return true;
    return false;

}

int main()
{
    std::string s;
    while(true)
    {
        std::cin >> s;
        if (s == "0")
            break;
        if (es_multiplo(s))
            std::cout << s << " is a multiple of 11.\n";
        else
            std::cout << s << " is not a multiple of 11.\n";
    }

    return 0;
}