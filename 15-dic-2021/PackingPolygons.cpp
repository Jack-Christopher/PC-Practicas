#include <bits/stdc++.h>

typedef std::complex<double> Point;
const double eps = 1e-6;

double Radius;

struct Circle
{
    Point c;
    double r;
    Circle(Point c, double r) : c(c), r(r) {}
};

int N;
Point allPoints[210];

//Determina el punto de intersección entre los dos si existe
void interseccion(const Circle &a, const Circle &b, std::vector<Point> & inter)
{
    double d2 = std::norm(b.c-a.c), rS = a.r + b.r, rD = a.r - b.r;
    if (d2 > rS * rS || d2 < rD*rD) 
        return;

    double ca = 0.5*(1 + rS * rD / d2);
    Point z = Point(ca, sqrt((a.r*a.r/d2)-ca*ca));
    inter.push_back(a.c + (b.c-a.c)*z);
    if (fabs(z.imag())>eps)
        inter.push_back(a.c + (b.c-a.c)*std::conj(z));
}

int getNumEnCirculo(const Circle &c)
{
    int count = 0;
    for (int i = 0; i < N; ++i)
        if (std::norm(allPoints[i]-c.c) <= c.r*c.r)
            ++count;

    return count;
}

int GetNumContained(int p1, int p2)
{
    std::vector<Point> inter;
    interseccion(Circle(allPoints[p1], Radius), Circle(allPoints[p2], Radius), inter);

    int best = 0;
    for (int i = 0; i < inter.size(); ++i)
    {
        best = std::max(best, getNumEnCirculo(Circle(inter[i], Radius)));
    }

    return best;
}

int main()
{
    while (std::cin >> N)
    {
        if (N == 0)
            break;
        for (int i = 0; i < N; ++i)
        {
            double x, y;
            std::cin >> x >> y;
            allPoints[i] = Point(x, y);
        }
        std::cin >> Radius;
        int best = 1;
        for (int i = 0; i < N; ++i)
            for (int j = i + 1; j < N; ++j)
                best = std::max(best, GetNumContained(i, j));
        
        if (best == N)
            std::cout << "The polygon can be packed in the circle.\n";
        else
            std::cout << "There is no way of packing that polygon.\n";
    }
}