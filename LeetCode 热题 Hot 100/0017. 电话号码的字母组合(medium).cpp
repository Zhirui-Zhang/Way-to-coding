法1：dfs，根据每一个已存储的string长度循环，增加s的长度，注意每次存储一个s后要弹出s最后一位
时间O(3^N)  空间O(N)
执行用时：0 ms, 在所有 C++ 提交中击败了100.00% 的用户
内存消耗：6.3 MB, 在所有 C++ 提交中击败了73.86% 的用户
class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if(digits.empty())    return {};    // 特殊情况处理，若不处理res会存入一个空值即[""]不满足条件{}
        vector<string> sample{"abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        vector<string> temp;
        for(auto d : digits)  
        {
            temp.push_back(sample[d-'0'-2]);    // 令temp存入给定的几个数字如"23"对应temp={"abc", "def"}
        } 
        dfs(temp, 0);    
        return res;
    }
private:
    vector<string> res;
    string s;
    void dfs(vector<string>& temp, int cur)    // cur表示当前temp的位置，若长度符合则存储该s
    {
        if(cur == temp.size())    
        {
            res.push_back(s);
            return;
        }
        for(auto t : temp[cur])
        {   
            s += t;
            dfs(temp, cur + 1);
            s.pop_back();   // !遍历结束后要令s长度-1!
        }
    }
};
