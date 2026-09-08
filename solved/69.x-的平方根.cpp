/*
 * @Author: SL8620 2584032673@qq.com
 * @Date: 2026-03-27 10:59:26
 * @LastEditors: SL8620 2584032673@qq.com
 * @LastEditTime: 2026-03-27 11:19:35
 * @FilePath: /LeetCode_Solve/home/lightwheel/Documents/leetcode/69.x-的平方根.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
/*
 * @lc app=leetcode.cn id=69 lang=cpp
 *
 * [69] x 的平方根 
 */

// @lc code=start
class Solution {
public:
    int mySqrt(int x) 
    {
        int st = 0;
        int ed = x;
        while(st < ed)
        {
            int mid = st + (ed-st)/2;
            long long int num = (long long int)mid * mid;
            long long int num2 = (long long int)(mid+1) * (mid+1);

            if(num <= x && num2 > x)
            {
                return mid;
            }
            else if(num > x) //接着往左找，更新右侧边界
            {
                ed = mid;
            }
            else if(num < x) //接着往右找，更新左侧边界
            {
                st = mid+1;
            }
        }
        return st;
    }
};
// @lc code=end

