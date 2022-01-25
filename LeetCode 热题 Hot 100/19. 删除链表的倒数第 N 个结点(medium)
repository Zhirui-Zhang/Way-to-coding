法1：两次遍历，第一次统计节点数，第二次删除并返回，并没有达到题目的要求，再考虑
时间O(N)  空间O(1)
执行用时：4 ms, 在所有 C++ 提交中击败了76.92% 的用户
内存消耗：10.3 MB, 在所有 C++ 提交中击败了81.37% 的用户
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* temp = head;
        int num = 0;
        while(temp)
        {
            ++num;
            temp = temp->next;
        }
        if(num == n)    return head->next;  // 考虑特殊情况，即删除头节点时需返回head->next，或者考虑设置一个哑节点next为头节点，可以避免特殊情况讨论
        temp = head;
        for(int i = 1; i < num - n; ++i)    temp = temp->next;
        temp->next =  temp->next->next; 
        return head;
    }
};

法2：双指针法，cur和pre差n+1个节点，当cur遍历到尾后的空指针时，pre正好到删除节点的前一个，删除即可
时间空间均不变
执行用时：4 ms, 在所有 C++ 提交中击败了76.92% 的用户
内存消耗：10.5 MB, 在所有 C++ 提交中击败了17.12% 的用户
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummy = new ListNode(0, head);    
        // 初始化一个哑节点，其next指向head，避免删除节点为head的特殊情况
        ListNode* pre = dummy, *cur = head;
        while(n--)
        {
            cur = cur->next;
        }
        while(cur)
        {
            pre = pre->next;
            cur = cur->next;
        }
        pre->next = pre->next->next;
        return dummy->next;
    }
};

法3：栈，先把所有节点入栈，然后依次出栈，当n==0时找到删除节点，感觉不如双指针，故代码略
