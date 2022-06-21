法1：建立temp类型的string数组分割text中的每个独立单词，随后依次与first和second比较，若相等，存入res中
时间O(N)  空间O(N)
执行用时：0 ms, 在所有 C++ 提交中击败了100.00% 的用户
内存消耗：6.5 MB, 在所有 C++ 提交中击败了43.54% 的用户
class Solution {
public:
    vector<string> findOcurrences(string text, string first, string second) {
        vector<string> res;
        vector<string> temp;
        int i = 0, j = 0;
        for(; i < text.size(); ++i)
        {
            if(text[i] == ' ')    
            {
                temp.push_back(text.substr(j, i-j));
                j = i + 1;
            }
        }
        temp.push_back(text.substr(j, i-j));
        for(int k = 0; k < temp.size(); ++k)
        {
            if(temp[k] == first && k+1 < temp.size() && temp[k+1] == second && k+2 < temp.size())    
            {
                res.push_back(temp[k+2]);
            }
        }
        return res;
    }
};
