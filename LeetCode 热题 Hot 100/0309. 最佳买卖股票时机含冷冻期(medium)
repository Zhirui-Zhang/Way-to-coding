法1：DP，好难理解，是个三状态机模型，模型图见笔记，注意边界值的设置，初始仅将dp[0][0]设为0，其他均为INT_MIN，防止非法转移
时间O(N)  空间O(N)
执行用时：8 ms, 在所有 C++ 提交中击败了22.44% 的用户
内存消耗：11.3 MB, 在所有 C++ 提交中击败了55.71% 的用户
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n+1, vector(3, INT_MIN));    // 初始为[n+1, 3]维数组，初始值设为0
        dp[0][0] = 0;                                       // 特别设置dp[0][0]=0
        for(int i = 0; i < n; ++i)
        {
            dp[i+1][0] = max(dp[i][0], dp[i][2]);
            dp[i+1][1] = max(dp[i][1], dp[i][0]-prices[i]);
            dp[i+1][2] = dp[i][1] + prices[i];
        }
        return max(dp[n][0], dp[n][2]);                      // 注意最后比较dp[n][0]和dp[n][2]即可，因为这两个都是手中无股票的情况，最后一天dp[n][1]持有股票不成立舍弃
    }
};

改进版：将dp数组转化为3个状态量，注意循环之前存储一下临时变量a b即可
时间O(N)  空间O(1)
执行用时：0 ms, 在所有 C++ 提交中击败了100.00% 的用户
内存消耗：10.8 MB, 在所有 C++ 提交中击败了95.96% 的用户
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int a = 0, b = -10000, c = -10000;
        for(auto price : prices)
        {
            int temp1 = a, temp2 = b;
            a = max(a, c);
            b = max(b, temp1 - price);
            c = temp2 + price;
        }
        return max(a, c);
    }
};
};
