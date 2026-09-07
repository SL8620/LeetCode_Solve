/*
 * 39. 组合总和（可重复元素的回溯）
 * 核心思路：排序后，每个位置可以从 start 继续选择，因此允许重复；目标不足时向前枚举。
 * 时间：指数级；空间：O(target)。
 * 易错点：下一轮从 start 开始允许重复，但从 i 开始会导致不同顺序重复答案。
 */
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
private:
    vector<int> path;
    vector<vector<int>> answer;

    void dfs(vector<int>& candidates, int target, int start)
    {
        if (target == 0)
        {
            answer.push_back(path);
            return;
        }
        for (int i = start; i < (int)candidates.size(); ++i)
        {
            if (candidates[i] > target)
            {
                break; // 已排序，后面只会更大
            }
            path.push_back(candidates[i]);
            // 下一轮仍从 i 开始，同一数字可以被重复使用。
            dfs(candidates, target - candidates[i], i);
            path.pop_back();
        }
    }

public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target)
    {
        sort(candidates.begin(), candidates.end());
        dfs(candidates, target, 0);
        return answer;
    }
};
