/*
 * 70. 爬楼梯（滚动 DP / 斐波那契）
 * 核心思路：到第 i 阶的方案数 = 到第 i-1 阶方案 + 到第 i-2 阶方案。
 * 时间：O(n)；空间：O(1)。
 */
#include <vector>
using namespace std;

class Solution
{
public:
    int climbStairs(int n)
    {
        int previous = 0, current = 1; // current 相当于 dp[0]
        for (int i = 0; i < n; ++i)
        {
            // 只保留最近两层状态，避免继续使用整个 dp 数组。
            int next = current + previous;
            previous = current;
            current = next;
        }
        return current;
    }
};
