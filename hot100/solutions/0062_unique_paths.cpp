/*
 * 62. 不同路径（二维/一维 DP）
 * 核心思路：到达 (y,x) 只能从上方或左侧来，故 dp[y][x]=dp[y-1][x]+dp[y][x-1]。
 * 时间：O(mn)；空间：O(n)。
 */
#include <vector>
using namespace std;

class Solution
{
public:
    int uniquePaths(int m, int n)
    {
        vector<long long> dp(n, 1); // dp[x] 表示当前行到达第 x 列的路径数
        for (int y = 1; y < m; ++y)
        {
            for (int x = 1; x < n; ++x)
            {
                // dp[x] 仍在表示上一行结果时加上左方，从而完成本行更新。
                dp[x] += dp[x - 1];
            }
        }
        return (int)dp[n - 1];
    }
};
