法1：贪心法？其实还是状态转移法，注意手续费要在状态1变成0时减去即可
时间O(N)  空间O(1)
执行用时：84 ms, 在所有 C++ 提交中击败了71.28% 的用户
内存消耗：53.6 MB, 在所有 C++ 提交中击败了89.72% 的用户class Solution {
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