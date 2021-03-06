法1：优先队列法，特别简单，遍历一次即可，按照大小顺序排序，随后存入返回的新节点中即可
时间O(NlogN)  空间O(N) N为lists中所有元素的个数
执行用时：20 ms, 在所有 C++ 提交中击败了80.09% 的用户
内存消耗：13.6 MB, 在所有 C++ 提交中击败了20.20% 的用户
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<int, vector<int>, greater<int>> pq;
        int n = lists.size();
        for(int i = 0; i < n; i++)    // 遍历lists，将所有节点存入小顶堆，自动排序
        {
            ListNode* temp = lists[i];
            while(temp)
            {
                pq.push(temp->val);
                temp = temp->next;
            }
        }
        ListNode* pre = new ListNode(0);        // pre设置为哑节点，避免lists为空的情况发生
        ListNode* cur = pre;
        while(!pq.empty())    // 根据小顶堆中的顺序，建立新节点并返回
        {
            cur->next = new ListNode(pq.top());
            pq.pop();
            cur = cur->next;
        }
        return pre->next;
    }
};

法2：分治归并法，类似于归并排序，分治直至合并两个相邻的list（这一步参照合并两个链表的代码即可），然后逐步合并，最后返回
时间O(NlogN)  空间O(N) N为lists中所有元素的个数
执行用时：16 ms, 在所有 C++ 提交中击败了94.94% 的用户
内存消耗：22.1 MB, 在所有 C++ 提交中击败了10.42% 的用户
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int n = lists.size();
        if(n == 0)    return nullptr;       // 必须考虑特殊情况，否则lists[left]为越界访问
        return MergeSort(lists, 0, n-1);
    }
private:
    ListNode* MergeSort(vector<ListNode*>& lists, int left, int right)   // 归并算法，注意返回条件，当left >= right（实际上是left == right），返回哪个都行
    {
        if(left >= right)    return lists[left];
        int mid = (left + right) / 2;
        ListNode* l1 = MergeSort(lists, left, mid);     // 传入的两个l1 l2用于最后一步合并的两个参数
        ListNode* l2 = MergeSort(lists, mid+1, right);
        return MergeTwoLists(l1, l2);
    }
    ListNode* MergeTwoLists(ListNode* list1, ListNode* list2) {         // 合并两个链表代码移植过来即可，可以用模拟版本，也可以用递归版本
        ListNode* cur = new ListNode(0);
        ListNode* res = cur;
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
        if(list1)   cur->next = list1;
        else    cur->next = list2;
        return res->next;
    }
};
