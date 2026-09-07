/*
 * 33. 搜索旋转排序数组（二分）
 * 核心思路：每次必有一半有序；若 target 落在有序半边就缩小到那里，否则去另一边。
 * 时间：O(log n)；额外空间：O(1)。
 * 易错点：数组元素唯一，因此 target==nums[mid] 可立即返回。
 */
#include <vector>
using namespace std;

class Solution
{
public:
    int search(vector<int>& nums, int target)
    {
        int left = 0, right = (int)nums.size() - 1;
        while (left <= right)
        {
            int mid = left + (right - left) / 2;
            if (nums[mid] == target)
            {
                return mid;
            }
            if (nums[left] <= nums[mid])
            {
                // 左半段有序，先判断 target 是否落在这个有序区间内。
                if (nums[left] <= target && target < nums[mid])
                {
                    right = mid - 1;
                }
                else
                {
                    left = mid + 1;
                }
            }
            else
            {
                // 反之右半段有序，再判断 target 是否落在右半段。
                if (nums[mid] < target && target <= nums[right])
                {
                    left = mid + 1;
                }
                else
                {
                    right = mid - 1;
                }
            }
        }
        return -1;
    }
};
