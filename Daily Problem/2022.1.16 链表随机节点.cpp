法1：水塘抽样法，该方法会保证每个节点被返回的概率均为1/n，证明略
时间O(1)  空间O(1)
执行用时：28 ms, 在所有 C++ 提交中击败了11.22% 的用户
内存消耗：16.2 MB, 在所有 C++ 提交中击败了16.48% 的用户
class Solution {
public:
    Solution(ListNode* head) {
        this->head = head;
    }
    
    int getRandom() {
        int res = 0, i = 1;
        ListNode* cur = head;
        while(cur)
        {
            if(rand() % i == 0)    res = cur->val;      // 关键点，对遍历到的第 i 个节点，随机选择区间 [0,i-1] 内的一个整数，如果其等于 0，则将答案置为该节点值，否则答案不变。
            ++i;
            cur = cur->next;
        }
        return res;
    }
private:
    ListNode* head;
};
