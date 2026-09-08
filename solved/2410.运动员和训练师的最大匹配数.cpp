/*** 
 * @Author: SL8620
 * @Date: 2026-03-02 08:26:25
 * @LastEditTime: 2026-03-02 08:27:13
 * @LastEditors: SL8620
 * @Description: 
 * @FilePath: \.leetcode\2410.运动员和训练师的最大匹配数.cpp
 * @
 */
/*
 * @lc app=leetcode.cn id=2410 lang=cpp
 *
 * [2410] 运动员和训练师的最大匹配数
 */

// @lc code=start
class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& players, vector<int>& trainers) 
    {
        int ans=0;
        // 对运动员和训练师的能力值进行排序
        sort(players.begin(), players.end());
        sort(trainers.begin(), trainers.end());

        if(players.empty() || trainers.empty())
        {
            return 0;
        }

        if(players.front()>trainers.back())
        {
            return 0;
        }

        int trainers_index = 0;
        for(int i=0; i<players.size(); i++)
        {
            for(int j=trainers_index; j<trainers.size(); j++)
            {
                if(players[i]<=trainers[j])
                {
                    trainers_index = j+1;
                    ans++;
                    break;
                }
            }
        }
        return ans;

        
    }
};
// @lc code=end

