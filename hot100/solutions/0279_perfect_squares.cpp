/*
 * 279. 完全平方数（完全背包 DP）
 * 核心思路：dp[i] 表示组成 i 所需最少平方数；外层遍历平方数，内层更新 i。
 * 时间：O(n√n)；空间：O(n)。
 * 易错点：平方数循环在数量外、金额在内，对应“物品任意使用”的完全背包。
 */
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

class Solution
{
public:
    int numSquares(int n)
    {
        vector<int> dp(n + 1, INT_MAX - 1);
        dp[0] = 0;
        // 外层枚举平方数，内层从小到大，表示每种平方数可使用任意次。
        for (int square = 1; square * square <= n; ++square)
        {
            int value = square * square;
            for (int amount = value; amount <= n; ++amount)
            {
                dp[amount] = min(dp[amount], dp[amount - value] + 1);
            }
        }
        return dp[n];
    }
};
