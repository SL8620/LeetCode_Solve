/*** 
 * @Author: SL8620
 * @Date: 2026-02-09 20:49:36
 * @LastEditTime: 2026-02-10 08:54:16
 * @LastEditors: SL8620
 * @Description: 
 * @FilePath: \.leetcode\27.移除元素.cpp
 * @
 */
/*
 * @lc app=leetcode.cn id=27 lang=cpp
 *
 * [27] 移除元素
 */

// @lc code=start
class Solution 
{
public:
    int removeElement(vector<int>& nums, int val) 
    {
        int k = 0;  // 下一个要写入的位置（保留区长度）
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] != val) {
                nums[k++] = nums[i];
            }
        }
        return k;
    }
};
// @lc code=end

