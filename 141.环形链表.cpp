/*
 * @Author: SL8620 2584032673@qq.com
 * @Date: 2026-04-08 16:29:39
 * @LastEditors: SL8620 2584032673@qq.com
 * @LastEditTime: 2026-04-08 17:17:21
 * @FilePath: /LeetCode_Solve/home/lightwheel/Documents/leetcode/141.环形链表.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
/*
 * @lc app=leetcode.cn id=141 lang=cpp
 *
 * [141] 环形链表
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */


class Solution {
public:
    bool hasCycle(ListNode *head) 
    {
        if(head == nullptr)
        {
            return false;
        }
        int visit = 100001;
        for(ListNode* node = head; node != nullptr; node = node->next)
        {
            if(node->val == visit)
            {
                return true;
            }
            node->val = visit;
        }
        return false;
    }
};
// @lc code=end

