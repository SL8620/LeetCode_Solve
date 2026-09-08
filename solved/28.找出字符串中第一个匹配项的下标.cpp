/*** 
 * @Author: SL8620
 * @Date: 2026-02-10 08:57:59
 * @LastEditTime: 2026-02-10 09:00:34
 * @LastEditors: SL8620
 * @Description: 
 * @FilePath: \.leetcode\28.找出字符串中第一个匹配项的下标.cpp
 * @
 */
/*
 * @lc app=leetcode.cn id=28 lang=cpp
 *
 * [28] 找出字符串中第一个匹配项的下标
 */

// @lc code=start
class Solution {
public:
    int strStr(string haystack, string needle) 
    {
        if(haystack.find(needle)!=string::npos)
        {
            return int(haystack.find(needle));
        }
        else
        {
            return -1;
        }
    }
};
// @lc code=end

