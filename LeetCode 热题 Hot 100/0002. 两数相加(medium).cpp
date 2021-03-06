法1：遍历法，每次相加时记录是否大于10，若大于时将进位digit=1，否则=0，l1 or l2遍历完后继续复制另一个的节点值  ！！注意最后是否需要加一个1的进位节点！！
时间O(N)  空间O(1)不算最后题目中的返回链表
执行用时：32 ms, 在所有 C++ 提交中击败了46.13% 的用户
内存消耗：69.5 MB, 在所有 C++ 提交中击败了30.11% 的用户
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int digit = 0;
        ListNode* cur = new ListNode(), *head = cur;
        while(l1 != nullptr && l2 != nullptr)
        {
            int temp = l1->val + l2->val + digit;
            ListNode* node = new ListNode(temp % 10);
            if(temp > 9)    digit = 1;
            else digit = 0; 
            cur->next = node;
            cur = cur->next;
            l1 = l1->next;
            l2 = l2->next;
        }
        while(l1 != nullptr)
        {
            int temp = l1->val + digit;
            ListNode* node = new ListNode(temp % 10);
            if(temp > 9)    digit = 1;
            else digit = 0; 
            cur->next = node;
            cur = cur->next;
            l1 = l1->next;
        }
        while(l2 != nullptr)
        {
            int temp = l2->val + digit;
            ListNode* node = new ListNode(temp % 10);
            if(temp > 9)    digit = 1;
            else digit = 0; 
            cur->next = node;
            cur = cur->next;
            l2 = l2->next;
        }
        if(digit == 1)
        {
            ListNode* node = new ListNode(1);
            cur->next = node;
            cur = cur->next;
        }
        return head->next;
    }
};

优化版：不需要分别讨论l1为空或l2为空的情况，每次都给两个节点赋值，若空赋0即可
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *head = nullptr, *tail = nullptr;
        int carry = 0;
        while (l1 || l2) {
            int n1 = l1 ? l1->val: 0;
            int n2 = l2 ? l2->val: 0;
            int sum = n1 + n2 + carry;
            if (!head) {
                head = tail = new ListNode(sum % 10);
            } else {
                tail->next = new ListNode(sum % 10);
                tail = tail->next;
            }
            carry = sum / 10;
            if (l1) {
                l1 = l1->next;
            }
            if (l2) {
                l2 = l2->next;
            }
        }
        if (carry > 0) {
            tail->next = new ListNode(carry);
        }
        return head;
    }
};
