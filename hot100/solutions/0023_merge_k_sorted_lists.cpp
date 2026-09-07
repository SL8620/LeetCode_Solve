/*
 * 23. 合并 K 个升序链表（最小堆）
 * 核心思路：堆中始终保存每条链表当前未取节点，每次弹出全局最小节点并接上下一个。
 * 时间：O(n log k)；空间：O(k)。
 * 易错点：比较器要以链表值从小到大为方向，C++ greater 表示小顶堆。
 */
#ifdef LOCAL_LEETCODE_TYPES
#include "list_node.h"
#endif
#include <queue>
#include <vector>
using namespace std;

class Solution
{
public:
    ListNode* mergeKLists(vector<ListNode*>& lists)
    {
        priority_queue<ListNode*, vector<ListNode*>, greater<ListNode*>> heap;
        for (ListNode* node : lists)
        {
            if (node)
            {
                heap.push(node);
            }
        }
        ListNode dummy(0);
        ListNode* tail = &dummy;
        // 堆顶始终是 k 条链表当前可用节点中的最小值。
        while (!heap.empty())
        {
            ListNode* current = heap.top();
            heap.pop();
            if (current->next)
            {
                heap.push(current->next);
            }
            tail->next = current;
            tail = current;
        }
        return dummy.next;
    }
};
