法1：双指针法，先统计节点总数num，在k++至等于num
执行用时：0 ms, 在所有 C++ 提交中击败了100.00% 的用户
内存消耗：10.3 MB, 在所有 C++ 提交中击败了54.91% 的用户
class Solution {
public:
    ListNode* getKthFromEnd(ListNode* head, int k) {
        ListNode *pre = head, *cur = head;
        int num = 0;
        while(cur != NULL)
        {
            cur = cur->next;
            num++;
        }
        while(k < num)
        {
            pre = pre->next;
            k++;
        }
        return pre;
    }
};
优化版
执行用时：4 ms, 在所有 C++ 提交中击败了71.51% 的用户
内存消耗：10.3 MB, 在所有 C++ 提交中击败了62.63% 的用户
class Solution {
public:
    ListNode* getKthFromEnd(ListNode* head, int k) {
        ListNode *pre = head, *cur = head;
        for(int i = 0; i < k; i++)    cur = cur->next;
        while(cur != NULL)
        {
            cur = cur->next;
            pre = pre->next;
        }
        return pre;
    }
};
