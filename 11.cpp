#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) 
    {
        int st = 0;
        int ed = height.size() - 1;
        int maxarea = 0;
        while(st < ed)
        {
            int width = ed - st;
            int area = min(height[st], height[ed]) * width;
            area = max(area, maxarea);
            maxarea = area;

            if(height[st] < height[ed])
            {
                st++;
            }
            else
            {
                ed--;
            }
        }
        return maxarea;
    }
};