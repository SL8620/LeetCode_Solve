/*
 * @Author: SL8620 2584032673@qq.com
 * @Date: 2026-03-27 10:13:30
 * @LastEditors: SL8620 2584032673@qq.com
 * @LastEditTime: 2026-03-27 10:56:51
 * @FilePath: /LeetCode_Solve/home/lightwheel/Documents/leetcode/34.在排序数组中查找元素的第一个和最后一个位置.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
/*
 * @lc app=leetcode.cn id=34 lang=cpp
 *
 * [34] 在排序数组中查找元素的第一个和最后一个位置
 */

// @lc code=start
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) 
    {
        int len = nums.size();
        int l_pos = 0;
        int r_pos = len;
        int index = -1;
        vector<int> ans = {-1, -1};

        while (l_pos < r_pos)
        {
            int m_pos = l_pos + (r_pos - l_pos)/2;
            int m_num = nums[m_pos];
            if(target == m_num)
            {
                index = m_pos;
                break;
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

        if (index == -1)
        {
            return ans;
        }
        else //找到了，前后二分确定区间
        {
            // 起始位置
            int st_pos_l = 0;
            int ed_pos_l = index;
            int st_pos_r = index;
            int ed_pos_r = len;

            while(st_pos_l < ed_pos_l)
            {
                int m_pos_l = st_pos_l + (ed_pos_l - st_pos_l)/2;
                int m_num_l = nums[m_pos_l];
                if(m_num_l == target)   //左边也许还有，更新右侧区间
                {
                    ed_pos_l = m_pos_l;
                }
                else if(m_num_l < target)   //左边起始点在右侧，更新左侧区间
                {
                    st_pos_l = m_pos_l+1;
                }
                // 不可能有大于target的情况
            }

            while(st_pos_r < ed_pos_r)
            {
                int m_pos_r = st_pos_r + (ed_pos_r - st_pos_r)/2;
                int m_num_r = nums[m_pos_r];
                if(m_num_r == target)   //右边也许还有，更新左侧区间
                {
                    st_pos_r = m_pos_r+1;
                }
                else if(m_num_r > target)   //右边终止点在左侧，更新右侧区间
                {
                    ed_pos_r = m_pos_r;
                }
                // 不可能有大于target的情况
            }

            ans[0] = st_pos_l;
            ans[1] = ed_pos_r-1;
            return ans;
        }
        
        
        
    }
};
// @lc code=end

