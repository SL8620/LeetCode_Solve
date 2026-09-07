/*
 * 41. 缺失的第一个正数（原地哈希）
 * 核心思路：值 x 应放在下标 x-1；最后扫描位置不匹配处即可。
 * 时间：O(n)；空间：O(1)。
 * 易错点：循环结束条件必须使用 nums[value-1] != value，不能只比较 nums[i] != i+1。
 */
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int firstMissingPositive(vector<int>& nums)
    {
        int n = nums.size();
        for (int i = 0; i < n; ++i)
        {
            // 只考虑 [1,n] 内的正数，缺失答案一定在这一范围内。
            while (nums[i] >= 1 && nums[i] <= n && nums[nums[i] - 1] != nums[i])
            {
                int target = nums[i] - 1;
                // 值 x 应当位于下标 x-1。
                swap(nums[i], nums[target]);
            }
        }
        for (int i = 0; i < n; ++i)
        {
            if (nums[i] != i + 1)
            {
                return i + 1;
            }
        }
        return n + 1;
    }
};
