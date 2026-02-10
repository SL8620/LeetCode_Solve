/*** 
 * @Author: SL8620
 * @Date: 2026-02-09 20:15:19
 * @LastEditTime: 2026-02-09 20:42:29
 * @LastEditors: SL8620
 * @Description: 
 * @FilePath: \.leetcode\26.删除有序数组中的重复项.cpp
 * @
 */
/*
 * @lc app=leetcode.cn id=26 lang=cpp
 *
 * [26] 删除有序数组中的重复项
 */

// @lc code=start
class Solution {
public:
    int removeDuplicates(vector<int>& nums) 
    {
        int ansLength = 1;
        if(nums.size()==0)
        {
           return 0;
        }
        
        for(int i=0; i<nums.size(); i++)
        {
            for(int j=i+1; j<nums.size(); j++)
            {
                if(nums[ansLength-1]!=nums[j])
                {
                    ansLength++;
                    nums[ansLength-1]=nums[j];
                    i=j;
                }
            }
        }

        return ansLength;

    }
};
// @lc code=end

