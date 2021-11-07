法1：递归法 想法到位了 但是空间复杂太高 下面有改进版
执行用时：24 ms, 在所有 C++ 提交中击败了47.14% 的用户
内存消耗：33.3 MB, 在所有 C++ 提交中击败了5.10% 的用户
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(l1 == NULL)  return l2;
        if(l2 == NULL)  return l1;
        ListNode *res = new(ListNode);
        res->val = min(l1->val, l2->val);
        if(l1->val < l2->val)    res->next = mergeTwoLists(l1->next, l2);
        else    res->next = mergeTwoLists(l1, l2->next);
        return res;
    }
};

改进版，不需要新建空间存放节点，直接改动原l1或者l2（取决于第一个节点的val值大小）
执行用时：16 ms, 在所有 C++ 提交中击败了93.84% 的用户
内存消耗：18.7 MB, 在所有 C++ 提交中击败了58.72% 的用户
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(l1 == NULL)  return l2;
        if(l2 == NULL)  return l1;
        if(l1->val < l2->val)    
        {
            l1->next = mergeTwoLists(l1->next, l2);
            return l1;
        }
        else    
        {
            l2->next = mergeTwoLists(l1, l2->next);
            return l2;
        }
    }
};

法2：双指针法，其实很简单的，先建立两个空指针res和cur，比较l1和l2 val 大小，用cur指向下一个
执行用时：24 ms, 在所有 C++ 提交中击败了47.14% 的用户
内存消耗：18.8 MB, 在所有 C++ 提交中击败了27.23% 的用户
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        //可以不必判断是否为空，后面会判断
        ListNode *res = new(ListNode), *cur = res;     
        //这里很关键，定义头节点的语句，令cur=res，cur继续前移直至结束，res保持不动，最后返回res->next
        while(l1 != NULL && l2 != NULL)
        {
            if(l1->val < l2->val)
            {
                cur->next = l1;
                l1 = l1->next;
            }
            else
            {
                cur->next = l2;
                l2 = l2->next;
            }
            cur = cur->next;
        }
        if(l1 == NULL)  cur->next = l2;
        else  cur->next = l1;
        return res->next;   //注意最后返回的是res->next指针，因为next才是头节点
    }
};
