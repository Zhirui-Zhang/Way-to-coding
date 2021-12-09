法1：遍历数组（不推荐）
执行用时：24 ms, 在所有 C++ 提交中击败了7.33% 的用户
内存消耗：16.7 MB, 在所有 C++ 提交中击败了48.17% 的用户
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int i = 0;
        for(; i < nums.size(); i++)
        {
            if(nums[i] != i)    return i;
        }
        return i;
    }
};

法2：二分法
执行用时：12 ms, 在所有 C++ 提交中击败了86.83% 的用户
内存消耗：16.6 MB, 在所有 C++ 提交中击败了86.92% 的用户
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int left = 0, right = nums.size() - 1;
        while(left <= right)
        {
            int mid = (left + right) / 2;
            if(mid == nums[mid])    left = mid + 1;
            else
            {
                right = mid - 1;
            }
        }
        return left;
    }
};
