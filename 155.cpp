/*
155. 最小栈
中等
相关标签
premium lock icon
相关企业
提示
设计一个支持 push ，pop ，top 操作，并能在常数时间内检索到最小元素的栈。

实现 MinStack 类:

MinStack() 初始化堆栈对象。
void push(int value) 将元素 value 推入堆栈。
void pop() 删除堆栈顶部的元素。
int top() 获取堆栈顶部的元素。
int getMin() 获取堆栈中的最小元素。
 

示例 1:

输入：
["MinStack","push","push","push","getMin","pop","top","getMin"]
[[],[-2],[0],[-3],[],[],[],[]]

输出：
[null,null,null,null,-3,null,0,-2]

解释：
MinStack minStack = new MinStack();
minStack.push(-2);
minStack.push(0);
minStack.push(-3);
minStack.getMin();   --> 返回 -3.
minStack.pop();
minStack.top();      --> 返回 0.
minStack.getMin();   --> 返回 -2.
 

提示：

-231 <= val <= 231 - 1
pop、top 和 getMin 操作总是在 非空栈 上调用
push, pop, top, and getMin最多被调用 3 * 104 次
*/

#include <bits/stdc++.h>
using namespace std;

class MinStack {
public:
    vector<int> v;
    int minValue;
    MinStack() 
    {
        v.clear();
        minValue = INT_MAX;
    }
    
    void push(int value) 
    {
        v.push_back(value);
        if(value < minValue)
        {
            minValue = value;
        }
    }
    
    void pop() 
    {
        int topValue = v.back();
        if(topValue == minValue)
        {
            minValue = INT_MAX;
            for(int i=0; i<v.size()-1; i++)
            {
                if(v[i]<minValue)
                {
                    minValue = v[i];
                }
            }
        }
        if(!v.empty())
        {
            v.pop_back();
        }
    }
    
    int top() 
    {
        return v.back();
    }
    
    int getMin() 
    {
        return minValue;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(value);
            }
        }
        return minValue;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(value);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */