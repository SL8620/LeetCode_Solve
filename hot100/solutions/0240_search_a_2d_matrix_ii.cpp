/*
 * 240. 搜索二维矩阵 II（排除法双指针）
 * 核心思路：从右上角出发。目标较小则排除当前整列，目标较大则排除当前整行。
 * 时间：O(m+n)；额外空间：O(1)。
 * 易错点：只有每行/列都分别有序时才不能用普通二维二分。
 */
#include <vector>
using namespace std;

class Solution
{
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target)
    {
        int y = 0, x = (int)matrix[0].size() - 1;
        while (y < (int)matrix.size() && x >= 0)
        {
            if (matrix[y][x] == target)
            {
                return true;
            }
            // 目标更小，当前列后续元素只会更大；目标更大，当前行后续元素只会更小。
            if (matrix[y][x] > target)
            {
                --x;
            }
            else
            {
                ++y;
            }
        }
        return false;
    }
};
