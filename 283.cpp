/*
283. 移动零
已解答
简单
相关标签
premium lock icon
相关企业
提示
给定一个数组 nums，编写一个函数将所有 0 移动到数组的末尾，同时保持非零元素的相对顺序。
请注意 ，必须在不复制数组的情况下原地对数组进行操作。


示例 1:
输入: nums = [0,1,0,3,12]
输出: [1,3,12,0,0]
示例 2:
输入: nums = [0]
输出: [0]
 
提示:

1 <= nums.length <= 104
-231 <= nums[i] <= 231 - 1

*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) 
    {
        int len = nums.size();
        if(len == 0 || len == 1)
        {
            return;
        }

        // 双指针法
        int left = 0;
        for(int right = 0; right < len; right++)
        {
            if(nums[right] != 0)
            {
                swap(nums[left], nums[right]);
                left++; 
            }
        }   

        
    }
};