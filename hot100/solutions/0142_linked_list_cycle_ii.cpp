/*
 * 142. 环形链表 II（快慢指针定位入口）
 * 核心思路：相遇后令 one=head、two=相遇点，再同速移动；二者下一次相遇就是环入口。
 * 时间：O(n)；额外空间：O(1)。
 * 数学：2(a+b)=a+b+c+b => a=c，其中 a 是入口前距离，c 是环内剩余距离。
 */
#ifdef LOCAL_LEETCODE_TYPES
#include "list_node.h"
#endif

class Solution
{
public:
    ListNode *detectCycle(ListNode *head)
    {
        ListNode *slow = head, *fast = head;
        // 先用 Floyd 算法找到环内相遇点；无环时返回 nullptr。
        do
        {
            if (!fast || !fast->next) return nullptr;
            slow = slow->next;
            fast = fast->next->next;
        }
        while (slow != fast);

        slow = head;
        // 数学性质：从头节点和相遇点同步前进，第一次重合位置就是环入口。
        while (slow != fast)
        {
            slow = slow->next;
            fast = fast->next;
        }
        return slow;
    }
};
