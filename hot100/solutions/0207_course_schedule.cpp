/*
 * 207. 课程表（有向图拓扑排序）
 * 核心思路：课程是点，先修关系是有向边；若不存在环，则可通过拓扑排序学完。
 * 时间：O(V+E)；空间：O(V+E)。
 * 易错点：每个点的入度只减少一次；处理完所有点才能判断全部课程可修。
 */
#include <vector>
#include <queue>
using namespace std;

class Solution
{
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites)
    {
        vector<vector<int>> graph(numCourses);
        vector<int> indegree(numCourses, 0);
        // previous -> course 是先修关系，course 的入度就是它尚未满足的依赖数。
        for (auto& requirement : prerequisites)
        {
            int course = requirement[0], previous = requirement[1];
            graph[previous].push_back(course);
            ++indegree[course];
        }
        queue<int> ready;
        for (int i = 0; i < numCourses; ++i)
        {
            if (indegree[i] == 0)
            {
                ready.push(i);
            }
        }
        int visited = 0;
        while (!ready.empty())
        {
            int course = ready.front(); ready.pop();
            ++visited;
            for (int next : graph[course])
            {
                if (--indegree[next] == 0)
                {
                    ready.push(next);
                }
            }
        }
        return visited == numCourses;
    }
};
