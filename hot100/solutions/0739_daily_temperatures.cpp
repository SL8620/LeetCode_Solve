/*
 * 739. 每日温度（单调递减栈）
 * 核心思路：栈保存“还没有找到更暖日期”的下标；遇到高温时弹出并计算答案。
 * 时间：O(n)；空间：O(n)。
 */
#include <vector>
#include <stack>
using namespace std;

class Solution
{
public:
    vector<int> dailyTemperatures(vector<int>& temperatures)
    {
        int n = temperatures.size();
        vector<int> answer(n, 0);
        stack<int> previous_cooler;
        for (int i = 0; i < n; ++i)
        {
            // 当前温度更高时，栈顶旧温度的第一个更暖日期就是 i。
            while (!previous_cooler.empty() &&
                   temperatures[i] > temperatures[previous_cooler.top()])
            {
                int j = previous_cooler.top(); previous_cooler.pop();
                answer[j] = i - j;
            }
            previous_cooler.push(i);
        }
        return answer;
    }
};
