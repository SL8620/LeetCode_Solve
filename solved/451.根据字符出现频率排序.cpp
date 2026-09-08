/*
 * @Author: SL8620 2584032673@qq.com
 * @Date: 2026-04-09 14:25:38
 * @LastEditors: SL8620 2584032673@qq.com
 * @LastEditTime: 2026-04-09 14:45:33
 * @FilePath: /leetcode/451.根据字符出现频率排序.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
/*
 * @lc app=leetcode.cn id=451 lang=cpp
 *
 * [451] 根据字符出现频率排序
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    string frequencySort(string s) 
    {
        unordered_map<char, int> figure_count;
        int len = s.size();
        for(int i=0; i<len; i++)
        {
            char ch = s[i];
            auto it = figure_count.find(ch);

            // 找到的情况，计数+1
            if(it != figure_count.end())
            {
                it->second += 1;
            }
            // 没找到，插入
            else
            {
                figure_count.insert({ch, 1});
            }
        }

        //排序
        vector<pair<char, int>> fig;
        for(const auto& pair : figure_count)
        {
            fig.push_back(pair);
        }
        sort(fig.begin(), fig.end(), [](const auto&a, const auto&b){
            return a.second > b.second;  //降序
        });

        string ss;

        for(const auto& pair : fig)
        {
            for(int i=0; i<pair.second; i++)
            {
                ss+=pair.first;
            }
        }
        return ss;
    }
};
// @lc code=end

