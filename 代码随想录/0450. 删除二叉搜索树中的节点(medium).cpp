法1：DFS递归，这道题用迭代法是在有点麻烦写不出来了，还是用递归吧，各种情况讨论，有点复杂，需要及时巩固复习
时间O(logN)树的高度  空间O(logN)树的高度
执行用时：32 ms, 在所有 C++ 提交中击败了64.22% 的用户
内存消耗：31.7 MB, 在所有 C++ 提交中击败了98.05% 的用户
class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (!root) return nullptr;      // 若找不到key值，返回空
        if (root->val == key) {         // 若找到，分三种情况讨论
            if (!root->left) {          // 1 左子树为空，返回右子树
                TreeNode* tmp = root->right;
                delete root;
                return tmp;
            } else if (!root->right) {
                TreeNode* tmp = root->left; // 2 右子树为空，返回左子树
                delete root;
                return tmp;
            } else {
                TreeNode* tmp = root->right;        // 3 左右都不为空，将root左子树转移到右子树的最左节点的左子树上
                while (tmp->left) tmp = tmp->left;
                tmp->left = root->left;
                TreeNode* node = root->right;       // node保存用于返回的节点
                delete root;
                return node;
            }
        }
        if (root->val > key) root->left = deleteNode(root->left, key);      // 二叉搜索树的递归
        if (root->val < key) root->right = deleteNode(root->right, key);    // 二叉搜索树的递归
        return root;
    }
};