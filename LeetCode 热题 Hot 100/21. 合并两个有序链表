法1：遍历模拟法，做过的题，做法略，遍历两个比较即可
时间O(N+M) 空间O(1)
执行用时：8 ms, 在所有 C++ 提交中击败了62.18% 的用户
内存消耗：14.3 MB, 在所有 C++ 提交中击败了73.29% 的用户
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* cur = new ListNode(0);
        ListNode* res = cur;    // 用于返回
        while(list1 && list2)
        {
            if(list1->val < list2->val)
            {
                cur->next = list1;
                cur = cur->next;
                list1 = list1->next;
            }
            else
            {
                cur->next = list2;
                cur = cur->next;
                list2 = list2->next;
            }
        }
        if(list1)   cur->next = list1;    // 连接最后剩余尾部，可简写为  cur->next = list1 == nullptr ? l2 : l1
        else    cur->next = list2;
        return res->next;
    }
};

法2：递归法
时间O(N+M)  空间O(N+M)
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (l1 == nullptr) {
            return l2;
        } else if (l2 == nullptr) {
            return l1;
        } else if (l1->val < l2->val) {
            l1->next = mergeTwoLists(l1->next, l2);
            return l1;
        } else {
            l2->next = mergeTwoLists(l1, l2->next);
            return l2;
        }
    }
};
