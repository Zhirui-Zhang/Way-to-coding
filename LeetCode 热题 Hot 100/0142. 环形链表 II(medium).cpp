法1：哈希表，记录每个节点并比较，若有重复则返回即可
时间O(N)  空间O(N)
代码略

法2：双指针法，符合题目进阶要求，与Ⅰ略有区别，这道题关键在于pre每次严格移动一次  cur严格移动两次后再进行比较
重点是数学追击问题，当pre和cur相遇时，令pre=head，随后依次向前移动，若相遇则为环起点
时间O(N)  空间O(1)
执行用时：4 ms, 在所有 C++ 提交中击败了98.09% 的用户
内存消耗：7.4 MB, 在所有 C++ 提交中击败了73.14% 的用户
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode* pre = head;
        ListNode* cur = head;
        while(cur && cur->next)   // 由于cur每次要移动两次，故需要判断->next是否也为空
        {
            cur = cur->next->next;
            pre = pre->next;
            if(pre == cur)        // 若相遇，标志位置为true后循环遍历即可
            {
                pre = head;
                while(pre != cur)
                {
                    pre = pre->next;
                    cur = cur->next;
                }
                return pre;
            }
        }
        return NULL;
    }
};
