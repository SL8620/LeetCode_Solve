/*
 * 1143. 最长公共子序列（二维字符串 DP）
 * 核心思路：字符相同则 +1；不同则取“少一个字符”的两子问题较大值。
 * 时间：O(mn)；空间：O(min(m,n))。
 */
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int longestCommonSubsequence(const string& text1, const string& text2)
    {
        if (text1.size() < text2.size())
        {
            return longestCommonSubsequence(text2, text1);
        }
        vector<int> previous(text2.size() + 1, 0), current = previous;
        for (int i = 1; i <= (int)text1.size(); ++i)
        {
            for (int j = 1; j <= (int)text2.size(); ++j)
            {
                if (text1[i - 1] == text2[j - 1])
                {
                    // 两个末尾字符相同，公共子序列长度直接在对角线状态上加一。
                    current[j] = previous[j - 1] + 1;
                }
                else
                {
                    current[j] = max(previous[j], current[j - 1]);
                }
            }
            previous.swap(current);
        }
        return previous.back();
    }
};
