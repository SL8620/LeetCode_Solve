/*
 * @Author: SL8620 2584032673@qq.com
 * @Date: 2026-03-27 11:21:51
 * @LastEditors: SL8620 2584032673@qq.com
 * @LastEditTime: 2026-03-27 14:10:22
 * @FilePath: /LeetCode_Solve/home/lightwheel/Documents/leetcode/367.有效的完全平方数.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
/*
 * @lc app=leetcode.cn id=367 lang=cpp
 *
 * [367] 有效的完全平方数
 */

// @lc code=start
class Solution {
public:
    bool isPerfectSquare(int num) 
    {
        int st = 0;
        int ed = num;
        while(st < ed)
        {
            int mid = st + (ed-st)/2;
            long long int num0 = (long long int)mid * mid;
            long long int num1 = (long long int)(mid-1) * (mid-1);
            long long int num2 = (long long int)(mid+1) * (mid+1);

            if(num0 == num || num1 == num || num2 == num)
            {
                return true;
            }
            
            else if(num < num0) //接着往左找，更新右侧边界
            {
                if(num1 < num)
                {
                    return false;
                }
                else
                {
                    ed = mid;
                }
                
            }
            else if(num > num0) //接着往右找，更新左侧边界
            {
                if(num < num2)
                {
                    return false;
                }
                else
                {
                    st = mid+1;
                }
            }
        }
        return false;
        
    }
};
// @lc code=end

