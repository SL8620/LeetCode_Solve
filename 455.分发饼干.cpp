/*** 
 * @Author: SL8620
 * @Date: 2026-02-10 19:30:19
 * @LastEditTime: 2026-03-02 08:22:55
 * @LastEditors: SL8620
 * @Description: 
 * @FilePath: \.leetcode\455.分发饼干.cpp
 * @
 */
/*
 * @lc app=leetcode.cn id=455 lang=cpp
 *
 * [455] 分发饼干
 */

// @lc code=start
class Solution 
{
public:
    int findContentChildren(vector<int>& g, vector<int>& s) 
    {
        int ans=0;
        // 对饼干大小和饥饿值进行排序
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());

        if(g.empty() || s.empty())
        {
            return 0;
        }

        if(g.front()>s.back())
        {
            return 0;
        }

        int biscuit_index = 0;
        for(int i=0; i<g.size(); i++)
        {
            for(int j=biscuit_index; j<s.size(); j++)
            {
                if(g[i]<=s[j])
                {
                    biscuit_index = j+1;
                    ans++;
                    break;
                }
            }
        }
        return ans;

    }
};
// @lc code=end

