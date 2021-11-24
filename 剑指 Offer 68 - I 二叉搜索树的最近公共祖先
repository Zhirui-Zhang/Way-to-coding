法1：DFS递归调用，利用二叉搜索树的特性，判断根节点和p q两节点值的大小
执行用时：28 ms, 在所有 C++ 提交中击败了73.52% 的用户
内存消耗：22.7 MB, 在所有 C++ 提交中击败了75.80% 的用户
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        //若root在p q之间返回root即可
        if(root == NULL || (root->val >= p->val && root->val <= q->val) || (root->val >= q->val && root->val <= p->val))      return root;
        //若不在判断在root左子树还是右子树，开始递归
        if(root->val >= p->val && root->val >= q->val)      return lowestCommonAncestor(root->left, p, q);
        return lowestCommonAncestor(root->right, p, q);
    }
};

法2：BFS，迭代法，层序遍历节点，判断与p q的大小关系
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(p->val > q->val)     //可以通过交换p q节点，始终保证p的值小于q
        {
            TreeNode* temp = p;
            p = q;
            q = temp;
        }
        while(root != NULL)
        {
            if(root->val < p->val)    root = root->right;
            if(root->val > q->val)    root = root->left;
            else    break;
        }
        return root;
    }
};
