/*
 * 102. 二叉树的层序遍历（BFS）
 * 核心思路：每轮先取得当前队列长度，它就是这一层的节点数，再整层出队。
 * 时间：O(n)；空间：O(n)。
 * 易错点：必须在循环内保存 level_size，不能在层处理过程中改变它。
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
    vector<vector<int>> levelOrder(TreeNode* root)
    {
        if (!root)
        {
            return {};
        }
        queue<TreeNode*> q;
        q.push(root);
        vector<vector<int>> answer;
        while (!q.empty())
        {
            int level_size = q.size(); // 必须在处理本层前保存节点数
            vector<int> level;
            for (int i = 0; i < level_size; ++i)
            {
                // 只处理当前层节点，子节点留给下一轮 BFS。
                TreeNode* node = q.front();
                q.pop();
                level.push_back(node->val);
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
            answer.push_back(level);
        }
        return answer;
    }
};
