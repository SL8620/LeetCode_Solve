/*
 * 84. 柱状图中最大的矩形（单调递减栈）
 * 核心思路：栈保存递增柱索引；柱子第一次变矮时确定其左右边界。
 * 时间：O(n)；空间：O(n)。
 * 易错点：处理完循环后还要反复弹栈；左边界是新栈顶而非“栈顶-1”。
 */
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int largestRectangleArea(vector<int>& heights)
    {
        stack<int> indexes;
        int answer = 0;
        // 多遍历一个高度 0，强制弹出栈中剩余的矩形。
        for (int i = 0; i <= (int)heights.size(); ++i)
        {
            int current = i == (int)heights.size() ? 0 : heights[i];
            while (!indexes.empty() && current < heights[indexes.top()])
            {
                int height = heights[indexes.top()];
                indexes.pop();
                // 弹栈后的新栈顶是右边界左侧的第一个更矮柱，i 是右边界。
                int left = indexes.empty() ? -1 : indexes.top();
                int width = i - left - 1;
                answer = max(answer, height * width);
            }
            indexes.push(i);
        }
        return answer;
    }
};
