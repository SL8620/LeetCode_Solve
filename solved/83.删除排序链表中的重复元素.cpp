/*
 * @Author: SL8620 2584032673@qq.com
 * @Date: 2026-04-08 16:03:49
 * @LastEditors: SL8620 2584032673@qq.com
 * @LastEditTime: 2026-04-08 16:28:32
 * @FilePath: /LeetCode_Solve/home/lightwheel/Documents/leetcode/83.删除排序链表中的重复元素.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
/*
 * @lc app=leetcode.cn id=83 lang=cpp
 *
 * [83] 删除排序链表中的重复元素
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
    ListNode* deleteDuplicates(ListNode* head) 
    {
        for(ListNode* p=head; p!=nullptr ; p=p->next)
        {
            int val = p->val;

            if(p->next != nullptr)
            {
                ListNode* finder = p->next;
                int val_next = finder->val;
                
                while(val_next == val)
                {
                    if(finder->next != nullptr)
                    {
                        finder = finder->next;
                        val_next = finder->val;
                    }
                    else // 到最后都是重复元素
                    {
                        p->next = nullptr;
                        return head; 
                    }
                }

                p->next = finder;

            }
            else
            {
                break;
            }
        }

        return head;
    }
};
// @lc code=end

