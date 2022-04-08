法1：DP法，老生常谈了，解法略
时间O(N)  空间O(1)
执行用时：0 ms, 在所有 C++ 提交中击败了100.00% 的用户
内存消耗：5.8 MB, 在所有 C++ 提交中击败了70.26% 的用户
class Solution {
public:
    int climbStairs(int n) {
        int a = 0, b = 0, c = 1;
        for(int i = 0; i < n; ++i)
        {
            a = b;
            b = c;
            c = a + b;
        }
        return c;
    }
};
