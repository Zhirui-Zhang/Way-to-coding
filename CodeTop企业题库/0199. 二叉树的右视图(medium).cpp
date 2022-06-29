法1：DFS，计算当前遍历树的高度，与res数组长度比较即可得知是否需要加入数组
时间O(N)  空间O(N)
执行用时：4 ms, 在所有 C++ 提交中击败了63.07% 的用户
内存消耗：11.5 MB, 在所有 C++ 提交中击败了97.45% 的用户
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        dfs(root, 0);
        return res;
    }

private:
    vector<int> res;
    void dfs(TreeNode* root, int curHeight) {
        if (!root) return ;
        if (res.size() == curHeight) res.push_back(root->val);
        dfs(root->right, curHeight + 1);
        dfs(root->left, curHeight + 1);
    }
};

法2：BFS，一个队列即可，简单
时间O(N)  空间O(N)
执行用时：4 ms, 在所有 C++ 提交中击败了63.07% 的用户
内存消耗：11.5 MB, 在所有 C++ 提交中击败了94.10% 的用户
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        if (!root) return {};
        vector<int> res;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            int n = q.size();
            res.push_back(q.front()->val);
            while (n--) {
                TreeNode* tmp = q.front();
                q.pop();
                if (tmp->right) q.push(tmp->right);
                if (tmp->left) q.push(tmp->left);
            }
        }
        return res;
    }
};