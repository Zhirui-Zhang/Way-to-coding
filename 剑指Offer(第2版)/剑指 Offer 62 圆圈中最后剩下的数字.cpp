法1：DP法，最最关键的点在于最初的值也就是最后剩余的数的下标为0，即f(1,m)=0  依次递推前面的函数值，直至f(n,m)
时间O(N)  空间O(1)  在草纸上画出来每一步的递推就可以看出来了
转移方程为： ！ f(n,m) = [f(n-1,m) + m] % n  ！
执行用时：4 ms, 在所有 C++ 提交中击败了97.77% 的用户
内存消耗：5.8 MB, 在所有 C++ 提交中击败了63.73% 的用户
class Solution {
public:
    int lastRemaining(int n, int m) {
        int pos = 0;                  // f(1,m) = 0
        for(int i = 2; i <= n; i++)   // 从f(2,m)开始即可
        {
            pos = (pos + m) % i;
        }
        return pos;                   // pos就是f(n,m)
    }
};

法2：递归法同理，但是空间复杂度变成O(N)了，反而复杂，故省略
