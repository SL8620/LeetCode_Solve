/*
 * 198. 打家劫舍（线性 DP）
 * 核心思路：dp[i] = max(dp[i-1], dp[i-2]+nums[i])：不偷或偷。
 * 时间：O(n)；空间：O(1)。
 */
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int rob(vector<int>& nums)
    {
        int without_current = 0, with_current = 0;
        for (int value : nums)
        {
            // with_current 是“偷当前户”的最优值，without_current 是“不偷当前户”的最优值。
            int next = max(with_current, without_current + value);
            without_current = with_current;
            with_current = next;
        }
        return with_current;
    }
};
