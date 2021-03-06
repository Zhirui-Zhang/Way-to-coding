法1：先分割两个字符串，用哈希表记录不同单词出现的次数，然后分别遍历哈希表，判断是否只出现一次并存储下来
时间O(N)  空间O(N)
执行用时：0 ms, 在所有 C++ 提交中击败了100.00% 的用户
内存消耗：6.5 MB, 在所有 C++ 提交中击败了92.54% 的用户
class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        vector<string> res;
        unordered_map<string, int> m;
        string temp;
        for(auto& s : s1)
        {
            if(s == ' ')
            {
                m[temp]++;
                temp = "";
            }
            else    temp += s;
        }
        m[temp]++;
        temp = "";
        for(auto& s : s2)
        {
            if(s == ' ')
            {
                m[temp]++;
                temp = "";
            }
            else    temp += s;
        }
        m[temp]++;
        for(auto [k, v] : m)
        {
            if(v == 1)    res.push_back(k);
        }

        return res;
    }
};
