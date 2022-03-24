法1：栈法，可以用两个栈的，一个放次数num，一个放当前结果res，其他思路一样，有点绕
时间O(N)  空间O(N)
执行用时：0 ms, 在所有 C++ 提交中击败了100.00% 的用户
内存消耗：6.5 MB, 在所有 C++ 提交中击败了24.18% 的用户
class Solution {
public:
    string decodeString(string s) {
        stack<pair<int, string>> st;    // 栈中存放pair<num, res>，可用两个栈
        int num;
        string res;
        for(auto c : s){                // 遍历字符串s，若字母，加在res后，若数字，变成合适的倍数
            if(c >= 'a' && c <= 'z'){
                res += c;
            }
            else if(c >= '0' && c <= '9'){
                num = 10 * num + c - '0';
            }
            else if(c == '['){           // 若左括号，将pair入栈，并把num res置空
                st.push({num, res});
                num = 0;
                res = "";
            }
            else{                         // 若右括号，取出当前栈的两个元素，并循环累加，注意是  b+=res  后  令 res = b   这里有点绕不太好想
                int a = st.top().first;
                string b = st.top().second;
                st.pop();
                for(int i = 0; i < a; i++){
                    b += res;
                }
                res = b;
            }
        }
        return res;
    }
};
