法1：利用replace函数，包括访问string元素的string[i]或者string.at(i)
执行用时：0 ms, 在所有 C++ 提交中击败了100.00% 的用户
内存消耗：6.2 MB, 在所有 C++ 提交中击败了39.58% 的用户
class Solution {
public:
    string replaceSpace(string s) {
        for(int i = 0; i < s.size(); i++)
        {
            if(s[i] == ' ')
                s.replace(i, 1, "%20");
        }
        return s;
    }
};

法2：正常解法，遍历字符串，统计空格个数后resize扩展字符串，然后依次从后往前修改空格字符，结束条件为i=j
行用时：0 ms, 在所有 C++ 提交中击败了100.00% 的用户
内存消耗：6.3 MB, 在所有 C++ 提交中击败了6.91% 的用户
class Solution {
public:
    string replaceSpace(string s) {
        int count = 0, len = s.size();
        for(int i = 0; i < len; i++)
        {
            if(s[i] == ' ')    count++;
        }
        s.resize(len + 2 * count);

        int i = len - 1, j = s.size() - 1;  //倒序从后往前替换空格
        for(; i < j; i--, j--)
        {
            if(s[i] == ' ')
            {
                s[j] = '0';
                s[j-1] = '2';
                s[j-2] = '%';
                j -= 2;
            }
            else
            {
                s[j] = s[i];
            }
        }
        return s;
    }
};
