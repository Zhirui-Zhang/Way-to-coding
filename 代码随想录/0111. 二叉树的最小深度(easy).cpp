法1：BFS，与最大深度的那道题有点不同，注意当二叉树只有一侧有节点时也要计算其高度，直至递归到叶子节点为止，而不是直接返回1
时间O(N)  空间O(N)
执行用时：236 ms, 在所有 C++ 提交中击败了40.45% 的用户
内存消耗：141.3 MB, 在所有 C++ 提交中击败了44.36% 的用户
class Solution {
public:
    int minDepth(TreeNode* root) {
        if (!root) return 0;
        if (!root->left && root->right) return 1 + minDepth(root->right);       // 注意这里若左节点为空，则计算右侧子树高度，反之亦然
        if (!root->right && root->left) return 1 + minDepth(root->left);
        return 1 + min(minDepth(root->left), minDepth(root->right));            // 若左右都不为空，才像最大高度那道题一样取左右子树的最小值
    }
};