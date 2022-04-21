法1：双指针法。单纯为应付空间O(1)设计的，借鉴反转链表的思想，根据奇偶判断应从何处反转链表，并将原链表一半处置空，最后依次遍历比较即可
官方题解中把反转链表包装起来，最后还把原链表还原了，可以学习一下
时间O(N)  空间O(1)
执行用时：180 ms, 在所有 C++ 提交中击败了72.06% 的用户
内存消耗：111.3 MB, 在所有 C++ 提交中击败了86.77% 的用户
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        ListNode* temp = head;    // 用于第一次遍历统计节点个数
        int num = 0;
        while(temp)
        {
            temp = temp->next;
            num++;
        }

        ListNode* cur = head;
        int half = num % 2 ? (num+1)/2 : num/2;   // 注意half算法，如果为1->2->3->2->1应到3  如果1->2->2->1应到第一个2
        while(--half)    cur = cur->next;
        ListNode* tail = cur;                     // 注意把3之后置空，或者第一个2之后置空，防止变成野指针
        cur = cur->next;                          // 但其实不置空也行，凑合着用呗
        tail->next = nullptr;

        ListNode* pre = nullptr;                  // 反转链表经典操作
        while(cur)
        {
            ListNode* temp = cur;
            cur = cur->next;
            temp->next = pre;
            pre = temp;
        }

        int n = num / 2;                           // 根据num/2比较，由于左右链表可能不完全一样，如1->2->3  和  1->2，应以右链表为准
        while(n--)
        {
            if(head->val != pre->val)    return false;
            head = head->next;
            pre = pre->next;
        }
        return true;
    }
};

法2：用栈比较好理解，统计一遍个数后，将前一半入栈，随后与后一半依次比较并出栈
时间O(N)  空间O(N)
代码略

法3：递归法，不太好理解，将head递归至最后一个节点后返回比较，但是这个题解其实正反比较了两遍，我觉得有点麻烦
时间O(N)  空间O(N)
class Solution {
    ListNode* frontPointer;
public:
    bool recursivelyCheck(ListNode* currentNode) {
        if (currentNode != nullptr) {
            if (!recursivelyCheck(currentNode->next)) {
                return false;
            }
            if (currentNode->val != frontPointer->val) {
                return false;
            }
            frontPointer = frontPointer->next;
        }
        return true;
    }

    bool isPalindrome(ListNode* head) {
        frontPointer = head;
        return recursivelyCheck(head);
    }
};
