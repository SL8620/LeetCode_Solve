/*** 
 * @Author: SL8620
 * @Date: 2026-02-10 12:24:46
 * @LastEditTime: 2026-02-10 13:00:56
 * @LastEditors: SL8620
 * @Description: 
 * @FilePath: \.leetcode\66.加一.cpp
 * @
 */
/*
 * @lc app=leetcode.cn id=66 lang=cpp
 *
 * [66] 加一
 */

// @lc code=start
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) 
    {
        int endPos = digits.size()-1;
        if(digits[endPos] != 9)
        {
            digits[endPos] = digits[endPos]+1;
            return digits;
        }
        else    //处理末尾有多个连续9的情况 19 09 129 4399 99
        {
            for(int i=endPos; i>=0; i--)
            {
                int j=i-1;
                if(j>=0)    // 防止越界
                {
                    if(digits[i]==9 && digits[j] ==9)
                    {
                        digits[i] = 0;
                        continue;
                    }

                    else if(digits[i]==9 && digits[j]!=9)   //找到后面都是9最长数字
                    {
                        digits[j] = digits[j]+1;
                        digits[i] = 0;
                        return digits;
                    }
                }
                else    // i=0时仍为9，说明全是9
                {
                    digits[0] = 1;
                    digits.push_back(0);
                    return digits;
                }
            }
            
        }
        return digits;
    }
};
// @lc code=end

