法1：遍历模拟法，做过的题，把细节再巩固巩固，比如res初始为1，还有临时变量temp的使用，以[2 3 4 5]为例
时间O(N)  空间O(1)
执行用时：32 ms, 在所有 C++ 提交中击败了6.37% 的用户
内存消耗：23.4 MB, 在所有 C++ 提交中击败了70.29% 的用户
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();        // nums = [2 3 4 5]
        vector<int> res(n, 1);      //  res = [1 1 1 1]
        for(int i = 1; i < n; ++i)
        {
            res[i] = res[i-1] * nums[i-1];    // 遍历结果res = [1 2 6 24]
        }

        int temp = 1;
        for(int i = n - 2; i >= 0; --i)       
        {
            temp *= nums[i+1];                // temp 依次等于 5 20 60 （从后往前）
            res[i] *= temp;                   // 最后输出res = [60 40 30 24]
        }
        return res;
    }
};
