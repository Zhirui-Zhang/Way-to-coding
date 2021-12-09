法1：动态规划？（迭代法）
执行用时：0 ms, 在所有 C++ 提交中击败了100.00% 的用户
内存消耗：5.8 MB, 在所有 C++ 提交中击败了75.54% 的用户
class Solution {
public:
    int numWays(int n) {
        if(n <= 1)  return 1;
        int res = 0, a = 1, b = 1;
        while(n > 1)
        {
            res = (a + b) % 1000000007;
            a = b;
            b = res;
            n--;
        }
        return res;
    }
};

