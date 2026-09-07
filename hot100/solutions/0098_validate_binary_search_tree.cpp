/*
 * 98. 验证二叉搜索树（带上下界的递归）
 * 核心思路：每个节点必须位于其祖先允许的开区间 (min,max) 内。
 * 时间：O(n)；空间：O(h)。
 * 易错点：只比较父节点是不够的；边界用 long long 表示 (±∞)，且左右边界均为开区间。
 */
#ifdef LOCAL_LEETCODE_TYPES
#include "tree_node.h"
#endif
#include <climits>

class Solution
{
public:
    bool isValidBST(TreeNode* root)
    {
        // 初始上下界使用 long long，容纳 int 的极值。
        return isValid(root, LONG_LONG_MIN, LONG_LONG_MAX);
    }

private:
    bool isValid(TreeNode* node, long long lower, long long upper)
    {
        if (!node)
        {
            return true;
        }
        long long value = node->val;
        // 左子树上界收紧为当前值，右子树下界收紧为当前值。
        return value > lower && value < upper &&
               isValid(node->left, lower, value) &&
               isValid(node->right, value, upper);
    }
};
