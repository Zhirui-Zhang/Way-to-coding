法1：迭代法+DFS法，先是利用中序遍历，将原二叉树的节点值记录在数组中，然后递归重构该二叉树，使其成为一棵平衡二叉搜索树
注意这里的难点是实现中序遍历，因为原树就是搜索树，是有大小顺序的，只有中序遍历才能实现
时间O(N)  空间O(N)
执行用时：144 ms, 在所有 C++ 提交中击败了31.01% 的用户
内存消耗：62.2 MB, 在所有 C++ 提交中击败了17.59% 的用户
class Solution {
public:
    TreeNode* balanceBST(TreeNode* root) {
        vector<int> v;
        stack<TreeNode*> s;
        while (root || !s.empty()) {        // 中序遍历模板，注意两个while中都是root而不是!root
            while (root) {
                s.push(root);
                root = root->left;
            }
            root = s.top();
            v.push_back(root->val);         // 模板中加一句插入数组
            s.pop();
            root = root->right;
        }
        return dfs(v, 0, v.size() - 1);
    }
private:
    TreeNode* dfs(vector<int>& v, int left, int right) {    // 二分法dfs重构二叉树，注意new节点的条件及方法
        if (left > right) return nullptr;                   // left > right时返回空节点
        if (left == right) return new TreeNode(v[left]);    // left = right时新建当前节点并返回
        int mid = (left + right) / 2;                       // 否则以数组中点建立根节点，分别递归左右子树即可
        TreeNode* root = new TreeNode(v[mid]);
        root->left = dfs(v, left, mid - 1);
        root->right = dfs(v, mid + 1, right);
        return root;
    }
};