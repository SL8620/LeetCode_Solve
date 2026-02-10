/*** 
 * @Author: SL8620
 * @Date: 2026-02-09 19:26:16
 * @LastEditTime: 2026-02-09 20:13:31
 * @LastEditors: SL8620
 * @Description: 
 * @FilePath: \.leetcode\21.合并两个有序链表.cpp
 * @
 */
/*
 * @lc app=leetcode.cn id=21 lang=cpp
 *
 * [21] 合并两个有序链表
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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) 
    {
        ListNode* head = new ListNode();
        ListNode* tail = new ListNode();
        head->next = tail;

        if(list1 == nullptr && list2 == nullptr)
        {
            return nullptr;
        }
        
        // 均为非空时正常运行
        while(list1 != nullptr || list2!=nullptr)
        {
            int l1_val = 101;
            int l2_val = 101;

            if(list1!=nullptr)
            {
                l1_val = list1->val;
            }
            if(list2!=nullptr)
            {
                l2_val = list2->val;
            }

            if(l1_val <= l2_val)
            {
                tail->next = list1;
                list1 = list1->next;
                tail = tail->next;
            }
            else
            {
                tail->next = list2;
                list2 = list2->next;
                tail = tail->next;
            }
        }
        return (head->next)->next;
    }
};
// @lc code=end

