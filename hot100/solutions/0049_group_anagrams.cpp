/*
 * 49. 字母异位词分组（哈希表 + 字符串规范化）
 * 核心思路：互为字母异位词的字符串排序后完全相同，所以排序结果可作为“桶键”。
 * 时间：O(n*klogk)，k 为单词平均长度；空间：O(n*k)。
 * 易错点：返回类型是 vector<vector<string>>，分组后顺序只要合理即可。
 */
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs)
    {
        unordered_map<string, vector<string>> groups;
        for (const string& word : strs)
        {
            string key = word;
            sort(key.begin(), key.end()); // 异位词排序后得到相同签名
            groups[key].push_back(word);  // 签名相同的词自动进入同一个桶
        }
        vector<vector<string>> answer;
        for (auto& [key, group] : groups)
        {
            // 原始字符串已经放进分组，直接搬走可避免额外复制。
            answer.push_back(move(group));
        }
        return answer;
    }
};
