/*
 * 283. 移动零（双指针）
 * 核心思路：fast 扫描非零值，slow 指向下一个非零值应写入的位置；最后补零。
 * 时间：O(n)；额外空间：O(1)。
 * 易错点：不能覆盖 slow 之前尚未判断的非零值，因此本题应“左移到零的位置”。
 */
#include <vector>
using namespace std;

class Solution
{
public:
    void moveZeroes(vector<int>& nums)
    {
        // slow 指向下一个非零值应写入的位置。
        int slow = 0;
        for (int fast = 0; fast < (int)nums.size(); ++fast)
        {
            if (nums[fast] != 0)
            {
                nums[slow++] = nums[fast];
            }
        }
        // [0, slow) 已经按原顺序存放所有非零值，剩余位置全部补零。
        while (slow < (int)nums.size())
        {
            nums[slow++] = 0;
        }
    }
};
