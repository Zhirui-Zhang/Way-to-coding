法1：两个队列，一个正常按顺序存放，满足pop_front需求，一个双向队列deque，其实只用来单向，即从后入从前出，用来存放当前最大值序列（截止到所有已经输入的数字）
时间O(1)注意这里时间复杂度的算法，因为每个元素最多入队和出队一次，所以时间不是O(N)，而是O(1)  空间O(N)
用例：push(5) push(1) push(3) pop() push(2) push(4)  deque依次为[5] [5 1] [5 3] [3] [3 2] [4]
执行用时：104 ms, 在所有 C++ 提交中击败了78.64% 的用户
内存消耗：47.6 MB, 在所有 C++ 提交中击败了71.25% 的用户
class MaxQueue {
public:
    queue<int> q1;    // 正常存放队列
    deque<int> q2;    // 存放当前最大值序列
    MaxQueue() {
        
    }
    
    int max_value() {
        if(q2.empty())    return -1;
        return q2.front();
    }
    
    void push_back(int value) {
        q1.push(value);
        if(q2.empty())    q2.push_back(value);
        else if(q2.front() < value)           // 如果新进来的值比当前最大值还大，直接清空q2后插入新值
        {
            q2.clear();
        }
        else if(q2.back() < value)            // 如果新进来的值比队尾的值大，依次从尾部pop出来，直至pop到小于上一个队尾的值时再插入新值
        {   
            while(!q2.empty() && q2.back() < value)     q2.pop_back();
        }
        q2.push_back(value);                  // 都不满足的话，直接从后面插入即可
    }
    
    int pop_front() {
        if(q1.empty())    return -1;
        int temp = q1.front();
        q1.pop();
        if(temp == q2.front())    q2.pop_front();   // 这里只关心q2.front()即可，因为q2也是有顺序的，只有当前pop的值等于队头时q2.pop_front()即可，其余情况不用动
        return temp;
    }
};

简化push_back函数：只考虑大于队尾值即可，不用考虑对头！
void push_back(int value) {
        q1.push(value); 
        while(!q2.empty() && q2.back() < value)     q2.pop_back();
        q2.push_back(value);
    }
