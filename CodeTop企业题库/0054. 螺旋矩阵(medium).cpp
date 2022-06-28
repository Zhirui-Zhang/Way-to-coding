法1：模拟法，做过的题目了，边界条件需要把握好，以及最后退出时可能有两种特殊情况需要注意
时间O(MN)  空间O(1)
执行用时：0 ms, 在所有 C++ 提交中击败了100.00% 的用户
内存消耗：6.7 MB, 在所有 C++ 提交中击败了56.81% 的用户class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> res;
        int leftRow = 0, leftCol = 0, rightRow = matrix.size() - 1, rightCol = matrix[0].size() - 1;
        while (leftRow < rightRow && leftCol < rightCol) {
            for (int j = leftCol; j <= rightCol; ++j) res.push_back(matrix[leftRow][j]);
            ++leftRow;
            for (int i = leftRow; i <= rightRow; ++i) res.push_back(matrix[i][rightCol]);
            --rightCol;
            for (int j = rightCol; j >= leftCol; --j) res.push_back(matrix[rightRow][j]);
            --rightRow;
            for (int i = rightRow; i >= leftRow; --i) res.push_back(matrix[i][leftCol]);
            ++leftCol;
        }
        if (leftRow == rightRow) {
            for (int j = leftCol; j <= rightCol; ++j) res.push_back(matrix[leftRow][j]);
        } else if (leftCol == rightCol) {
            for (int i = leftRow; i <= rightRow; ++i) res.push_back(matrix[i][rightCol]);
        }
        return res;
    }
};