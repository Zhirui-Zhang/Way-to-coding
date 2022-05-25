法1:DP，其实我想到DP了，也想到建一个amount大小的数组，但是怕空间太大超时就没做，结果我自己想到dfs时间超时了，还是掌握的不熟练啊
时间O(N*M)N为coins长度，M为amount长度  空间O(M)即DP数组大小
执行用时：84 ms, 在所有 C++ 提交中击败了45.41% 的用户
内存消耗：14 MB, 在所有 C++ 提交中击败了84.38% 的用户
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount+1, amount+1);     // 这里重点是长度为amount+1，初值其实可以任意设置，INT_MAX也行，但只有当coins[j]<=amount时才会更新，所以amount+1其实就够了
        dp[0] = 0;                              // 特殊情况，当总金额为0时，不需要金币就可以实现，也满足了测试用例需要
        for(int i = 1; i < dp.size(); ++i){
            for(int j = 0; j < coins.size(); ++j){
                if(coins[j] <= i){              // 注意只有在coins[j]<=i时才考虑更新dp[i]，否则dp[i-coins[j]]会发生越界
                    dp[i] = min(dp[i], dp[i-coins[j]]+1);   // 状态转移方程，意为减去当前金币面额后的状态所需金币数量+1，与自身比较并更新
                }
            }
        }
        return dp[amount] == amount+1 ? -1 : dp[amount];    // 注意最后返回值若为amount+1说明无法构成该面额，返回-1
    }
};

法2：这道题不强调硬币的顺序，即无论排列还是组合，故内外两侧遍历顺序怎样都行，这里给出外物品内背包的方法2
执行用时：68 ms, 在所有 C++ 提交中击败了76.70% 的用户
内存消耗：14.1 MB, 在所有 C++ 提交中击败了39.14% 的用户
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1, amount + 1);     // 初始为一个较大值
        dp[0] = 0;      // 注意初始化当背包容量为0时，不需要硬币数量
        for (int i = 0; i < coins.size(); ++i) {    // 外层遍历物品
            for (int j = coins[i]; j < dp.size(); ++j) {    // 内层遍历背包
                dp[j] = min(dp[j], 1 + dp[j - coins[i]]);       
            }
        }
        return dp[amount] == amount + 1 ? -1 : dp[amount];
    }
};