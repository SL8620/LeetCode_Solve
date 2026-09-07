/*
 * 2. 两数相加（链表模拟加法）
 * 核心思路：逐位相加并记录进位；当还有进位或链表未结束时继续创建节点。
 * 时间：O(max(n,m))；空间：O(max(n,m))。
 * 易错点：循环条件包含 carry；进位是 (sum)/10，当前位是 (sum)%10。
 */
#ifdef LOCAL_LEETCODE_TYPES
#include "list_node.h"
#endif

class Solution
{
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
    {
        ListNode dummy(0);
        ListNode* tail = &dummy;
        int carry = 0;
        // carry 也参与循环，最高位产生的新进位需要再建一个节点。
        while (l1 || l2 || carry)
        {
            int sum = carry;
            if (l1)
            {
                sum += l1->val;
                l1 = l1->next;
            }
            if (l2)
            {
                sum += l2->val;
                l2 = l2->next;
            }
            carry = sum / 10;
            tail->next = new ListNode(sum % 10);
            tail = tail->next;
        }
        return dummy.next;
    }
};
