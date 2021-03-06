法1：DP太难想了，状态转移方程f(n,x) = (下i-1) ∑ (上6) * f(n−1,x−i) × 1/6   初始一个dp数组，为6个1/6，每次迭代时更新dp数组，最后输出
时间O(N^2) 循环n轮*每轮遍历n次     空间O(N) 除了题目中的dp外，temp数组需要n的空间
执行用时：0 ms, 在所有 C++ 提交中击败了100.00% 的用户
内存消耗：6.1 MB, 在所有 C++ 提交中击败了76.71% 的用户
class Solution {
public:
    vector<double> dicesProbability(int n) {
        vector<double> dp(6, 1.0/6.0);            // 初始数组，存放6个1/6
        for(int i = 2; i <= n; i++)
        {
            vector<double> temp(5 * i + 1, 0);    // 临时数组，长度为输出的长度即5n+1，类型为double
            for(int j = 0; j < dp.size(); j++)    // j从0一直到原始的dp长度
            {
                for(int k = 0; k < 6; k++)        // k永远是从0到5，用来更新每一轮迭代的temp数值
                {
                    temp[k + j] += dp[j] / 6.0;   // 更新temp，重点是temp的下标表示方法， k+j 正好遍历完每一次更新的所有下标  从0到5i共5i+1个数
                }
            }
            dp = temp;                            // 每一轮结束后深拷贝dp数组，实现对其的更新，便于下一轮迭代
        }
        return dp;                                // 结束后返回dp数组
    }
};
