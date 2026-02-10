/*
 * @lc app=leetcode.cn id=9 lang=cpp
 *
 * [9] 回文数
 */

// @lc code=start
class Solution {
public:
    bool isPalindrome(int x) 
    {
        // 特判，负数,10的倍数都不是
        if (x==0)
        {
            return true;
        }

        if(x<0 || x%10==0)
        {
            return false;
        }

        int reverse[32];
        long int reverseSum = 0;
        memset(reverse,0,sizeof(reverse));
        int bits = 0;
        int temp_x = x;

        while (temp_x>0)
        {
            int last = temp_x%10;
            reverse[bits] = last;
            temp_x/=10;
            bits++;
        }

        if(reverse[0]!= reverse[bits-1])
        {
            return false;
        }

        for(int i=0;i<bits;i++)
        {
            reverseSum = reverseSum*10;
            reverseSum += reverse[i];
        }
        
        if(reverseSum == x)
        {
            return true;
        }
        else
        {
            return false;
        }
        
        
    }
};
// @lc code=end

