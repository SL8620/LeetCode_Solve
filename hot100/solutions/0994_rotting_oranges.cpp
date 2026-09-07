/*
 * 994. 腐烂的橘子（多源 BFS）
 * 核心思路：把所有腐烂橘子同时加入队列；每一轮对应一分钟，向四周传播腐烂。
 * 时间：O(mn)；空间：O(mn)。
 * 易错点：轮换“剩余的新鲜橘子”计数，而不是统计所有新感染者再层层相减。
 */
#include <vector>
#include <queue>
using namespace std;

class Solution
{
public:
    int orangesRotting(vector<vector<int>>& grid)
    {
        int m = grid.size(), n = grid[0].size();
        int fresh = 0, minutes = 0;
        queue<pair<int,int>> q;
        // 所有腐烂源同时入队，下一轮才表示一分钟后的状态。
        for (int y = 0; y < m; ++y)
        {
            for (int x = 0; x < n; ++x)
            {
                if (grid[y][x] == 2)
                {
                    q.push({y, x});
                }
                else if (grid[y][x] == 1)
                {
                    ++fresh;
                }
            }
        }
        const int dy[] = {1,-1,0,0}, dx[] = {0,0,1,-1};
        while (!q.empty() && fresh > 0)
        {
            int level_size = q.size();
            for (int i = 0; i < level_size; ++i)
            {
                auto [y,x] = q.front(); q.pop();
                for (int d = 0; d < 4; ++d)
                {
                    int ny = y + dy[d], nx = x + dx[d];
                    if (ny < 0 || ny >= m || nx < 0 || nx >= n || grid[ny][nx] != 1)
                    {
                        continue;
                    }
                    grid[ny][nx] = 2; // 立即标记，避免同一橘子重复入队
                    --fresh;
                    q.push({ny,nx});
                }
            }
            ++minutes;
        }
        return fresh == 0 ? minutes : -1;
    }
};
