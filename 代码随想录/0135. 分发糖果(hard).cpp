法1：贪心+dp，关键在于正反两趟遍历，一次比较递增，一次比较递减，同时反向遍历的时候需要注意增加判断条件，否则最高点还会加1导致错误
举例：[1 2 3 2 1] [1 2 87 87 87 2 1] [1 3 2 2 1]
时间O(N)  空间O(N)
执行用时：12 ms, 在所有 C++ 提交中击败了97.17% 的用户
内存消耗：17.2 MB, 在所有 C++ 提交中击败了76.49% 的用户
class Solution {
public:
    int candy(vector<int>& ratings) {
        int sum = 0, n = ratings.size();
        vector<int> dp(n, 1);   // 定义dp数组，初始为n个1

        for (int i = 1; i < n; ++i) {
            if (ratings[i - 1] < ratings[i]) {     // 正向遍历，比较连续递增的两个数
                dp[i] = dp[i - 1] + 1;
            }
        }
        for (int i = n - 2; i >= 0; --i) {
            if (ratings[i + 1] < ratings[i] && dp[i] <= dp[i + 1]) {
                dp[i] = dp[i + 1] + 1;                          // 反向遍历时注意最后一个条件，满足dp[i-1] <= dp[i]时才增加
            }
        }
        for (auto d : dp) {     // 计算dp数组的糖果总数和
            sum += d;
        }
        return sum;
    }
};