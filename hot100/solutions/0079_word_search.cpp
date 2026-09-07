/*
 * 79. 单词搜索（网格回溯）
 * 核心思路：从每个匹配首字母的位置 DFS；临时把访问过的格子改为非字母，递归后恢复。
 * 时间：最坏 O(mn*3^L)；空间：O(L)。
 * 易错点：不能使用全局 bool 网格却不恢复；本题题目保证不会修改原网格内容（恢复后等价）。
 */
#include <string>
#include <vector>
using namespace std;

class Solution
{
private:
    int m, n;
    bool dfs(vector<vector<char>>& board, const string& word,
             int y, int x, int index)
    {
        if (y < 0 || y >= m || x < 0 || x >= n || board[y][x] != word[index])
        {
            return false;
        }
        if (index == (int)word.size() - 1)
        {
            return true;
        }
        char saved = board[y][x];
        board[y][x] = '#'; // 标记当前路径，防止同一格在一条路径中被重复使用
        bool found = dfs(board, word, y + 1, x, index + 1) ||
                     dfs(board, word, y - 1, x, index + 1) ||
                     dfs(board, word, y, x + 1, index + 1) ||
                     dfs(board, word, y, x - 1, index + 1);
        board[y][x] = saved; // 回溯恢复，其他路径仍可使用这个格子
        return found;
    }

public:
    bool exist(vector<vector<char>>& board, const string& word)
    {
        if (board.empty())
        {
            return false;
        }
        m = board.size(); n = board[0].size();
        // 每个格子都可能成为单词起点，因此从左上到右下逐一尝试。
        for (int y = 0; y < m; ++y)
        {
            for (int x = 0; x < n; ++x)
            {
                if (dfs(board, word, y, x, 0))
                {
                    return true;
                }
            }
        }
        return false;
    }
};
