法1：DP，一眼DP，就是做不出来，状态转移方程确实不好想，写在记事本上，就是每次遍历时，记录当前所有乘积中的最大值和最小值，并更新res即可，记录最小值的目的是有可能下一轮成为最大值的因数
时间O(N)  空间O(1)
执行用时：12 ms, 在所有 C++ 提交中击败了12.18% 的用户
内存消耗：13.3 MB, 在所有 C++ 提交中击败了81.35% 的用户
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int curMax = nums[0], curMin = nums[0], res = nums[0];
        for(int i = 1; i < nums.size(); ++i)
        {
            int a = curMax, b = curMin;    // 注意要用a b记录，因为下面可能会更改curMax curMin的值，需要提前保存
            curMax = max({nums[i], a*nums[i], b*nums[i]});    // 更新现有的最大值 & 最小值
            curMin = min({nums[i], a*nums[i], b*nums[i]});
            res = max(res, curMax);        // 更新res的值，注意与当前最大值比较即可
        }
        return res;
    }
};
