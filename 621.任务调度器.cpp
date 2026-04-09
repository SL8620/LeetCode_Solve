/*
 * @Author: SL8620 2584032673@qq.com
 * @Date: 2026-04-08 13:41:30
 * @LastEditors: SL8620 2584032673@qq.com
 * @LastEditTime: 2026-04-08 15:52:47
 * @FilePath: /LeetCode_Solve/home/lightwheel/Documents/leetcode/621.任务调度器.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
/*
 * @lc app=leetcode.cn id=621 lang=cpp
 *
 * [621] 任务调度器
 */
#include<bits/stdc++.h>
using namespace std;

// @lc code=start


class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) 
    {
        int task_cnt[26];
        memset(task_cnt, 0, sizeof(task_cnt));

        int len = tasks.size();
        for(int i=0; i<len; i++)
        {
            int index = tasks[i] - 'A';
            task_cnt[index]++;
        }

        sort(task_cnt, task_cnt+26, [](int a, int b){ return a>b; });

        int max_cnt = task_cnt[0];
        int max_cnt_num = 1;
        for(int i=1; i<26; i++)
        {
            if(task_cnt[i] == max_cnt)
                max_cnt_num++;
            else
                break;
        }
        int ans = (max_cnt-1) * (n+1) + max_cnt_num;
        return max(ans, len);
        
    }
};
// @lc code=end

