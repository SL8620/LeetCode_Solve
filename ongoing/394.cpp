/*
394. 字符串解码
中等
相关标签
premium lock icon
相关企业
给定一个经过编码的字符串，返回它解码后的字符串。

编码规则为: k[encoded_string]，表示其中方括号内部的 encoded_string 正好重复 k 次。注意 k 保证为正整数。
你可以认为输入字符串总是有效的；输入字符串中没有额外的空格，且输入的方括号总是符合格式要求的。
此外，你可以认为原始数据不包含数字，所有的数字只表示重复的次数 k ，例如不会出现像 3a 或 2[4] 的输入。
测试用例保证输出的长度不会超过 105。

示例 1：
输入：s = "3[a]2[bc]"
输出："aaabcbc"
示例 2：
输入：s = "3[a2[c]]"
输出："accaccacc"
示例 3：
输入：s = "2[abc]3[cd]ef"
输出："abcabccdcdcdef"
示例 4：
输入：s = "abc3[cd]xyz"
输出："abccdcdcdxyz"
 

提示：

1 <= s.length <= 30
s 由小写英文字母、数字和方括号 '[]' 组成
s 保证是一个 有效 的输入。
s 中所有整数的取值范围为 [1, 300] 
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string decodeString(string s) 
    {
        stack<string> strStack;
        stack<int>  numStack;
        stack<char> opStack;
        stack<string> ansStack;
        string ans;
        
        int len = s.size();
        for(int i=0; i<len; i++)
        {
            if(s[i]>='0' && s[i]<='9')
            {
                int next = 0;
                while(s[i+next]>='0' && s[i+next]<='9')
                {
                    next++;
                }
                string num = s.substr(i,next);
                numStack.push(stoi(num));
                i += next-1;

            }
            else if(s[i]>='a' && s[i]<='z')
            {
                int next = 0;
                while(s[i+next]>='a' && s[i+next]<='z')
                {
                    next++;
                }
                string ss = s.substr(i,next);
                strStack.push(ss);
                i += next-1;
            }
            else if(s[i] == '[')
            {
                opStack.push(s[i]);
            }
            else if(s[i] == ']')
            {
                string ss = strStack.top();
                strStack.pop();
                int num = numStack.top();
                numStack.pop();
                opStack.pop();
                
                string temp;
                for(int j=0; j<num; j++)
                {
                    temp += ss;
                }
                
                if(!strStack.empty())
                {
                    string pre = strStack.top();
                    strStack.pop();
                    pre += temp;
                    strStack.push(pre);
                }
                else
                {
                    strStack.push(temp);
                }

            }

        }
        queue<string> strQueue;
        while(!strStack.empty())
        {
            strQueue.push(strStack.top());
            strStack.pop();
        }
        while(!strQueue.empty())
        {
            ans += strQueue.front();
            strQueue.pop();
        }
        return ans;
    }
};