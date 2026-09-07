/*
 * 34. 在排序数组中查找元素的第一个和最后一个位置（二分查找）
 * 核心思路：first = lower_bound(target)；若不存在或不等则返回 {-1,-1}；
 *       last = lower_bound(target+1)-1。
 * 时间：O(log n)；额外空间：O(1)。
 * 易错点：upper_bound 版本需保证比较值不溢出，使用 lower_bound 更稳。
 */
#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> searchRange(vector<int>& nums, int target)
    {
        int first = lower_bound(nums, target);
        if (first == (int)nums.size() || nums[first] != target)
        {
            return {-1, -1}; // target 完全不存在
        }
        // target+1 的插入位置前一个位置，就是 target 的最后出现位置。
        int last = lower_bound(nums, target + 1) - 1;
        return {first, last};
    }

private:
    int lower_bound(vector<int>& nums, int target)
    {
        int left = 0, right = (int)nums.size();
        while (left < right)
        {
            int mid = left + (right - left) / 2;
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
