法1：DP法，背包问题，但我还不是很懂，创建一个长度为half+1的数组，初始为0，随后从后往前遍历dp数组，查看是否能把当前nums[i]放入背包，题解见excel表
时间O(N^2)  空间O(N)
执行用时：196 ms, 在所有 C++ 提交中击败了59.58% 的用户
内存消耗：9.5 MB, 在所有 C++ 提交中击败了77.61% 的用户
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for(auto num : nums){
            sum += num;
        }
        if(sum % 2 == 1){
            return false;
        }                                                       // 如果总和为偶数直接返回false
            
        int half = sum / 2, n = nums.size();
        
        vector<int> dp(half+1, 0);                              // dp数组长度为half+1，其中dp[0]一定保持为0，dp[j]表示背包的总容量为j时可以凑成的子集总和

        for(int i = 0; i < n; ++i){
            for(int j = half; j >= nums[i]; --j){               // 注意内层循环为倒序遍历！！！
                dp[j] = max(dp[j], dp[j-nums[i]]+nums[i]);      // 状态转移方程为  dp[j] = max(dp[j], dp[j-nums[i]]+nums[i]) 意为取若拿当前值nums[i]的结果比现有值大，则更新
            }
        }
        return dp[half] == half;
    }
};
