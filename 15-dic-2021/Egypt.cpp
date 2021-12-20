#include <bits/stdc++.h>

void is_right_triangle(int a, int b, int c)
{
    std::vector<int> sides;
    sides.push_back(a);
    sides.push_back(b);
    sides.push_back(c);
    std::sort(sides.begin(), sides.end());

    
    if (sides[0]*sides[0] + sides[1]*sides[1] == sides[2]*sides[2])
        std::cout<< "right" << std::endl;
    else
        std::cout<< "wrong" << std::endl;
}

int main()
{
    int a, b, c;

    while(std::cin>>a >>b >> c)
    {
        if (a == 0 && b == 0 && c == 0)
            break;
        is_right_triangle(a, b, c);
    }
    return 0;
}