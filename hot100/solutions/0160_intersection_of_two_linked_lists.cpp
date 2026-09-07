/*
 * 160. 相交链表（双指针换头遍历）
 * 核心思路：两指针分别走完各自链表后切换到另一条头部；若相交，会在第二轮同起点同步相遇。
 * 时间：O(n+m)；额外空间：O(1)。
 * 易错点：指针到 nullptr 后切换到另一条链表，而不是立即返回 nullptr。
 */
#ifdef LOCAL_LEETCODE_TYPES
#include "list_node.h"
#endif

class Solution
{
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
    {
        ListNode* a = headA;
        ListNode* b = headB;
        while (a != b)
        {
            // 到达链表末尾后切换到另一条链表的头部，抵消两条链表长度差。
            a = a ? a->next : headB;
            b = b ? b->next : headA;
        }
        return a; // 两条链表相交时是交点；否则二者都为 nullptr。
    }
};
