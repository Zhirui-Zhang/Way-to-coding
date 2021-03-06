法1：BFS广度优先，只考虑向右和向下搜索即可，重点在于如何判断该节点已被访问（利用visited[][]数组）以及如何存放每一个节点对（queue<pair<int, int>> q）
执行用时：4 ms, 在所有 C++ 提交中击败了56.47% 的用户
内存消耗：6.5 MB, 在所有 C++ 提交中击败了68.59% 的用户
class Solution {
public:
    int movingCount(int m, int n, int k) {
        // visited数组判断是否已经访问过，访问过则为真，这里的初始化情况为visited是m行个每行为n个false的数组
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        // 队列q存放数组对，注意用pair存储的话，访问时需要 .first 和 .second
        queue<pair<int, int>> q;
        q.push({0, 0});
        int res = 0;
        visited[0][0] = true;
        while (!q.empty()) {
            auto front = q.front();     // 搞不清楚什么类型时用auto!!!实际 front 类型为 pair<int, int>
            q.pop();
            int x = front.first, y = front.second;
            res++;
            for (auto d : directions)   // d 也是pair<int, int>，依次为(0,1) 和 (1,0)
            {
                int new_x = x + d.first;
                int new_y = y + d.second;
                //当横纵小于m,n且数位和小于k且数组对未被访问时加入队列并置为真；否则继续循环，
                if (new_x < m && new_y < n && !visited[new_x][new_y] && sumDigit(new_x, new_y) <= k) 
                {
                    q.push({new_x, new_y});
                    visited[new_x][new_y] = true;
                } 
            }
        }
        return res;
    }
    // 计算两坐标数位和函数
    int sumDigit(int i, int j) {
        int sum = 0;
        while (i > 0) 
        {
            sum += i % 10;
            i /= 10;
        }
        while (j > 0) 
        {
            sum += j % 10;
            j /= 10;
        }
        return sum;
    }
private:
    vector<pair<int, int>> directions = {{0, 1}, {1, 0}};   //仅仅向右或者向下遍历
};

法2：DFS深度优先，想明白DFS了就并不难，注意细节例如传入visited数组中注意用引用！！！
执行用时：4 ms, 在所有 C++ 提交中击败了56.47% 的用户
内存消耗：6.4 MB, 在所有 C++ 提交中击败了75.69% 的用户
class Solution {
public:
    int DFS(vector<vector<bool>>& visited, int m, int n, int i, int j, int k)
    {
        if(i >= m || j >= n || visited[i][j] || sumDigit(i, j) > k)    return 0;    // 注意退出条件！
        visited[i][j] = true;
        return 1 + DFS(visited, m, n, i + 1, j, k) + DFS(visited, m, n, i, j + 1, k);
    }
    int movingCount(int m, int n, int k) 
    {
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        int res = 0;
        res = DFS(visited, m, n, 0, 0, k);
        return res;
    }

    // 计算两坐标数位和函数
    int sumDigit(int i, int j) 
    {
        int sum = 0;
        while (i > 0) 
        {
            sum += i % 10;
            i /= 10;
        }
        while (j > 0) 
        {
            sum += j % 10;
            j /= 10;
        }
        return sum;
    }
};
