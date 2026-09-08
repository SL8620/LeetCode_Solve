/*
 * @lc app=leetcode id=1 lang=cpp
 *
 * [1] Two Sum
 */

// @lc code=start
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) 
    {

        unsigned int vectorSize = nums.size();
        unsigned startPos,endPos=0;
        for (int i=0;i<vectorSize;i++)
        {
            int head = i;
            int sum=0;
            for(int j = head; j <vectorSize; j++)
            {
                sum += nums[j];

                //和小于目标值，继续累加
                if(sum < target)
                {
                    continue;
                }
                // 和大于目标值，说明开头错误
                else if(sum > target)
                {
                    break;
                }
                else if(sum == target)
                {
                    startPos = head;
                    endPos = j;
                    return {startPos,endPos};
                }
            }
        }
        return {};
    }
};
// @lc code=end

