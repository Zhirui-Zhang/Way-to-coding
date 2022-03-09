法1：DP法，空间开销有点大，由于原数组不是int数组，没有在原数组基础上修改，而是新建dp数组后遍历matrix累加得到的
时间O(MN)  空间O(MN)
执行用时：56 ms, 在所有 C++ 提交中击败了52.37% 的用户
内存消耗：17.6 MB, 在所有 C++ 提交中击败了38.68% 的用户
class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int res = 0, m = matrix.size(), n = matrix[0].size();
        vector<vector<int>> dp(m, vector<int>(n, 0));
        for(int i = 0; i < m; ++i)
        {
            for(int j = 0; j < n; ++j)
            {
                if(matrix[i][j] == '1')     // 只有当为'1'再考虑，否则dp[i][j]为0
                {
                    if(i - 1 >= 0 && j - 1 >= 0 && matrix[i-1][j] != '0' && matrix[i][j-1] != '0' && matrix[i-1][j-1] != '0')
                    {
                        dp[i][j] = min({dp[i-1][j], dp[i][j-1], dp[i-1][j-1]}) + 1;   // 当左边上边和左上方都为1时，dp[i][j]为他们的最小值+1，否则为1即可
                    }
                    else    dp[i][j] = 1;
                    res = max(res, dp[i][j]);   // 每轮结束后更新res
                }
            }
        }
        return res*res;
    }
};

优化版：判断dp[i][j]+1的部分有点复杂了，其实取最小值+1的话，如果是周边0也完全可以，所以条件只要改为数组不越界即可
执行用时：60 ms, 在所有 C++ 提交中击败了33.15% 的用户
内存消耗：17.6 MB, 在所有 C++ 提交中击败了54.45% 的用户
class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int res = 0, m = matrix.size(), n = matrix[0].size();
        vector<vector<int>> dp(m, vector<int>(n, 0));
        for(int i = 0; i < m; ++i)
        {
            for(int j = 0; j < n; ++j)
            {
                if(matrix[i][j] == '1')
                {
                    if(i - 1 >= 0 && j - 1 >= 0)
                    {
                        dp[i][j] = min({dp[i-1][j], dp[i][j-1], dp[i-1][j-1]}) + 1;
                    }
                    else    dp[i][j] = 1;
                    res = max(res, dp[i][j]);
                }
            }
        }
        return res*res;
    }
};
