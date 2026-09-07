/*
 * 189. 轮转数组（三次反转）
 * 核心思路：先整体反转，再分别反转前 k%n 个元素和其余元素。
 * 时间：O(n)；额外空间：O(1)。
 * 易错点：k 可能大于 n，先取模防止越界或做多余旋转。
 */
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    void rotate(vector<int>& nums, int k)
    {
        int n = nums.size();
        k %= n; // 轮转 n 次后回到原状
        // 整体反转后，目标顺序就是后 k 个元素来到前面。
        reverse(nums.begin(), nums.end());
        reverse(nums.begin(), nums.begin() + k);
        reverse(nums.begin() + k, nums.end());
    }
};
