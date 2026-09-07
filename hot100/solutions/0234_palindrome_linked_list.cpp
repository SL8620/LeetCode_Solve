/*
 * 234. 回文链表（快慢指针 + 反转后半段）
 * 核心思路：找到中点，反转后半段，再同时比较前后半段；比较完可恢复链表。
 * 时间：O(n)；额外空间：O(1)。
 * 易错点：奇数链表的中间节点属于前半段，比较时忽略即可。
 */
#ifdef LOCAL_LEETCODE_TYPES
#include "list_node.h"
#endif

class Solution
{
public:
    bool isPalindrome(ListNode* head)
    {
        ListNode* slow = head;
        ListNode* fast = head;
        // fast 速度是 slow 的两倍，找到后半段起点。
        while (fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* prev = nullptr;
        ListNode* current = slow;
        while (current)
        {
            ListNode* next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }
        ListNode* left = head;
        ListNode* right = prev;
        // right 是反转后的较短半段，奇数链表的中间节点不必比较。
        while (right)
        {
            if (left->val != right->val) return false;
            left = left->next;
            right = right->next;
        }
        return true;
    }
};
