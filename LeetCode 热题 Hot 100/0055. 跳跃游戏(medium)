法1：DP法，每次统计下一步可以跳越的最远距离，若dp[i-1]=0说明无法跳过，返回false
时间O(N)  空间O(N)
执行用时：56 ms, 在所有 C++ 提交中击败了42.62% 的用户
内存消耗：49.2 MB, 在所有 C++ 提交中击败了5.86% 的用户
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, 0);
        dp[0] = nums[0];    // 初始化dp[0]的值为nums[0]
        for(int i = 1; i < n; ++i)
        {
            if(dp[i-1] == 0)    return false;   // 遍历nums数组，更新dp[i]的值，若dp[i-1]=0则返回false
            dp[i] = max(dp[i-1]-1, nums[i]);
        }
        return true;    // 若顺利遍历成功则返回true
    }
};

DP优化版：原数组就地修改，避免新增DP数组
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        for(int i = 1; i < n; ++i)
        {
            if(nums[i-1] == 0)    return false;
            nums[i] = max(nums[i-1]-1, nums[i]);
        }
        return true;
    }
};

法2：贪心法，用一个变量temp记录当前可移动最远距离，遍历数组更新temp即可
时间O(N)  空间O(1)
执行用时：48 ms, 在所有 C++ 提交中击败了77.35% 的用户
内存消耗：47 MB, 在所有 C++ 提交中击败了87.52% 的用户
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size(), temp = nums[0];
        for(int i = 1; i < n; ++i)
        {
            if(temp == 0)    return false;
            temp = max(temp-1, nums[i]);
        }
        return true;
    }
};
