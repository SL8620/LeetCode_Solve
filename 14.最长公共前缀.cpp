/*** 
 * @Author: SL8620
 * @Date: 2026-02-09 13:12:03
 * @LastEditTime: 2026-02-09 14:09:41
 * @LastEditors: SL8620
 * @Description: 
 * @FilePath: \.leetcode\14.最长公共前缀.cpp
 * @
 */
/*
 * @lc app=leetcode.cn id=14 lang=cpp
 *
 * [14] 最长公共前缀
 */

// @lc code=start
class Solution 
{
public:
    string longestCommonPrefix(vector<string>& strs) 
    {
        // 返回变量声明
        string lcp;

        int firstSize = strs[0].size();
        if(firstSize==0)
        {
            lcp="";
            return lcp;
        }

        int lcp_size = 0;
        bool cmpResult = true;

        // 遍历进行判断
        while(cmpResult)
        {
            char currentCmp,currentFont;
            if(firstSize > lcp_size)
            {
                currentCmp = strs[0].at(lcp_size);
            }
            else
            {
                break;
            }
            
            for(int i=1; i<strs.size(); i++)
            {
                int currentSize = strs[i].size();
                if(currentSize==0)
                {
                    lcp="";
                    return lcp;
                }

                if(currentSize > lcp_size)
                {
                    currentFont = strs[i].at(lcp_size);
                }
                else
                {
                    return lcp;
                }

                if(currentCmp != currentFont)
                {
                    cmpResult = false;
                    break;
                }
            }
            if(cmpResult)
            {
                // 更新输出结果
                lcp.push_back(currentCmp);
                // 更新下标
                lcp_size++;
            }
        }
        return lcp;
    }
};
// @lc code=end

