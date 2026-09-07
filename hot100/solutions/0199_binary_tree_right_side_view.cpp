/*
 * 199. 二叉树的右视图（BFS）
 * 核心思路：每一层 BFS 的最后一个节点就是从右边看到的节点。
 * 时间：O(n)；空间：O(n)。
 */
#ifdef LOCAL_LEETCODE_TYPES
#include "tree_node.h"
#endif
#include <vector>
#include <queue>
using namespace std;

class Solution
{
public:
    vector<int> rightSideView(TreeNode* root)
    {
        if (!root)
        {
            return {};
        }
        vector<int> answer;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty())
        {
            int size = q.size();
            // 每轮 size 是一层的节点数，因此 i==size-1 就是该层最右节点。
            for (int i = 0; i < size; ++i)
            {
                TreeNode* node = q.front(); q.pop();
                if (i == size - 1)
                {
                    answer.push_back(node->val); // 本层最后一个节点最靠右
                }
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
        }
        return answer;
    }
};
