法1：DFS，做过的题，做饭复杂了一点，有改进版
时间O(N)  空间O(N)
执行用时：4 ms, 在所有 C++ 提交中击败了45.15% 的用户
内存消耗：9.5 MB, 在所有 C++ 提交中击败了32.05% 的用户
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if(!root)    return root;
        TreeNode* temp = root->left;
        root->left = root->right;
        root->right = temp;
        invertTree(root->left);
        invertTree(root->right);
        return root;
    }
};

改进版：
执行用时：0 ms, 在所有 C++ 提交中击败了100.00% 的用户
内存消耗：9.5 MB, 在所有 C++ 提交中击败了48.21% 的用户
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if(!root)    return root;
        TreeNode* temp = root->left;  
        root->left = invertTree(root->right);
        root->right = invertTree(temp);
        return root;
    }
};

改进版2：
采用更通俗易懂的BFS方式
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if (!root) return root;
        swap(root->left, root->right);
        invertTree(root->left);
        invertTree(root->right);
        return root;
    }
};

法2：BFS略
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        queue<TreeNode*> que;
        if (root != NULL) que.push(root);
        while (!que.empty()) {
            int size = que.size();
            for (int i = 0; i < size; i++) {
                TreeNode* node = que.front();
                que.pop();
                swap(node->left, node->right); // 节点处理
                if (node->left) que.push(node->left);
                if (node->right) que.push(node->right);
            }
        }
        return root;
    }
};
