法1：双指针，注意特殊情况先判断是否头节点就为所求值（head不为空），否则一定在后面出现，即为一般情况
执行用时：8 ms, 在所有 C++ 提交中击败了86.74% 的用户
内存消耗：9.1 MB, 在所有 C++ 提交中击败了55.55% 的用户
class Solution {
public:
    ListNode* deleteNode(ListNode* head, int val) {
        if(head->val == val)    return head->next;
        ListNode *pre = head, *cur = head->next;
        while(cur != NULL)
        {
            if(cur->val == val)
            {
                pre->next = cur->next;
                cur = NULL;
                break;
            }
            pre = cur;
            cur = cur->next;
        }
        return head;
    }
};

代码优化：减少每次的if判断语句
执行用时：8 ms, 在所有 C++ 提交中击败了86.74% 的用户
内存消耗：9 MB, 在所有 C++ 提交中击败了81.56% 的用户
class Solution {
public:
    ListNode* deleteNode(ListNode* head, int val) {
        if(head->val == val)    return head->next;
        ListNode *pre = head, *cur = head->next;
        while(cur != NULL && cur->val != val)
        {
            pre = cur;
            cur = cur->next;
        }
        if(cur != NULL)     pre->next = cur->next;
        return head;
    }
};

