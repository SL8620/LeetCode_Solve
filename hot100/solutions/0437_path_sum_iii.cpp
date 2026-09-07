/*
 * 437. 路径总和 III（前缀和 DFS）
 * 核心思路：若当前前缀和为 p，路径和 target 等价于存在更早前缀 p-target。
 * 时间：O(n)；空间：O(n)。
 * 易错点：DFS 返回前撤销 count[prefix]，否则会把不同子树中的路径混在一起。
 */
#ifdef LOCAL_LEETCODE_TYPES
#include "tree_node.h"
#endif
#include <unordered_map>
using namespace std;

class Solution
{
private:
    long long prefix = 0;
    int answer = 0;
    unordered_map<long long,int> count;
    long long target;

    void dfs(TreeNode* node)
    {
        if (!node)
        {
            return;
        }
        prefix += node->val;
        // 存在更早前缀 p-target，就有一条以当前节点结尾的合法路径。
        if (count.count(prefix - target))
        {
            answer += count[prefix - target];
        }
        ++count[prefix];
        dfs(node->left);
        dfs(node->right);
        --count[prefix]; // 回溯时撤销当前前缀，避免跨子树误匹配
        prefix -= node->val;
    }

public:
    int pathSum(TreeNode* root, long long targetSum)
    {
        target = targetSum;
        count[0] = 1;
        dfs(root);
        return answer;
    }
};
