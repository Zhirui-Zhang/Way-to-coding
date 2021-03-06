♥我愿称之为最浪漫的一题♥
首先注意不可以用反转链表的方法，会报错，改变链表结构，其次注意要判断的是整个对象是否相等，并不只是val值相等？这个值是题目事先设置好的，不用管他了，做题就行

法1：自己的做法，其实是四指针法，中心思想是让A和B来到同一起跑线再开始遍历
执行用时：32 ms, 在所有 C++ 提交中击败了97.84% 的用户
内存消耗：14.2 MB, 在所有 C++ 提交中击败了76.31% 的用户
class Solution {
public: 
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *pre_A = headA, *cur_A = headA, *pre_B = headB, *cur_B = headB;
        int n = 0, m = 0;
        while(cur_A != NULL)
        {
            cur_A = cur_A->next;
            n++;
        }
        while(cur_B != NULL)
        {
            cur_B = cur_B->next;
            m++;
        }
        int temp = n > m ? n - m : m - n;
        if(n > m)   while(temp--)    pre_A = pre_A->next;
        else    while(temp--)   pre_B = pre_B->next;
        while(pre_A != NULL)    
        {
            if(pre_A == pre_B)    return pre_A; //注意这里比较的是pre_A == pre_B即整个对象是否相等
            pre_A = pre_A->next;
            pre_B = pre_B->next;
        }
        return  NULL;   //最后若无返回空
    }
};

法2：双指针法，A走一遍到B头节点，B走一遍到A头节点，当A=B时可能是指向同一个节点或者都为空，设两者公共部分长度为c，此时A和B都走了len(A)+len(B)-c，退出
执行用时：40 ms, 在所有 C++ 提交中击败了70.63% 的用户
内存消耗：14.2 MB, 在所有 C++ 提交中击败了67.94% 的用户
class Solution {
public: 
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *A = headA, *B = headB;
        while(A != B)
        {
            A = A != NULL ? A->next : headB;
            B = B != NULL ? B->next : headA;
        }
        return A;
    }
};
