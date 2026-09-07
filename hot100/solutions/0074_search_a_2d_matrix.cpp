/*
 * 74. 搜索二维矩阵（一维下标二分）
 * 核心思路：把矩阵按行拼成升序数组；mid 映射回 row=mid/n, col=mid%n。
 * 时间：O(log(mn))；额外空间：O(1)。
 * 易错点：条件必须是矩阵题给定的“每行最大值小于下一行最小值”。
 */
#include <vector>
using namespace std;

class Solution
{
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target)
    {
        int m = matrix.size(), n = matrix[0].size();
        int left = 0, right = m * n - 1;
        while (left <= right)
        {
            int mid = left + (right - left) / 2;
            // 矩阵按行展开成升序数组，利用除法和取余还原二维下标。
            int value = matrix[mid / n][mid % n];
            if (value == target)
            {
                return true;
            }
            if (value < target)
            {
                left = mid + 1;
            }
            else
            {
                right = mid - 1;
            }
        }
        return false;
    }
};
