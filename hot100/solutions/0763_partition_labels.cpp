/*
 * 763. 划分字母区间（贪心 + 最后出现位置）
 * 核心思路：先记录每字母最后位置；扩展当前区间时，只要其最远末尾仍在当前区内就可继续。
 * 时间：O(n)；空间：O(字符集大小)。
 * 易错点：分割条件是 max_right == i，而不是等字符数量相等这种有限前提。
 */
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    vector<int> partitionLabels(string s)
    {
        int last[26]{};
        for (int i = 0; i < (int)s.size(); ++i)
        {
            last[s[i] - 'a'] = i;
        }
        vector<int> answer;
        int start = 0, max_right = 0;
        for (int i = 0; i < (int)s.size(); ++i)
        {
            // 当前区间内任何字母都不能再在更远处出现。
            max_right = max(max_right, last[s[i] - 'a']);
            if (i == max_right)
            {
                answer.push_back(i - start + 1);
                start = i + 1;
            }
        }
        return answer;
    }
};
