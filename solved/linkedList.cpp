/*
 * @Author: SL8620 2584032673@qq.com
 * @Date: 2026-04-09 13:50:57
 * @LastEditors: SL8620 2584032673@qq.com
 * @LastEditTime: 2026-04-09 14:24:16
 * @FilePath: /leetcode/linkedList.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

struct linkedList
{
    int data;
    linkedList *next;
};

void printList(linkedList *head)
{
    linkedList *p = head;
    while(p != nullptr)
    {
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
}

linkedList* generateList(vector <int> &nums)
{
    linkedList *head = new linkedList{nums[0], nullptr};
    linkedList *p = head;
    for(int i=1; i<nums.size(); i++)
    {
        p->next = new linkedList{nums[i], nullptr};
        p = p->next;
    }
    return head;
}

void reverse(linkedList*& head)
{
    linkedList* prev = nullptr;
    linkedList* curr = head;

    while (curr != nullptr)
    {
        linkedList* next = curr->next; // 记住下一个节点
        curr->next = prev;             // 反指
        prev = curr;                   // 前移
        curr = next;                   // 前移
    }
    head = prev; // prev 为新的头节点
}

int main()
{
    vector<int> nums = {1, 2, 3, 4, 5};
    linkedList *head = generateList(nums);
    printList(head);
    reverse(head);
    printList(head);

    return 0;
}