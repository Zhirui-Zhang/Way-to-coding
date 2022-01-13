法1：双指针法，记录数组中最大值和次大值，最后判断
时间O(N)  空间O(1)
执行用时：0 ms, 在所有 C++ 提交中击败了100.00% 的用户
内存消耗：10.7 MB, 在所有 C++ 提交中击败了15.49% 的用户
class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        if(nums.size() == 1)    return 0;
        int first = INT_MIN, second = nums[0], index = 0;
        for(int i = 1; i < nums.size(); ++i)
        {
            if(nums[i] > second)    
            {
                first = second;
                second = nums[i];
                index = i;
            }
            else if(nums[i] > first)    first = nums[i];
        }
        return second >= 2 * first ? index : -1;
    }
};
