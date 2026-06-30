#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) 
    {
        vector<int> res;
        int len = nums.size();

        unordered_map<int,int> mp;
        for(int i=0; i<len; i++)
        {
            mp[nums[i]] = 1;
        }

        for(int i=1; i<=len; i++)
        {
            auto it = mp.find(i);
            if(it == mp.end())  // 没找到，说明缺失
            {
                res.push_back(i);
            }
        }

        return res;
        
    }
};