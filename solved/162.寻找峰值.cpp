/*
 * @Author: SL8620 2584032673@qq.com
 * @Date: 2026-03-27 09:54:56
 * @LastEditors: SL8620 2584032673@qq.com
 * @LastEditTime: 2026-04-09 15:33:10
 * @FilePath: /leetcode/162.寻找峰值.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
/*
 * @lc app=leetcode.cn id=162 lang=cpp
 *
 * [162] 寻找峰值
 */

// @lc code=start
class Solution {
public:
    int findPeakElement(vector<int>& nums) 
    {
        int len = nums.size();
        int st = 0;
        int ed = len-1;
        
        // 特判
        if(len>=2 && nums[0]>nums[1])
        {
            return 0;
        }
        if(len>=2 && nums[len-1]>nums[len-2])
        {
            return len-1;
        }

        while(st < ed)
        {
            int mid = st+(ed-st)/2;
            // 正好就是要找的峰值
            if(nums[mid]>nums[mid-1] && nums[mid]>nums[mid+1])
            {
                return mid;
            }
            // 附近是升序排列，峰值在右侧
            else if(nums[mid]>=nums[mid-1] && nums[mid]<nums[mid+1])
            {
                st = mid+1;
            }
            // 附近是降序排列，峰值在左侧
            else if(nums[mid]<nums[mid-1] && nums[mid]>=nums[mid+1])
            {
                ed = mid;
            }
            // 听天由命,
            else
            {
                ed = mid;
            }
        }
        return 0;
        
    }
};
// @lc code=end

