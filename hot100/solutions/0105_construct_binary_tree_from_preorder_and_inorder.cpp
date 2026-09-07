/*
 * 105. 从前序与中序遍历序列构造二叉树（递归 + 游标）
 * 核心思路：前序第一个值是根；中序中根左侧是左子树，右侧是右子树。
 * 时间：O(n²) 最坏；空间：O(h)。用哈希索引可优化为 O(n)。
 */
#ifdef LOCAL_LEETCODE_TYPES
#include "tree_node.h"
#endif
#include <vector>
#include <unordered_map>
using namespace std;

class Solution
{
private:
    int preorder_index = 0;
    unordered_map<int,int> inorder_position;

    TreeNode* build(vector<int>& preorder, int left, int right)
    {
        if (left > right)
        {
            return nullptr;
        }
        // 前序游标每次消耗的值，就是当前区间尚未创建的根。
        int root_value = preorder[preorder_index++];
        int root_index = inorder_position[root_value];
        TreeNode* root = new TreeNode(root_value);
        root->left = build(preorder, left, root_index - 1);
        root->right = build(preorder, root_index + 1, right);
        return root;
    }

public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder)
    {
        // 中序位置只建立一次索引，避免每次递归线性扫描。
        for (int i = 0; i < (int)inorder.size(); ++i)
        {
            inorder_position[inorder[i]] = i;
        }
        return build(preorder, 0, (int)inorder.size() - 1);
    }
};
