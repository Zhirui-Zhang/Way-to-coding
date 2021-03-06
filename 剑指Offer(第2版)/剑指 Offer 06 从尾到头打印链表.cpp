法1：vector中自带的reverse函数
执行用时：8 ms, 在所有 C++ 提交中击败了24.52% 的用户
内存消耗：8.4 MB, 在所有 C++ 提交中击败了87.43% 的用户
class Solution {
public:
    vector<int> reversePrint(ListNode* head) {
        vector<int> v;    //返回数组
        if(head == NULL)
        {
            return {};
        }
        else
        {
            while(head != NULL)
            {
                v.push_back(head->val);
                head = head->next;
            }
            reverse(v.begin(), v.end());
            return v;
        }
    }
}
法2：递归法
执行用时：44 ms, 在所有 C++ 提交中击败了6.84% 的用户
内存消耗：248.3 MB, 在所有 C++ 提交中击败了5.03% 的用户
class Solution {
public:
    vector<int> v;    //定义返回数组，当采用递归法时必须定义为全局变量！
    vector<int> reversePrint(ListNode* head) {
        if(head == NULL)    return v;   //这里只需return v即可
        reversePrint(head->next);   //不需要接受返回值也可
        v.push_back(head->val);
        return v;
    }
};
法3：入栈法
执行用时：4 ms, 在所有 C++ 提交中击败了85.17% 的用户
内存消耗：8.5 MB, 在所有 C++ 提交中击败了58.36% 的用户
class Solution {
public:
    vector<int> reversePrint(ListNode* head) {
    //入栈法
    stack<int> s;
    vector<int> v;
    while(head)
    {
        s.push(head->val);
        head = head->next;
    }
    while(!s.empty())
    {
        v.push_back(s.top());
        s.pop();
    }
    return v;
    }
};
法4：双指针法
执行用时：4 ms, 在所有 C++ 提交中击败了85.17% 的用户
内存消耗：8.4 MB, 在所有 C++ 提交中击败了89.96% 的用户
class Solution {
public:
    vector<int> reversePrint(ListNode* head) {
    //双指针法
    vector<int> v;
    ListNode* pre = NULL;
    ListNode* cur = head;
    while(cur)
    {
        ListNode* temp = cur;
        cur = cur->next;
        temp->next = pre;
        pre = temp;
    }
    while(pre)
    {
        v.push_back(pre->val);
        pre = pre->next;
    }
    return v;    
    }
};

综上比较来看，目前最好的方法是双指针法！
