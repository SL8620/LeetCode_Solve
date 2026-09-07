/*
 * 51. N 皇后（回溯 + 位集）
 * 核心思路：逐行放后，cols/diag1/diag2 记录已占用列与两条对角线。
 * 时间：约 O(N!)；空间 O(N)（仅计每行临时数据）。
 * 易错点：从左到右放时 diag1=x+row 始终递减，diag2=x-row 可能为负，需平移索引。
 */
#include <string>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution
{
private:
    int n;
    vector<string> board;
    vector<vector<string>> answer;
    unordered_set<int> cols, diag1, diag2;

    void dfs(int row)
    {
        if (row == n)
        {
            answer.push_back(board);
            return;
        }
        for (int x = 0; x < n; ++x)
        {
            // 同一主/副对角线上的坐标分别保持 row+col、row-col+常数。
            int d1 = row + x, d2 = row - x + n - 1;
            if (cols.count(x) || diag1.count(d1) || diag2.count(d2))
            {
                continue;
            }
            cols.insert(x); diag1.insert(d1); diag2.insert(d2);
            board[row][x] = 'Q';
            dfs(row + 1);
            cols.erase(x); diag1.erase(d1); diag2.erase(d2); // 撤销当前列状态
            board[row][x] = '.';
        }
    }

public:
    vector<vector<string>> solveNQueens(int n)
    {
        this->n = n;
        board.assign(n, string(n, '.'));
        dfs(0);
        return answer;
    }
};
