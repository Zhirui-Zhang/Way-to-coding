法1：DP法，老生常谈了，解法略
时间O(N)  空间O(1)
执行用时：0 ms, 在所有 C++ 提交中击败了100.00% 的用户
内存消耗：5.8 MB, 在所有 C++ 提交中击败了70.26% 的用户
class Solution {
public:
    int climbStairs(int n) {
        int a = 0, b = 0, c = 1;
        for(int i = 0; i < n; ++i)
        {
            a = b;
            b = c;
            c = a + b;
        }
        return c;
    }
};

拓展：如果改为一步可迈m阶台阶（m < n），一共有多少种方法，就变成了一道完全背包的问题，且由于是排列问题，应该外层背包容量，内层物品
class Solution {
public:
    int climbStairs(int n, int m) {
        vector<int> dp(n + 1, 0);
        dp[0] = 1;      // 初始化dp[0] = 1
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {       // 而这道题只是m = 2的特殊情况而已
                if (i >= j) dp[i] += dp[i - j];
            }
        }
        return dp[n];
    }
};