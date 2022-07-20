法1：二分法，由于题目给定相邻元素不相等，且左右边界为-∞，则如果中间元素小于右边元素，一定存在元素符合峰值要求，没必要前后加入两个元素，直接下标比较即可
时间O(logN)  空间O(1)
执行用时：0 ms, 在所有 C++ 提交中击败了100.00% 的用户
内存消耗：8.5 MB, 在所有 C++ 提交中击败了86.36% 的用户
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int left = 0, right = nums.size() - 1;
        while (left < right) {      // 注意边界是left < right且right = nums.size() - 1
            int mid = (left + right) / 2;
            if (nums[mid] < nums[mid + 1]) left = mid + 1;
            else right = mid;
        }
        return left;
    }
};