法1：dp法，根据每个字符特性动态规划下一位的个数，状态转移方程举例字符为'i'  dp[i][2] = dp[i-1][0]+dp[i-1][1]+dp[i-1][3]+dp[i-1][4]
！！！注意mod=1e9+7的写法！！！  栽在这上面了，每次提交都通过不了，淦
时间O(N)  空间O(1)
执行用时：8 ms, 在所有 C++ 提交中击败了49.19% 的用户
内存消耗：6 MB, 在所有 C++ 提交中击败了58.87% 的用户
class Solution {
public:
    int countVowelPermutation(int n) {
        long long mod = 1e9 + 7;    // 幂级数的写法！！！
        vector<long long> temp(5, 1);   // 初始数组temp
        vector<long long> dp(5, 0);
        for(int i = 1; i < n; ++i)
        {
            dp[0] = temp[1];
            dp[1] = (temp[0]+temp[2]) % mod;
            dp[2] = (temp[0]+temp[1]+temp[3]+temp[4]) % mod;
            dp[3] = (temp[2]+temp[4]) % mod;
            dp[4] = temp[0];
            temp = dp;    // 注意需要每次赋值dp数组给temp数组，以便下一次dp使用
        }
        return (temp[0] + temp[1] + temp[2] + temp[3] + temp[4]) % mod;    // 最后采用temp返回的好处是可以包含n=1的特殊情况，而不用特殊讨论了
    }
};
