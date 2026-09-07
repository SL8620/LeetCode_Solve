/*
 * 21. 合并两个有序链表（哑结点 + 归并）
 * 核心思路：每轮比较两条链表头，把较小节点接到结果尾部；最后接上剩余部分。
 * 时间：O(n+m)；额外空间：O(1)（不计哑结点常数）。
 * 易错点：链表可能为空，返回 dummy.next 而不是 dummy。
 */
#ifdef LOCAL_LEETCODE_TYPES
#include "list_node.h"
#endif

class Solution
{
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2)
    {
        ListNode dummy(0);
        ListNode* tail = &dummy;
        while (list1 && list2)
        {
            if (list1->val <= list2->val)
            {
                tail->next = list1;
                list1 = list1->next;
            }
            else
            {
                tail->next = list2;
                list2 = list2->next;
            }
            tail = tail->next;
        }
        // 两条链表只会剩一条，直接接到结果尾部。
        tail->next = list1 ? list1 : list2;
        return dummy.next;
    }
};
