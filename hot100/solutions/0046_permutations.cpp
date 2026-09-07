/*
 * 46. 全排列（回溯）
 * 核心思路：path 保存已选数字，visited 判断是否可用；达到长度时记录一份 path。
 * 时间：O(n*n!)；空间：O(n)（递归栈与 path）。
 * 易错点：递归退出后必须撤销 visited，才能尝试其他数字。
 */
#include <vector>
using namespace std;

class Solution
{
private:
    vector<int> path;
    vector<bool> used;
    vector<vector<int>> answer;

    void dfs(const vector<int>& nums)
    {
        if (path.size() == nums.size())
        {
            answer.push_back(path);
            return;
        }
        for (int i = 0; i < (int)nums.size(); ++i)
        {
            if (used[i])
            {
                continue;
            }
            used[i] = true;
            path.push_back(nums[i]);
            dfs(nums);
            path.pop_back();
            // 回溯：撤销当前选择后，同一位置才能尝试其他数字。
            used[i] = false;
        }
    }

public:
    vector<vector<int>> permute(vector<int>& nums)
    {
        used.assign(nums.size(), false);
        dfs(nums);
        return answer;
    }
};
