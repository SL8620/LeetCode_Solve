/*
 * 226. 翻转二叉树（递归/DFS）
 * 核心思路：对每个节点交换左右子节点，并递归处理两棵子树。
 * 时间：O(n)；空间：O(h)。
 */
#ifdef LOCAL_LEETCODE_TYPES
#include "tree_node.h"
#endif
#include <algorithm>
using namespace std;

class Solution
{
public:
    TreeNode* invertTree(TreeNode* root)
    {
        if (!root)
        {
            return nullptr;
        }
        // 先交换当前节点的左右孩子，再递归处理交换后的子树。
        swap(root->left, root->right);
        invertTree(root->left);
        invertTree(root->right);
        return root;
    }
};
