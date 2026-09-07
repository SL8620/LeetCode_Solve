/*
 * 20. 有效的括号（栈）
 * 核心思路：左括号入栈；右括号必须与栈顶左括号匹配；最后栈必须为空。
 * 时间：O(n)；空间：O(n)。
 */
#include <string>
#include <stack>
using namespace std;

class Solution
{
public:
    bool isValid(string s)
    {
        stack<char> open;
        for (char c : s)
        {
            // 栈中保存等待被匹配的右括号，遇到时立即检查栈顶。
            if (c == '(') open.push(')');
            else if (c == '[') open.push(']');
            else if (c == '{') open.push('}');
            else if (open.empty() || open.top() != c)
            {
                return false;
            }
            else open.pop();
        }
        return open.empty();
    }
};
