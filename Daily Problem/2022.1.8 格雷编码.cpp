法1：倒序对称生成法，很巧妙，难想到，每次基于上次生成的编码倒序依次加delta生成新的编码，进入下一轮之前将delta翻倍
例：初始[0 1]  delta = 2  之后依次加入 1+2  0+2  -> [0 1 3 2]  -> delta = 4 依次加入2+4 3+4 1+4 0+4 -> [0 1 3 2 6 7 5 4]
时间O(2^N)  空间O(1)
执行用时：8 ms, 在所有 C++ 提交中击败了71.63% 的用户
内存消耗：11.7 MB, 在所有 C++ 提交中击败了38.05% 的用户
class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> res;
        res.push_back(0);
        res.push_back(1);
        int delta = 2;    // 设置一个基数，表示数组下标2^n-1，初始为2，每轮循环后*2
        for(int i = 2; i <= n; ++i)
        {
            for(int j = delta - 1; j >= 0; j--)
            {
                res.push_back(res[j] + delta);
            }
            delta *= 2;
        }
        return res;
    }
};
