/*
 * 24. 两两交换链表中的节点（哑结点 + 迭代）
 * 核心思路：保存 a、b 及下一组起点，交换 a/b 的指向，再移动到下一组。
 * 时间：O(n)；额外空间：O(1)。
 * 易错点：交换前先保存 pair_head->next->next，否则会丢失后续链表。
 */
#ifdef LOCAL_LEETCODE_TYPES
#include "list_node.h"
#endif

class Solution
{
public:
    ListNode* swapPairs(ListNode* head)
    {
        ListNode dummy(0, head);
        ListNode* pair_prev = &dummy;
        while (pair_prev->next && pair_prev->next->next)
        {
            ListNode* a = pair_prev->next;
            ListNode* b = a->next;
            ListNode* after = b->next; // 必须先保存下一组，否则交换时会断链
            // 重新连接 b->a->after，并让 a 成为下一组交换的前驱。
            b->next = a;
            a->next = after;
            pair_prev->next = b;
            pair_prev = a; // a 变成下一组的前驱
        }
        return dummy.next;
    }
};
