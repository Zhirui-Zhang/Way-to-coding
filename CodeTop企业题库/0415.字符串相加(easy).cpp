法1：双指针法，如果把两个string分别转换成int是不行的，会发生长度溢出，只能逐个位加减模拟
时间O(N)  空间O(1)
执行用时：4 ms, 在所有 C++ 提交中击败了67.94% 的用户
内存消耗：6.5 MB, 在所有 C++ 提交中击败了82.68% 的用户
class Solution {
public:
    string addStrings(string num1, string num2) {
        int i = num1.length() - 1, j = num2.length() - 1, carry = 0;    // carry表示当前长度是否需要进位
        string res;
        while (i >= 0 || j >= 0) {      // 注意这里的处理方法，只有当i j都 < 0时才说明加法结束，退出循环即可
            int x = (i >= 0) ? num1[i] - '0' : 0;   // 若当前小于0，说明该数字已遍历结束，赋0就行
            int y = (j >= 0) ? num2[j] - '0' : 0;
            int tmp = x + y + carry;
            res.push_back('0' + tmp % 10);  // 加上'0'转换为char类型
            carry = tmp / 10;           // 计算下次是否需要进位
            --i;
            --j;
        }
        if (carry == 1) res.push_back('1');   // 注意如果两个数字都遍历结束，仍需要进位时，在最后加个1！！！
        // 计算完以后的答案需要翻转过来
        reverse(res.begin(), res.end());
        return res;
    }
};
