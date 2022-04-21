法1：遍历法，自己写的代码看起来就恶心，看完题解其实做法差不多，只不过这道题本身比较恶心2333
设置四个边界点，然后依次上下左右遍历，每次遍历到边界的前一个点，以免下次遍历发生重复
while循环退出时有两种情况，一种是行未遍历完列值相等，一种是列未遍历完行值相等，分别讨论即可
时间O(MN)遍历一遍  空间O(1)常数空间大小
执行用时：12 ms, 在所有 C++ 提交中击败了36.60% 的用户
内存消耗：9.7 MB, 在所有 C++ 提交中击败了52.12% 的用户
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> res;
        if(matrix.empty() || matrix[0].empty())    return res;
        int l_row = 0, l_col = 0, r_row = matrix.size() - 1, r_col = matrix[0].size() -1;   // 分别为左上和右下两个边界点的坐标值
        while(l_row < r_row && l_col < r_col)                                               // 循环退出条件，退出时分两种情况讨论
        {
            int i = l_row, j = l_col;
            for(; j < r_col; j++)    res.push_back(matrix[i][j]);                           // 四次遍历，每次将对应的边界值-1或者+1，或者放在最后一起+-也可以
            r_col--;
            for(; i < r_row; i++)    res.push_back(matrix[i][j]);
            r_row--;
            for(; j > l_col; j--)    res.push_back(matrix[i][j]);
            l_col++;
            for(; i > l_row; i--)    res.push_back(matrix[i][j]);
            l_row++;
        }
        if(r_col == l_col)                                                                   // 行未遍历完但列值相等
        {
            for(int i = l_row; i <= r_row; i++)    res.push_back(matrix[i][l_col]);
        }
        else if(r_row == l_row)                                                              // 列未遍历完但行值相等
        {
            for(int j = l_col; j <= r_col; j++)    res.push_back(matrix[l_row][j]);
        }   
        return res;
    }
};

题解的优化中可以将变量名称设置为 top  bottom  left  right ，核心代码不变，这样便于理解
