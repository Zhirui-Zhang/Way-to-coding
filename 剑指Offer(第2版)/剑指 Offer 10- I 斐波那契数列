法1：迭代法（动态规划？，不是很懂具体含义），官方解法中有用矩阵的，复杂度O(logn)，算了不学了
执行用时：0 ms, 在所有 C++ 提交中击败了100.00% 的用户
内存消耗：5.8 MB, 在所有 C++ 提交中击败了68.06% 的用户
class Solution {
public:
    int fib(int n) {
        if(n <= 1)  return n;
        int res = 0, temp = 0, temp_=1;
        for(int i = 2; i <= n; i++)
        {
            res = (temp + temp_) % 1000000007;  //注意结果要对给定数字取余，否则会报错
            temp = temp_;
            temp_ = res;
        }
        return res;
    }
};
