#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) 
    {
        int len = nums.size();
        vector<int> ans;

        unordered_set<int> s;
        for(int i = 0; i < len; i++)
        {
            s.insert(nums[i]);
        }

        for(int i = 1; i <= len; i++)
        {
            if(s.find(i) == s.end())
            {
                ans.push_back(i);
            }
        }
        return ans;
    }
};