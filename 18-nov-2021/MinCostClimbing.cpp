#include <bits/stdc++.h>

int minCostClimbingStairs(std::vector<int>& cost) 
{
    int min;
    std::vector<int> dp(cost.size(), 0);
    dp[0] = cost[0];
    dp[1] = cost[1];
    for(int i = 2; i < cost.size(); i++)
    {
        min = std::min(dp[i-1], dp[i-2]) + cost[i];
        dp[i] = min;
    }
    return std::min(dp[cost.size()-1], dp[cost.size()-2]);
}


int main()
{
    // std::vector<int> cost = {10, 15, 20};
    std::vector<int> cost = {1, 100, 1, 1, 1, 100, 1, 1, 100, 1};
    std::cout << minCostClimbingStairs(cost) << std::endl;

    return 0;
}