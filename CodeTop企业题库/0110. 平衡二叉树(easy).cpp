法1：自底向上的递归，若高度差>1，一路返回false即可，否则返回当前左右的较大高度值
时间O(N)  空间O(N)
执行用时：8 ms, 在所有 C++ 提交中击败了85.00% 的用户
内存消耗：20.3 MB, 在所有 C++ 提交中击败了83.70% 的用户
class Solution {
public:
    bool isBalanced(TreeNode* root) {
        if (dfs(root) == -1) return false;
        return true;
    }

private:
    int dfs(TreeNode* root) {
        if (!root) return 0;
        int leftHeight = dfs(root->left);
        int rightHeight = dfs(root->right);
        if (leftHeight == -1 || rightHeight == -1) return -1;   // 也可以把这两条语句放在一起，返回-1
        if (abs(leftHeight - rightHeight) > 1) return -1;
        return 1 + max(leftHeight, rightHeight);
    }
};