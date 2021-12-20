#include <bits/stdc++.h>

using namespace std;

int superficie(int x_1, int y_1, int x_2, int y_2, int x_3, int y_3)
{
    return ( x_1*y_2 + x_2*y_3 + x_3*y_1 - y_1*x_2 - y_2*x_3 - y_3*x_1 );
}

bool interseccion(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4)
{
    int s1, s2, s3, s4;

    s1 = superficie(x1,y1,x3,y3,x2,y2);
    s2 = superficie(x1,y1,x4,y4,x2,y2);
    s3 = superficie(x3,y3,x1,y1,x4,y4);
    s4 = superficie(x3,y3,x2,y2,x4,y4);
    
    if(s1*s2<0 && s3*s4<0) 
        return true;
    if(s1==0 && (x3-x1)*(x3-x2)<=0 && (y3-y1)*(y3-y2)<=0) 
        return true;
    if(s2==0 && (x4-x1)*(x4-x2)<=0 && (y4-y1)*(y4-y2)<=0) 
        return true;
    if(s3==0 && (x1-x3)*(x1-x4)<=0 && (y1-y3)*(y1-y4)<=0) 
        return true;
    if(s4==0 && (x2-x3)*(x2-x4)<=0 && (y2-y3)*(y2-y4)<=0) 
        return true;
    
    return false;
}

int main()
{
    int n;
    int x_start, y_start, x_end, y_end, x_left, y_top, x_right, y_bottom;
    bool intersecta;

    std::cin >> n;
        
    for(int k = 1; k <= n; k++)
    {
        intersecta = false;

        // lectura de puntos
        std::cin>> x_start >> y_start >> x_end >> y_end >> x_left >> y_top >> x_right >> y_bottom;
        
        if(x_left>x_right) 
            swap(x_left, x_right);
        if(y_bottom>y_top) 
            swap(y_bottom, y_top);
        
        if(interseccion(x_start, y_start, x_end, y_end, x_left, y_top, x_right, y_top)) 
            intersecta=true;
        else if(interseccion(x_start, y_start, x_end, y_end, x_left, y_bottom, x_right, y_bottom)) 
            intersecta=true;
        else if(interseccion(x_start, y_start, x_end, y_end, x_left, y_top, x_left, y_bottom)) 
            intersecta=true;
        else if(interseccion(x_start, y_start, x_end, y_end, x_right, y_top, x_left, y_bottom)) 
            intersecta=true;
        else if(    ((x_start>=x_left) && (x_start<=x_right))   &&  ( (x_end>=x_left) && (x_end<=x_right)) && 
                    ((y_start>=y_bottom) && (y_start<=y_top)) && ((y_end>=y_bottom) && (y_end<=y_top))      ) 
            intersecta =true;
        
        if(intersecta) 
            std::cout << "T" << std::endl;
        else 
            std::cout << "F" << std::endl;
    }
    
    return 0;
}