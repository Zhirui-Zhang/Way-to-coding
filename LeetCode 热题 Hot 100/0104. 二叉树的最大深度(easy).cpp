法1：DFS法
时间O(N)  空间O(N)
执行用时：8 ms, 在所有 C++ 提交中击败了62.73% 的用户
内存消耗：18.5 MB, 在所有 C++ 提交中击败了28.85% 的用户
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(!root)    return 0;
        return 1 + max(maxDepth(root->left), maxDepth(root->right));
    }
};
