法1：完全背包问题，注意难点在于外层for循环遍历物品还是背包容量，套用题解的话
1.如果求组合数就是外层for循环遍历物品，内层for遍历背包
2.如果求排列数就是外层for遍历背包，内层for循环遍历物品
时间O(M)  空间O(N*M) M为amount，N为coins数组长度
执行用时：12 ms, 在所有 C++ 提交中击败了44.44% 的用户
内存消耗：6.9 MB, 在所有 C++ 提交中击败了86.94% 的用户
class Solution {
public:
    int change(int amount, vector<int>& coins) {
        vector<int> dp(amount + 1, 0);
        dp[0] = 1;      // 注意初始化当背包容量为0时，有一种方法凑成，就是什么都不添加
        for (int i = 0; i < coins.size(); ++i) {    // 外层遍历物品
            for (int j = coins[i]; j < dp.size(); ++j) {    // 内层遍历背包
                dp[j] += dp[j - coins[i]];          // 状态转移方程，和494.目标和的那道题相同
            }
        }
        return dp[amount];
    }
};