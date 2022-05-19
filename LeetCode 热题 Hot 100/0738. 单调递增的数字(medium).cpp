法1：贪心法，太蠢了，完全没想到用字符串处理比较好，还在傻乎乎的逐位取余，除10，再乘10加回来，我是SB
时间O(logN)  空间O(logN)表示数字n的位数
执行用时：0 ms, 在所有 C++ 提交中击败了100.00% 的用户
内存消耗：5.7 MB, 在所有 C++ 提交中击败了92.50% 的用户
class Solution {
public:
    int monotoneIncreasingDigits(int n) {
        if (n <= 9) return n;       // 特殊情况可省略
        string s = to_string(n);    // 转换成字符串处理省了很多麻烦！！！避免如10000变成9999时少了一位，非常不好处理
        // flag用来标记赋值9从哪里开始
        // 设置为这个默认值，为了防止第二个for循环在flag没有被赋值的情况下执行
        int flag = s.size();
        for (int i = s.size() - 1; i > 0; --i) {    // 反向遍历字符串，因为如332正向遍历的话，先为329，然后3又大于2没法处理
            if (s[i - 1] > s[i] ) {
                flag = i;       // 也不能直接让s[i] = '9'，比如10000就只变成了09000而非9999，必须要设置一个标志位flag指示从此开始全为'9'
                --s[i - 1];     // 注意这里字符'3'也可以直接--成'2'
            }
        }
        for (int i = flag; i < s.size(); ++i) {
            s[i] = '9';
        }
        return stoi(s);
    }
};

可以尝试一下正向遍历，很难处理的，尤其是10000这种，第一次变成09000，然后变成08900就不对了