/*
 * 438. 找到字符串中所有字母异位词（定长滑动窗口 + 计数数组）
 * 核心思路：维护长度为 p.size() 的窗口，比较 26 个字母的出现次数。
 * 时间：O(|s|)；空间：O(1)。
 * 易错点：窗口长度固定；p 可能比 s 长；最终只需返回下标，不必实际保存字符串。
 */
#include <string>
#include <vector>
#include <array>
using namespace std;

class Solution
{
public:
    vector<int> findAnagrams(string s, string p)
    {
        if (s.size() < p.size()) return {};
        array<int, 26> need{}, window{}; // 小写字母只有 26 种，可用 O(1) 空间计数
        for (char c : p) ++need[c - 'a']; // need 保存目标窗口应有多少个字母
        vector<int> answer;
        for (int right = 0; right < (int)s.size(); ++right)
        {
            ++window[s[right] - 'a']; // 右端扩大一个字符
            if (right >= (int)p.size())
            {
                // 窗口满后，左端字符正好移动出窗口。
                --window[s[right - p.size()] - 'a'];
            }
            // 26 个计数完全相同，说明当前窗口是异位词。
            if (window == need) answer.push_back(right - p.size() + 1);
        }
        return answer;
    }
};
