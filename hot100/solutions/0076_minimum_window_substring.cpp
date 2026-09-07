/*
 * 76. 最小覆盖子串（变长滑动窗口 + 计数）
 * 核心思路：right 扩张直到满足所有字符需求，再收缩 left 寻找更短答案。
 * 时间：O(|s|+|t|)；空间：O(字符集大小)。
 * 易错点：need 保存需求次数，formed 记录“已经满足需求种类数”，字符数量可大于需求。
 */
#include <string>
#include <unordered_map>
#include <climits>
using namespace std;

class Solution
{
public:
    string minWindow(string s, string t)
    {
        unordered_map<char, int> need, window;
        for (char c : t)
        {
            ++need[c];
        }
        int left = 0, formed = 0, best_len = INT_MAX, best_left = 0;
        for (int right = 0; right < (int)s.size(); ++right)
        {
            char c = s[right];
            ++window[c];
            // 只有窗口中的计数第一次满足需求时，才说明一种字符被覆盖完整。
            if (need.count(c) && window[c] == need[c])
            {
                ++formed;
            }
            // 已经覆盖 t 的全部字符后，尝试收缩左端寻找更短答案。
            while (formed == (int)need.size() && left <= right)
            {
                if (right - left + 1 < best_len)
                {
                    best_len = right - left + 1;
                    best_left = left;
                }
                char removed = s[left];
                --window[removed];
                if (need.count(removed) && window[removed] < need[removed])
                {
                    --formed;
                }
                ++left;
            }
        }
        return best_len == INT_MAX ? "" : s.substr(best_left, best_len);
    }
};
