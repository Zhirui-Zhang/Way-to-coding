法1：DP法+双指针法，判断如何内层循环时出错了，其实一维dp数组即可，只不过需要每次从0开始判断之前是否存在回文子串
时间O(N^3)  空间O(N)  这个内层每次都需要循环遍历，浪费时间，如果事先用dp数组存储是否回文可使时间降为O(N^2) 空间O(N^2)
执行用时：384 ms, 在所有 C++ 提交中击败了5.02% 的用户
内存消耗：6.4 MB, 在所有 C++ 提交中击败了94.88% 的用户
class Solution {
public:
    int minCut(string s) {
        int n = s.size();
        vector<int> dp(n, n);           // 初始化为n个n，也就是最多分割不超过n次，dp[i]表示范围[0, i]的回文子串的最少分割次数
        for (int i = 0; i < n; ++i) {
            if (checkS(s, 0, i)) {      // 如果[0, i]是回文，不需要切割
                dp[i] = 0;
                continue;
            }
            for (int j = 0; j < i; ++j) {   // 否则从头遍历判断，若之前存在回文子串，+1比较是否更少即可
                if (checkS(s, j + 1, i)) dp[i] = min(dp[i], dp[j] + 1);     // 状态转移方程为dp[i] = min(dp[i], dp[j] + 1)
            }
        }
        return dp[n - 1];       // 返回最后一个元素
    }

private:
    bool checkS(string& s, int left, int right) {
        while (left <= right) {
            if (s[left] != s[right]) return false;
            left++;
            right--;
        }
        return true;
    }
};

法2：DP法，不需要每次都遍历s字符串，事先用一个dp数组存储回文子串情况，降低时间复杂度
时间O(N^2)  空间O(N^2)
执行用时：36 ms, 在所有 C++ 提交中击败了84.37% 的用户
内存消耗：8 MB, 在所有 C++ 提交中击败了60.63% 的用户
class Solution {
public:
    int minCut(string s) {
        int n = s.size();
        vector<vector<bool>> isPalindromic(n, vector<bool>(n, false));
        for (int i = n - 1; i >= 0; i--) {      // 反向遍历，即方向为从下到上，从左到右
            for (int j = i; j < n; j++) {
                if (s[i] == s[j] && (j - i <= 1 || isPalindromic[i + 1][j - 1])) {
                    isPalindromic[i][j] = true;
                }
            }
        }

        // 之后写法与上面法1相同
        vector<int> dp(n, n);
        for (int i = 1; i < n; i++) {
            if (isPalindromic[0][i]) {
                dp[i] = 0;
                continue;
            }
            for (int j = 0; j < i; j++) {
                if (isPalindromic[j + 1][i]) {
                    dp[i] = min(dp[i], dp[j] + 1);
                }
            }
        }
        return dp[n - 1];

    }
};
