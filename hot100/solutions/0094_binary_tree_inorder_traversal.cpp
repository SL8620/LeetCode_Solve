/*
 * 94. 二叉树的中序遍历（栈）
 * 核心思路：不断把左链入栈；弹栈时访问，再转向右子树。
 * 时间：O(n)；空间：O(h)。
 * 易错点：push 节点和访问节点是两个阶段，不能 push 后立刻访问。
 */
#ifdef LOCAL_LEETCODE_TYPES
#include "tree_node.h"
#endif
#include <vector>
#include <stack>
using namespace std;

class Solution
{
public:
    vector<int> inorderTraversal(TreeNode* root)
    {
        vector<int> answer;
        stack<TreeNode*> nodes;
        TreeNode* current = root;
        while (current || !nodes.empty())
        {
            // 中序遍历必须先不断压入左链，访问时机由后续弹栈完成。
            while (current)
            {
                nodes.push(current);
                current = current->left;
            }
            current = nodes.top(); // 此时左子树已经处理完
            nodes.pop();
            answer.push_back(current->val);
            current = current->right;
        }
        return answer;
    }
};
