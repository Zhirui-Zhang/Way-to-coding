法1：DP法，直接修改原数组，比较n-2和n-3中较大值加到自身即可，并注意每次更新res
时间O(N)  空间O(1)
执行用时：0 ms, 在所有 C++ 提交中击败了100.00% 的用户
内存消耗：7.5 MB, 在所有 C++ 提交中击败了61.51% 的用户
class Solution {
public:
    int rob(vector<int>& nums) {
        int res = 0, n = nums.size();
        if(n == 1)    return nums[0];
        if(n == 2)    return max(nums[0], nums[1]);
        nums[2] += nums[0];
        res = max(nums[1], nums[2]);
        for(int i = 3; i < n; ++i)
        {
            nums[i] += max(nums[i-2], nums[i-3]);
            res = max(res, nums[i]);
        }
        return res;
    }
};


优化版：用两个滚动变量即可，随时更新
时间O(N)  空间O(1)
class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1)    return nums[0];
        int first = nums[0], second = max(nums[0], nums[1]);
        for(int i = 2; i < n; ++i)
        {
            int temp = second;
            second = max(nums[i]+first, second);
            first = temp;
        }
        return second;
    }
};
