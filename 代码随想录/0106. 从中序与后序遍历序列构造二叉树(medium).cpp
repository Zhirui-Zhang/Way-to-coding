法1：哈希表+DFS，同前序中序相同，参数计算稍有不同，总算能自己写出来了
时间O(N)  空间O(N)
执行用时：16 ms, 在所有 C++ 提交中击败了82.75% 的用户
内存消耗：25.6 MB, 在所有 C++ 提交中击败了61.34% 的用户
class Solution {
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n = inorder.size();
        for (int i = 0; i < n; ++i) {
            hash[inorder[i]] = i;
        }
        return dfs(postorder, n - 1, 0, n - 1);     
    }

private:
    unordered_map<int, int> hash;
    TreeNode* dfs(vector<int>& postorder, int root, int left, int right) {
        // 参数依次为 root:后序中的根节点下标，left:中序中的左节点左边界下标，right:中序中的右节点右边界下标
        if (left > right) return nullptr;
        int pos = hash[postorder[root]];
        TreeNode* node = new TreeNode(postorder[root]);
        node->left = dfs(postorder, root - right + pos - 1, left, pos - 1);
        node->right = dfs(postorder, root - 1, pos + 1, right);
        return node;
    }
};