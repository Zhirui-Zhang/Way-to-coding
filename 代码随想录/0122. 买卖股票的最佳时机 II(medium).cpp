法1：DP法，借助之前最佳时机Ⅲ的状态转移法写出来了，更简单一点，只有两种状态，没有冷却期
时间O(N)  空间O(1)
执行用时：8 ms, 在所有 C++ 提交中击败了47.34% 的用户
内存消耗：12.6 MB, 在所有 C++ 提交中击败了83.64% 的用户
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int a = 0, b = INT_MIN;
        for (auto price : prices) {
            int tmp = a;
            a = max(a, b + price);          // a状态表示当天不持有股票，b状态表示当天持有股票
            b = max(tmp - price, b);
        }
        return a;
    }
};
DP法：未省略原版，突出状态转移方程的写法
执行用时：12 ms, 在所有 C++ 提交中击败了16.86% 的用户
内存消耗：14.8 MB, 在所有 C++ 提交中击败了9.80% 的用户
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int> (2, 0));      // dp[i][0]表示第i天手中无股票时最大利润，dp[i][1]表示第i天手中有股票时最大利润
        dp[0][1] = -prices[0];
        for (int i = 1; i < n; ++i) {
            dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] + prices[i]);
            dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] - prices[i]);
        }
        return dp[n - 1][0];
    }
};

法2：贪心法，只收集差值为正利润的结果加入到res中
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int res = 0;
        for (int i = 1; i < prices.size(); i++) {
            res += max(prices[i] - prices[i - 1], 0);
        }
        return res;
    }
};
