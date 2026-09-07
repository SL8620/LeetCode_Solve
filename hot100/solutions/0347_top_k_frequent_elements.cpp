/*
 * 347. 前 K 个高频元素（哈希计数 + 桶排序）
 * 核心思路：频次最大不超过 n，用 buckets[frequency] 保存元素。
 * 时间：O(n)；空间：O(n)。
 * 易错点：桶从高频到低频遍历即可；同一桶内的顺序在题目不作要求时均可。
 */
#include <vector>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    vector<int> topKFrequent(vector<int>& nums, int k)
    {
        unordered_map<int,int> frequency;
        for (int value : nums)
        {
            ++frequency[value];
        }
        vector<vector<int>> buckets(nums.size() + 1);
        // 桶下标就是出现次数，范围天然限制在 [0,n]。
        for (auto [value, count] : frequency)
        {
            buckets[count].push_back(value);
        }
        vector<int> answer;
        // 从高频桶向低频桶收集，不需要对所有元素做比较排序。
        for (int count = buckets.size() - 1; count > 0 && (int)answer.size() < k; --count)
        {
            for (int value : buckets[count])
            {
                if ((int)answer.size() == k)
                {
                    break;
                }
                answer.push_back(value);
            }
        }
        return answer;
    }
};
