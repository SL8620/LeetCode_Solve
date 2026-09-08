/*
 * @lc app=leetcode.cn id=605 lang=cpp
 *
 * [605] 种花问题
 */

// @lc code=start
class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) 
    {
        int size = flowerbed.size();
        int left = 0;
        int right = 0;
        for(int i=1; i<size; i++)
        {
            // 左向右遍历 01 10 00
            // 00
            if(flowerbed[i]==0 && flowerbed[i-1]==0)
            {
                flowerbed[i-1] = 2;
                continue;
            }
            // 10
            else if(flowerbed[i]==0 && flowerbed[i-1] == )

        }
    }
};
// @lc code=end

