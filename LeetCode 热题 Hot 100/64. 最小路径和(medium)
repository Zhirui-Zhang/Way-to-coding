法1：DP，原地修改，先把第一行和第一列修改，然后遍历整个数组原地修改即可
时间O(MN)  空间O(1)
执行用时：8 ms, 在所有 C++ 提交中击败了77.69% 的用户
内存消耗：9.4 MB, 在所有 C++ 提交中击败了91.36% 的用户
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        for(int i = 1; i < m; ++i)    grid[i][0] += grid[i-1][0];
        for(int j = 1; j < n; ++j)    grid[0][j] += grid[0][j-1];
        for(int i = 1; i < m; ++i)
        {
            for(int j = 1; j < n; ++j)
            {
                grid[i][j] += min(grid[i-1][j], grid[i][j-1]);
            }
        }
        return grid[m-1][n-1];
    }
};  
