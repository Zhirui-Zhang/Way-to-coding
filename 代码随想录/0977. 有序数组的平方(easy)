法1：双指针法，真巧妙啊，不看答案我还真不一定想出这么好的解法
时间O(N)  空间O(1)
执行用时：24 ms, 在所有 C++ 提交中击败了82.49% 的用户
内存消耗：25.2 MB, 在所有 C++ 提交中击败了66.23% 的用户
class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n, 0);
        int i = 0, j = n - 1, k = n - 1;  
        while (i <= j) {        // 注意这里的条件是<=，因为要考虑最后一个元素
            if (nums[i] * nums[i] < nums[j] * nums[j]) {
                res[k] = nums[j] * nums[j];
                k--;
                j--;
            } else {
                res[k] = nums[i] * nums[i];
                k--;
                i++;
            }
        }
        return res;
    }
};
