#include <bits/stdc++.h>

int minPathSum(std::vector<std::vector<int>>& grid) 
{
    for (int i = 0; i < grid.size(); i++)
    {
        for (int j = 0; j < grid[0].size(); j++)
        {
            if (i == 0 && j == 0)
                continue;
            else if (i == 0)
                grid[i][j] += grid[i][j - 1];
            else if (j == 0)
                grid[i][j] += grid[i - 1][j];
            else
                grid[i][j] += std::min(grid[i - 1][j], grid[i][j - 1]);
        }
    }
    return grid[grid.size() - 1][grid[0].size() - 1];
}

int main()
{
    std::vector<std::vector<int>> grid = {{1,3,1},{1,5,1},{4,2,1}};
    std::cout<< minPathSum(grid);

    return 0;
}