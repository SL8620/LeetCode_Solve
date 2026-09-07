/*
 * 543. 二叉树的直径（后序 DFS）
 * 核心思路：递归返回经过当前节点向上的最长边数；用左右返回值之和更新全局答案。
 * 时间：O(n)；空间：O(h)。
 * 易错点：直径不一定经过根节点，边数也比节点数少 1。
 */
#ifdef LOCAL_LEETCODE_TYPES
#include "tree_node.h"
#endif
#include <algorithm>
using namespace std;

class Solution
{
private:
    int best = 0;

    int height(TreeNode* node)
    {
        if (!node)
        {
            return 0;
        }
        int left = height(node->left);
        int right = height(node->right);
        // 经过当前节点的路径包含左右两条向上的最长边。
        best = max(best, left + right);
        return 1 + max(left, right);
    }

public:
    int diameterOfBinaryTree(TreeNode* root)
    {
        height(root);
        return best;
    }
};
