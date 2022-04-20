法1：模拟法，一个栈只负责插入push操作，另一个栈负责需要pop弹出时的元素搬移，注意应用已有的函数！！！要不还得再写一遍，太笨了
时间O(1)平均复杂度为O(1)每个元素只插入和弹出两次  空间O(1)
执行用时：0 ms, 在所有 C++ 提交中击败了100.00% 的用户
内存消耗：6.7 MB, 在所有 C++ 提交中击败了84.95% 的用户
class MyQueue {
private:
    stack<int> s1;
    stack<int> s2;
public:
    MyQueue() {

    }
    
    void push(int x) {
        s1.push(x);
    }
    
    int pop() {
        int res = this->peek();     // 注意这里调用已有的peek()函数
        s2.pop();                   // 调用后还得pop一下
        return res;
    }
    
    int peek() {
        if (s2.empty()) {
            while (!s1.empty()) {
                s2.push(s1.top());      // 这里也是可以写的简洁一点，不需要设置一个tmp变量
                s1.pop();
            }
        }
        return s2.top();
    }
    
    bool empty() {
        return s1.empty() && s2.empty();    // 只有两个栈都为空才说明队列为空
    }
};
