法1：回溯法，并不是很难，细节有点不太好想，尤其是判断当前行以上是否存在冲突时
时间O(N!)  空间O(N)不考虑tmp字符串数组所占空间，递归深度为N
执行用时：4 ms, 在所有 C++ 提交中击败了91.26% 的用户
内存消耗：7.3 MB, 在所有 C++ 提交中击败了49.47% 的用户
class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<string> tmp(n, string(n, '.'));      // 注意初始化的方法，括号前要加一个string说明创建对象类型
        dfs(0, n, tmp);
        return res;
    }

private:
    vector<vector<string>> res;
    void dfs(int row, int n, vector<string>& tmp) {
        if (row == n) {     // 退出条件，当前行号为n
            res.push_back(tmp);
            return;
        }
        for (int col = 0; col < n; ++col) {
            if (checkQ(row, col, n ,tmp)) {     // 如果满足皇后条件即可进入下一层递归
                tmp[row][col] = 'Q';
                dfs(row + 1, n, tmp);
                tmp[row][col] = '.';            // 注意回溯
            }
        }
    }

    bool checkQ(int row, int col, int n, vector<string>& tmp) {     
        // 检查皇后的三种情况，注意不用检查本行，因为当前层内只有一个皇后，不会冲突，且只需要检查当前行上方的字符即可，因为下方还未创建
        // 检查当前列
        for (int i = 0; i < row; ++i) {
            if (tmp[i][col] == 'Q') return false;
        }
        // 检查左上方
        for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; --i, --j) {
            if (tmp[i][j] == 'Q') return false;
        }
        // 检查右上方
        for (int i = row - 1, j = col + 1; i >= 0 && j < n; --i, ++j) {
            if (tmp[i][j] == 'Q') return false;
        }
        return true;
    }
};