法1：回溯法，和51题N皇后如出一辙，只不过换成了统计次数，关键还是在于内层遍历的是列，保证当前行中只有一个皇后，检查是否与上面和左上右上重合即可
时间O(N!)  空间O(N)递归深度
执行用时：4 ms, 在所有 C++ 提交中击败了62.45% 的用户
内存消耗：6 MB, 在所有 C++ 提交中击败了45.17% 的用户
class Solution {
public:
    int totalNQueens(int n) {
        vector<vector<int>> Queen(n, vector<int>(n, 0));    // 自定义一个二维数组，用于记录当前格子，1为Queen，0为空
        dfs(Queen, 0, n);
        return res;
    }
private:
    int res;
    
    void dfs(vector<vector<int>>& Queen, int row, int n) {
        if (row == n) {     // 注意递归中只需要row行一个参数，col列在for循环递归中
            ++res;
            return;
        }
        for (int col = 0; col < n; ++col) {     // 每一次从col=0开始，逐列判断是否符合要求，保证当前row只有一个皇后
            if (!checkN(Queen, row, col, n)) continue;
            Queen[row][col] = 1;
            dfs(Queen, row + 1, n);
            Queen[row][col] = 0;
        }
    }

    bool checkN(vector<vector<int>>& Queen, int row, int col, int n) {
        for (int i = 0; i < row; ++i) {     // 检查正上方
            if (Queen[i][col] == 1) return false;
        }
        for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; --i, --j) {    // 检查左上方
            if (Queen[i][j] == 1) return false;
        }
        for (int i = row - 1, j = col + 1; i >= 0 && j < n; --i, ++j) {     // 检查右上方
            if (Queen[i][j] == 1) return false;
        }
        return true;
    }
};