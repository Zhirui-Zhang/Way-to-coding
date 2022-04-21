法1.双指针法，左右各一个指针，维护当前的最高的水柱和盛水量
时间O(N)  空间O(1)
执行用时：60 ms, 在所有 C++ 提交中击败了96.84% 的用户
内存消耗：57.6 MB, 在所有 C++ 提交中击败了68.63% 的用户
class Solution {
public:
    int maxArea(vector<int>& height) {
        int res = 0, left = 0, right = height.size() - 1;
        while(left < right)
        {
            int temp = (right - left) * min(height[left], height[right]);
            res = max(temp, res);
            if(height[left] <= height[right])    left++;
            else right--;
        }
        return res;
    }
};
