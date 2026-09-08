/*
 * @Author: SL8620 2584032673@qq.com
 * @Date: 2026-04-08 17:24:05
 * @LastEditors: SL8620 2584032673@qq.com
 * @LastEditTime: 2026-04-08 18:57:52
 * @FilePath: /LeetCode_Solve/home/lightwheel/Documents/leetcode/92.反转链表-ii.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
/*
 * @lc app=leetcode.cn id=92 lang=cpp
 *
 * [92] 反转链表 II
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) 
    {
        if(left == right)
        {
            return head;
        }
        ListNode* st_prev;
        ListNode* ed_next;
        ListNode* st;
        ListNode* ed;
        int cnt=0;
        for(ListNode* node = head; node != nullptr; node = node->next)
        {
            cnt++;
            if(cnt == left)
            {
                st = node;
            }
            else if(cnt == right)
            {
                ed = node;
            }
            else if(cnt == left-1)
            {
                if(left-1 > 0)
                {
                    st_prev = node;
                }
                else
                {
                    st_prev = head;
                }
            }
            else if(cnt == right+1)
            {
                ed_next = node;
                break;
            }
        }

        ListNode* node_prev, *node_cur, *node_next;
        node_prev->next = nullptr;
        for(ListNode* node = st; node != ed; node = node->next)
        {
           node_cur = node;
           node_next = node->next;
           node->next = node_prev;
           node_prev = node_cur;
           node_cur = node_next;
           node_next = node_next->next;
        }
        st_prev->next = ed;
        ed->next = ed_next;

        return head;

    }
};
// @lc code=end

