class CQueue {
private:
    stack<int> s1;
    stack<int> s2;

public:
    CQueue() {
    }
    
    void appendTail(int value) {
        s1.push(value);
    }
    
    int deleteHead() {
        int i;
        if(!s2.empty()){
            i = s2.top();
            s2.pop();
            return i;
        }
        else if(!s1.empty()){
            while(!s1.empty()){
                s2.push(s1.top());
                s1.pop();
            }
            i = s2.top();
            s2.pop();
            return i;
        }   
        else return -1; 
    }
};
