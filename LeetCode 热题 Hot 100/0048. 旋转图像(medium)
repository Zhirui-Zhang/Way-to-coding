法1：模拟法，逐行旋转，每次旋转四个方位的值，记录左上角的值，然后依次将其他的值导入各个方向角，注意横纵坐标的对应关系即可
时间O(N^2)  空间O(1)
执行用时：4 ms, 在所有 C++ 提交中击败了45.95% 的用户
内存消耗：6.8 MB, 在所有 C++ 提交中击败了90.26% 的用户
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        for(int i = 0; i < n / 2; ++i)    // 假如是例1，到5处即可停止因为5不需要旋转，而例2则需要转完4863才能退出
        {
            for(int j = i; j < n - i - 1; ++j)    // j从i 开始到该行的n-i-1处，因为最后一位已经旋转完，不需要继续旋转
            {
                int temp = matrix[i][j];          // 先记录左上角的值
                matrix[i][j] = matrix[n-j-1][i];  // 左下角移到左上角，横纵对调或用n-x-1
                matrix[n-j-1][i] = matrix[n-i-1][n-j-1];  // 右下角到左下角
                matrix[n-i-1][n-j-1] = matrix[j][n-i-1];  // 右上角到右下角
                matrix[j][n-i-1] = temp;          // 右上角赋予temp的值
            }
        }
    }
};
