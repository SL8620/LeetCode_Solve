/*
 * 78. 子集（回溯/二进制枚举）
 * 核心思路：在每个位置选择“加入当前元素”或“跳过”；当前 path 每次都是合法答案。
 * 时间：O(n*2^n)；空间：O(n)。
 * 易错点：每个位置只允许继续向后选择，不能从 0 重新选导致重复。
 */
#include <vector>
using namespace std;

class Solution
{
private:
    vector<int> path;
    vector<vector<int>> answer;

    void dfs(vector<int>& nums, int start)
    {
        // 进入递归时的 path 就是一个合法子集。
        answer.push_back(path);
        // 从 start 继续选，避免生成相同子集的不同排列。
        for (int i = start; i < (int)nums.size(); ++i)
        {
            path.push_back(nums[i]);
            dfs(nums, i + 1);
            path.pop_back();
        }
    }

public:
    vector<vector<int>> subsets(vector<int>& nums)
    {
        dfs(nums, 0);
        return answer;
    }
};
