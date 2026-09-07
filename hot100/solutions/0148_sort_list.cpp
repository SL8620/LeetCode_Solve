/*
 * 148. 排序链表（归并排序）
 * 核心思路：快慢指针断成两半，递归排序后按双指针合并两个有序链表。
 * 时间：O(n log n)；空间：O(log n) 递归栈。
 * 易错点：先让 slow 前进，slow 才会停在前半段尾部；合并时用哑结点避免边界特判。
 */
#ifdef LOCAL_LEETCODE_TYPES
#include "list_node.h"
#endif
#include <algorithm>
using namespace std;

class Solution
{
public:
    ListNode* sortList(ListNode* head)
    {
        if (!head || !head->next) return head;
        ListNode* slow = head;
        ListNode* fast = head->next;
        // slow 从 head 开始而 fast 从 head->next，保证 slow 最后落在前半段末尾。
        while (fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* right = slow->next;
        slow->next = nullptr;
        return merge(sortList(head), sortList(right));
    }

private:
    ListNode* merge(ListNode* a, ListNode* b)
    {
        ListNode dummy(0);
        ListNode* tail = &dummy;
        while (a && b)
        {
            if (a->val <= b->val)
            {
                tail->next = a; a = a->next;
            }
            else
            {
                tail->next = b; b = b->next;
            }
            tail = tail->next;
        }
        tail->next = a ? a : b;
        return dummy.next;
    }
};
