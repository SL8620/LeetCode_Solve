/*
 * 32. 最长有效括号（栈 + 下标）
 * 核心思路：栈保存可能的左边界索引；栈顶表示当前无效区间起点。
 * 时间：O(n)；空间：O(n)。
 * 易错点：栈初始放 -1 作为虚拟左边界；遇到 ')' 后弹栈，答案长度为 i-stack.top()。
 */
#include <string>
#include <stack>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int longestValidParentheses(string s)
    {
        stack<int> left_index;
        left_index.push(-1); // 虚拟左边界，保证长度计算从索引 0 开始
        int answer = 0;
        for (int i = 0; i < (int)s.size(); ++i)
        {
            if (s[i] == '(')
            {
                left_index.push(i);
            }
            else
            {
                // 弹出前一个左括号后，栈顶是当前有效段的左边界前一个下标。
                left_index.pop();
                if (left_index.empty())
                {
                    left_index.push(i); // 新的无效左边界
                }
                else
                {
                    answer = max(answer, i - left_index.top());
                }
            }
        }
        return answer;
    }
};
