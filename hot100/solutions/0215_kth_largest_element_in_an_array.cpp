/*
 * 215. 数组中的第K个最大元素（堆）
 * 核心思路：遍历时堆始终保留当前最大的 k 个元素，堆顶就是第 k 大。
 * 时间：O(n log k)；空间：O(k)。
 * 易错点：priority_queue 默认是大顶堆；求“前 k 个最大值的下界”要使用小顶堆。
 */
#include <vector>
#include <queue>
#include <functional>
using namespace std;

class Solution
{
public:
    int findKthLargest(vector<int>& nums, int k)
    {
        priority_queue<int, vector<int>, greater<int>> smallest_k;
        for (int value : nums)
        {
            smallest_k.push(value);
            if ((int)smallest_k.size() > k)
            {
                // 小顶堆只保留候选中较大的 k 个，堆顶就是第 k 大。
                smallest_k.pop();
            }
        }
        return smallest_k.top();
    }
};
