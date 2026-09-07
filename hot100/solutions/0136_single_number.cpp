/*
 * 136. 只出现一次的数字（异或）
 * 核心思路：x^x=0，0^x=x，且交换结合；把所有数异或后，出现两次的数互相抵消。
 * 时间：O(n)；额外空间：O(1)。
 */
#include <vector>
using namespace std;

class Solution
{
public:
    int singleNumber(vector<int>& nums)
    {
        int answer = 0;
        // 异或的自反性会让所有重复两次的值抵消，只留下唯一值。
        for (int value : nums)
        {
            answer ^= value;
        }
        return answer;
    }
};
