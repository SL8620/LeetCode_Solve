/*
 * 3. 无重复字符的最长子串（滑动窗口 + 哈希）
 * 核心思路：right 扩窗口；出现重复时把 left 追到重复字符的右侧。
 * 时间：O(n)；空间：O(字符集大小)。
 * 易错点：last_seen 必须判断是否在窗口内，即 >= left。
 */
#include <string>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        // 记录字符最后一次出现的下标，而不是记录出现次数。
        unordered_map<char, int> last_seen;
        int left = 0, answer = 0;
        for (int right = 0; right < (int)s.size(); ++right)
        {
            char c = s[right];
            // 下标不小于 left 才说明重复字符仍位于当前窗口内。
            if (last_seen.count(c) && last_seen[c] >= left)
            {
                left = last_seen[c] + 1; // 跳过旧位置，移除重复字符
            }
            last_seen[c] = right; // 更新为当前字符在窗口中的最新位置
            answer = max(answer, right - left + 1); // 当前窗口长度
        }
        return answer;
    }
};
