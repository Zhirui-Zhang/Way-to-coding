法1：哈希表
执行用时：48 ms, 在所有 C++ 提交中击败了23.67% 的用户
内存消耗：10.5 MB, 在所有 C++ 提交中击败了59.00% 的用户
class Solution {
public:
    char firstUniqChar(string s) {
        unordered_map<char, int> un_map;
        for(char c : s)     //记住遍历用char c : s!!!
        {
            if(!un_map[c])    un_map[c] = 1;
            else un_map[c]++;
        }
        for(char c : s)
        {
            if(un_map[c] == 1)   return c;
        }
        return ' ';
    }
};

法2：有序哈希表
在法1的基础上增加一个数组vector，记录每个元素的顺序，这样就不用在遍历一次string了，节省一点时间
代码略
