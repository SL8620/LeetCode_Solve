/*
 * 104. 二叉树的最大深度（递归）
 * 核心思路：以根为起点，树深 = 左右子树较大深度 + 1；空树深度为 0。
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
    int maxDepth(TreeNode* root)
    {
        if (!root)
        {
            return 0; // 空树没有节点，深度为 0
        }
        // 当前根节点贡献一层，子树深度取左右较大值。
        return 1 + max(maxDepth(root->left), maxDepth(root->right));
    }
};
