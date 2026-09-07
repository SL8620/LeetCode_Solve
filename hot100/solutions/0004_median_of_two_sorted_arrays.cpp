/*
 * 4. 寻找两个正序数组的中位数（划分二分）
 * 核心思路：保证较短数组一侧为 cut1，使 left_half 总共有 (m+n+1)/2 个元素；
 *       调整 cut1，使 max_left <= min_right 且 max_right <= min_left。
 * 时间：O(log min(m,n))；空间：O(1)。
 * 易错点：空半边的边界值用 ±INF；左右总元素允许相差 1。
 */
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

class Solution
{
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2)
    {
        // 始终二分较短数组，保证 cut2 一定有效且复杂度最小。
        if (nums1.size() > nums2.size())
        {
            return findMedianSortedArrays(nums2, nums1);
        }
        int m = nums1.size(), n = nums2.size();
        int left_size = (m + n + 1) / 2;
        int left = 0, right = m;
        while (left <= right)
        {
            int cut1 = left + (right - left) / 2;
            int cut2 = left_size - cut1;
            int left1 = cut1 == 0 ? INT_MIN : nums1[cut1 - 1];
            int right1 = cut1 == m ? INT_MAX : nums1[cut1];
            int left2 = cut2 == 0 ? INT_MIN : nums2[cut2 - 1];
            int right2 = cut2 == n ? INT_MAX : nums2[cut2];
            // 两侧跨界顺序都正确，说明已经找到中位数划分。
            if (left1 <= right2 && left2 <= right1)
            {
                int left_max = max(left1, left2);
                if ((m + n) % 2) return left_max;
                return (left_max + min(right1, right2)) / 2.0;
            }
            if (left1 > right2)
            {
                right = cut1 - 1;
            }
            else
            {
                left = cut1 + 1;
            }
        }
        return 0.0;
    }
};
