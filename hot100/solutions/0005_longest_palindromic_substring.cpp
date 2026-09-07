/*
 * 5. 最长回文子串（中心扩展）
 * 核心思路：枚举每个字符（奇数中心）和相邻字符间隙（偶数中心），向两侧扩展。
 * 时间：O(n²)；空间：O(1)。
 */
#include <string>
#include <algorithm>
using namespace std;

class Solution
{
public:
    string longestPalindrome(string s)
    {
        if (s.size() < 2)
        {
            return s;
        }
        int best_left = 0, best_len = 1;
        for (int center = 0; center < (int)s.size(); ++center)
        {
            // 同时枚举奇数中心和偶数中心，避免漏掉两种长度。
            int len = expand(s, center, center);
            if (len > best_len)
            {
                best_len = len; best_left = center - len / 2;
            }
            len = expand(s, center, center + 1);
            if (len > best_len)
            {
                best_len = len; best_left = center - len / 2 + 1;
            }
        }
        return s.substr(best_left, best_len);
    }

private:
    int expand(const string& s, int left, int right)
    {
        while (left >= 0 && right < (int)s.size() && s[left] == s[right])
        {
            --left; ++right;
        }
        return right - left - 1;
    }
};
