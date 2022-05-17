法1：贪心法，真的是简单题吗，有点难过，先排序，对负数取反并求总和
若最后k为0或为偶数说明所有可变负数已转换，直接返回sum，否则再次排序，减去最小的数即可
时间O(NlogN)  空间O(logN)
执行用时：4 ms, 在所有 C++ 提交中击败了89.47% 的用户
内存消耗：8.8 MB, 在所有 C++ 提交中击败了49.68% 的用户
class Solution {
public:
    int largestSumAfterKNegations(vector<int>& nums, int k) {
        int sum = 0;
        sort(nums.begin(), nums.end());
        for (auto& num : nums) {            // 注意为了修改数组，使用auto&类型，否则num为拷贝后的的右值，无法修改
            if (num < 0 && k > 0) {
                num = -num;
                --k;
            }
            sum += num;
        }
        if (k % 2 == 0) return sum;         // 隐含k为0
        sort(nums.begin(), nums.end());     // 否则此时原数组一定都为正数，需要找到其中的最小值
        return sum - 2 * nums[0];           // 排序后减去二倍的最小值即可
    }
};