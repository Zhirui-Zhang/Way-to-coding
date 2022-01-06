法1：DP法  重复题  仍思考了一段时间  还需加强
时间O(MN)  空间O(MN)
执行用时：4 ms, 在所有 C++ 提交中击败了87.26% 的用户
内存消耗：6.9 MB, 在所有 C++ 提交中击败了50.42% 的用户
class Solution {
public:
    bool isMatch(string s, string p) {
        int n = s.size(), m = p.size();
        vector<vector<bool>> dp(n+1, vector<bool>(m+1, false));   // 注意dp数组的写法
        dp[0][0] = true;    
        for(int j = 2; j < m + 1; j += 2)
        {
            if(dp[0][j-2] && p[j-1] == '*')    dp[0][j] = true;   // 注意是p[j-1] 而不是 p[j]！
        }
        for(int i = 1; i < n + 1; ++i)
        {
            for(int j = 1; j < m + 1; ++j)
            {
                if(p[j-1] == '*')   // 只考虑p[j-1]是不是 *
                {
                    if(dp[i][j-2])    dp[i][j] = true;
                    if(dp[i-1][j] && p[j-2] == s[i-1])    dp[i][j] = true;
                    if(dp[i-1][j] && p[j-2] == '.')    dp[i][j] = true;
                }
                else
                {
                    if(dp[i-1][j-1] && s[i-1] == p[j-1])    dp[i][j] = true;
                    if(dp[i-1][j-1] && p[j-1] == '.')    dp[i][j] = true;
                }
            }
        }
        return dp[n][m];
    }
};
