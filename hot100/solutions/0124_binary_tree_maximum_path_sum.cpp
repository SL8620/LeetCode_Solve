/*
 * 124. 二叉树中的最大路径和（后序贡献 DP）
 * 核心思路：单边返回“当前节点 + max(0, 左/右贡献)”；全局答案取“当前节点+左右非负贡献”。
 * 时间：O(n)；空间：O(h)。
 * 易错点：负贡献必须截断为 0；答案可只包含一个节点。
 */
#ifdef LOCAL_LEETCODE_TYPES
#include "tree_node.h"
#endif
#include <algorithm>
#include <climits>
using namespace std;

class Solution
{
private:
    int answer = INT_MIN;

    int gain(TreeNode* node)
    {
        if (!node)
        {
            return 0;
        }
        // 负贡献只会降低路径和，因此向上传递时截断为 0。
        int left = max(0, gain(node->left));
        int right = max(0, gain(node->right));
        // 全局路径可以在当前节点分叉，但返回值只能选择一条边继续向上。
        answer = max(answer, node->val + left + right);
        return node->val + max(left, right);
    }

public:
    int maxPathSum(TreeNode* root)
    {
        gain(root);
        return answer;
    }
};
