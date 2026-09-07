/*
 * 131. 分割回文串（回溯 + 预处理）
 * 核心思路：从 start 开始枚举下一个切片 [start,i]；只有它是回文串才递归到 i+1。
 * 时间：状态 O(n²)，可达答案为指数级；空间 O(n)。
 * 易错点：回文判断表由中心扩展填充，能降低每次判断的重复工作。
 */
#include <string>
#include <vector>
using namespace std;

class Solution
{
private:
    vector<string> path;
    vector<vector<string>> answer;

    void dfs(const string& s, int start, vector<vector<bool>>& pal)
    {
        if (start == (int)s.size())
        {
            answer.push_back(path);
            return;
        }
        for (int end = start; end < (int)s.size(); ++end)
        {
            if (!pal[start][end])
            {
                continue; // 非回文切片不能作为当前分段
            }
            path.push_back(s.substr(start, end - start + 1));
            dfs(s, end + 1, pal);
            path.pop_back();
        }
    }

public:
    vector<vector<string>> partition(string s)
    {
        int n = s.size();
        vector<vector<bool>> pal(n, vector<bool>(n, false));
        // pal[begin][end] 只依赖更小区间，因此由短到长填充。
        for (int end = 0; end < n; ++end)
        {
            for (int begin = 0; begin <= end; ++begin)
            {
                if (s[begin] != s[end])
                {
                    continue;
                }
                pal[begin][end] = (end - begin < 2) || pal[begin + 1][end - 1];
            }
        }
        dfs(s, 0, pal);
        return answer;
    }
};
