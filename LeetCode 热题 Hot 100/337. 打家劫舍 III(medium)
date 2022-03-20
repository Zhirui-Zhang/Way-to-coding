法1:二叉树DP法，解法太妙了，真的甘拜下风，自己就是没想出来怎么表示左右子树已偷或没偷，原来是用pair记录的，高
时间O(N)  空间O(N)
执行用时：12 ms, 在所有 C++ 提交中击败了88.78% 的用户
内存消耗：21.6 MB, 在所有 C++ 提交中击败了92.39% 的用户
class Solution {
public:
    int rob(TreeNode* root) {
        auto res = dfs(root);
        return max(res.first, res.second);      // pair中first表示不偷当前节点，second表示偷当前节点
    }
private:
    pair<int, int> dfs(TreeNode* root){
        if(!root)    return {0, 0};             // 若为空，表示偷不偷都为0
        auto left = dfs(root->left);            // 递归遍历左子树和右子树的值
        auto right = dfs(root->right);
        return {max(left.first, left.second) + max(right.first, right.second), root->val + left.first + right.first};       
        // 返回pair类型，若不偷当前节点，则左右各取最大值相加，若偷，则自己的值加上左右不偷的值
    }
};
