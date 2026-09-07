/*
 * 35. 搜索插入位置（lower_bound）
 * 核心思路：二分找到第一个不小于 target 的位置，它就是插入位置。
 * 时间：O(log n)；额外空间：O(1)。
 */
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int searchInsert(vector<int>& nums, int target)
    {
        int left = 0, right = (int)nums.size();
        while (left < right)
        {
            int mid = left + (right - left) / 2;
            // 保持答案在左闭右开区间 [left,right] 中。
            if (nums[mid] < target)
            {
                left = mid + 1;
            }
            else
            {
                right = mid;
            }
        }
        return left;
    }
};
