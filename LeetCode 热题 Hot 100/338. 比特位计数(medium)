法1：n&n-1法，套用以前做过的题写出的结果，不是严格的O(N)复杂度，也没有用到DP，有待改进
时间O(N)一个数最多只有32个1，所以时间最大为O(32N)  空间O(1)
执行用时：8 ms, 在所有 C++ 提交中击败了22.93% 的用户
内存消耗：7.7 MB, 在所有 C++ 提交中击败了49.18% 的用户
class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> res(n+1, 0);
        for(int i = 0; i < n + 1; ++i){
            int temp = i;
            while(temp != 0){
                res[i]++;
                temp &= temp - 1;
            }
        }
        return res;
    }
};

法2：DP，自从数字2之后每次都是前2^N个数字所有位数和+1，所以用DP数组记录每一轮的1个数，遍历一次即可得出答案
时间O(N)  空间O(1)
执行用时：4 ms, 在所有 C++ 提交中击败了84.60% 的用户
内存消耗：7.7 MB, 在所有 C++ 提交中击败了58.65% 的用户
class Solution {
public:
    vector<int> countBits(int n) {
        if(n == 0)    return {0};   // 特殊情况返回0
        vector<int> dp(n+1, 1);     // 初始都设为1，只有dp[0]=0
        dp[0] = 0;
        for(int pow = 2; pow <= n; pow *= 2){   // pow表示当前的指数下标范围，每次*2
            for(int i = pow; i <= n && i < 2 * pow; ++i){   // i从pow开始遍历，同时注意不要超过n，每次都为1+dp[i-pow]即可
                dp[i] += dp[i-pow];
            }
        }
        return dp;
    }
};
