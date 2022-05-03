法1：DFS，左右互相搜索，注意二叉搜索树的特性，当节点值小于low时，其左子树一定全部小于，递归右子树即可，大于high时同理
时间O(N)  空间(N)
执行用时：8 ms, 在所有 C++ 提交中击败了96.47% 的用户
内存消耗：23.3 MB, 在所有 C++ 提交中击败了66.85% 的用户
class Solution {
public:
    TreeNode* trimBST(TreeNode* root, int low, int high) {
        if (!root) return nullptr;
        if (root->val > high) return trimBST(root->left, low, high);
        if (root->val < low) return trimBST(root->right, low, high);
        root->left = trimBST(root->left, low, high);
        root->right = trimBST(root->right, low, high);
        return root;
    }
};