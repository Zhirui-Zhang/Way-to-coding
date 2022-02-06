法1：动态规划dp，边界不太好想，关键是当形如 (()) 的嵌套括号时要注意加上嵌套括号外的dp值  每一步都要判断访问是否越界
例：s = ")()(()))"    最终dp=[0 0 2 0 0 2 6 0]
时间O(N)  空间O(N)
执行用时：0 ms, 在所有 C++ 提交中击败了100.00% 的用户
内存消耗：7.1 MB, 在所有 C++ 提交中击败了64.62% 的用户
class Solution {
public:
    int longestValidParentheses(string s) {
        int res = 0, n = s.size();
        vector<int> dp(n, 0);           // dp数组初始化为n个0
        for(int i = 1; i < n; ++i)      // 从第二个字符开始遍历
        { 
            if(s[i] == ')')             // 只考虑为右括号)的情况  左括号(的dp值均为0
            {
                if(s[i-1] == '(')       // 如果有相邻的括号出现，更新dp[i]=2+dp[i-2]，且判断是否越界
                {
                    dp[i] = 2;
                    if(i-2 >= 0)    dp[i] += dp[i-2];
                }
                else if(i-dp[i-1]-1 >=0 && s[i-dp[i-1]-1] == '(')   // 否则判断是否为嵌套括号即(())类型，且判断是否越界
                {
                    dp[i] = dp[i-1] + 2;
                    if(i-dp[i-1]-2 >= 0)    dp[i] += dp[i-dp[i-1]-2];   // 注意还要再加上之前的dp值，且判断是否越界
                }
            }
            res = max(dp[i], res);      // 每一轮结束后更新res的值
        }
        return res;
    }
};

法2：栈，注意先在栈底放一个-1！！！，目的是保证第一次为()时也能计算res的值，推导一遍即可理解  例不变
时间O(N)  空间O(N)
执行用时：4 ms, 在所有 C++ 提交中击败了74.17% 的用户
内存消耗：7 MB, 在所有 C++ 提交中击败了77.72% 的用户
class Solution {
public:
    int longestValidParentheses(string s) {
        int res = 0, n = s.size();
        stack<int> st;
        st.push(-1);    
        for(int i = 0; i < n; ++i)
        {
            if(s[i] == '(')    st.push(i);      // 左括号直接将当前位置i入栈
            else
            {
                st.pop();                       // 右括号先弹出与其匹配的左括号，然后根据栈是否为空决定入栈还是更新res的值为  i-最后一个没有被匹配的右括号的下标
                if(st.empty())    st.push(i);
                else    res = max(res, i - st.top());
            }
        }
        return res;
    }
};
