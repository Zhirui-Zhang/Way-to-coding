法1：双指针法，做过的题，做法略，只不过代码可以简化
时间O(M+N)  空间O(1)
执行用时：40 ms, 在所有 C++ 提交中击败了70.18% 的用户
内存消耗：14.3 MB, 在所有 C++ 提交中击败了54.63% 的用
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* a = headA;
        ListNode* b = headB;
        while(a || b)
        {
            if(a == b)    return a;
            else if(!a)    
            {
                a = headB;
                b = b->next;
            }
            else if(!b)
            {
                a = a->next;
                b = headA;
            }
            else
            {
                a = a->next;
                b = b->next;
            }
        }
        return NULL;
    }
};

代码简化版：
ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *A = headA, *B = headB;
        while(A != B)
        {
            A = A != NULL ? A->next : headB;
            B = B != NULL ? B->next : headA;
        }
        return A;
    }
