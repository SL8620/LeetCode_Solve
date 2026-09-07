/*
 * 141. 环形链表（Floyd 快慢指针）
 * 核心思路：有环时快指针最终会从后面追上慢指针。
 * 时间：O(n)；额外空间：O(1)。
 * 易错点：先判空，再保证 fast/fast->next 同时有效。
 */
#ifdef LOCAL_LEETCODE_TYPES
#include "list_node.h"
#endif

class Solution
{
public:
    bool hasCycle(ListNode *head)
    {
        ListNode *slow = head, *fast = head;
        // 先判断 fast/fast->next 有效，才能安全移动两步。
        while (fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast) return true;
        }
        return false;
    }
};
