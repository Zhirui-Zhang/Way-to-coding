法1：并查集，和684类似，但是考虑的点更多了一些，一共有三种情况，分别是两种入度为2和一种形成环
另外好好总结下并查集的模板，别再在数组n个数上犯错了
时间O(N) 每次join函数都将最终的两个父节点相连，时间接近于O(N)  空间O(N)
执行用时：4 ms, 在所有 C++ 提交中击败了97.34% 的用户
内存消耗：9.2 MB, 在所有 C++ 提交中击败了82.39% 的用户
class Solution {
public:
    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        father.resize(n + 1);
        init(n + 1);                       // 初始化父节点数组，注意和indegree一样，都是n+1个节点
        vector<int> indegree(n + 1, 0);    // 定义入度数组，统计每个节点的入度
        for (int i = 0; i < n; ++i) {
            indegree[edges[i][1]]++;
        }
        vector<int> v;
        // 再次反向遍历edges，找入度为2的节点所对应的边，注意要倒序，因为优先返回最后出现在二维数组中的答案
        // 记录的i是边的下标值，也就是例[[1,2],[1,3],[2,3]]中记录的是i=2和i=1
        for (int i = n - 1; i >= 0; --i) {
            if (indegree[edges[i][1]] == 2) v.push_back(i);
        }
        if (!v.empty()) {
            // 若v不为空，说明有两条边使得某个节点入度为2，看删哪条边可以构成树
            if (isTreeAfterRemoveEdge(edges, v[0])) return edges[v[0]];
            else return edges[v[1]];
        }
        // 若v为空，说明是edges中存在环导致，其写法等同于684题，利用并查集，找到构成环的对应边
        for (int i = 0; i < n; ++i) {
            if (isSameFather(edges[i][0], edges[i][1])) return edges[i];    // 构成有向环了，就是要删除的边
            join(edges[i][0], edges[i][1]);
        }
        return {};
    }
private:
    vector<int> father;
    void init(int n) {
        // 初始化每个节点的根节点都是它自己
        for (int i = 0; i < n; ++i) {
            father[i] = i;
        }
    }
    int find(int i) {
        if (father[i] == i) return i;
        father[i] = find(father[i]);    // 如根不是自己，递归找根，并将下面节点的直接根都改为最顶层的根，加快搜索效率
        return father[i];
    }
    int isSameFather(int x, int y) {
        int f1 = find(x);
        int f2 = find(y);
        return f1 == f2;
    }
    void join(int x, int y) {
        int f1 = find(x);
        int f2 = find(y);
        if (f1 == f2) return ;
        father[f2] = f1;        // 一定要注意这里是分别找到两个节点的最终父节点，比较是否相同，若不相同，让两个最终父节点互相建立关系即可
    }
    bool isTreeAfterRemoveEdge(vector<vector<int>>& edges, int edgeNum) {
        for (int i = 0; i < edges.size(); ++i) {
            if (i == edgeNum) continue;         // 如果遇到当前删除边的下标，跳过不进行join操作
            if (isSameFather(edges[i][0], edges[i][1])) return false;   // 构成有向环了，一定不是树
            join(edges[i][0], edges[i][1]);
        }
        return true;
    }
};