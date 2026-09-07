/*
 * 155. 最小栈（单调栈）
 * 核心思路：每次 push 当前值与栈顶最小值中的较小者；栈顶始终保存到目前为止的最小值。
 * 时间：三个操作均摊 O(1)；空间 O(n)。
 * 易错点：push 时保存 min(min, value)，pop 时直接弹栈即可，不需要恢复旧最小值。
 */
#include <stack>
#include <algorithm>
using namespace std;

class MinStack
{
private:
    stack<pair<int,int>> values_and_min; // pair<当前值, 到该位置的最小值>

public:
    MinStack()
    {
    }

    void push(int val)
    {
        // 同时压入当前值和“截至该位置”的最小值，pop 后最小值自动回到上一层。
        int current_min = values_and_min.empty() ? val
                        : min(val, values_and_min.top().second);
        values_and_min.push({val, current_min});
    }

    void pop()
    {
        values_and_min.pop();
    }
    int top()
    {
        return values_and_min.top().first;
    }
    int getMin()
    {
        return values_and_min.top().second;
    }
};
