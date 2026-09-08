/*
279. 完全平方数
中等

给你一个整数 n ，返回 和为 n 的完全平方数的最少数量 。
完全平方数 是一个整数，其值等于另一个整数的平方；换句话说，其值等于一个整数自乘的积。例如，1、4、9 和 16 都是完全平方数，
而 3 和 11 不是。

示例 1
输入：n = 12
输出：3 
解释：12 = 4 + 4 + 4

示例 2：
输入：n = 13
输出：2
解释：13 = 4 + 9

1  2  3  4  5  6  7  8  9  10  11  12
1  2  3  1  2  3  4  2  1   2   3   4 
提示：
    1 <= n <= 104
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numSquares(int n) 
    {
        vector<int> dp(n+1, INT_MAX);
        dp[0] = 0;
        dp[1] = 1;
        for(int i=2; i<=n; i++)
        {
            for(int j=1; j*j<i; j++)
            {
                int diff = i-j*j;
                dp[i] = min(dp[i], dp[diff]+1);
            }
        }

        return dp[n];
    }
};