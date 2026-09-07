/*
 * 128. 最长连续序列（哈希集）
 * 核心思路：只从“序列起点”开始向后数。若 x-1 不在集合中，x 就是某个序列的开头。
 * 时间：每个数只扩展一次，平均 O(n)；空间：O(n)。
 * 易错点：用普通集合的 find/insert，避免向集合中插入元素导致迭代器失效。
 */
#include <vector>
#include <unordered_set>
using namespace std;

class Solution
{
public:
    int longestConsecutive(vector<int>& nums)
    {
        // 集合会自动去重，也让每次 x+1 查询为平均 O(1)。
        unordered_set<int> values(nums.begin(), nums.end());
        int best = 0;
        for (int x : values)
        {
            // 只有 x-1 不存在时，x 才可能是某个连续序列的起点。
            if (values.count(x - 1)) continue;
            int end = x;
            while (values.count(end + 1)) ++end; // 向右数完整个连续区间
            best = max(best, end - x + 1);       // 序列长度包含两端
        }
        return best;
    }
};
