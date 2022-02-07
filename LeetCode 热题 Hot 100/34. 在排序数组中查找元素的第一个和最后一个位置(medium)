法1：二分法，并不是完全的二分法，在找到target目标值后仍为遍历，时间复杂度最坏为O(N)，应改进
时间O(N)  空间(1)
执行用时：8 ms, 在所有 C++ 提交中击败了61.45% 的用户
内存消耗：13.2 MB, 在所有 C++ 提交中击败了78.47% 的用户
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> res(2, -1);
        int n = nums.size();
        int left = 0, right = n - 1;
        while(left <= right)
        {
            int mid = (left + right) / 2;
            if(nums[mid] > target)    right = mid - 1;
            else if(nums[mid] < target)    left = mid + 1;
            else
            {
                left = mid - 1, right = mid + 1;    // 左右开弓找边界范围
                while(left >= 0 && nums[left] == target)    left--;
                res[0] = left + 1;
                while(right < n && nums[right] == target)    right++;
                res[1] = right - 1;
                break;
            }
        }
        return res;
    }
};

法2：改进版
时间O(logN)  空间O(N)
执行用时：4 ms, 在所有 C++ 提交中击败了94.51% 的用户
内存消耗：13.3 MB, 在所有 C++ 提交中击败了41.92% 的用户
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> res(2, -1);
        int n = nums.size();
        if(n == 0)    return res;       // 特殊情况需要考虑，否则下面nums[left]可能会越界
        int left = 0, right = n - 1;
        while(left < right)     // 寻找左边界，利用模板1
        {
            int mid = (left + right) / 2;
            if(nums[mid] >= target)    right = mid;
            else    left = mid + 1;
        }
        if(nums[left] != target)    return res;     // 若左边界不存在，直接返回res
        res[0] = left;                              // 若存在，存入res[0]即左边界，重置right
        right = n - 1;
        while(left < right)     // 寻找右边界，利用模板2，注意此时left不为0，目的是缩小搜索范围
        {
            int mid = (left + right + 1) / 2;
            if(nums[mid] <= target)    left = mid;
            else    right = mid - 1;
        }
        res[1] = right;                             // 存入res[1]右边界
        return res;
    }
};
