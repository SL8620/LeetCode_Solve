/*
 * 56. 合并区间（排序 + 扫描）
 * 核心思路：按起点排序；当前区间起点不大于答案区间的终点时可以合并。
 * 时间：O(n log n)；空间：O(1) 额外空间（不算答案）。
 * 易错点：重叠判断使用 <=；合并终点要取两者较大值。
 */
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals)
    {
        sort(intervals.begin(), intervals.end()); // 先按左端点排序
        vector<vector<int>> answer;
        for (auto& interval : intervals)
        {
            if (answer.empty() || answer.back()[1] < interval[0])
            {
                answer.push_back(interval);
            }
            else
            {
                // 有重叠时，只需把已有区间的右端点扩张。
                answer.back()[1] = max(answer.back()[1], interval[1]);
            }
        }
        return answer;
    }
};
