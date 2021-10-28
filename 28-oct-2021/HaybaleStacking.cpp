#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    int N, K;
    int A, B;
    scanf("%d %d", &N, &K);

    std::vector<int> diferencias(N);

    for (int t = 0; t < K; t++)
    {
        scanf("%d %d", &A, &B);
        diferencias[A - 1] ++;
        if (B < N)
            diferencias[B] --;
    }

    // Recrear arreglo
    std::vector<int> arreglo(N);
    int actual = 0;

    for (int t = 0; t < N; t++)
    {
        arreglo[t] = actual;
        actual += diferencias[t];
    }

    std::sort(arreglo.begin(), arreglo.end());

    printf("%d\n", arreglo[N/2]);

    return 0;
}