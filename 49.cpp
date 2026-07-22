#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) 
    {
        int len = strs.size();
        vector<vector<string>> res;
        unordered_map<string, vector<string>> mp;
        for(int i=0; i<len; i++)
        {
            string cur = strs[i];
            string findStr = cur;
            sort(findStr.begin(), findStr.end());
            auto it = mp.find(findStr);
            if(it!=mp.end())
            {
                it->second.push_back(cur);
            }
            else
            {
                vector<string> vs;
                vs.push_back(cur);
                mp[findStr] = vs;
            }
        }
        for(auto it: mp)
        {
            res.push_back(it.second);
        }
        
    }
};