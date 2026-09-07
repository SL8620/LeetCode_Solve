/*
 * 72. 编辑距离（二维字符串 DP）
 * 核心思路：dp[i][j] 表示把 word1 前缀转成 word2 前缀的最少操作数。
 *       相同时沿用 diag；否则取删除/插入/替换后最优 +1。
 * 时间：O(mn)；空间：O(min(m,n))。
 */
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int minDistance(string word1, string word2)
    {
        int m = word1.size(), n = word2.size();
        if (m < n)
        {
            return minDistance(word2, word1); // 交换后让 word2 更短，减少列数
        }
        vector<int> previous(n + 1), current(n + 1);
        for (int j = 0; j <= n; ++j) previous[j] = j;
        for (int i = 1; i <= m; ++i)
        {
            current[0] = i;
            for (int j = 1; j <= n; ++j)
            {
                if (word1[i - 1] == word2[j - 1])
                {
                    current[j] = previous[j - 1];
                }
                else
                {
                    // 分别对应删除、插入和替换三种操作。
                    current[j] = 1 + min({previous[j], current[j - 1], previous[j - 1]});
                }
            }
            previous.swap(current);
        }
        return previous[n];
    }
};
