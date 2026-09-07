/*
 * 138. 随机链表的复制（哈希映射原节点 -> 新节点）
 * 核心思路：第一遍创建所有新节点；第二遍设置 next 和 random。
 * 时间：O(n)；空间：O(n)。
 * 易错点：顺序应为“建节点→连关系”，不能在建节点时递归 random 导致重复创建。
 */
#ifdef LOCAL_LEETCODE_TYPES
#include "random_node.h"
#endif
#include <unordered_map>
using namespace std;

class Solution
{
public:
    Node* copyRandomList(Node* head)
    {
        if (!head) return nullptr;
        unordered_map<Node*, Node*> copied;
        Node* current = head;
        // 第一遍只建立一一对应，避免 random 指针造成递归重复创建。
        while (current)
        {
            copied[current] = new Node(current->val);
            current = current->next;
        }
        current = head;
        // 第二遍建立关系；不存在的节点通过 map 返回 nullptr。
        while (current)
        {
            copied[current]->next = copied[current->next];
            copied[current]->random = copied[current->random];
            current = current->next;
        }
        return copied[head];
    }
};
