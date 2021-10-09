第一次提交：
class MinStack {
    stack<int> s1;  //数据栈
    stack<int> s2;  //辅助栈，用来存放数据栈不同时期的最小值
public:
    /** initialize your data structure here. */
    MinStack() {

    }
    
    void push(int x) {
        s1.push(x);
        if(s2.empty())  s2.push(x);
        else{
            if(x < s2.top()){
                s2.push(x);
            }
            else    s2.push(s2.top());
        }
    }
    
    void pop() {
        s1.pop();
        s2.pop();
    }
    
    int top() {
        return s1.top();
    }
    
    int min() {
        return s2.top();
    }
};

第二次提交：（优化版，改进了s2的初始top值，不必再判断是否为空，使得最终内存消耗减少0.1MB）
class MinStack {
    stack<int> s1;  //数据栈
    stack<int> s2;  //辅助栈，用来存放数据栈不同时期的最小值
public:
    /** initialize your data structure here. */
    MinStack() {
        s2.push(INT_MAX);
    }
    
    void push(int x) {
        s1.push(x);
        if(x < s2.top())    s2.push(x);
        else    s2.push(s2.top());
    }
    
    void pop() {
        s1.pop();
        s2.pop();
    }
    
    int top() {
        return s1.top();
    }
    
    int min() {
        return s2.top();
    }
};
