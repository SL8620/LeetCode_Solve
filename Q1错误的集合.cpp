#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) 
    {
        int len = nums.size();
        vector<int> res;
        unordered_map<int,int> mp; 
        int dup;
        int lost;

        for(int i=0; i<len; i++)
        {
            auto it = mp.find(nums[i]);
            if(it != mp.end())  // 找到重复元素，直接赋值
            {
                dup = nums[i];
            }
            else
            {
                mp[nums[i]] = 1;
            }
        }

        for(int i=1; i<=len; i++)
        {
            auto it = mp.find(i);
            if(it == mp.end())  // 没找到，说明缺失
            {
                lost = i;
            }
        }
        res.push_back(dup);
        res.push_back(lost);
        
        return res;
    }
};