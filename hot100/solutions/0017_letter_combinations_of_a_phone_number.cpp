/*
 * 17. 电话号码的字母组合（回溯 + 映射表）
 * 核心思路：digit 依次对应多组字符；在位置 i 处枚举按键字符并递归。
 * 时间：O(3^m*4^n)；空间：O(m+n)。
 * 易错点：输入为空时返回空答案，不能错误返回 {""}。
 */
#include <string>
#include <vector>
using namespace std;

class Solution
{
private:
    const string letters[10] = {"", "", "abc", "def", "ghi", "jkl",
                               "mno", "pqrs", "tuv", "wxyz"};
    string path;
    vector<string> answer;

    void dfs(const string& digits, int index)
    {
        if (index == (int)digits.size())
        {
            answer.push_back(path);
            return;
        }
        // 枚举当前数字按键对应的每个字母。
        for (char c : letters[digits[index] - '0'])
        {
            path.push_back(c);
            dfs(digits, index + 1);
            path.pop_back(); // 撤销选择后才能尝试下一个字母
        }
    }

public:
    vector<string> letterCombinations(const string& digits)
    {
        if (digits.empty())
        {
            return {};
        }
        dfs(digits, 0);
        return answer;
    }
};
