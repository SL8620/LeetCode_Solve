#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) 
    {
        unordered_map<int, int> mp;
        vector<int> res;
        int len = nums.size();
        for(int i=0; i<len; i++)
        {
            int cur = nums[i];

            // 先查表，没有就存入
            auto it = mp.find(cur);
            if(it == mp.end())
            {
                mp[cur] = i;
            }
            
            int diff = target - cur;
            it = mp.find(diff);
            if(it != mp.end() && it->second != i)
            {
                res.push_back(it->second);
                res.push_back(i);
                break;
            }
        }
        return res;
    }
};