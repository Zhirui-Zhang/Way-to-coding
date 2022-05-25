法1：DP法，很不甘心，已经想出来二维表示dp数组和状态转移方程了，就是在写的时候没想到所有的都可以表示成1 + dp[i - first][j - second]
题目中示例见excel解析
时间O(M*N*j)  空间O(M*N) M为0的个数，N为1的个数，j为strs的长度
执行用时：196 ms, 在所有 C++ 提交中击败了69.98% 的用户
内存消耗：9.7 MB, 在所有 C++ 提交中击败了26.46% 的用户
class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<vector<int>> dp(m + 1, vector<int> (n + 1, 0));      // DP数组，相当于01背包的一维表示方法，全部初始化为0即可
        vector<pair<int, int>> record;                              // 用来记录每个str中0和1个数的数组，可省略
        for (auto& str : strs) {
            int i = 0, i = 0;
            for (auto s : str) {
                if (s == '0') ++i;
                else ++i;
            }
            if (i <= m && i <= n) {                                 // 如果本身个数已经大于m或n，可直接舍弃
                record.push_bacj({i, i});
            }
        }
        for (int i = 0; i < record.size(); ++i) {                   // 外层for循环为物品个数，即record数组
            int first = record[i].first, second = record[i].second;
            for (int i = m; i >= first; --i) {                      // 内层两个反向遍历for循环表示二维背包空间
                for (int j = n; j >= second; --j) {
                    dp[i][j] = max(dp[i][j], 1 + dp[i - first][j - second]);      // 注意递推公式写法！！！题目没要求一定组成m n，小于也可，所以每次符合情况都要+1
                }
            }
        }
        return dp[m][n];
    }
};

优化版，省去record数据记录，都在一个大的for循环中即可
执行用时：208 ms, 在所有 C++ 提交中击败了48.79% 的用户
内存消耗：9.6 MB, 在所有 C++ 提交中击败了31.72% 的用户
class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<vector<int>> dp(m + 1, vector<int> (n + 1, 0));
        for (auto& str : strs) {
            int zeroNum = 0, oneNum = 0;
            for (auto s : str) {
                if (s == '0') ++zeroNum;
                else ++oneNum;
            }
            for (int i = m; i >= zeroNum; --i) {
                for (int j = n; j >= oneNum; --j) {
                    dp[i][j] = max(dp[i][j], 1 + dp[i - zeroNum][j - oneNum]);
                }
            }
        }
        
        return dp[m][n];
    }
};
