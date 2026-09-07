/*
 * 11. 盛最多水的容器（对撞双指针）
 * 核心思路：面积由短板和宽度决定。每次移动较短的一边，才有机会更新最大值。
 * 时间：O(n)；额外空间：O(1)。
 * 易错点：虽然短边也可能不再构成答案，但不能同时移动两边。
 */
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int maxArea(vector<int>& height)
    {
        // 两端指针一开始覆盖尽可能宽的区间。
        int left = 0, right = (int)height.size() - 1;
        int answer = 0;
        while (left < right)
        {
            // 容量由短板决定，宽度就是两根竖线的距离。
            int area = min(height[left], height[right]) * (right - left);
            answer = max(answer, area);
            // 宽度必然缩小，所以只能尝试移动较短的一边寻找更大面积。
            if (height[left] < height[right]) ++left;
            else
            {
                --right;
            }
        }
        return answer;
    }
};
