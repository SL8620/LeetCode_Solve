/*
 * 236. 二叉树的最近公共祖先（后序 DFS）
 * 核心思路：若左右递归各找到一个，则当前节点就是 LCA；只有一侧返回时继续向上传。
 * 时间：O(n)；空间：O(h)。
 * 易错点：p、q 必定存在，因此找到当前节点即返回，无需求别的枝。
 */
#ifdef LOCAL_LEETCODE_TYPES
#include "tree_node.h"
#endif

class Solution
{
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q)
    {
        if (!root || root == p || root == q)
        {
            return root;
        }
        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);
        // 左右子树各找到一个目标，说明当前节点是分叉点。
        if (left && right)
        {
            return root;
        }
        return left ? left : right;
    }
};
