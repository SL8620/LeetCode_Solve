/*** 
 * @Author: SL8620
 * @Date: 2026-02-03 22:02:40
 * @LastEditTime: 2026-02-04 10:39:47
 * @LastEditors: SL8620
 * @Description: 
 * @FilePath: \.leetcode\1.两数之和.cpp
 * @
 */
/*
 * @lc app=leetcode.cn id=1 lang=cpp
 *
 * [1] 两数之和
 */

// @lc code=start
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) 
    {
        unsigned int vectorSize = nums.size();
        
        unordered_map<int, int> map;

        for(int i=0;i<vectorSize;i++)
        {
            int rest = target-nums[i];
            if(map.count(rest) && map[rest]!=i)
            {
                return {map[rest],i};
            }
            map[nums[i]] = i;

        }

        return {};

    }
};
// @lc code=end

