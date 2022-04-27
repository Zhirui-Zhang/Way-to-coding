法1：DFS，按照之前的规律，这道题需要遍历整个树，所以函数不需要返回值，利用回溯法，题目并不难
时间O(N)  空间O(N)
执行用时：0 ms, 在所有 C++ 提交中击败了100.00% 的用户
内存消耗：19.3 MB, 在所有 C++ 提交中击败了77.09% 的用户
class Solution {
public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        dfs(root, targetSum);
        return res;
    }
private:
    vector<vector<int>> res;
    vector<int> tmp;
    void dfs(TreeNode* root, int targetSum) {
        if (!root) return;
        if (!root->left && !root->right && root->val == targetSum) {
            tmp.push_back(root->val);
            res.push_back(tmp);
            tmp.pop_back();
            return;
        }
        tmp.push_back(root->val);
        dfs(root->left, targetSum - root->val);
        dfs(root->right, targetSum - root->val);
        tmp.pop_back();
    }
};