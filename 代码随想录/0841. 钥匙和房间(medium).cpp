法1：BFS+图论，并不难，借助队列，依次将取得的钥匙和房间匹配入队，最后检查是否有房间未访问过
时间O(N)  空间O(N)
执行用时：8 ms, 在所有 C++ 提交中击败了83.63% 的用户
内存消耗：10.1 MB, 在所有 C++ 提交中击败了79.52% 的用户
class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        vector<bool> visited(n, false);
        visited[0] = true;  // 0号房间默认已访问
        queue<int> q;
        q.push(0);
        while (!q.empty()) {
            int i = q.front();
            q.pop();
            for (auto room : rooms[i]) {
                if (!visited[room]) {       // 注意要在入队之前就判断是否已访问过，若未访问入队，否则会死循环
                    q.push(room);
                    visited[room] = true;
                }
            }
        }
        for (auto v : visited) {            // 遍历visited数组，检查是否有房间未访问过
            if (!v) return false;
        }
        return true;
    }
};

法2：BFS同理，代码略