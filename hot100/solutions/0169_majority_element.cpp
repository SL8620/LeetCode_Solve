/*
 * 169. 多数元素（Boyer-Moore 投票法）
 * 核心思路：不同元素两两抵消；候选在剩余序列中占比必然 > 1/2，所以最后仍为候选。
 * 时间：O(n)；额外空间：O(1)。
 */
#include <vector>
using namespace std;

class Solution
{
public:
    int majorityElement(vector<int>& nums)
    {
        int candidate = 0, votes = 0;
        for (int value : nums)
        {
            if (votes == 0)
            {
                candidate = value;
            }
            // 相同元素 +1，不同元素 -1；每轮抵消一对不同元素。
            votes += value == candidate ? 1 : -1;
        }
        return candidate;
    }
};
