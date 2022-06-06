法1：模拟法+双指针，利用数组从左右分别交换next指针即可
时间O(N)  空间O(N)
执行用时：36 ms, 在所有 C++ 提交中击败了58.35% 的用户
内存消耗：18.3 MB, 在所有 C++ 提交中击败了27.42% 的用户
class Solution {
public:
    void reorderList(ListNode* head) {
        vector<ListNode*> v;
        while (head) {      // 遍历整个链表，将每个节点放入数组中
            v.push_back(head);
            head = head->next;
        }
        int left = 0, right = v.size() - 1;
        while (left < right) {  // 当left != right时，分别交换左右next指针
            v[left++]->next = v[right];
            v[right--]->next = v[left];
        }
        v[left]->next = nullptr;    // 最后注意将最后一个节点置为nullptr
    }
};

法2：双向队列法，利用deque的特性，分别pop_front pop_back节点并交换即可
时间O(N)  空间O(N)
执行用时：32 ms, 在所有 C++ 提交中击败了83.52% 的用户
内存消耗：18 MB, 在所有 C++ 提交中击败了34.01% 的用户
class Solution {
public:
    void reorderList(ListNode* head) {
        ListNode* cur = head;       // 复制一个head节点，用于接下来交换next指针用
        deque<ListNode*> dq;
        while (head) {
            dq.push_back(head);
            head = head->next;
        }
        bool flag = true;
        while (!dq.empty()) {
            if (flag) {             // 根据奇偶性决定交换front还是back节点
                dq.front()->next = dq.back();
                dq.pop_front();
            } else {
                dq.back()->next = dq.front();
                dq.pop_back();
            }
            cur = cur->next;        // 注意移动cur指针并将flag置反
            flag = !flag;
        }
        cur->next = nullptr;        // 同样最后一个节点需要置nullptr
    }
};