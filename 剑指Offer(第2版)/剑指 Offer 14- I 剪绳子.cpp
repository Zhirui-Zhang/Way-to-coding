法1：总结规律法，除n==2 3 两种特殊情况外，均符合特殊规律，即形似3*3*3或2*3*3或者3*3*4，判断n%3的值即可
时间O(logN)是pow函数内的复杂度  空间O(1)  为何结果不尽人意呢？
执行用时：0 ms, 在所有 C++ 提交中击败了100.00% 的用户
内存消耗：6.1 MB, 在所有 C++ 提交中击败了21.07% 的用户
class Solution {
public:
    int cuttingRope(int n) {
        if(n < 4)    return n-1;    // 特殊情况
        int index = n/3;            // 对n%3取模后三种情况分别进行讨论
        if(n % 3 == 0)    return pow(3, index); 
        if(n % 3 == 1)    return 4*pow(3, index-1);
        return 2*pow(3, index);
    }
};

法2：动态规划DP法，重点在于求解转移方程，弄明白前几个就全懂了
时间O(N^2)  空间O(N)
执行用时：0 ms, 在所有 C++ 提交中击败了100.00% 的用户
内存消耗：6.1 MB, 在所有 C++ 提交中击败了43.30% 的用户
class Solution {
public:
    int cuttingRope(int n) {
        vector<int> dp(n+1, 1);     // 初始化dp数组为n+1个1，否则会越界
        for(int i = 3; i < n + 1; i++)      // 数组下标从3开始求即可，因为之前都没有意义，毕竟题中的n>=2，一直到dp[n]
        {
            for(int j = 2; j < i; j++)      // 每次截的长度j从2开始，最大到i-1，其实到i/2就可以了，后面是对称的
            {
                dp[i] = max(dp[i], max(j*(i-j), j*dp[i-j]));    // 转移方程，即截掉长度j后若停止，为j*(i-j)，若不停止，则为j*dp[i-j]，取最大值与自身dp[i]对比后更新自身的值
            }
        }
        return dp[n];
    }
};
