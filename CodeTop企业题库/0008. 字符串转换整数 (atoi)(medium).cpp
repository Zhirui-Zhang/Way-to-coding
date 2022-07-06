法1：模拟法
时间O(N)  空间O(1)
执行用时：0 ms, 在所有 C++ 提交中击败了100.00% 的用户
内存消耗：6.8 MB, 在所有 C++ 提交中击败了87.48% 的用户
class Solution {
public:
    int myAtoi(string s) {
        long res = 0, pos = 0, n = s.size();
        bool negative = false;
        while (pos < n && s[pos] == ' ') ++pos;
        if (s[pos] == '-') {
            negative = true;
            ++pos;
        } else if (s[pos] == '+') ++pos;
        for (int i = pos; i < n; ++i) {
            if (s[i] >= '0' && s[i] <= '9') {
                res *= 10;
                res += s[i] - '0';      // 这里即使是000123也没关系，因为res * 0不变
                if (res > INT_MAX) return negative ? INT_MIN : INT_MAX;     // 这里很关键，如果为 INT_MAX+1或者-INT_MIN 大于INT_MAX，正好返回INT_MAX或INT_MIN
            }   
            else break;
        }
        return negative ? -res : res;
    }
};