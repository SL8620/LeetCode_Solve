/*
 * 108. 将有序数组转换为二叉搜索树（分治建树）
 * 核心思路：每次选择区间中点作为根，左半区建左子树、右半区建右子树。
 * 时间：O(n)；空间：O(log n)。
 * 易错点：必须用“中点”才能保持高度平衡，而不是简单地顺序插入。
 */
#ifdef LOCAL_LEETCODE_TYPES
#include "tree_node.h"
#endif
#include <vector>
using namespace std;

class Solution
{
public:
    TreeNode* sortedArrayToBST(vector<int>& nums)
    {
        return build(nums, 0, (int)nums.size() - 1);
    }

private:
    TreeNode* build(vector<int>& nums, int left, int right)
    {
        if (left > right)
        {
            return nullptr;
        }
        // 选中点做根，左右子树规模最多相差 1，树才会平衡。
        int mid = left + (right - left) / 2;
        return new TreeNode(nums[mid], build(nums, left, mid - 1),
                                   build(nums, mid + 1, right));
    }
};
