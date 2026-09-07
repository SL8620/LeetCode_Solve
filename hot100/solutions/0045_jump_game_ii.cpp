/*
 * 45. 跳跃游戏 II（分层贪心）
 * 核心思路：cur_end 是当前跳跃可达边界，far_end 是下一段最大边界；
 *       走到 cur_end 时才必须再跳一次。
 * 时间：O(n)；空间：O(1)。
 * 易错点：题目保证可达，所以无需处理不可达情况；只在边界端点加跳跃次数。
 */
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int jump(vector<int>& nums)
    {
        int jumps = 0, current_end = 0, farthest = 0;
        for (int i = 0; i + 1 < (int)nums.size(); ++i)
        {
            farthest = max(farthest, i + nums[i]);
            if (i == current_end)
            {
                // 到达当前层边界，必须再跳一次才能覆盖更远位置。
                ++jumps;
                current_end = farthest;
            }
        }
        return jumps;
    }
};
