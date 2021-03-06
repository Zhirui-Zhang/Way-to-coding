法1：DP法，太难了要自闭了，根本没思路，看答案看了一下午，不知道能记住多久，二刷的时候还能会不
dp数组长度比s p 均大一，目的是可以判断s为空，p不为空时是否成立，重点在于讨论p当前字符是否为*，状态转移方程写在笔记本上，有点多
时间  空间均为O(MN)
执行用时：4 ms, 在所有 C++ 提交中击败了91.09% 的用户
内存消耗：6.7 MB, 在所有 C++ 提交中击败了49.48% 的用户
class Solution {
public:
    bool isMatch(string s, string p) {
        int m = s.size() + 1, n = p.size() + 1;                    // 设置dp数组的行列数，各为s p的长度加1，这样可以将s为空的情况一起考虑进去，当s为空，p = "a*b*c*"仍然为true
        vector<vector<bool>> dp(m, vector<bool>(n, false));        // 初始dp数组，为m行n列个false
        dp[0][0] = true;                                           // dp[0][0]设为true，即当s p均为空是返回true
        for(int i = 2; i < n; i+=2)                                // 初始化dp的第一行，仅考虑p的偶数位即可，只有上一个状态为true且当前p的偶数位为 * 号时才可以忽略前面的字符，将其置为真
        {
            if(dp[0][i-2] && p[i-1] == '*')    dp[0][i] = true;
        }
        for(int i = 1; i < m; i++)                                 // 进入动态规划，状态转移环节，用s[i-1] 和 p[j-1]表示当前s p的元素
        {
            for(int j = 1; j < n; j++)
            {
                if(p[j-1] == '*')                                   // 主要分成两种情况，p的当前元素是否为 * 号，借助*号实现删除p元素或者保持p元素或者复制p元素
                {
                    if(dp[i][j-2])    dp[i][j] = true;              // 为*号时，分三种情况（1）p向前两位状态为true，意味可以利用*删除前面的字符，如 a 和 ab*
                    if(dp[i-1][j] && p[j-2] == s[i-1])    dp[i][j] = true;    
                                                                    // （2）p向前一位的值等于s当前值，可以利用*复制p前一位  如maa 和 ma* 相等 前提是上一行状态dp[i-1][j]为true 即 ma 和 ma* 相等
                    if(dp[i-1][j] && p[j-2] == '.')    dp[i][j] = true;
                                                                    // （3）p向前一位的值等于'.'，可以利用'*'复制p前一位的'.'  如mab 和 m.* 相等 因为'*'复制了一个'.'变成了 m.. 前提是上一行状态dp[i-1][j]为true 即 ma 和 m.* 相等
                }
                else                                                // 当不为*号时，只有满足前面字符都相等且（1）当前字符相等或者（2）p[j-1] = . 可为任意值时成立，新状态为true
                {
                    if(dp[i-1][j-1] && s[i-1] == p[j-1])    dp[i][j] = true;
                    if(dp[i-1][j-1] && p[j-1] == '.')     dp[i][j] = true;
                }
            }
        }
        return dp[m-1][n-1];
    }
};
