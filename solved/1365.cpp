#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) 
    {
        int len = nums.size();
        vector<int> res(len, 0);
        vector<int> dup(len, 0);
        unordered_map<int,int> mp;

        vector<int> tmp = nums;
        sort(nums.begin(), nums.end());
        for(int i=1; i<len; i++)
        {
            if(nums[i] == nums[i-1])
            {
                res[i] = res[i-1];
                dup[i] = dup[i-1] + 1;
            }
            else
            {
                res[i] = res[i-1] + dup[i-1] + 1;
            }
            mp.insert({nums[i], res[i]});
        }

        for(int i=0; i<len; i++)
        {
            res[i] = mp[tmp[i]];
        }

        return res;
    }
};