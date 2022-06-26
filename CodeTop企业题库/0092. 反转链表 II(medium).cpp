法1：双指针法，是25题的简化版，只需翻转一次即可
时间O(N)  空间O(1)
执行用时：0 ms, 在所有 C++ 提交中击败了100.00% 的用户
内存消耗：7.2 MB, 在所有 C++ 提交中击败了70.56% 的用户
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (left == right) return head;
        ListNode* dummy = new ListNode(0, head);
        ListNode* pre = dummy;
        --left;
        --right;
        while (left) {
            pre = pre->next;
            --left;
            --right;
        }
        head = pre->next;           // 主要是需要记录开始头节点head和前一个节点pre+末尾节点tail和后一个节点newHead
        ListNode* tail = head;
        while (right) {
            tail = tail->next;
            --right;
        }
        ListNode* newHead = tail->next;
        tie(head, tail) = reverseTwoList(head, tail);   // C++17语法
        pre->next = head;
        tail->next = newHead;
        return dummy->next;
    }

private:
    pair<ListNode*, ListNode*> reverseTwoList(ListNode* head, ListNode* tail) {
        ListNode* pre = new ListNode(0, head);
        ListNode* cur = pre->next;
        while (pre != tail) {
            ListNode* tmp = cur;
            cur = cur->next;
            tmp->next = pre;
            pre = tmp;
        }
        return {tail, head};
    }
};

法2：头插法，只需要遍历一次链表即可实现反转，通过向头部添加节点的方式实现
时间O(N)  空间O(1)
class Solution {
public:
    ListNode *reverseBetween(ListNode *head, int left, int right) {
        ListNode *dummy = new ListNode(0, head);
        ListNode *pre = dummy;
        for (int i = 0; i < left - 1; i++) {
            pre = pre->next;
        }
        ListNode *cur = pre->next;
        ListNode *tmp;  
        for (int i = 0; i < right - left; i++) {    // 依次将遍历到的节点插到pre节点后面，进行right - left次头插
            tmp = cur->next;
            cur->next = tmp->next;
            tmp->next = pre->next;
            pre->next = tmp;
        }
        return dummy->next;
    }
};