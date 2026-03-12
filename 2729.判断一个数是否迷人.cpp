/*
 * @Author: error: error: git config user.name & please set dead value or install git && error: git config user.email & please set dead value or install git & please set dead value or install git
 * @Date: 2026-03-12 11:18:10
 * @LastEditors: error: error: git config user.name & please set dead value or install git && error: git config user.email & please set dead value or install git & please set dead value or install git
 * @LastEditTime: 2026-03-12 11:32:37
 * @FilePath: /LeetCode_Solve/home/lightwheel/Documents/leetcode/2729.判断一个数是否迷人.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
/*
 * @lc app=leetcode.cn id=2729 lang=cpp
 *
 * [2729] 判断一个数是否迷人
 */

// @lc code=start
class Solution {
public:
    bool isFascinating(int n) 
    {
        string n1 = to_string(1*n);
        string n2 = to_string(2*n);
        string n3 = to_string(3*n);

        string judge = n1 + n2 + n3;

        int count[10] = {0};
        for(int i=0; i<judge.size(); i++)
        {
            int num = judge[i]-'0';
            if(num==0 || count[num] == 1)
            {
                return false;
            }
            count[num]++;
        }

        for(int i=1;i<10; i++)
        {
            if(count[i] == 0)
            {
                return false;
            }
        }
        
        return true;
        
    }
};
// @lc code=end

