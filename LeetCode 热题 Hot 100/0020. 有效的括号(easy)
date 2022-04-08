法1：入栈法，注意最后返回的是该栈是否为空
时间O(N)  空间O(N)
执行用时：0 ms, 在所有 C++ 提交中击败了100.00% 的用户
内存消耗：6.1 MB, 在所有 C++ 提交中击败了90.76% 的用户class Solution {
public:
    bool isValid(string s) {
        int n = s.size();
        if(n % 2 == 1)    return false;   // 奇数个数一定为false
        stack<char> st;
        for(int i = 0; i < n; ++i)
        {
            if(s[i] == '(' || s[i] == '[' || s[i] == '{')   // 左半边符号入栈
            {
                st.push(s[i]);
            }
            else
            {
                if(st.empty())    return false;   // 无左半边时一定为false
                char c = st.top();
                if(c == '(' && s[i] != ')' || c == '[' && s[i] != ']' || c == '{' && s[i] != '}')  
                    return false;   // 右半边不匹配返回false
                st.pop();           // 注意弹出栈顶符号
            }
        }
        return st.empty();
    }
};
