/*
 * 31. 下一个排列（从右向左找升降序）
 * 核心思路：从右找第一个 nums[i] < nums[i+1]；再从右找刚好更大的数交换；
 *       最后反转 i+1 之后的降序段，得到最小的新后缀。
 * 时间：O(n)；额外空间：O(1)。
 * 易错点：找不到 pivot 时整个数组是最大排列，应反转恢复递增。
 */
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    void nextPermutation(vector<int>& nums)
    {
        int i = (int)nums.size() - 2;
        // 找到最右侧的上升点 i，它是最小的、需要增大的位置。
        while (i >= 0 && nums[i] >= nums[i + 1])
        {
            --i;
        }
        if (i >= 0)
        {
            int j = (int)nums.size() - 1;
            while (nums[j] <= nums[i])
            {
                --j;
            }
            swap(nums[i], nums[j]);
        }
        reverse(nums.begin() + i + 1, nums.end());
    }
};
