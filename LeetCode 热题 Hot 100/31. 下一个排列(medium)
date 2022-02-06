法1：两次遍历扫描，第一次从后向前遍历找到相邻递增的数字位置，若存在再遍历找到大于该位置的一个数，交换后颠倒后面的数组
例：[1 5 8 4 7 6 5 3 1]   nums[left]=4 nums[right]=5
时间O(N)  空间O(1)
执行用时：4 ms, 在所有 C++ 提交中击败了73.14% 的用户
内存消耗：11.9 MB, 在所有 C++ 提交中击败了9.36% 的用户
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int left = nums.size() - 2, right = nums.size() - 1;
        while(left >= 0 && nums[left] >= nums[left+1])    left--;   // 第一次遍历，找到相邻递增的数字，即例中的4
        if(left >= 0)   // 如果left存在，二次遍历寻找仅次于left的right即5，否则就是完全递减数组，直接反转整个数组即可
        {
            while(nums[left] >= nums[right])    right--;
            swap(nums[left], nums[right]);    // 找到左右两个位置后交换这两个数
        }
        for(left++, right = nums.size()-1; left < right; left++, right--)   // 手动实现reverse(nums.begin()+left+1, nums.end())函数，可直接替换，目的是反转left之后的数组
        {
            swap(nums[left], nums[right]);
        }
    }
};


法2：STL函数库直接调用即可，复杂度与手动实现相同变
执行用时：8 ms, 在所有 C++ 提交中击败了23.35% 的用户
内存消耗：11.8 MB, 在所有 C++ 提交中击败了34.15% 的用户
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        next_permutation(nums.begin(), nums.end());
    }
};
