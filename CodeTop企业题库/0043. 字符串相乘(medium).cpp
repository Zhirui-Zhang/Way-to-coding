法1：模拟法，完全按照乘法的计算思路，并借助之前415的字符串相加，模拟字符串相乘，有细节需要注意
时间O(MN+N^2)相乘O(MN)+相加O(M(M+N))  空间O(M+N)存储最长相乘长度为M+N
执行用时：12 ms, 在所有 C++ 提交中击败了39.78% 的用户
内存消耗：9.7 MB, 在所有 C++ 提交中击败了36.01% 的用户
class Solution {
public:
    string multiply(string num1, string num2) {
        if (num1 == "0" || num2 == "0") return "0";     // 如果有0字符串需要特殊注意，与其他数字进位情况不同，直接返回0即可
        string res;
        int n1 = num1.size() - 1, n2 = num2.size() - 1;
        for (int i = 0; i <= n1; ++i) {                 // 注意相乘顺序，如 123 * 456  可先计算123*4+0=492 再492*10 + 123*5=5535 再 5535*10+ 123*6=56088
            string tmp;
            int carry = 0;
            for (int j = n2; j >= 0; --j) {
                int num = (num1[i] - '0') * (num2[j] - '0') + carry;
                tmp += (num % 10 + '0');
                carry = num / 10;
            }
            if (carry != 0) tmp += (carry + '0');       // 注意和加法不同，乘法可能出现更大的值，不止为1
            reverse(tmp.begin(), tmp.end());
            res += '0';                                 // 每次相加前对上一次的结果后面补一个0，符合乘法计算步骤
            res = plus(res, tmp);
        }
        return res;
    }

private:
    string plus(string& s1, string& s2) {
        string res;
        int n1 = s1.size() - 1, n2 = s2.size() - 1;
        int carry = 0;
        for (; n1 >= 0 || n2 >= 0; --n1, --n2) {        // 相加判断退出条件，很关键
            int a = (n1 >= 0) ? s1[n1] - '0' : 0;
            int b = (n2 >= 0) ? s2[n2] - '0' : 0;
            int num = a + b + carry;
            res += (num % 10 + '0');
            carry = num / 10;
        }
        if (carry == 1) res += '1';                     // 决定是否多一位
        reverse(res.begin(), res.end());
        return res;
    }
};