<!--
 * @Author: SL8620
 * @Date: 2026-02-03 22:18:34
 * @LastEditTime: 2026-02-03 22:18:34
 * @LastEditors: SL8620
 * @Description: 
 * @FilePath: \.leetcode\note.md
 * 
-->
#include <unordered_map>

unordered_map<int, int> map;

// 插入
map[key] = value;           // O(1) 平均
map.insert({key, value});   // O(1) 平均

// 查询
if (map.find(key) != map.end()) {  // O(1) 平均
    int val = map[key];
}
if (map.count(key)) {              // O(1) 平均，更简洁
    int val = map[key];
}

// 删除
map.erase(key);             // O(1) 平均

// 遍历
for (auto& p : map) {
    int key = p.first;
    int val = p.second;
}

// 获取大小
int size = map.size();      // O(1)
bool empty = map.empty();   // O(1)
