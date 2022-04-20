法1：模拟法，一个队列就能实现栈的模拟，即每当需要pop弹出时，把除了back()的元素全弹出来再插回去即可，此时需要借助q.size()函数
时间O(N)每次pop都需要O(N)的时间  空间O(1)
执行用时：0 ms, 在所有 C++ 提交中击败了100.00% 的用户
内存消耗：6.6 MB, 在所有 C++ 提交中击败了49.04% 的用户
class MyStack {
private:
    queue<int> q;

public:
    MyStack() {

    }
    
    void push(int x) {
        q.push(x);
    }
    
    int pop() {
        int res = q.back();               // 存下返回值
        int num = q.size();
        for (int i = 1; i < num; ++i) {
            q.push(q.front());
            q.pop();
        }
        q.pop();                  // 只有最后一个元素不需要push回去，而是直接pop弹出
        return res;
    }
    
    int top() {
        return q.back();
    }
    
    bool empty() {
        return q.empty();
    }
};
