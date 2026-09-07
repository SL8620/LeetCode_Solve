/*
 * 19. 删除链表的倒数第 N 个结点（前后指针）
 * 核心思路：先让 fast 走 n 步；再让二者一起走，fast 走完时，slow 正好停在待删节点前。
 * 时间：O(L)；额外空间：O(1)。
 * 易错点：使用哑结点处理删除头节点；fast 要停在第 n+1 个节点之前。
 */
#ifdef LOCAL_LEETCODE_TYPES
#include "list_node.h"
#endif

class Solution
{
public:
    ListNode* removeNthFromEnd(ListNode* head, int n)
    {
        ListNode dummy(0, head);
        ListNode* fast = &dummy;
        ListNode* slow = &dummy;
        // fast 先走 n 步，使两个指针保持 n 个节点的固定间隔。
        for (int i = 0; i < n; ++i)
        {
            fast = fast->next;
        }
        // fast 最后停在尾节点时，slow 正好位于待删节点之前。
        while (fast->next)
        {
            fast = fast->next;
            slow = slow->next;
        }
        ListNode* removed = slow->next;
        slow->next = removed->next;
        delete removed;
        return dummy.next;
    }
};
