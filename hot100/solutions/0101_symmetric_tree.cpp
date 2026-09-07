/*
 * 101. 对称二叉树（双递归）
 * 核心思路：判断左树的左/右子树，是否分别对称地匹配右树的右/左子树。
 * 时间：O(n)；空间：O(h)。
 */
#ifdef LOCAL_LEETCODE_TYPES
#include "tree_node.h"
#endif

class Solution
{
public:
    bool isSymmetric(TreeNode* root)
    {
        return isMirror(root, root);
    }

private:
    bool isMirror(TreeNode* left, TreeNode* right)
    {
        if (!left && !right)
        {
            return true;
        }
        // 只有一边为空时结构必然不对称。
        if (!left || !right)
        {
            return false;
        }
        // 对称位置是左的左和右的右、左的右和右的左。
        return left->val == right->val &&
               isMirror(left->left, right->right) &&
               isMirror(left->right, right->left);
    }
};
