法1：在0123的基础上推广到最多k次交易，思想不变，最多有2k+1状态，初始化后针对奇偶性，奇数是买入，偶数是卖出
时间O()  空间O()
执行用时：12 ms, 在所有 C++ 提交中击败了31.58% 的用户
内存消耗：12.2 MB, 在所有 C++ 提交中击败了54.30% 的用户
class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        if (prices.empty()) return 0;       // 针对测试用例中的奇怪案例
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int> (2 * k + 1, 0));  // dp数组维度(n, 2k+1)
        for (int i = 1; i < 2 * k + 1; i += 2) {
            dp[0][i] = -prices[0];          // 对每个奇数下标初始化为-prices[0]，表示第k次买入
        }
        for (int i = 1; i < n; ++i) {
            for (int j = 1; j < 2 * k + 1; j += 2) {    // dp[i][0]始终为0，可忽略，之后按照奇偶决定+/- prices[i]
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - 1] - prices[i]);
                dp[i][j + 1] = max(dp[i - 1][j + 1], dp[i - 1][j] + prices[i]);
            }
        }
        return dp[n - 1][2 * k];            // 返回最后一天的最后一个状态即可
    }
};