法1：string自带函数删除erase  子串substr  拼接+=
执行用时：4 ms, 在所有 C++ 提交中击败了78.58% 的用户
内存消耗：7.4 MB, 在所有 C++ 提交中击败了53.45% 的用户
class Solution {
public:
    string reverseLeftWords(string s, int n) {
        if(s.empty())   return s;
        string temp = s.substr(0, n);
        s.erase(0, n);
        s += temp;
        return s;
    }
};

法2：巧解，扩展s为原来2倍
执行用时：0 ms, 在所有 C++ 提交中击败了100.00% 的用户
内存消耗：7.7 MB, 在所有 C++ 提交中击败了30.74% 的用户
class Solution {
public:
    string reverseLeftWords(string s, int n) {
        int len = s.size();
        s += s;
        return s.substr(n, len);
    }
};

法3：增加难度，不能申请额外空间，只能在本串上操作——三次反转法
执行用时：4 ms, 在所有 C++ 提交中击败了78.58% 的用户
内存消耗：7 MB, 在所有 C++ 提交中击败了81.24% 的用户
class Solution {
public:
    string reverseLeftWords(string s, int n) {
        reverse(s.begin(), s.begin()+n);
        reverse(s.begin()+n, s.end());
        reverse(s.begin(), s.end());
        return s;
    }
};
