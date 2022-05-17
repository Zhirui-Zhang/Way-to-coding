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
