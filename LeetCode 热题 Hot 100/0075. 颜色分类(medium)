法1：双指针法，前后各一个指针，能实现一趟遍历    注意需要先循环交换右指针，再交换左指针，避免交换后仍不为正序排列
时间O(N)  空间O(1)
执行用时：0 ms, 在所有 C++ 提交中击败了100.00% 的用户
内存消耗：8.1 MB, 在所有 C++ 提交中击败了27.81% 的用户
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int left = 0, right = nums.size() - 1;
        for(int i = 0; i <= right; ++i)
        {
            while(i < right && nums[i] == 2)    // 当前为2时一直与右指针交换，并左移右指针
            {
                swap(nums[i], nums[right]);
                right--;
            }
            if(nums[i] == 0)                    // 当前为0时，与左指针交换并右移左指针
            {
                swap(nums[i], nums[left]);
                left++;
            }
        }
    }
};



