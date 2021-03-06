法1：递归法，根据正负奇偶条件分四种确定返回情况，其中核心思想是 x^n = (1/x)^(-n)  x^(2n) = (x^2)^n
！注意特殊情况 n = -2^31 = -2147483648时，不能直接使 n = -n 因为最大为2^31-1越界了！
！解决方法1：使用long类型代替-n  2:利用 -3/2 = -2余1的特性！
执行用时：0 ms, 在所有 C++ 提交中击败了100.00% 的用户
内存消耗：5.7 MB, 在所有 C++ 提交中击败了99.50% 的用户
class Solution {
public:
    double myPow(double x, int n) {
        if(n == 0)      return (double)1;
        if(n == -1)     return 1.0 / x;
        if(n & 1 == 1)    return x * myPow(x*x, n>>1);  //若n为奇数，返回 x * mypow()
        else    return myPow(x*x, n>>1);
    }
};

法2：迭代法  
执行用时：0 ms, 在所有 C++ 提交中击败了100.00% 的用户
内存消耗：5.7 MB, 在所有 C++ 提交中击败了93.47% 的用户
class Solution {
public:
    double myPow(double x, int n) {
        // if(n == 0)      return (double)1;  这里初始res = 1.0 可省去n=0的特殊情况
        long b = n;  //使用长整型避免出现越界情况
        double res = 1.0;
        if(b < 0)     
        {
            x = 1/x;
            b = -b;
        }
        while(b > 0)
        {
            if((b & 1) == 1)    res *= x;   //若为奇数，多乘一次
            x *= x; 
            b >>= 1;
        }
        return res;
    }
};
