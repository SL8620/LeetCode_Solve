/*
 * 560. 和为 K 的子数组（前缀和 + 哈希）
 * 核心思路：若 prefix[j] - prefix[i] == k，则区间 [i+1,j] 的和为 k。
 *       出现 prefix=k 时代表从数组开头开始的区间。
 * 时间：O(n)；空间：O(n)。
 * 易错点：哈希表初始放入前缀和 0 出现一次；这里不能排序或用双指针，因为存在负数。
 */
#include <vector>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    int subarraySum(vector<int>& nums, int k)
    {
        unordered_map<long long, int> count;
        count[0] = 1; // 表示“还没有读取任何元素”的前缀和
        long long prefix = 0;
        int answer = 0;
        for (int value : nums)
        {
            prefix += value; // prefix 是从数组开头到当前位置的和
            // prefix - earlier = k 时，中间区间 [earlier+1, right] 的和为 k。
            if (count.count(prefix - k)) answer += count[prefix - k];
            // 最后才记录当前前缀，避免把长度为 0 的区间算进去。
            ++count[prefix];
        }
        return answer;
    }
};
