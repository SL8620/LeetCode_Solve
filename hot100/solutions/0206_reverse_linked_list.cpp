/*
 * 206. 反转链表（迭代三指针）
 * 核心思路：prev 指向已反转部分，current 指向当前节点；先保存 next 再改指针。
 * 时间：O(n)；额外空间：O(1)。
 * 易错点：修改 current->next 之前必须先保存原 next。
 */
#ifdef LOCAL_LEETCODE_TYPES
#include "list_node.h"
#endif

class Solution
{
public:
    ListNode* reverseList(ListNode* head)
    {
        ListNode* prev = nullptr;
        ListNode* current = head;
        while (current)
        {
            // 先保存原后继，否则修改 next 后就找不到剩余链表了。
            ListNode* next = current->next;
            current->next = prev;           // 当前节点反向指向已反转部分
            prev = current;
            current = next;
        }
        return prev; // 遍历结束时 prev 是新的头节点
    }
};
