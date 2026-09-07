/*
 * 114. 二叉树展开为链表（后序栈构造右链）
 * 核心思路：逆前序栈遍历（根→右→左），依次把节点接到结果尾部，得到先序顺序。
 * 时间：O(n)；空间：O(n)。
 * 易错点：每轮先清空左子树和 next，否则会形成环。
 */
#ifdef LOCAL_LEETCODE_TYPES
#include "tree_node.h"
#endif
#include <stack>
using namespace std;

class Solution
{
public:
    void flatten(TreeNode* root)
    {
        if (!root)
        {
            return;
        }
        stack<TreeNode*> st;
        st.push(root);
        TreeNode* prev = nullptr;
        while (!st.empty())
        {
            TreeNode* node = st.top(); st.pop();
            // 右子树先入栈，左子树后入栈，才能得到根-左-右的访问顺序。
            if (node->right) st.push(node->right);
            if (node->left) st.push(node->left);
            if (prev) prev->right = node;
            node->left = nullptr;
            prev = node;
        }
    }
};
