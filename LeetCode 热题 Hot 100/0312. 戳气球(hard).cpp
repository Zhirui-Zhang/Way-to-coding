法1:DP，有点类似于正则表达式的那道题，都是二维数组遍历求解，例题题解附excel上传  关键在于状态转移方程推导  以及  初始化无关的值全都为0，不予考虑
    dp[start][end] = max(dp[start][end], dp[start][i]+dp[i][end]+nums[start]*nums[i]*nums[end])
时间O(N^3)  空间O(N^2)
执行用时：392 ms, 在所有 C++ 提交中击败了75.82% 的用户
内存消耗：10.1 MB, 在所有 C++ 提交中击败了13.14% 的用户
class Solution {
public:
    int maxCoins(vector<int>& nums) {
        nums.insert(nums.begin(), 1);   // 首尾各填充一个0，便于后续计算
        nums.push_back(1);
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));

        for(int start = n - 3; start >= 0; --start){        // 注意start 和 end的起始值，由于想要计算戳气球的值至少需要连续三个nums[i]，所以从nums[3]~nums[5]开始统计即可
            for(int end = start + 2; end < n; ++end){
                for(int i = start + 1; i < end; ++i){       // i从start+1一直到end-1 也就是(start, end)开区间 注意不等于end，否则边界失效
                    dp[start][end] = max(dp[start][end], dp[start][i]+dp[i][end]+nums[start]*nums[i]*nums[end]);
                }
            }
        }
        
        return dp[0][n-1];
    }
};
