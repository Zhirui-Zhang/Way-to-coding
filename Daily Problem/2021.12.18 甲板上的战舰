遍历法即可，并没有medium那么难，就是题目理解了好久
时间O(M*N) 空间O(1) 题目要求
执行用时：8 ms, 在所有 C++ 提交中击败了74.06% 的用户
内存消耗：7.7 MB, 在所有 C++ 提交中击败了98.22% 的用户
class Solution {
public:
    int countBattleships(vector<vector<char>>& board) {
        int m = board.size(), n = board[0].size();
        int res = 0;
        for(int i = 0; i < m; ++i)
        {
            for(int j = 0; j < n; ++j)
            {
                if(board[i][j] == 'X')                      
                {
                    if(i > 0 && board[i-1][j] == 'X')    continue;      // 注意只记录某一个战舰起始点res+1，当某一格为X但不是起始点时continue即可
                    if(j > 0 && board[i][j-1] == 'X')    continue;
                    ++res;
                }
            }
        }
        return res;
    }
};
