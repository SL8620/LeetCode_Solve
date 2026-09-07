/*
 * 25. K 个一组翻转链表（分组迭代反转）
 * 核心思路：先探测当前是否还有 k 个节点；有则反转 [head,next_group)，再把两组接起来。
 * 时间：O(n)；额外空间：O(1)。
 * 易错点：不足 k 个的尾部必须保持原顺序；连接反转组时需要单独保存前驱和新尾。
 */
#ifdef LOCAL_LEETCODE_TYPES
#include "list_node.h"
#endif

class Solution
{
public:
    ListNode* reverseKGroup(ListNode* head, int k)
    {
        ListNode dummy(0, head);
        ListNode* group_prev = &dummy;
        while (true)
        {
            ListNode* probe = group_prev;
            // 先探测当前组是否还有 k 个节点，不足时保持尾部原顺序。
            for (int i = 0; i < k; ++i)
            {
                probe = probe->next;
                if (!probe)
                {
                    return dummy.next;
                }
            }
            ListNode* group_head = group_prev->next;
            ListNode* next_group = probe->next;
            ListNode* prev = next_group;
            ListNode* current = group_head;
            while (current != next_group)
            {
                ListNode* next = current->next;
                current->next = prev; // 用上一次已处理的节点作为当前节点的前驱
                prev = current;
                current = next;
            }
            group_prev->next = prev;
            group_prev = group_head; // 原来的组头变成反转组的新尾
        }
    }
};
