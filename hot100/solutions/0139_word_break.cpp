/*
 * 139. 单词拆分（字符串 DP）
 * 核心思路：dp[i] 表示前缀 s[0..i) 能否拆分；仅在 dp[j] 为真且 s[j..i) 在字典中时转移。
 * 时间：O(n²) 字符比较级；空间：O(n)。
 */
#include <string>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution
{
public:
    bool wordBreak(string s, vector<string>& wordDict)
    {
        unordered_set<string> words(wordDict.begin(), wordDict.end());
        vector<bool> dp(s.size() + 1, false);
        dp[0] = true;
        for (int right = 1; right <= (int)s.size(); ++right)
        {
            for (int left = 0; left < right && !dp[right]; ++left)
            {
                if (dp[left] && words.count(s.substr(left, right - left)))
                {
                    // 左侧前缀可拆分，且中间片段在字典中，右端点也可拆分。
                    dp[right] = true;
                }
            }
        }
        return dp[s.size()];
    }
};
