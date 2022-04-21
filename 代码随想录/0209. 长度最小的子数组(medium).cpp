法1：双指针+滑动窗口，认真审题啊！题目是连续数组和 >= target ！！！一直当 = 做的，难怪每次提交都过不了，气死
时间O(N)  空间(1)
执行用时：8 ms, 在所有 C++ 提交中击败了61.33% 的用户
内存消耗：10.4 MB, 在所有 C++ 提交中击败了13.45% 的用户
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int i = 0, j = 0, n = nums.size();
        int res = n + 1, tmp = 0;     // res随便设一个比n大的值即可，若不存在，返回0，tmp为当前窗口的子数组和
        for (; j < n; ++j) {
            tmp += nums[j];
            while (tmp >= target) {   // 注意while循环条件！！ >= ！！，只要 大于等于 就计算当前总长度并更新，随后滑动窗口
                res = min(res, j - i + 1);
                tmp -= nums[i++];
            }
        }
        return (res == n + 1) ? 0 : res;
    }
};
