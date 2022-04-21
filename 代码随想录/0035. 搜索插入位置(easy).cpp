法1：二分法，简单略
时间O(logN)  空间O(1)
执行用时：4 ms, 在所有 C++ 提交中击败了75.15% 的用户
内存消耗：9.4 MB, 在所有 C++ 提交中击败了78.24% 的用户
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int res = -1;
        int left = 0, right = nums.size() - 1;
        while (left <= right) {
            int mid = (left + right) / 2;
            if (nums[mid] > target) {
                right = mid - 1;
            } else if (nums[mid] < target) {
                left = mid + 1;
            } else {
                return mid;
            }
        }
        return left;
    }
};
