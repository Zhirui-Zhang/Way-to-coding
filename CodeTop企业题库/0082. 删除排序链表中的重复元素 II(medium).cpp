法1：双指针，模拟即可，注意如果出现相同数值的节点要全部删除，一个不留，所以需要遍历到不相同的节点处，改变pre指针指向
时间O(N)  空间O(1)
执行用时：8 ms, 在所有 C++ 提交中击败了51.55% 的用户
内存消耗：10.8 MB, 在所有 C++ 提交中击败了44.64% 的用户
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* dummy = new ListNode(0, head);
        ListNode* pre = dummy;
        while (head) {
            int val = head->val;        // 记录当前节点的val值
            if (head->next && head->next->val == val) {     // 如果下一个出现重复，while循环至第一个不重复的节点，并沿途delete所有节点
                pre->next = nullptr;    // 防止指向野指针
                while (head && head->val == val) {
                    ListNode* tmp = head;
                    head = head->next;
                    delete tmp;
                }
                pre->next = head;       // 更改pre指针的next指向
            }
            else {
                head = head->next;      // 若不相同，两个指针依次向下遍历一个节点即可
                pre = pre->next;
            }
        }
        return dummy->next;
    }
};