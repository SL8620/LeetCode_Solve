/*
 * 287. 寻找重复数（Floyd 环检测）
 * 核心思路：把值 nums[x] 看作下标 x 的下一个节点；重复值导致两条路在环内相遇。
 * 时间：O(n)；额外空间：O(1)。
 * 易错点：数组中存在 n+1 个数、数值 1..n，因此不会跳出下标范围。
 */
#include <vector>
using namespace std;

class Solution
{
public:
    int findDuplicate(vector<int>& nums)
    {
        int slow = nums[0], fast = nums[0];
        // 把 nums[x] 当作下标 x 的 next，重复值会让多个前驱指向同一节点并形成环。
        do
        {
            slow = nums[slow];
            fast = nums[nums[fast]];
        }
        while (slow != fast);

        slow = nums[0];
        while (slow != fast)
        {
            slow = nums[slow];
            fast = nums[fast];
        }
        return slow;
    }
};
