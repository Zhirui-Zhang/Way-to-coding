法1：DP法，难点在于利用两个dp数组，分别记录当前最长递增子序列长度和个数，并记录最大长度值，最后遍历dp数组，累加res结果值
时间O(N^2)  空间O(N)
执行用时：180 ms, 在所有 C++ 提交中击败了5.56% 的用户
内存消耗：12.8 MB, 在所有 C++ 提交中击败了74.90% 的用户
class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int maxLen = 1, res = 0, n = nums.size();
        vector<int> dp(n, 1);           // 初始化dp count都为n个1，dp[i]表示以nums[i]为结尾的字符串的最长递增子序列的长度       
        vector<int> count(n, 1);        // count[i]表示以nums[i]为结尾的字符串，最长递增子序列的个数为count[i]
        for (int i = 1; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                if (nums[j] < nums[i]) {    // 只有当dp[j] < dp[i]时满足严格递增，才可能发生更新
                    if (dp[j] + 1 > dp[i]) count[i] = count[j];     // 若为更长的长度，令count[i] = count[j]
                    else if (dp[j] + 1 == dp[i]) count[i] += count[j];  // 若长度相等，则count[i] += count[j]
                    dp[i] = max(dp[i], dp[j] + 1);  // 更新dp[i]
                }
                maxLen = max(maxLen, dp[i]);        // 记录当前最长递增子序列的长度
            }
        }
        for (int i = 0; i < n; ++i) {               // 遍历整个dp数组，若为最长长度，res加上count中的值
            if (dp[i] == maxLen) res += count[i];
        }
        return res;
    }
};