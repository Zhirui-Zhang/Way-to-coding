法1：BFS+并查集，与399除法求值有点类似，
时间O(N^2)  空间O(N)
执行用时：16 ms, 在所有 C++ 提交中击败了7.43% 的用户
内存消耗：12.2 MB, 在所有 C++ 提交中击败了5.00% 的用户
class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        unordered_map<int, vector<int>> visited;        // 记录每个节点后面对应有多少条边
        visited[edges[0][0]].push_back(edges[0][1]);    // 先加入1：2  2：1这一对边
        visited[edges[0][1]].push_back(edges[0][0]);
        for (int i = 1; i < n; ++i) {
            int x = edges[i][0], y = edges[i][1];
            if (visited.find(x) != visited.end()) {     // 如果已经存储过节点，BFS查看是否形成环
                vector<bool> tmp(n, false);             // 建立一个数据，记录是否已经遍历过当前节点
                tmp[x] = true;
                queue<int> q;
                q.push(x);
                while (!q.empty()) {
                    int a = q.front();
                    q.pop();
                    for (auto v : visited[a]) {         // 遍历当前节点对应的所有未被访问过的边，若等于y说明形成环，返回{x, y}
                        if (v == y) return {x, y};
                        if (!tmp[v]) {
                            tmp[v] = true;
                            q.push(v);
                        }
                    }
                }
            }
            visited[x].push_back(y);                    // 将对应的边存入无向图
            visited[y].push_back(x);
        }     
        return {-1, -1};                                // 若不存在随意返回，由于本题目规定一定存在，这一条就没必要了
    }
};

代码随想录的并查集代码，确实比我的强不少，唉
时间O(N)由于每次递归都修改最终根，时间复杂度近似于O(N)  空间O(N)
执行用时：4 ms, 在所有 C++ 提交中击败了95.48% 的用户
内存消耗：8.4 MB, 在所有 C++ 提交中击败了91.10% 的用户
class Solution {
private:
    // 题目中最长为1000个节点
    int father[1001];   

    // 并查集初始化，使每个节点原始的根是它自己
    void init(int n) {
        for (int i = 0; i <= n; ++i) {
            father[i] = i;
        }
    }
    // 并查集里寻根的过程
    int find(int u) {
        if (u == father[u]) return u;   // 如果根是自己，直接返回
        father[u] = find(father[u]);    // 否则递归找根，并将下面节点的直接根都改为最顶层的根，其实可以不改的，但是改了效率更高
        return father[u];               // 若不改，就是直接 return find(father[u])
    }
    // 将v->u 这条边加入并查集
    void join(int u, int v) {
        u = find(u);
        v = find(v);
        if (u == v) return ;
        father[v] = u;  // 一定要注意这里是分别找到两个节点的最终父节点，比较是否相同，若不相同，让两个最终父节点互相建立关系即可
    }
    // 判断 u 和 v是否找到同一个根
    bool same(int u, int v) {
        u = find(u);
        v = find(v);
        return u == v;
    }
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        init(n);
        for (int i = 0; i < n; i++) {
            if (same(edges[i][0], edges[i][1])) return edges[i];
            else join(edges[i][0], edges[i][1]);
        }
        return {};  // 随意返回
    }
};