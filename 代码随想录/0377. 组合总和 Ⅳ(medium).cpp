法1：DP完全背包，注意与518零钱兑换Ⅱ不同，本题求的是排列总数，即数组顺序有影响，所以应用外层遍历背包容量，内层遍历物品的方法
时间O(M*N)  空间O(M) M为target，N为nums数组长度
执行用时：4 ms, 在所有 C++ 提交中击败了47.38% 的用户
内存消耗：6.4 MB, 在所有 C++ 提交中击败了58.02% 的用户
class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        vector<int> dp(target + 1, 0);
        dp[0] = 1;
        for (int i = 1; i < dp.size(); ++i) {       // 外层for循环遍历背包容量
            for (int j = 0; j < nums.size(); ++j) { // 内层for循环遍历所有物品
                // 注意测试用例中有特殊案例，使得部分dp数组的排列数超过INT_MAX，所以在递推公式前判断一下是否超过最大值，超过省略即可，没必要用
                // 同时不要写成 dp[i] + dp[i - nums[j]] < INT_MAX 这样还是越界
                if (i >= nums[j] && dp[i] < INT_MAX - dp[i - nums[j]]) dp[i] += dp[i - nums[j]];
            }   
        }
        return dp[target];
    }
};