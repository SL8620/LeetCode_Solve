/*** 
 * @Author: SL8620
 * @Date: 2026-02-10 09:02:13
 * @LastEditTime: 2026-02-10 09:36:42
 * @LastEditors: SL8620
 * @Description: 
 * @FilePath: \.leetcode\35.搜索插入位置.cpp
 * @
 */
/*
 * @lc app=leetcode.cn id=35 lang=cpp
 *
 * [35] 搜索插入位置
 */

// @lc code=start
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) 
    {
        int left = 0;
        int right = nums.size()-1;
        int mid;
        while(left <= right)
        {
            int mid = left + (right - left) / 2;
            if(nums[mid] < target) //在右侧
            {
                left = mid + 1;
            }
            else if (nums[mid] > target) //在左侧
            {
                right = mid - 1;
            }
            else //相等
            {
                return mid;
            }
        }
        return left;
    }
};
// @lc code=end

