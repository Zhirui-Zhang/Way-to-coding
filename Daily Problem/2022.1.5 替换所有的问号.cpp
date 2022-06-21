法1：遍历替换法，引入从a到z字符串temp，太麻烦了，有简化版
时间O(C*N) C为常数26  空间O(C)
执行用时：0 ms, 在所有 C++ 提交中击败了100.00% 的用户
内存消耗：6 MB, 在所有 C++ 提交中击败了35.16% 的用户
class Solution {
public:
    string modifyString(string s) {
        if(s.size() == 1)    return s[0] == '?' ? "a" : s;
        string temp = "abcdefghijklmnopqrstuvwxyz";
        for(int i = 0; i < s.size(); i++)
        {
            if(s[i] == '?')
            {
                for(int j = 0; j < 26; j++)
                {
                    if(i == 0 && temp[j] != s[1])
                    {
                        s[i] = temp[j];
                        break;
                    }
                    if(i == s.size() - 1 && temp[j] != s[i - 1])
                    {
                         s[i] = temp[j];
                         break;
                    }
                    if(i > 0 && i < s.size() - 1 && temp[j] != s[i - 1] && temp[j] != s[i + 1])
                    {
                        s[i] = temp[j];
                        break;
                    }
                }
            }
        }
        return s;
    }
};

法2：其实测试从a到c三个字符就可以了，毕竟最多只比较前后两个字符
时间O(C+N) C=3  空间O(1)
class Solution {
public:
    string modifyString(string s) {
        int n = s.size();
        for (int i = 0; i < n; ++i) {
            if (s[i] == '?') {
                for (char ch = 'a'; ch <= 'c'; ++ch) {    // 注意这里可以从a循环到c，反之上面可以从a到z。不必建立临时模拟字符串
                    if ((i > 0 && s[i - 1] == ch) || (i < n - 1 && s[i + 1] == ch)) {
                        continue;
                    }
                    s[i] = ch;
                    break;
                }
            }
        }
        return s;
    }
};
