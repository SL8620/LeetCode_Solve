/*

383. 赎金信
简单
相关标签
premium lock icon
相关企业
给你两个字符串：ransomNote 和 magazine ，判断 ransomNote 能不能由 magazine 里面的字符构成。
如果可以，返回 true ；否则返回 false 。
magazine 中的每个字符只能在 ransomNote 中使用一次。
 
示例 1：
输入：ransomNote = "a", magazine = "b"
输出：false

示例 2：
输入：ransomNote = "aa", magazine = "ab"
输出：false

示例 3：
输入：ransomNote = "aa", magazine = "aab"
输出：true
 
提示：

1 <= ransomNote.length, magazine.length <= 105
ransomNote 和 magazine 由小写英文字母组成
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) 
    {
        unordered_map<char, int> mp;
        for(char c : magazine)
        {
            auto it = mp.find(c);
            if(it != mp.end())
            {
                it->second++;
            }
            else
            {
                mp.insert({c, 1});
            }
        }
        
        int len = ransomNote.length();
        for(int i = 0; i < len; i++)
        {
            char ch = ransomNote[i];
            auto it = mp.find(ch);
            if(it != mp.end())
            {
                it->second--;
                if(it->second == 0)
                {
                    mp.erase(it);
                }
            }
            else
            {
                return false;
            }
        }
        return true;
    }
};