/*
 * 239. 滑动窗口最大值（单调队列）
 * 核心思路：队列保存“还有机会成为最大值”的下标，队首始终是当前窗口最大值。
 * 时间：O(n)；空间：O(k)。
 * 易错点：队列保存下标才能判断队首是否已经离开窗口；新值进入时清理被它压制的旧值。
 */
#include <vector>
#include <deque>
using namespace std;

class Solution
{
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k)
    {
        // 保存下标，队列对应的值始终保持单调递减。
        deque<int> decreasing;
        vector<int> answer;
        for (int i = 0; i < (int)nums.size(); ++i)
        {
            // 新元素更大时，旧元素已经不可能成为后面的窗口最大值。
            while (!decreasing.empty() && nums[decreasing.back()] <= nums[i])
            {
                decreasing.pop_back();
            }
            decreasing.push_back(i);
            // 队首必须仍在窗口左边界 i-k+1 内。
            if (decreasing.front() <= i - k)
            {
                decreasing.pop_front();
            }
            // i 达到 k-1 后窗口才达到完整长度。
            if (i >= k - 1)
            {
                answer.push_back(nums[decreasing.front()]);
            }
        }
        return answer;
    }
};
