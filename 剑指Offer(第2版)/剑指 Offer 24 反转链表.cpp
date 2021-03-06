第一次提交：
使用双指针法，也为迭代法，利用前后两个指针，每次向前挪动一个节点，同时引入第三个临时节点实现反向连接
执行用时：4 ms, 在所有 C++ 提交中击败了88.86% 的用户
内存消耗：8.1 MB, 在所有 C++ 提交中击败了45.30% 的用户
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
    ListNode* cur = NULL;   //构建双指针
    ListNode* pre = head;
    while(pre != NULL){
        ListNode* temp;    //构建第三个临时指针
        temp = pre;
        pre = pre->next;
        temp->next = cur;
        cur = temp;
    }
    return cur;
    }
};

第二次提交：
使用递归法
执行用时：4 ms, 在所有 C++ 提交中击败了88.86% 的用户
内存消耗：8.3 MB, 在所有 C++ 提交中击败了7.14% 的用户
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if (!head || !head->next) {
            return head;
        }
        ListNode* newHead = reverseList(head->next);
        head->next->next = head;
        head->next = nullptr;
        return newHead;
    }
};
