#include <bits/stdc++.h>
using namespace std;

// 322. 零钱兑换
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) 
    {
        int len = coins.size();
        vector<int> dp(amount+1, INT_MAX-1);
        dp[0] = 0;
        for(int i=0; i<len; i++)
        {
            int coin = coins[i];
            for(int val=coin; val<=amount; val++)
            {
                dp[val] = min(dp[val], dp[val-coin]+1);
            }
        }
        return dp[amount] == INT_MAX-1 ? -1 : dp[amount];
    }
};

// 279. 完全平方数
class Solution {
public:
    int numSquares(int n) 
    {
        vector<int> dp(n+1, INT_MAX);
        
        dp[0] = 0;
        for(int i=1; i<=n; i++)
        {
            for(int j=1; j*j<=i; j++)
            {
                dp[i] = min(dp[i], dp[i-j*j]+1);
            }
        }
        return dp[n];
    }
};