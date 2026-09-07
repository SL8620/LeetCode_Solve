/*
 * 238. 除了自身以外数组的乘积（前后缀乘积）
 * 核心思路：answer[i] = i 左侧所有数的乘积 × i 右侧所有数的乘积。
 * 时间：O(n)；额外空间：O(1)，答案数组不算额外空间。
 * 易错点：先写入左前缀，再反向遍历时边读边写右前缀。
 */
#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> productExceptSelf(vector<int>& nums)
    {
        int n = nums.size();
        vector<int> answer(n, 1);
        for (int i = 1; i < n; ++i)
        {
            // 第一遍得到 i 左侧所有数的乘积。
            answer[i] = answer[i - 1] * nums[i - 1];
        }
        int suffix = 1;
        for (int i = n - 1; i >= 0; --i)
        {
            // 第二遍用右后缀补充答案，并维护后续右侧乘积。
            answer[i] *= suffix;
            suffix *= nums[i];
        }
        return answer;
    }
};
