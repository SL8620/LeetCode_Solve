/*
 * 208. 实现 Trie (前缀树)（前缀树）
 * 核心思路：每个节点保存 26 个子节点指针和“是否为完整单词”标记。
 * insert/search/startsWith 均 O(L)。
 * 易错点：search 必须检查 terminal；startsWith 只要路径存在即可。
 */
#include <string>
using namespace std;

class Trie
{
private:
    struct TrieNode
    {
        TrieNode* children[26]{};
        bool terminal = false;
    };
    TrieNode* root;

    static int index(char c)
    {
        return c - 'a';
    }

public:
    Trie() : root(new TrieNode())
    {
    }

    void insert(const string& word)
    {
        TrieNode* node = root;
        for (char c : word)
        {
            if (!node->children[index(c)])
            {
                // 不存在对应前缀时才创建新节点，已有路径可直接复用。
                node->children[index(c)] = new TrieNode();
            }
            node = node->children[index(c)];
        }
        node->terminal = true;
    }

    bool search(const string& word)
    {
        TrieNode* node = find(word);
        return node && node->terminal;
    }

    bool startsWith(const string& prefix)
    {
        return find(prefix) != nullptr;
    }

private:
    TrieNode* find(const string& text)
    {
        TrieNode* node = root;
        for (char c : text)
        {
            node = node->children[index(c)];
            if (!node)
            {
                return nullptr; // 路径中断，说明该前缀不存在
            }
        }
        return node;
    }
};
