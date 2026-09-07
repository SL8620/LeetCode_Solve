/*
 * 416. 分割等和子集（0-1 背包）
 * 核心思路：先判断总和为偶数；再求是否存在若干数之和为 total/2。
 * 时间：O(n*target)；空间：O(target)（一维滚动数组）。
 * 易错点：0-1 背包容量必须倒序遍历，避免同一元素重复使用。
 */
#include <vector>
using namespace std;

class Solution
{
public:
    bool canPartition(vector<int>& nums)
    {
        int total = 0;
        for (int value : nums) total += value;
        if (total % 2) return false;
        int target = total / 2;
        vector<bool> dp(target + 1, false);
        dp[0] = true;
        for (int value : nums)
        {
            // 0-1 背包容量倒序更新，保证同一元素只使用一次。
            for (int sum = target; sum >= value; --sum)
            {
                dp[sum] = dp[sum] || dp[sum - value];
            }
        }
        return dp[target];
    }
};
