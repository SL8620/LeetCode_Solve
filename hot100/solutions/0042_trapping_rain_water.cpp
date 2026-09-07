/*
 * 42. 接雨水（单调递减栈）
 * 核心思路：栈保存左边界；遇到较高柱时弹出底柱，其上方积水由左右两侧较高柱决定。
 * 时间：O(n)；空间：O(n)。
 * 易错点：宽度是 right-left-1，高度是 min(left,right)-height[mid]。
 */
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int trap(vector<int>& height)
    {
        stack<int> indexes;
        int answer = 0;
        for (int i = 0; i < (int)height.size(); ++i)
        {
            // 新柱子比栈顶更高时，它和栈顶左侧柱子可以围出积水。
            while (!indexes.empty() && height[i] > height[indexes.top()])
            {
                int bottom = indexes.top();
                indexes.pop(); // 被弹出的柱子是当前积水的最低底面
                if (indexes.empty()) break;
                int left = indexes.top(); // 栈顶是左边界，当前 i 是右边界
                int width = i - left - 1; // 两个边界柱之间的格子数
                int level = min(height[left], height[i]) - height[bottom];
                answer += width * level;
            }
            // 栈内下标对应的柱高保持递减，便于后续继续找边界。
            indexes.push(i);
        }
        return answer;
    }
};
