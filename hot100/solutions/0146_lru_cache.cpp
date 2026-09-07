/*
 * 146. LRU 缓存（哈希表 + 双向链表）
 * 核心思路：哈希表 O(1) 找节点，双向链表维护“最近使用”顺序：头部最新，尾部最旧。
 * 每个操作 O(1)；空间 O(capacity)。
 * 易错点：删除/移动前先从哈希表和旧链表位置移除；回收尾节点。
 */
#include <unordered_map>
#include <list>
using namespace std;

class LRUCache
{
private:
    int capacity;
    list<pair<int,int>> recency; // pair<key,value>，front 最近使用
    unordered_map<int, list<pair<int,int>>::iterator> address;

public:
    LRUCache(int capacity) : capacity(capacity)
    {
    }

    int get(int key)
    {
        if (!address.count(key))
        {
            return -1;
        }
        // 使用过的节点移到链表前端，保持最近使用顺序。
        recency.splice(recency.begin(), recency, address[key]);
        return address[key]->second;
    }

    void put(int key, int value)
    {
        if (address.count(key))
        {
            recency.splice(recency.begin(), recency, address[key]);
            address[key]->second = value;
            return;
        }
        if ((int)recency.size() == capacity)
        {
            int oldest_key = recency.back().first;
            recency.pop_back();
            address.erase(oldest_key);
        }
        recency.emplace_front(key, value);
        address[key] = recency.begin();
    }
};
