/*
 * 15. 三数之和（排序 + 对撞双指针）
 * 核心思路：固定第一个数，再在其右侧找两个和为 -nums[i] 的数；排序便于跳过重复解。
 * 时间：O(n²)；空间：除答案外 O(log n)（排序栈空间）。
 * 易错点：三处都必须去重；固定值大于 0 可提前结束。
 */
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    vector<vector<int>> threeSum(vector<int>& nums)
    {
        // 排序既方便对撞指针，也方便连续跳过重复答案。
        sort(nums.begin(), nums.end());
        vector<vector<int>> answer;
        for (int i = 0; i + 2 < (int)nums.size(); ++i)
        {
            // 后面的数都更大，固定值大于 0 时不可能凑出 0。
            if (nums[i] > 0) break;
            if (i > 0 && nums[i] == nums[i - 1]) continue; // 去重固定值
            int left = i + 1, right = (int)nums.size() - 1;
            while (left < right)
            {
                // 先用 64 位整数相加，避免极端整数相加发生溢出。
                long long sum = 1LL * nums[i] + nums[left] + nums[right];
                if (sum == 0)
                {
                    answer.push_back({nums[i], nums[left], nums[right]});
                    // 记录旧值，之后跳过所有值相同的 left/right，避免重复答案。
                    int old_left = nums[left], old_right = nums[right];
                    while (left < right && nums[left] == old_left) ++left;
                    while (left < right && nums[right] == old_right) --right;
                }
                else if (sum < 0)
                {
                    // 中间还偏小，必须让较小指针右移。
                    ++left;
                }
                else
                {
                    // 中间偏大，让较大指针左移。
                    --right;
                }
            }
        }
        return answer;
    }
};
