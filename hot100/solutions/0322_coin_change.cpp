/*
 * 322. 零钱兑换（完全背包 / 最少硬币数）
 * 核心思路：dp[a] = min(dp[a-coin]+1)，对每种 coin 使用到任意次数。
 * 时间：O(amount*n)；空间：O(amount)。
 * 易错点：用 INT_MAX-1 作为不可达哨兵，避免加 1 溢出。
 */
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

class Solution
{
public:
    int coinChange(vector<int>& coins, int amount)
    {
        vector<int> dp(amount + 1, INT_MAX - 1);
        dp[0] = 0;
        for (int coin : coins)
        {
            for (int value = coin; value <= amount; ++value)
            {
                // 完全背包正向更新，允许当前硬币被重复使用。
                dp[value] = min(dp[value], dp[value - coin] + 1);
            }
        }
        return dp[amount] == INT_MAX - 1 ? -1 : dp[amount];
    }
};
