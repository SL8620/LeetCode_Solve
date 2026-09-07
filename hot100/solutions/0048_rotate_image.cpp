/*
 * 48. 旋转图像（转置 + 行反转）
 * 核心思路：顺时针 90° 等价于先沿主对角线转置，再把每行左右翻转。
 * 时间：O(n²)；额外空间：O(1)。
 * 易错点：转置循环只遍历严格上三角，避免交换两次恢复原状。
 */
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    void rotate(vector<vector<int>>& matrix)
    {
        int n = matrix.size();
        // 先沿主对角线转置，矩阵[row][col] 与 matrix[col][row] 交换。
        for (int y = 0; y < n; ++y)
        {
            for (int x = y + 1; x < n; ++x)
            {
                swap(matrix[y][x], matrix[x][y]);
            }
        }
        for (auto& row : matrix) reverse(row.begin(), row.end());
    }
};
