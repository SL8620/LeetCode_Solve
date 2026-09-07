/*
 * 73. 矩阵置零（首行首列充当标记）
 * 核心思路：用矩阵第 0 行/列记录哪些行列需要清零，避免额外 bool 数组。
 * 时间：O(mn)；额外空间：O(1)。
 * 易错点：先记录首行首列自身是否含零，再写标记，否则会被自己修改。
 */
#include <vector>
using namespace std;

class Solution
{
public:
    void setZeroes(vector<vector<int>>& matrix)
    {
        int m = matrix.size(), n = matrix[0].size();
        // 首行首列也承担标记职责，因此必须单独记住它们原本是否有零。
        bool first_row_zero = false, first_col_zero = false;
        for (int x = 0; x < n; ++x) if (matrix[0][x] == 0) first_row_zero = true;
        for (int y = 0; y < m; ++y) if (matrix[y][0] == 0) first_col_zero = true;
        for (int y = 1; y < m; ++y)
        {
            for (int x = 1; x < n; ++x)
            {
                if (matrix[y][x] == 0)
                {
                    // 用首列标记行，用首行列标记列。
                    matrix[0][x] = 0;
                    matrix[y][0] = 0;
                }
            }
        }
        for (int y = 1; y < m; ++y)
        {
            for (int x = 1; x < n; ++x)
            {
                if (matrix[y][0] == 0 || matrix[0][x] == 0)
                {
                    matrix[y][x] = 0;
                }
            }
        }
        if (first_row_zero) for (int x = 0; x < n; ++x) matrix[0][x] = 0;
        if (first_col_zero) for (int y = 0; y < m; ++y) matrix[y][0] = 0;
    }
};
