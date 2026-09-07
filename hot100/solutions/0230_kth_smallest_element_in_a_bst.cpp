/*
 * 230. 二叉搜索树中第 K 小的元素（中序遍历）
 * 核心思路：BST 的中序遍历天然得到从小到大的序列，找到第 k 个即可停止。
 * 时间：最坏 O(n)；空间：O(h)。
 * 易错点：使用计数器并在达到 k 后尽快结束递归。
 */
#ifdef LOCAL_LEETCODE_TYPES
#include "tree_node.h"
#endif

class Solution
{
private:
    int counter = 0, answer = 0;

    void inorder(TreeNode* node, int k)
    {
        if (!node || counter >= k)
        {
            return;
        }
        inorder(node->left, k);
        // 每访问一个节点就说明它比之前的所有节点都大。
        if (++counter == k)
        {
            answer = node->val;
            return;
        }
        inorder(node->right, k);
    }

public:
    int kthSmallest(TreeNode* root, int k)
    {
        inorder(root, k);
        return answer;
    }
};
