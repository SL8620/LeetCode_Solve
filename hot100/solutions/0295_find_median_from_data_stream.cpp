/*
 * 295. 数据流的中位数（对顶堆）
 * 核心思路：最大堆保存较小一半，最小堆保存较大一半；两堆最多相差 1 个元素。
 * 时间：插入 O(log n)，取中位数 O(1)；空间 O(n)。
 * 易错点：插入后先平衡数量，再检查是否要在左堆保存额外一个元素。
 */
#include <queue>
#include <vector>
#include <functional>
using namespace std;

class MedianFinder
{
private:
    priority_queue<int> left;                // 较小的一半，大顶堆
    priority_queue<int, vector<int>, greater<int>> right; // 较大的一半，小顶堆

public:
    MedianFinder()
    {
    }

    void addNum(int num)
    {
        left.push(num);
        // 先放到左侧，再把最大值送到右侧，维持 left 的值全部不大于 right。
        right.push(left.top());
        left.pop();
        if (right.size() > left.size())
        {
            // 左堆允许多一个元素，奇数长度时它就是中位数。
            left.push(right.top()); right.pop();
        }
    }

    double findMedian()
    {
        if (left.size() > right.size())
        {
            return left.top();
        }
        return (static_cast<double>(left.top()) + right.top()) / 2.0;
    }
};
