法1：投机取巧法，鉴于要求空间为O(1)和数据范围，可以循环10000次，若还未到头说明存在环，当然这不是正经解法，23333
时间O(N)  空间O(1)
执行用时：8 ms, 在所有 C++ 提交中击败了93.29% 的用户
内存消耗：7.9 MB, 在所有 C++ 提交中击败了80.34% 的用户
class Solution {
public:
    bool hasCycle(ListNode *head) {
        for(int i = 0; i <= 10000; ++i)
        {
            if(!head)    return false;
            head = head->next;
        }
        return true;
    }
};

法2：正经解法，哈希表，若访问过则返回true，说实话这应该是第一时间想到的解法，淦，这都没想出来
时间O(N)  空间O(1)
class Solution {
public:
    bool hasCycle(ListNode *head) {
        unordered_map<ListNode*, bool> un_map;
        while (!head) 
        {
            if (un_map.find(head) != un_map.end())    return true;
            un_map[head] = true;
            head = head->next;
        }
        return false;
    }
};

法3：双指针，正统空间为O(1)的解法，使用快慢指针，cur每次循环走两步，pre走一步，总会相遇的
时间O(N)  空间O(1)
执行用时：8 ms, 在所有 C++ 提交中击败了93.29% 的用户
内存消耗：7.8 MB, 在所有 C++ 提交中击败了82.82% 的用户
class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode* pre = head;
        ListNode* cur = head;
        while(cur)
        {
            cur = cur->next;
            if(cur == pre)    return true;
            if(cur)    cur = cur->next;
            else    return false;
            pre = pre->next;
        }
        return false;
    }
};
