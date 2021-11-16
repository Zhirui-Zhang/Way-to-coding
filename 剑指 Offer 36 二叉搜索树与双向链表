法1：DFS+双指针法，中序遍历  左节点->根节点->右节点  方法很好想，但程序需要思考推敲，尤其是找到！首节点head和尾节点pre！
执行用时：8 ms, 在所有 C++ 提交中击败了38.95% 的用户
内存消耗：7.4 MB, 在所有 C++ 提交中击败了72.55% 的用户
class Solution {
public:
    Node* treeToDoublyList(Node* root) {
        if(root == NULL)     return NULL;   //这里如果不对空集特殊情况的话，head->left将会报错
        DFS(root);
        head->left = pre;   //最后注意将首尾节点的指针相连
        pre->right = head;
        return head;
    }
private:
    Node* head, * pre;
    void DFS(Node* cur)
    {
        if(cur == NULL)   return;
        DFS(cur->left);
        if(pre == NULL)     head = cur;   //如果pre为空，说明第一次遍历到了左边最小的节点，将其置为head
        else    pre->right = cur;    //否则为正常遍历情况
        cur->left = pre;
        pre = cur;    //pre向前移动到cur节点
        DFS(cur->right);
    }
};
