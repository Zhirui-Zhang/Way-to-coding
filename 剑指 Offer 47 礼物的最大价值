法1：迭代法——动态规划  逐渐入门了，动态规划关键方法是要找到一般表达式，此题表达式为是
※grid[i][j] = max(grid[i-1][j], grid[i][j-1]) + grid[i][j]※
执行用时：8 ms, 在所有 C++ 提交中击败了73.62% 的用户
内存消耗：8.8 MB, 在所有 C++ 提交中击败了95.03% 的用户
class Solution {
public:
    int maxValue(vector<vector<int>>& grid) {
        //横竖都不空，不用判断空集
        //直接修改原grid矩阵，可以减小空间复杂度
        int m = grid.size(), n = grid[0].size();
        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(i == 0 && j == 0)  continue;
                else if(i == 0)    grid[i][j] += grid[i][j-1];
                else if(j == 0)    grid[i][j] += grid[i-1][j];
                else    grid[i][j] += max(grid[i-1][j], grid[i][j-1]);
            }
        }
        return grid[m-1][n-1];
    }
};
