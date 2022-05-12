法1：回溯法，二重回溯，每次都是从头遍历到尾，检查当前行列组中的正确性
时间O(9*M)M是'.'的个数  空间O(N^2)
执行用时：24 ms, 在所有 C++ 提交中击败了47.11% 的用户
内存消耗：6.3 MB, 在所有 C++ 提交中击败了35.26% 的用户
class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        dfs(board);
    }

private:
    // 与N皇后找出所有解的无返回值不同，数独是只要找到对应的解就可以一路提前返回
    bool dfs(vector<vector<char>>& board) {
        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                if (board[i][j] != '.') continue;       // 如果已经填入数字，pass
                for (char c = '1'; c <= '9'; ++c) {
                    if (checkNum(i, j, c, board)) {     // 如果检查成功，开始递归
                        board[i][j] = c;
                        if (dfs(board)) return true;    // 若找到正确解，一路返回
                        board[i][j] = '.';              // 否则重新假设，再次递归
                    }
                }
                return false;       // 如果遍历了该位置的9个数字都不对，说明之前假定的有问题，应返回false重新尝试
            }
        }
        return true;        // 在两层递归都结束时，说明已找到正确解，返回true
    }
    bool checkNum(int row, int col, char c, vector<vector<char>>& board) {
        // 依次检查该列、该行、该组
        for (int i = 0; i < 9; ++i) {
            if (board[i][col] == c) return false;
        }
        for (int j = 0; j < 9; ++j) {
            if (board[row][j] == c) return false;
        }
        int startRow = (row / 3) * 3;  // 定义该组起始行、列的计算方法
        int startCol = (col / 3) * 3;
        for (int i = startRow; i < startRow + 3; ++i) {
            for (int j = startCol; j < startCol + 3; ++j) {
                if (board[i][j] == c) return false;
            }
        }
        return true;
    }
};