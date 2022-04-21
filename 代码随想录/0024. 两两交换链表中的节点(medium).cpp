法1：双指针法，遍历模拟，注意指针指向即可
时间O(N)  空间O(1)
执行用时：4 ms, 在所有 C++ 提交中击败了51.27% 的用户
内存消耗：7.4 MB, 在所有 C++ 提交中击败了11.18% 的用户
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode* dummy = new ListNode(0, head);
        ListNode* pre = dummy;
        ListNode* cur = head;
        while (cur && cur->next) {
            ListNode* tmp = cur;        // 例 dummy->1->2->3->4，pre 为 dummy，tmp为1，cur为2
            cur = cur->next;
            pre->next = cur;            // pre指向2
            tmp->next = cur->next;      // 1指向3
            cur->next = tmp;            // 2指向1
            pre = tmp;                  // 令pre = 1，cur = 3
            cur = tmp->next;            // 目前链表变为 dummy->2->1->3->4
        }
        return dummy->next;
    }
};
