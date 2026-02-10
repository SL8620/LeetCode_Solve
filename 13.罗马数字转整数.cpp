/*
 * @lc app=leetcode.cn id=13 lang=cpp
 *
 * [13] 罗马数字转整数
 */

// @lc code=start
class Solution {
public:
    int romanToInt(string s) 
    {
        int ans=0;

        for(int i=0;i<s.length();i++)
        {
            switch (s[i])
            {
            case 'M':
                ans+=1000;
                break;
            
            case 'D':
                ans+=500;
                break;

            case 'C':
                if(s[i+1] == 'D' || s[i+1] == 'M')
                {
                    ans += (s[i+1] =='D'?400:900);
                    s[i+1] = 'Z';
                }
                else
                {
                    ans+=100;
                }
                break;

            case 'L':
                ans+=50;
                break;
            
            case 'X':
                if(s[i+1] == 'L' || s[i+1] == 'C')
                {
                    ans += (s[i+1] =='L'?40:90);
                    s[i+1] = 'Z';
                }
                else
                {
                    ans+=10;
                }
                break;
            
            case 'V':
                ans+=5;
                break;
            
            case 'I':
                if(s[i+1] == 'V' || s[i+1] == 'X')
                {
                    ans += (s[i+1] =='V'?4:9);
                    s[i+1] = 'Z';
                }
                else
                {
                    ans+=1;
                }
                break;

            case 'Z':
                ans+=0;
                break;
            
            default:
                break;
            }
        }
        return ans;
    }
};
// @lc code=end

