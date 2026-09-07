/*
 * 53. 最大子数组和（Kadane / 动态规划）
 * 核心思路：dp[i] 表示“必须以 i 结尾”的最大和；前缀为负时不如重新开始。
 * 时间：O(n)；空间：O(1)。
 * 易错点：至少选一个元素，所以不能把空子数组的和 0 作为答案初始化。
 */
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

class Solution
{
public:
    int maxSubArray(vector<int>& nums)
    {
        // ending 必须以当前位置结尾，answer 保存全局最大值。
        int ending = nums[0];
        int answer = nums[0];
        for (int i = 1; i < (int)nums.size(); ++i)
        {
            // 前缀和小于零时，不如从当前位置重新开始。
            ending = max(nums[i], ending + nums[i]);
            answer = max(answer, ending);
        }
        return answer;
    }
};
