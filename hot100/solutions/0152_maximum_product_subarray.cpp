/*
 * 152. 乘积最大子数组（双状态 DP）
 * 核心思路：负数会翻转最大/最小关系，因此同时维护以当前位置结尾的最大、最小乘积。
 * 时间：O(n)；空间：O(1)。
 * 易错点：零会切断所有乘积，三种状态均需先重置为当前元素。
 */
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int maxProduct(vector<int>& nums)
    {
        int ending_max = nums[0], ending_min = nums[0], answer = nums[0];
        for (int i = 1; i < (int)nums.size(); ++i)
        {
            int value = nums[i];
            if (value == 0)
            {
                ending_max = ending_min = 0;
            }
            else
            {
                // 负数乘负数可能变大，所以必须同时更新最大和最小状态。
                int next_max = max({value, ending_max * value, ending_min * value});
                int next_min = min({value, ending_max * value, ending_min * value});
                ending_max = next_max;
                ending_min = next_min;
            }
            answer = max(answer, ending_max);
        }
        return answer;
    }
};
