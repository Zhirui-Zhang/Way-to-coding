法1：DFS做过的题，结果还是想原来麻烦的两次递归方法，还得好好复习记住啊
时间O(N)  空间O(N)
执行用时：20 ms, 在所有 C++ 提交中击败了27.78% 的用户
内存消耗：13.9 MB, 在所有 C++ 提交中击败了57.81% 的用户
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root || root == p || root == q)    return root;             // 如果有一侧等于root或者root为空，返回root节点
        TreeNode* left = lowestCommonAncestor(root->left, p, q);        // 分别递归root的左子树和右子树
        TreeNode* right = lowestCommonAncestor(root->right, p, q);
        if(left && right)     return root;                              // 判断left right情况，若都不为空，说明在root两侧，返回root
        else if(!left)    return right;                                 // 若左侧为空，说明都在右侧，返回right，反之亦然    
        else    return left;                                            // 忽略两侧都为空情况，因为随便返回一个都是空的
    }
};
