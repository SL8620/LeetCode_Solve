/*
 * 200. 岛屿数量（DFS 淹没岛屿）
 * 核心思路：每遇到一个 '1' 就增加答案，并从它开始把整座岛改为 '0'，避免重复计数。
 * 时间：O(mn)；空间：O(mn) 最坏递归栈。
 * 易错点：DFS 要先判坐标合法，再判断网格值，避免越界。
 */
#include <vector>
using namespace std;

class Solution
{
private:
    int m, n;
    void dfs(vector<vector<char>>& grid, int y, int x)
    {
        // 坐标或字符不合法时立即返回，保证不会越界。
        if (y < 0 || y >= m || x < 0 || x >= n || grid[y][x] != '1')
        {
            return;
        }
        grid[y][x] = '0'; // 淹没当前陆地，防止同一座岛重复计数
        dfs(grid, y + 1, x);
        dfs(grid, y - 1, x);
        dfs(grid, y, x + 1);
        dfs(grid, y, x - 1);
    }

public:
    int numIslands(vector<vector<char>>& grid)
    {
        if (grid.empty() || grid[0].empty()) return 0;
        m = grid.size(); n = grid[0].size();
        int answer = 0;
        for (int y = 0; y < m; ++y)
        {
            for (int x = 0; x < n; ++x)
            {
                if (grid[y][x] == '1')
                {
                    ++answer;
                    dfs(grid, y, x);
                }
            }
        }
        return answer;
    }
};
