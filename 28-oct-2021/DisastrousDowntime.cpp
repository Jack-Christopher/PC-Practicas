#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <map>


int main()
{
    int n, k;
    scanf("%d %d", &n, &k);

    std::map<int, int> m;

    for (int p = 0; p < n; p++)
    {
        int t;
        scanf("%d", &t);
        if (m.find(t) == m.end())
            m[t] = 1;
        else
            m[t]++;
        if (m.find(t+1000) == m.end())
            m[t+1000] = -1;
        else
            m[t+1000]--;
    }

    std::vector<int> arreglo(2*n);
    
    //iterate over a map
    int t = 0, actual = 0;
    for (auto it = m.begin(); it != m.end(); it++)
    {
        actual += it->second;
        arreglo[t++] = actual;
    }

    int ans = *std::max_element(arreglo.begin(), arreglo.end());
    if (ans%k == 0)
        printf("%d\n", ans/k);
    else
        printf("%d\n", ans/k+1);

    return 0;
}