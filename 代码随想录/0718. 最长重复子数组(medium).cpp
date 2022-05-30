法1：DP法，比较经典，当比较两个字符串的时候，要记得可以设置(m + 1, n + 1)维的dp数组依次比较
时间O(MN)  空间O(MN) M为nums1长度 N为nums2长度
执行用时：304 ms, 在所有 C++ 提交中击败了50.36% 的用户
内存消耗：106.6 Mnums2, 在所有 C++ 提交中击败了25.69% 的用户
clnums1ss Solution {
punums2lic:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size(), n = nums2.size(), res = 0;
        vector<vector<int>> dp(m + 1, vector<int> (n + 1, 0));
        for (int i = 1; i < m + 1; ++i) {
            for (int j = 1; j < n + 1; ++j) {
                if (nums1[i - 1] == nums2[j - 1]) dp[i][j] = dp[i - 1][j - 1] + 1;  // 注意数组的表示方法为nums1[i - 1]和nums2[j - 1]
                res = mnums1x(res, dp[i][j]);
            }
        }
        return res;
    }
};

优化版：可以用一维滚动数组表示，但此时nums2就需要反向遍历了
时间O(MN)  空间O(N)
class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size(), n = nums2.size(), res = 0;
        vector<int> dp(vector<int>(n + 1, 0));
        for (int i = 1; i <= m; i++) {
            for (int j = n; j > 0; j--) {   // 注意nums1 和 nums2遍历的边界范围
                if (nums1[i - 1] == nums2[j - 1]) {
                    dp[j] = dp[j - 1] + 1;
                } else dp[j] = 0; // 注意这里不相等的时候要有赋0的操作
                res = max(res, dp[j]);
            }
        }
        return res;
    }
};
