/*
 * 1. 两数之和（哈希表）
 * 核心思路：一边遍历，一边把“已经看过的值”放进哈希表；
 *       碰到当前数 a 时，只需查询 target-a 是否已经出现过。
 * 时间：O(n)；空间：O(n)。
 * 易错点：先查询再插入，避免把同一个下标使用两次。
 */
#include <vector>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    vector<int> twoSum(vector<int>& nums, int target)
    {
        // 只保存已经扫描过的值；当前元素暂时不能和自己配对。
        unordered_map<int, int> value_to_index;
        for (int i = 0; i < (int)nums.size(); ++i)
        {
            // 若互补值已经出现，它和当前元素就是答案。
            int need = target - nums[i];
            if (value_to_index.count(need))
            {
                return {value_to_index[need], i};
            }
            // 没有命中后再记录当前值，保证同一个下标不会被使用两次。
            value_to_index[nums[i]] = i;
        }
        return {}; // 题目保证有答案，这里只是让所有分支都返回。
    }
};
