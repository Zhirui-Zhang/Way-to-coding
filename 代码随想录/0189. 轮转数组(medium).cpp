法1：原地旋转法，做过的题，三次旋转，注意判断一下k如果大于n应取余即可
时间O(N)  空间O(1)
执行用时：28 ms, 在所有 C++ 提交中击败了44.13% 的用户
内存消耗：24.4 MB, 在所有 C++ 提交中击败了57.94% 的用户
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k = k % n;      // 将k取余
        if (k == 0) return;
        int left = 0, right = n - k - 1;
        while (left < right) swap(nums[left++], nums[right--]);
        left = n - k, right = n - 1;
        while (left < right) swap(nums[left++], nums[right--]);
        left = 0, right = n - 1;
        while (left < right) swap(nums[left++], nums[right--]);
    }
};

优化版：利用reverse函数
执行用时：24 ms, 在所有 C++ 提交中击败了72.68% 的用户
内存消耗：24.3 MB, 在所有 C++ 提交中击败了82.02% 的用户
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k = k % n;
        if (k == 0) return;
        reverse(nums.begin(), nums.end());
        reverse(nums.begin(), nums.begin() + k);
        reverse(nums.begin() + k, nums.end());
    }
};