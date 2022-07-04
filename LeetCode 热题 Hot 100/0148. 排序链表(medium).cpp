法1：（迭代版）自底向上的归并排序法，但是与通常的归并不同，这次是空间复杂度为O(1)的方法，与数组不同，链表可以直接通过改变指针方向进行排序，因此可以实现O(1)
时间O(NlogN)  空间O(1)
执行用时：128 ms, 在所有 C++ 提交中击败了13.19% 的用户
内存消耗：31.8 MB, 在所有 C++ 提交中击败了57.79% 的用
class Solution {
public:
    ListNode* sortList(ListNode* head) {
        ListNode* dummy = new ListNode(0, head);    // 创建一个哑节点，方便指向
        ListNode* p = head;
        int len = 0;    // 用来遍历一轮统计链表长度
        while(p)
        {
            len++;
            p = p->next;
        }

        for(int i = 1; i < len; i <<= 1)    // 每次循环时成倍扩展比较，以 4->3->5->2->1 为例  初始size=1
        {
            ListNode* cur = dummy->next;
            ListNode* tail = dummy;   // cur为当前需要比较的节点位置，tail为目前已排序好的尾节点，遍历开始前指向哑节点即可
            while(cur)
            {
                ListNode* left = cur;       // left=4->null  right=3->null  cur=5->2->1->null  下一轮left=5->null  right=2->null  cur=1->null 再下一轮left=1->null  right=cur=null
                ListNode* right = cut(left, i);
                cur = cut(right, i);
                tail->next = merge(left, right);
                while(tail->next)    tail = tail->next;    // 比较完一轮后，将尾节点移至下一次比较的位置  即3->4->null tail在4处
            }
        }
        return dummy->next;
    }
private:
    ListNode* cut(ListNode* node, int size)
    {
        while(--size && node)    node = node->next;
        if(!node)    return nullptr;        // 注意这里容易忽略！！！退出循环有两种情况，一种是不够分成size长度，即node为空，返回即可
        ListNode* temp = node->next;              // 如果是size为0，需要将最后一位置为空后返回前一个节点
        node->next = nullptr;
        return temp;
    }

    ListNode* merge(ListNode* l1, ListNode* l2)     // 合并左右指针环节
    {
        ListNode* dummy = new ListNode(0);
        ListNode* temp = dummy;
        while(l1 && l2)
        {
            if(l1->val < l2->val)   
            {
                temp->next = l1;
                temp = temp->next;
                l1 = l1->next;
            }
            else
            {
                temp->next = l2;
                temp = temp->next;
                l2 = l2->next; 
            }
        }
        temp->next = l1 ? l1 : l2;
        return dummy->next;
    }
};

法2：（递归版）自顶向下的递归排序法，先递归至单个节点，再依次向上递归，复杂度更高，注意沿途记录快慢节点的位置
时间O(NlogN)  空间O(logN)
执行用时：180 ms, 在所有 C++ 提交中击败了31.15% 的用户
内存消耗：72.3 MB, 在所有 C++ 提交中击败了15.89% 的用户
class Solution {
public:
    ListNode* sortList(ListNode* head) {
        if (head == nullptr || head->next == nullptr) return head;
        ListNode *slow = head, *fast = head, *pre = head;
        while (fast && fast->next) {
            // 记录slow的前驱，针对链表有偶数个结点的情况
            pre = slow;
            slow = slow->next;
            fast = fast->next->next;
        }       
        pre->next = nullptr;    // 注意切断slow前一个节点
        ListNode *l1 = sortList(head);
        ListNode *l2 = sortList(slow);
        return mergeSort(l1, l2);
    }

private:
    ListNode* mergeSort(ListNode* l1, ListNode* l2) {
        ListNode *dummy = new ListNode(0);
        ListNode *pre = dummy;
        while (l1 && l2) {
            if (l1->val < l2->val) {
                pre->next = l1;
                l1 = l1->next;
                pre = pre->next;
            } else {
                pre->next = l2;
                l2 = l2->next;
                pre = pre->next;
            }
        }
        pre->next = l1 ? l1 : l2;
        return dummy->next;
    }
};