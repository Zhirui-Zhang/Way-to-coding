法1：经典异或位运算题目
时间O(N)  空间O(1)
执行用时：20 ms, 在所有 C++ 提交中击败了35.28% 的用户
内存消耗：16.5 MB, 在所有 C++ 提交中击败了41.08% 的用户
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int temp = nums[0];
        for(int i = 1; i < nums.size(); ++i)    temp ^= nums[i];
        return temp;    
    }
};
