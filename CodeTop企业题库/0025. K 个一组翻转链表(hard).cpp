法1：双指针法，套用反转链表的easy题，只不过需要逐次反转，导致代码过长，后面有优化版
时间O(N)  空间O(1)
执行用时：12 ms, 在所有 C++ 提交中击败了84.19% 的用户
内存消耗：11.2 MB, 在所有 C++ 提交中击败了54.82% 的用户
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        int n = 1;
        ListNode* res = head;
        while (n < k) {
            res = res->next;
            ++n;
        }
        ListNode* newHead = res->next;
        reverseList(head, res);     // 第一次比较特殊，需要找到返回的尾节点，记为res
        while (true) {              // 之后就是while循环，一直反转，直到链表结束
            n = 1;
            ListNode* tail = newHead;
            while (n < k && tail) { // 多一个判断tail是否为空的条件
                tail = tail->next;
                ++n;
            }
            if (!tail) break;       // 如果为空，说明剩下的长度不够k，无需反转，直接break
            ListNode* nextHead = tail->next;    // 记录下一次反转的头节点
            head->next = reverseList(newHead, tail);    // 这里很重要，上一次的尾节点接上本次反转后的头节点
            head = newHead;         // 更新下一次的头尾节点
            newHead = nextHead;
        }
        head->next = newHead;       // 最后还要更新一次节点
        return res;
    }

private:
    ListNode* reverseList(ListNode* head, ListNode* tail) {     // 反转链表的模板代码，只不过多了一个tail节点，用来判断何时退出while循环
        ListNode* pre = new ListNode(0, head);
        ListNode* cur = head;
        while (pre != tail) {       // 注意退出条件pre != tail
            ListNode* tmp = cur;
            cur = cur->next;
            tmp->next = pre;
            pre = tmp;
        }   
        return pre;                 // 最后返回头节点，用来与之前的连接
    }
};

官方优化版：
执行用时：12 ms, 在所有 C++ 提交中击败了84.19% 的用户
内存消耗：11.1 MB, 在所有 C++ 提交中击败了92.87% 的用户
class Solution {
public:
    // 翻转一个子链表，并且返回新的头与尾
    pair<ListNode*, ListNode*> myReverse(ListNode* head, ListNode* tail) {
        ListNode* pre = new ListNode(0, head);
        ListNode* cur = head;
        while (pre != tail) {       // 注意退出条件pre != tail
            ListNode* tmp = cur;
            cur = cur->next;
            tmp->next = pre;
            pre = tmp;
        } 
        return {tail, head};        // 倒序返回
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* dummy = new ListNode(0, head);    // 哑节点很重要，用于最后返回值
        ListNode* pre = dummy;

        while (head) {
            ListNode* tail = pre;
            // 查看剩余部分长度是否大于等于 k
            for (int i = 0; i < k; ++i) {
                tail = tail->next;
                if (!tail) {    // 如果不够k个，直接返回，不用break
                    return dummy->next;
                }
            }
            ListNode* newHead = tail->next;     // 记录下一次反转的头节点
            // 这里是 C++17 的写法，也可以写成
            // pair<ListNode*, ListNode*> result = myReverse(head, tail);
            // head = result.first;
            // tail = result.second;
            tie(head, tail) = myReverse(head, tail);
            // 把子链表重新接回原链表
            pre->next = head;
            tail->next = newHead;
            head = newHead;
            pre = tail;
        }

        return dummy->next;
    }
};