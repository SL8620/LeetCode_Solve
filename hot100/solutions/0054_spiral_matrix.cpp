/*
 * 54. 螺旋矩阵（边界收缩）
 * 核心思路：维护上下左右四个边界；每次按“右→下→左→上”走完后收缩边界。
 * 时间：O(mn)；额外空间：O(1)。
 * 易错点：每一方向开始前或结束后都要判断边界，才能处理单行/单列矩阵。
 */
#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix)
    {
        if (matrix.empty() || matrix[0].empty()) return {};
        int top = 0, bottom = (int)matrix.size() - 1;
        int left = 0, right = (int)matrix[0].size() - 1;
        vector<int> answer;
        while (top <= bottom && left <= right)
        {
            for (int x = left; x <= right; ++x)
            {
                // 先处理最上边一行，之后上边界收缩。
                answer.push_back(matrix[top][x]);
            }
            ++top;
            for (int y = top; y <= bottom; ++y)
            {
                answer.push_back(matrix[y][right]);
            }
            --right;
            if (top <= bottom)
            {
                // 只有上下边界仍合法时才处理底边，避免重复访问。
                for (int x = right; x >= left; --x)
                {
                    answer.push_back(matrix[bottom][x]);
                }
                --bottom;
            }
            if (left <= right)
            {
                for (int y = bottom; y >= top; --y)
                {
                    answer.push_back(matrix[y][left]);
                }
                ++left;
            }
        }
        return answer;
    }
};
