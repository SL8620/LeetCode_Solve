/*
 * 394. 字符串解码（数字栈 + 字符串栈）
 * 核心思路：遇到 [ 时把当前字符串和数字入栈；遇到 ] 时重复并拼接。
 * 时间：O(输出长度)；空间：O(嵌套深度)。
 * 易错点：读完字母后要立即重置 count；k 可能不止一位。
 */
#include <string>
#include <stack>
using namespace std;

class Solution
{
public:
    string decodeString(const string& s)
    {
        stack<string> texts;
        stack<int> counts;
        string current;
        int count = 0;
        for (char c : s)
        {
            if (isdigit(c))
            {
                // 数字可能有多位，需要逐位拼接。
                count = count * 10 + (c - '0');
            }
            else if (c == '[')
            {
                // 进入内层前保存外层状态，等待 ']' 后重新拼接。
                texts.push(current);
                counts.push(count);
                current.clear();
                count = 0;
            }
            else if (c == ']')
            {
                string previous = texts.top(); texts.pop();
                int repeat = counts.top(); counts.pop();
                string expanded;
                for (int i = 0; i < repeat; ++i) expanded += current;
                current = previous + expanded;
            } else {
                current.push_back(c);
            }
        }
        return current;
    }
};
