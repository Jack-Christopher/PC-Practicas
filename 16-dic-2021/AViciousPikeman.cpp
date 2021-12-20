#include <bits/stdc++.h>

int comp(const void *p, const void *q) 
{
    int *a = (int *) p;
    int *b = (int *) q;
    return *a - *b;
}

int main() 
{
    int N, T;
    int A, B, C;
    long long int t_[10000];

    std::cin >> N >> T >> A >> B >> C >> t_[0];

    for (int i = 1; i < N; i++)
        t_[i] = (A * t_[i-1] + B) % C + 1;

    // std::sort(t_, t_ + N, [](const long long int &a, const long long int &b){return a-b;});
    std::qsort(t_, N, sizeof(long long int), comp);

    long long int penalty, solucionados, temp;
    penalty = 0;
    solucionados = 0;
    temp = 0;

    for (int i = 0; i < N; i++) 
    {
        if (temp + t_[i] <= T) 
        {
            penalty = (penalty + t_[i] + temp) % 1000000007;
            temp += t_[i];
            solucionados++;
        }
        else
            break;
    }

    std::cout << solucionados << " " << penalty << std::endl;
    return 0;
}