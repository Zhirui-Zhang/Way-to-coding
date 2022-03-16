法1：DFS，很复杂的一道题，细节很多，二刷的时候再好好回顾一遍吧
时间O(2^N)  空间O(N)
执行用时：116 ms, 在所有 C++ 提交中击败了22.08% 的用户
内存消耗：8.7 MB, 在所有 C++ 提交中击败了51.23% 的用户
class Solution {
public:
    vector<string> removeInvalidParentheses(string s) {
        int left = 0, right = 0;        // 分别表示需要删除的左括号数量和右括号数量
        for(auto c : s){                // 遍历s，若为左括号，l++，若为右括号，根据当前是否存在左括号决定是否r++
            if(c == '(')    left++;
            else if(c == ')'){
                if(left == 0){
                    right++;
                }
                else{
                    left--;              // 以例"()())()"说明，结束后l=0 r=1说明右括号多了一个，需要删除，递归进入dfs函数
                }
            }
        }

        dfs(s, 0, left, right, 0, 0);

        vector<string> res;               // 将不重复的字符串输入到res中
        for(auto un : un_set){
            res.push_back(un);
        }
        return res;
    }
private:
    unordered_set<string> un_set;           // un_set用来删除重复字符串，保留重复中的唯一一个后输出到res中
    string temp;
    void dfs(string& s, int i, int left, int right, int lcnt, int rcnt){    
    // i为下标，left right表示剩余需要删除的左/右括号数量，lcnt rcnt分别表示当前temp中已有的左右括号数量，用来判断目前左右括号数量是否匹配
        if(i == s.size()){
            if(lcnt == rcnt)    un_set.insert(temp);     // 只有当下标满足条件且左右括号数量匹配时，进行保存
            return;
        }
        if(s[i] == '(' && left > 0){                     // 当需要删除的左括号>0时，删除并递归，注意不管怎样，每次递归下标i都要记得+1
            dfs(s, i+1, left-1, right, lcnt, rcnt);
        }
        if(s[i] == ')' && right > 0){
            dfs(s, i+1, left, right-1, lcnt, rcnt);      // 同理，当需要删除的右括号>0时，删除并递归
        }

        temp += s[i];                                    // 暂时存入s[i]

        if(s[i] >= 'a' && s[i] <= 'z'){                  // 当s[i]为字母时，不用动，只把下标+1即可
            dfs(s, i+1, left, right, lcnt, rcnt);
        }
        else if(s[i] == '('){                            // 当s[i]为左括号时，令lcnt+1
            dfs(s, i+1, left, right, lcnt+1, rcnt);
        }
        else if(rcnt < lcnt){                            // 注意并非当s[i]为右括号就rcnt+1，因为可能出现"()())("的情况，而是应该判断当前右括号数是否小于左括号数，若小于，rcnt+1
            dfs(s, i+1, left, right, lcnt, rcnt+1);
        }

        temp.pop_back();
    }
};
