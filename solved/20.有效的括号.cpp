/*** 
 * @Author: SL8620
 * @Date: 2026-02-09 14:19:36
 * @LastEditTime: 2026-02-09 19:19:40
 * @LastEditors: SL8620
 * @Description: 
 * @FilePath: \.leetcode\20.有效的括号.cpp
 * @
 */
/*
 * @lc app=leetcode.cn id=20 lang=cpp
 *
 * [20] 有效的括号
 */

#include <string>
#include <stack>
using namespace std; 


// @lc code=start
class Solution {
public:
    bool isValid(string s) 
    {
        if(s.length()%2!=0)
        {
            return false;
        }

        if(s.length()==0)
        {
            return true;
        }

        stack<char> st;
        for(int i=0; i<s.length(); i++)
        {
            if(s[i]=='(' || s[i]=='[' || s[i]=='{')
            {
                st.push(s[i]);
                continue;
            }

            // 此时当前字符是右括号，栈如果已经空了，说明无效
            if(st.empty())
            {
                return false;
            }
            
            switch (s[i])
            {
            case ')':
                if(st.top() == '(')
                {
                    st.pop();
                }
                else
                {
                    return false;
                }
                break;

            case ']':
                if(st.top() == '[')
                {
                    st.pop();
                }
                else
                {
                    return false;
                }
                break;
            
            case '}':
                if(st.top() == '{')
                {
                    st.pop();
                }
                else
                {
                    return false;
                }
                break;

            default:
                break;
            }
        }

        if(st.size()==0)
        {
            return true;
        }
        return false;
    }   
};
// @lc code=end

