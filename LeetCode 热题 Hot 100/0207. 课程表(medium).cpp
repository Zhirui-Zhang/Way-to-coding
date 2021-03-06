法1：DFS，此题DFS比BFS好理解
本质为拓扑排序题，计算每个节点的入度并统计所有边，最后将每个入度为0的节点依次入队，遍历每条边看是否会形成环，如果最后入度为0的节点数=num，说明不存在环，返回true
例题题解记事本中有
时间O(M+N) n为课程数，m为先修课程数  空间O(M+N) 其中邻接表存储空间为O(M+N)，队列q空间为O(N)
执行用时：12 ms, 在所有 C++ 提交中击败了98.09% 的用户
内存消耗：13.7 MB, 在所有 C++ 提交中击败了31.50% 的用户
class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> indegree(numCourses, 0);        // 记录每个节点的入度，初始为n个0
        vector<vector<int>> edges(numCourses);      // 用！邻接表（并非邻接矩阵）！记录每条边，先初始n个数组，之后遍历时再push_back每条对应边的节点

        for(auto pre : prerequisites)
        {
            ++indegree[pre[0]];                     // 对每个课程对进行入度++和对应边的记录，注意pre[0]和pre[1]别搞混了
            edges[pre[1]].push_back(pre[0]);
        }

        queue<int> q;                               // 建立bfs队列，对每个初始入度为0的点入队，即可以先修的课程
        for(int i = 0; i < indegree.size(); ++i)    // ！！！注意这里不能用auto :进行遍历，因为判断=0的是每个值indegree[i]，而需要存储的是序号i
        {
            if(indegree[i] == 0)    q.push(i);
        }
        
        int res = 0;                                // 初始一个值0，当每个入度为0的节点出队时+1，最后返回时若res!=num说明存在环
        while(!q.empty())
        {
            int temp = q.front();
            q.pop();
            ++res;
            for(auto i : edges[temp])               // 这里就可以用auto : 因为i就表示每个节点的下标，可以在indegree数组中访问
            {
                --indegree[i];
                if(indegree[i] == 0)    q.push(i);
            }
        }

        return res == numCourses;
    }
};

法2：BFS，直接套用官方答案，可以简单看下
复杂度不变
class Solution {
private:
    vector<vector<int>> edges;
    vector<int> visited;
    bool valid = true;

public:
    void dfs(int u) {
        visited[u] = 1;
        for (int v: edges[u]) {
            if (visited[v] == 0) {
                dfs(v);
                if (!valid) {
                    return;
                }
            }
            else if (visited[v] == 1) {
                valid = false;
                return;
            }
        }
        visited[u] = 2;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        edges.resize(numCourses);
        visited.resize(numCourses);
        for (const auto& info: prerequisites) {
            edges[info[1]].push_back(info[0]);
        }
        for (int i = 0; i < numCourses && valid; ++i) {
            if (!visited[i]) {
                dfs(i);
            }
        }
        return valid;
    }
};
