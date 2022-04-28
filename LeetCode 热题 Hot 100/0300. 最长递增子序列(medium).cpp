法1：DP，没想到复杂度可以这么高，我一直在想怎么达到O(N)，结果用二分法才能O(NlogN)，是我想太多，状态转移方程  dp[i]=max(dp[i], dp[j]+1)  j∈[0, i)
时间O(N^2)  空间O(N)
执行用时：268 ms, 在所有 C++ 提交中击败了39.51% 的用户
内存消耗：10.1 MB, 在所有 C++ 提交中击败了88.66% 的用户
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int res = 0, n = nums.size();
        vector<int> dp(n, 1);       // dp数组初始为每个长度为1，即只包含自己
        for(int i = 0; i < n; ++i)
        {
            for(int j = 0; j < i; ++j)    // 遍历i和j寻找完全递增数组的长度，并与自身比较更新
            {
                if(nums[j] < nums[i])    dp[i] = max(dp[i], dp[j]+1);
            }
            res = max(res, dp[i]);        // 更新当前最长长度
        }
        return res;
    }
};

法2：DP+二分查找，实在是不太好想，例题详见笔记题解，dp数组记录的是当前最长递增子序列i的元素下标
时间O(NlogN)  空间O(N)
执行用时：12 ms, 在所有 C++ 提交中击败了73.94% 的用户
内存消耗：10.1 MB, 在所有 C++ 提交中击败了87.47% 的用户
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int res = 0, n = nums.size();
        vector<int> dp(n, 0);       // 这里初始化值任意，只是为了占位
        for(auto num : nums)
        {
            int i = 0, j = res;     // 令左边界为0，右边界为当前最大长度值
            while(i < j)
            {
                int mid = (i + j) / 2;  // 二分查找最适合num的位置，即num大了往右查，小了往左查
                if(dp[mid] < num)    i = mid + 1;       // 注意二分边界范围，其实就是算法lower_bound()的思想
                else    j = mid;        
                // 注意为了满足严格递增思想，即使当前位置的元素dp[mid]等于num也应该往左查，插入到小的位置上，比如例中的18应插在101的位置上
            }
            dp[j] = num;                // 对找到的合适位置j处放置num
            if(res == j)    res++;      // 判断当前是否为最大值并更新res
        }
        return res;
    }
};
