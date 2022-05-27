法1：DP法，关键在于分析五个状态，注意每一天中五个状态的转移方程，其实就是上一天不变与当天买入/卖出股票对比取较大值
dp[i][0]：第i天仍无任何操作，没买入/卖出过，始终为0
dp[i][1]：第i天第一次买入的最大利润，与前一天对比取较大值
dp[i][2]：第i天第一次卖出的最大利润，与前一天对比取较大值
dp[i][3]：第i天第二次买入的最大利润，与前一天对比取较大值
dp[i][4]：第i天第二次卖出的最大利润，与前一天对比取较大值
时间O(N)  空间O(N)
执行用时：256 ms, 在所有 C++ 提交中击败了40.60% 的用户
内存消耗：131.9 MB, 在所有 C++ 提交中击败了35.38% 的用户
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int> (5, 0));
        dp[0][1] = -prices[0];      // 初始第一次买入，即为-prices[0]
        dp[0][3] = -prices[0];      // 初始第二次卖出，即为-prices[0]+prices[0]-prices[0]
        for (int i = 1; i < n; ++i) {
            dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] - prices[i]); // 由于dp[i][0]始终为0，可以不参与循环
            dp[i][2] = max(dp[i - 1][2], dp[i - 1][1] + prices[i]);
            dp[i][3] = max(dp[i - 1][3], dp[i - 1][2] - prices[i]);
            dp[i][4] = max(dp[i - 1][4], dp[i - 1][3] + prices[i]);
        }
        return max({dp[n - 1][0], dp[n - 1][2], dp[n - 1][4]});     // 最后返回所有手中无股票的情况，其实直接返回dp[n - 1][4]就行
    }
};

空间优化版，感觉没啥必要，还抽象，不如dp数组直观：
时间O(N)  空间O(1)
执行用时：92 ms, 在所有 C++ 提交中击败了98.62% 的用户
内存消耗：73.4 MB, 在所有 C++ 提交中击败了80.91% 的用户
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int a = -prices[0], b = 0, c = -prices[0], d = 0;
        for (int i = 1; i < prices.size(); ++i) {
            int e = a, f = b, g = c, h = d;
            a = max(e, -prices[i]);
            b = max(f, e + prices[i]);
            c = max(g, f - prices[i]);
            d = max(h, g + prices[i]);
        }
        return d;     // 其实直接返回d即可
    }
};

而且这里直接写成下面这样也是可以的，不需要保存上一天的状态，因为若a不变，b自然不受影响，若a = -prices[i]，则b = max(b, 0)还是相当于和b自身比较
a = max(a, -prices[i]);
b = max(b, a + prices[i]);
c = max(c, b - prices[i]);
d = max(d, c + prices[i]);