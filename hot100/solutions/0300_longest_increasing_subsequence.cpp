/*
 * 300. 最长递增子序列（贪心 + lower_bound）
 * 核心思路：tails[len] 保存长度为 len+1 的递增子序列的最小末尾值。
 * 时间：O(n log n)；空间：O(n)。
 * 易错点：本题求长度，tails 本身通常不是原数组的一个合法子序列。
 */
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int lengthOfLIS(vector<int>& nums)
    {
        vector<int> tails;
        for (int value : nums)
        {
            auto it = lower_bound(tails.begin(), tails.end(), value);
            if (it == tails.end())
            {
                tails.push_back(value);
            }
            else
            {
                // 维护“该长度的最小末尾值”，更容易接上后续元素。
                *it = value;
            }
        }
        return tails.size();
    }
};
