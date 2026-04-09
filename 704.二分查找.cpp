/*
 * @Author: SL8620 2584032673@qq.com
 * @Date: 2026-03-27 09:42:27
 * @LastEditors: SL8620 2584032673@qq.com
 * @LastEditTime: 2026-03-27 09:47:10
 * @FilePath: /LeetCode_Solve/home/lightwheel/Documents/leetcode/704.二分查找.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
/*
 * @lc app=leetcode.cn id=704 lang=cpp
 *
 * [704] 二分查找
 */

// @lc code=start
class Solution {
public:
    int search(vector<int>& nums, int target) 
    {
        int len = nums.size();
        int l_pos = 0;
        int r_pos = len;
        while (l_pos < r_pos)
        {
            int m_pos = l_pos + (r_pos-l_pos)/2;
            int m_num = nums[m_pos];
            if(m_num == target)
            {
                return m_pos;
            }
            else if(target < m_num)
            {
                r_pos = m_pos;
            }
            else if(target > m_num)
            {
                l_pos = m_pos+1;
            }
        }
        return -1;
        
    }
};
// @lc code=end

