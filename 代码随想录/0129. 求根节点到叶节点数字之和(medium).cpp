法1：DFS，小难点在于递归返回条件是叶节点（即左右为空），而非单纯的节点为空，若只是 if (!root) 就返回会导致重复计算
时间O(N)  空间O(N)
执行用时：4 ms, 在所有 C++ 提交中击败了42.89% 的用户
内存消耗：8.9 MB, 在所有 C++ 提交中击败了89.41% 的用户
class Solution {
public:
    int sumNumbers(TreeNode* root) {
        dfs(root, 0);
        return sum;
    }
private:
    int sum;
    void dfs(TreeNode* root, int curNum) {
        if (!root) {                            // 如果遇到空节点，说明此路不通，返回
            return;
        }
        curNum = 10 * curNum + root->val;
        if (!root->left && !root->right) {      // 只有在遍历到叶节点时才进行相加并返回
            sum += curNum;
            return;
        }
        dfs(root->left, curNum);                // 后序遍历
        dfs(root->right, curNum);
    }
};