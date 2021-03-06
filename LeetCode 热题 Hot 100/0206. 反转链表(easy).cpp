法1：迭代法，略，注意开始pre应设为空
时间O(N)  空间O(1)
执行用时：8 ms, 在所有 C++ 提交中击败了46.65% 的用户
内存消耗：8.1 MB, 在所有 C++ 提交中击败了47.57% 的用户
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* pre = nullptr;
        ListNode* cur = head;
        while(cur)
        {
            ListNode* temp = cur;
            cur = cur->next;
            temp->next = pre;
            pre = temp;
        }
        return pre;
    }
};

法2：递归法，有点遗忘了，重点记忆一下！
时间O(N)  空间O(N)
执行用时：4 ms, 在所有 C++ 提交中击败了94.57% 的用户
内存消耗：8.3 MB, 在所有 C++ 提交中击败了8.85% 的用户
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(!head || !head->next)    return head;    // 退出循环条件很重要，需同时满足head和next都不为空才行！！！
        ListNode* res = reverseList(head->next);    // res的作用就是用来记录最后返回的节点（节点5）！！！否则在例1->2->3->4->5->NULL中最后无法返回节点5
        head->next->next = head;                    // 接下来的两个方向置换也容易忘记，回顾！！！
        head->next = nullptr;
        return res;
    }
};
