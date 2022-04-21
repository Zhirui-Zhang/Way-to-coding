法1：DFS递归调用，经典例题，略
执行用时：8 ms, 在所有 C++ 提交中击败了70.62% 的用户
内存消耗：18.2 MB, 在所有 C++ 提交中击败了99.17% 的用户
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(root == NULL)    return 0;
        return 1 + max(maxDepth(root->left), maxDepth(root->right));
    }
};
