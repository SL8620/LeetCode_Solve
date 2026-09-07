/*
 * 64. 最小路径和（二维 DP 滚动数组）
 * 核心思路：每格最小代价 = 该格代价 + min(上方最小代价, 左方最小代价)。
 * 时间：O(mn)；空间：O(n)。
 */
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

class Solution
{
public:
    int minPathSum(vector<vector<int>>& grid)
    {
        int m = grid.size(), n = grid[0].size();
        vector<int> dp(n, 0);
        for (int y = 0; y < m; ++y)
        {
            for (int x = 0; x < n; ++x)
            {
                // 首行/首列只有单一方向；起点没有前驱，直接设为 0。
                int from_top = y == 0 ? INT_MAX : dp[x];
                int from_left = x == 0 ? INT_MAX : dp[x - 1];
                if (y == 0 && x == 0) from_top = from_left = 0;
                dp[x] = grid[y][x] + min(from_top, from_left);
            }
        }
        return dp[n - 1];
    }
};
