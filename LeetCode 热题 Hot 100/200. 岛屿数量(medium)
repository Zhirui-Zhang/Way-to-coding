法1：BFS，方法不难，做过类型题，可惜在修改原数组位置处出错，导致用例超时，应注意
时间O(MN)  空间O(min(M,N))  注意空间不是单纯的O(MN)而是整个矩阵全为1时队列最长，此时空间为min(M,N)
执行用时：32 ms, 在所有 C++ 提交中击败了61.80% 的用户
内存消耗：12.9 MB, 在所有 C++ 提交中击败了31.16% 的用户
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int res = 0, m = grid.size(), n = grid[0].size();
        queue<pair<int, int>> q;
        for(int i = 0; i < m; ++i)
        {
            for(int j = 0; j < n; ++j)
            {
                if(grid[i][j] == '1')
                {
                    q.push({i, j});
                    grid[i][j] = '0';   // 注意要在这里直接置为'0'
                    while(!q.empty())
                    {
                        int row = q.front().first, col = q.front().second;
                        q.pop();
                        if(row+1 < m && grid[row+1][col] == '1')    
                        {
                            q.push({row+1, col});
                            grid[row+1][col] = '0';     
                            // 注意在这里就直接置为'0'，否则当数据很大时，会重复很多次入队，大大浪费时间导致超时！！！
                        }    
                        if(row-1 >= 0 && grid[row-1][col] == '1')    
                        {
                            q.push({row-1, col});
                            grid[row-1][col] = '0';
                        }
                        if(col+1 < n && grid[row][col+1] == '1')    
                        {
                            q.push({row, col+1});
                            grid[row][col+1] = '0';
                        }
                        if(col-1 >= 0 && grid[row][col-1] == '1')    
                        {
                            q.push({row, col-1});
                            grid[row][col-1] = '0';
                        }
                    }
                    res++;      // 遍历一个岛屿后，res结果+1，其实放在循环之处加也可以
                }
            }
        }
        return res;
    }
};

法2：DFS法，略，整体思路一样，但是空间复杂度以及置'0'的写法位置与BFS略有不同，应注意
时间O(MN)  空间O(MN)
class Solution {
private:
    void dfs(vector<vector<char>>& grid, int r, int c) {
        int nr = grid.size();
        int nc = grid[0].size();

        grid[r][c] = '0';       // dfs可以在递归之前置'0'
        if (r - 1 >= 0 && grid[r-1][c] == '1') dfs(grid, r - 1, c);
        if (r + 1 < nr && grid[r+1][c] == '1') dfs(grid, r + 1, c);
        if (c - 1 >= 0 && grid[r][c-1] == '1') dfs(grid, r, c - 1);
        if (c + 1 < nc && grid[r][c+1] == '1') dfs(grid, r, c + 1);
    }

public:
    int numIslands(vector<vector<char>>& grid) {
        int nr = grid.size();
        if (!nr) return 0;
        int nc = grid[0].size();

        int num_islands = 0;
        for (int r = 0; r < nr; ++r) {
            for (int c = 0; c < nc; ++c) {
                if (grid[r][c] == '1') {
                    ++num_islands;
                    dfs(grid, r, c);
                }
            }
        }

        return num_islands;
    }
};
