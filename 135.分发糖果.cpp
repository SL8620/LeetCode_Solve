/*** 
 * @Author: SL8620
 * @Date: 2026-03-02 08:34:25
 * @LastEditTime: 2026-03-02 09:05:19
 * @LastEditors: SL8620
 * @Description: 
 * @FilePath: \.leetcode\135.分发糖果.cpp
 * @
 */
/*
 * @lc app=leetcode.cn id=135 lang=cpp
 *
 * [135] 分发糖果
 */

// @lc code=start
class Solution {
public:
    int candy(vector<int>& ratings) 
    {
        int ans=0;
        int chile_count = ratings.size();
        vector<int> candy(chile_count, 1);

        // 单侧比较，左比右大时左边加一
        for(int i=0; i<chile_count-1; i++)
        {
            if(ratings[i]<ratings[i+1])
            {
                candy[i+1] = candy[i]+1;
            }
        }  

        for(int i=chile_count-1; i>0; i--)
        {
            if(ratings[i-1]>ratings[i])
            {
                candy[i-1] = max(candy[i-1], candy[i]+1);
            }
        }
        for(int i=0; i<chile_count; i++)
        {
            ans += candy[i];
        }
        return ans;
    }
};
// @lc code=end

