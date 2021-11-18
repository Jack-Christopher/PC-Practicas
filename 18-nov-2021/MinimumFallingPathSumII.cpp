#include <bits/stdc++.h>

int minFallingPathSum(std::vector<std::vector<int>>& grid) 
{
    int n = grid.size();
    int m = grid[0].size();

    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            int min = INT_MAX;
            for (int k = 0; k < m; k++)
            {
                if (j != k)
                {
                    min = std::min(min, grid[i - 1][k]);
                }
            }
            grid[i][j] += min;
        }
    }

    auto result = std::min_element(grid[n - 1].begin(), grid[n - 1].end());
    return *result;
}

int main()
{
    std::vector<std::vector<int>> arr = {{1,2,3},{4,5,6},{7,8,9}};
    // std::vector<std::vector<int>> arr = {{7}};
    std::cout << minFallingPathSum(arr) ;
    return 0;
}