法1：数学方法，果然有数学推导，最多四个值，记住即可，后面还有DP适合死记硬背
时间O(根号N)  空间O(1)
执行用时：0 ms, 在所有 C++ 提交中击败了100.00% 的用户
内存消耗：5.9 MB, 在所有 C++ 提交中击败了93.80% 的用户
class Solution {
private:
    bool isAnswer1(int n)
    {
        int i = 1;
        while(i*i < n)    ++i;
        if(i*i == n)    return true;
        else    return false;
    }
    bool isAnswer4(int n)
    {
        while(n % 4 == 0)    n /= 4;
        if(n % 8 == 7)    return true;
        else    return false;
    }
public:
    int numSquares(int n) {
        if(isAnswer1(n))    return 1;     // 如果是平方数如4 9 16 25，返回1
        if(isAnswer4(n))    return 4;     // 如果为4^k(8m+7)，返回4
        for(int i = 1; i*i < n; ++i)      // 如果为n=a^2+b^2，枚举所有a^2，查看是否为b^2，返回2，否则返回3
        {
            int j = n - i * i;
            if(isAnswer1(j))    return 2;
        }
        return 3;
    }
};

法2：DP法，统计每个值对应的个数，每次更新自身和前一个平方和+1的数，返回dp[n]即可
时间O(N根号N)  空间O(N)
执行用时：196 ms, 在所有 C++ 提交中击败了26.90% 的用户
内存消耗：8.8 MB, 在所有 C++ 提交中击败了62.19% 的用户
int numSquares(int n)
{
    vector<int> dp(n+1, INT_MAX); // 每个数的最优解都存在dp数组里
    dp[0] = 0;
    for (int i = 1; i <= n; i++){
        for(int j = 1; i-j*j >= 0 ; j++) {  // 观察比N小的数，且符合N = IxI + N'的数值
            dp[i] = min(dp[i], dp[i-j*j] + 1); // 把最优解（最小值）+ 1 写入result
        }
    }
    return dp[n];
}
