法1：双指针法，i始终指向第一个为0的位置，j寻找不为0的位置
时间O(N)  空间O(1)
执行用时：24 ms, 在所有 C++ 提交中击败了36.22% 的用户
内存消耗：18.8 MB, 在所有 C++ 提交中击败了24.21% 的用户
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();
        if(n == 1)    return;
        int i = 0, j = 1;
        while(j < n)
        {
            if(nums[i] == 0 && nums[j] != 0)
            {
                swap(nums[i], nums[j]);
                ++i;
            }
            if(nums[i] != 0)    i = j;
            ++j;
        }
        return;
    }
};

改进版：只考虑右指针是否为0即可
执行用时：16 ms, 在所有 C++ 提交中击败了87.17% 的用户
内存消耗：18.8 MB, 在所有 C++ 提交中击败了53.72% 的用户
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();
        for (int i = 0, j = 0; j < n; ++j) {
            if (nums[j] != 0) {
                swap(nums[i], nums[j]);
                i++;
            }
        }
        return;
    }
};
