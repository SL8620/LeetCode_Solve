/*
 * 153. 寻找旋转排序数组中的最小值（二分）
 * 核心思路：比较 nums[mid] 与 nums[right]。若 mid 更大，最小值必在右侧。
 * 时间：O(log n)；额外空间：O(1)。
 * 易错点：无法区分时（相等）只能缩小一个边界；本题元素唯一所以用 < 即可。
 */
#include <vector>
using namespace std;

class Solution
{
public:
    int findMin(vector<int>& nums)
    {
        int left = 0, right = (int)nums.size() - 1;
        while (left < right)
        {
            int mid = left + (right - left) / 2;
            // 用 nums[right] 作为基准，总能判断最小值位于 mid 的哪一侧。
            if (nums[mid] > nums[right])
            {
                left = mid + 1; // 旋转点必在 mid 右侧
            }
            else
            {
                right = mid; // mid 自身也可能是最小值
            }
        }
        return nums[left];
    }
};
