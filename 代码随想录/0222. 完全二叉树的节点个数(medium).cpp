法1：DFS法，与普通的递归不同，由于是完全二叉树，需要利用其性质巧解，分别找到左右子树中的完全二叉树，相加计算可得结果，注意加上根节点
时间O(logN)*O(logN)  空间O(logN)
执行用时：32 ms, 在所有 C++ 提交中击败了47.27% 的用户
内存消耗：30.1 MB, 在所有 C++ 提交中击败了68.29% 的用户
class Solution {
public:
    int countNodes(TreeNode* root) {
        if (!root) return 0;
        TreeNode* left = root->left;
        TreeNode* right = root->right;
        int leftHeight = 1, rightHeight = 1;
        // 定义左右子树的初始高度
        while (left) {
            leftHeight++;
            left = left->left;
        }
        while (right) {
            rightHeight++;
            right = right->right;
        }
        if (leftHeight == rightHeight) return pow(2, leftHeight) - 1;
        // 若当前的树为完全二叉树，则套用公式 节点个数等于 2的n次方 - 1
        return countNodes(root->left) + countNodes(root->right) + 1;
        // 否则递归寻找左右子树中的完全二叉树，注意返回时还要注意加上根节点
    }
};