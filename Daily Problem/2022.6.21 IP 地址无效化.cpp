法1：双指针法，很简单，做过类似题，从后向前遍历即可
时间O(N)  空间O(1)
执行用时：0 ms, 在所有 C++ 提交中击败了100.00% 的用户
内存消耗：5.7 MB, 在所有 C++ 提交中击败了88.49% 的用户
class Solution {
public:
    string defangIPaddr(string address) {
        int n = address.size();
        address.resize(n + 6);
        int j = address.size() - 1;
        for (int i = n - 1; i >= 0; --i) {
            if (address[i] == '.') {
                address[j--] = ']';
                address[j--] = '.';
                address[j--] = '[';
            }
            else address[j--] = address[i];
        }
        return address;
    }
};