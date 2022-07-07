法1：原地哈希法，其实已经想的一模一样了，把应有的元素置换到合适的坑里，可惜判断条件少了一个重复元素情况，导致没过，气死了
时间O(N)每个元素最多判断两次，最后再遍历一次  空间O(1)
执行用时：124 ms, 在所有 C++ 提交中击败了60.54% 的用户
内存消耗：80.9 MB, 在所有 C++ 提交中击败了96.39% 的用户
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        for (int i = 0; i < n; ++i) {
            while (nums[i] != i + 1) {  // 例：当 nums[0] != 1  nums[1] != 2 时
                if (nums[i] <= 0 || nums[i] > n || nums[i] == nums[nums[i] - 1]) break;
                // 这里的判断很重要！如果nums[i]不在[1, n]里或者出现两个重复元素如nums = [1, 1]，break退出
                swap(nums[i], nums[nums[i] - 1]);   // 否则交换
            }
        }
        for (int i = 0; i < n; ++i) {
            if (nums[i] != i + 1) return i + 1;     // 最后遍历一次原nums数组，找到坑位不对的元素
        }
        return n + 1;       // 若遍历一遍都不存在，返回最大值n + 1
    }
};