法1：DP法，和打家劫舍Ⅰ差不多，只不过要分两次计算dp数组，一次0 ~ n - 1，一次2 ~ n
时间O(N)  空间O(N)
执行用时：0 ms, 在所有 C++ 提交中击败了100.00% 的用户
内存消耗：7.7 MB, 在所有 C++ 提交中击败了44.69% 的用户
class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return nums[0];
        if (n == 2) return max(nums[0], nums[1]);       // 两种特殊情况，否则接下来n >= 3
        vector<int> dp(n - 1, 0);
        
        dp[0] = nums[0];                                // 第一次遍历0 ~ n - 1，记录res1
        dp[1] = max(nums[0], nums[1]);
        for (int i = 2; i < n - 1; ++i) {
            dp[i] = max(dp[i - 1], dp[i - 2] + nums[i]);
        }
        int res1 = dp[n - 2];

        dp[0] = nums[1];                                // 第二次遍历2 ~ n，先重置dp初始值，然后记录res2，比较即可
        dp[1] = max(nums[1], nums[2]);
        for (int i = 2; i < n - 1; ++i) dp[i] = 0;
        for (int i = 3; i < n; ++i) {
            dp[i - 1] = max(dp[i - 2], dp[i - 3] + nums[i]);
        }
        int res2 = dp[n - 2];
        return max(res1, res2);
    }
};

随想录写法，泛化版，包装成一个函数更好一些
class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.size() == 1) return nums[0];               // 一种特殊情况即可，nums.size() == 2的情况res1 res2包括了
        int result1 = robRange(nums, 0, nums.size() - 2); 
        int result2 = robRange(nums, 1, nums.size() - 1); 
        return max(result1, result2);
    }
    // 198.打家劫舍的逻辑
    int robRange(vector<int>& nums, int start, int end) {
        if (end == start) return nums[start];
        vector<int> dp(nums.size());
        dp[start] = nums[start];
        dp[start + 1] = max(nums[start], nums[start + 1]);
        for (int i = start + 2; i <= end; i++) {
            dp[i] = max(dp[i - 2] + nums[i], dp[i - 1]);
        }
        return dp[end];
    }
};