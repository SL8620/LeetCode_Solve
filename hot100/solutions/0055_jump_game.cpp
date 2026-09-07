/*
 * 55. 跳跃游戏（贪心维护最远可达点）
 * 核心思路：扫描时更新 max_reachable；若 i 已越过可达点，则后面都无法到达。
 * 时间：O(n)；空间：O(1)。
 */
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    bool canJump(vector<int>& nums)
    {
        int reachable = 0;
        for (int i = 0; i < (int)nums.size(); ++i)
        {
            if (i > reachable)
            {
                return false; // 连当前下标都到不了，后面更无法到达
            }
            reachable = max(reachable, i + nums[i]);
            // reachable 统一保存从已访问位置能到达的最远下标。
            if (reachable >= (int)nums.size() - 1) return true;
        }
        return true;
    }
};
