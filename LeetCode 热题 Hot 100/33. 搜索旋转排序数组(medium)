法1：二分法，关键点在于第一次分割一定会分成两段数组[left, mid-1]和[mid, right]，其中一个数组有序，根据这个有序的数组决定下一次循环的边界方向
例：[4 5 6 7 0 1 2] 为左侧[left, mid-1]=[4 5 6]有序 和 [6 7 0 1 2 4 5]为右侧[mid, right]=[1 2 4 5]有序
时间O(logN)  空间O(1)
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int left = 0, right = n - 1;
        while(left <= right)
        {
            int mid = (left + right) / 2;
            if(nums[mid] == target)    return mid;  // 等于中点值返回
            if(nums[mid] > nums[right])     // 右侧无序，左侧有序，从左侧判断下一步边界
            {
                if(nums[left] == target)    return left;  // 等于左端点值返回
                if(target > nums[left] && target < nums[mid])   right = mid - 1;  // 若在左侧范围内，缩短右边界right
                else    left = mid + 1;                                           // 否则可能在右侧无序数组中，缩短左边界left
            }
            else                            // 左侧无序，右侧有序，从左侧判断下一步边界
            {
                if(nums[right] == target)    return right;  // 以下同理
                if(target > nums[mid] && target < nums[right])   left = mid + 1;
                else    right = mid - 1;
            }
        }
        return -1;
    }
};
