/*
 * 75. 颜色分类（荷兰国旗 / 三指针）
 * 核心思路：low 之后是 0，unknown 之后是 2；遇到 0 放前面，遇到 2 放后面。
 * 时间：O(n)；额外空间：O(1)。
 * 易错点：从中间换到末尾时，未知区域缩小但指针不能额外前进。
 */
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    void sortColors(vector<int>& nums)
    {
        int low = 0, unknown = 0, high = (int)nums.size() - 1;
        while (unknown <= high)
        {
            if (nums[unknown] == 0)
            {
                swap(nums[low++], nums[unknown++]);
            }
            else if (nums[unknown] == 2)
            {
                // 从 high 换来的值尚未判断，unknown 暂时不能前进。
                swap(nums[unknown], nums[high--]);
            }
            else
            {
                ++unknown; // 已经是 1，位于正确区间
            }
        }
    }
};
