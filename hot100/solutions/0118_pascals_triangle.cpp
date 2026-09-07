/*
 * 118. 杨辉三角（逐行 DP）
 * 核心思路：每行两端为 1；中间值等于上一行正上方与左上方两数之和。
 * 时间：O(n²)；空间：O(1) 额外空间（不算答案）。
 */
#include <vector>
using namespace std;

class Solution
{
public:
    vector<vector<int>> generate(int numRows)
    {
        vector<vector<int>> triangle(numRows);
        for (int row = 0; row < numRows; ++row)
        {
            triangle[row].resize(row + 1, 1);
            for (int i = 1; i < row; ++i)
            {
                // 中间值来自上一行左上和右上两个位置。
                triangle[row][i] = triangle[row - 1][i - 1] + triangle[row - 1][i];
            }
        }
        return triangle;
    }
};
