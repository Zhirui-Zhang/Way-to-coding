法1：贪心法？其实还是状态转移法，注意手续费要在状态1变成0时减去即可
时间O(N)  空间O(1)
执行用时：84 ms, 在所有 C++ 提交中击败了71.28% 的用户
内存消耗：53.6 MB, 在所有 C++ 提交中击败了89.72% 的用户
class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int a = 0, b = -5e4;     // b不能设为INT_MIN，会溢出，设置成给定数据的最小值边界即可
        for (auto price : prices) {
            int tmp = a;
            a = max(a, b + price - fee);        // 注意需要减去手续费fee
            b = max(b, tmp - price);
        }
        return a;                                   // 只能返回a，因为状态b手中还持有股票
    }
};

代码随想录模板DP法：
时间O(N)  空间O(N)
执行用时：224 ms, 在所有 C++ 提交中击败了5.15% 的用户
内存消耗：88.7 MB, 在所有 C++ 提交中击败了19.04% 的用户
class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        vector<vector<int>> dp(n, vector(2, 0));    
        dp[0][1] = -prices[0];          // 注意初始化时设置第一天买入值dp[0][1] = -prices[0]                         
        for(int i = 1; i < n; ++i) {
            dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] + prices[i] - fee);    // dp[i][0]表示当天手中无股票，如果是当天卖出的话注意减去手续费
            dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] - prices[i]);          // dp[i][1]表示当天持有股票，可能当天买入/前一天持有的
        }
        return dp[n - 1][0];            // 返回最后一天手中无股票的情况                        
    }
};