法1：栈法，很简单，解法略
时间O(N)  空间O(N)
执行用时：12 ms, 在所有 C++ 提交中击败了42.54% 的用户
内存消耗：11.7 MB, 在所有 C++ 提交中击败了10.21% 的用户
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> s;
        for (auto token : tokens) {
            if (token == "+" || token == "-" || token == "*" || token == "/") {
                int n1 = s.top();
                s.pop();
                int n2 = s.top();
                s.pop();
                int tmp = 0;
                if (token == "+")    tmp = n2 + n1;
                if (token == "-")    tmp = n2 - n1;
                if (token == "*")    tmp = n2 * n1;
                if (token == "/")    tmp = n2 / n1;
                s.push(tmp);
            } else {
                s.push(stoi(token));
            }
        }
        return s.top();
    }
};
