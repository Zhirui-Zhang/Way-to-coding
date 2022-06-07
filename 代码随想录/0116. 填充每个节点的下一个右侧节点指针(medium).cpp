法1：DFS法，由于题目进阶要求限制，只能采用递归方法，注意递归之前判断当前节点是否为空以及是否为叶节点，是的话直接返回，无需设置next指针
时间O(N)  空间O(1) 其实有递归深度的，由于是完美二叉树，递归深度应该为O(logN)，但是题目要求可以忽略
执行用时：16 ms, 在所有 C++ 提交中击败了84.38% 的用户
内存消耗：16.3 MB, 在所有 C++ 提交中击败了94.12% 的用户
class Solution {
public:
    Node* connect(Node* root) {
        dfs(root);
        return root;
    }
private:
    void dfs(Node* root) {
        if (!root || !root->left) return;       // 判断root为空主要是为特殊情况（节点数量为0）准备的，主要是判断是否为叶节点，叶节点无需设置下一层的next指针，直接返回即可
        root->left->next = root->right;         // 让下一层左子树next指向右子树
        if (root->next) root->right->next = root->next->left;   // 如果当前层的节点有next指针，让下一层右子树指向当前next的左子树
        dfs(root->left);                        // 后序遍历，递归左右子树
        dfs(root->right);
    }
};