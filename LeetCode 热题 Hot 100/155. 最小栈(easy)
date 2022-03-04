法1：辅助栈法，注意s2事先准备一个哨兵即可
时间O(1)  空间O(N)
执行用时：24 ms, 在所有 C++ 提交中击败了37.26% 的用户
内存消耗：15.9 MB, 在所有 C++ 提交中击败了80.67% 的用户
class MinStack {
private:
    stack<int> s1;
    stack<int> s2;
public:
    MinStack() {
        s2.push(INT_MAX);
    }
    
    void push(int val) {
        s1.push(val);
        s2.push(min(s2.top(), val));
    }
    
    void pop() {
        s1.pop();
        s2.pop();
    }
    
    int top() {
        return s1.top();
    }
    
    int getMin() {
        return s2.top();
    }
};

法2：若只用一个栈，可以存储pair<int, int>类型的元素
class MinStack {
private:
    stack<pair<int, int>> st;
public:
    MinStack() {
        st.push({0, INT_MAX});      // 哨兵
    }
    
    void push(int x) {
        st.push({x, min(x, st.top().second)});
    }
    
    void pop() {
        st.pop();
    }
    
    int top() {
        return st.top().first;
    }
    
    int getMin() {
        return st.top().second;
    }
};
