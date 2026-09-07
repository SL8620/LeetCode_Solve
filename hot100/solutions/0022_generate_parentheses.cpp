/*
 * 22. 括号生成（回溯）
 * 核心思路：只要“左括号数 < n”就可加左；“已用右括号数 < 左括号数”就可加右。
 * 时间：Catalan 数级别；空间：O(n)。
 * 易错点：不是只在结束时判合法性，而是每一步都用不变式约束搜索。
 */
#include <string>
#include <vector>
using namespace std;

class Solution
{
private:
    string path;
    vector<string> answer;

    void dfs(int n, int left, int right)
    {
        if ((int)path.size() == 2 * n)
        {
            answer.push_back(path);
            return;
        }
        if (left < n)
        {
            path.push_back('(');
            dfs(n, left + 1, right);
            path.pop_back();
        }
        // 右括号数不能超过左括号数，否则当前前缀已经非法。
        if (right < left)
        {
            path.push_back(')');
            dfs(n, left, right + 1);
            path.pop_back();
        }
    }

public:
    vector<string> generateParenthesis(int n)
    {
        dfs(n, 0, 0);
        return answer;
    }
};
