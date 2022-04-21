法1：双指针法，从后往前遍历，遇到空格判断是否是多余空格，若不是，在s后追加该部分单词，注意最后需要判断是否有首个单词遗漏
时间O(N)  空间O(N) 并不是O(1)
执行用时：0 ms, 在所有 C++ 提交中击败了100.00% 的用户
内存消耗：7.2 MB, 在所有 C++ 提交中击败了29.21% 的用户
class Solution {
public:
    string reverseWords(string s) {
        int n = s.size();
        int i = n - 1, j = n;
        for (; i >= 0; i--) {
            if (s[i] == ' ') {
                if (j == i + 1) {     // 若为邻接空格，则跳过
                    j--;
                } else {
                    s += s.substr(i + 1, j - i - 1);
                    s += ' ';
                    j = i;
                }
            }
        }
        if (s[0] != ' ') {              // 注意判断首个字符是否为空格，不为空格需要追加首单词，为空格则需删除末尾多余空格
            s += s.substr(0, j);
        } else {
            s.pop_back();
        }
        return s.substr(n);
    }
};

法2：空间为O(1)的解法，比较麻烦一点，先把多余的空格删掉，然后整体反转，随后针对每一个单词再次反转，达到最终效果
时间O(N)  空间O(1)
执行用时：0 ms, 在所有 C++ 提交中击败了100.00% 的用户
内存消耗：6.9 MB, 在所有 C++ 提交中击败了70.52% 的用户
class Solution {
public:
    string reverseWords(string s) {
        removeSpace(s);
        reverse(s, 0, s.size() - 1);        
        for (int i = 0, j = 0; j <= s.size(); ++j) {    // j的范围到了s.size()，与一般的取值范围不同！！！
            if (j == s.size() || s[j] == ' ') {     // 注意这里对最后一个单词的处理方法
                reverse(s, i, j - 1);
                i = j + 1;
            }
        }
        return s;
    }
    
private:
    void removeSpace(string& s) {       // 关键代码，将前后中间的多余代码都删除
        int i = 0, j = 0;
        for (; j < s.size(); ++j) {
            if (s[j] != ' ') {
                if (i != 0) {
                    s[i++] = ' ';
                }
                while (j < s.size() && s[j] != ' ') {
                    s[i++] = s[j++];
                }
            }
        }
        s.resize(i);                // 注意这里的写法，将s多余的空格都删除后，调整大小为i，就可以把后面没用的字符直接删除了
    }

    void reverse(string& s, int left, int right) {
        for (; left < right; left++, right--) {
            swap(s[left], s[right]);
        }
    }
};
