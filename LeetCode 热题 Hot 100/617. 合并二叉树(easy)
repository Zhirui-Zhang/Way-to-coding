法1：简答题我重拳出击，判断三种情况即可
时间O(N)  空间O(N)
执行用时：20 ms, 在所有 C++ 提交中击败了99.49% 的用户
内存消耗：31.5 MB, 在所有 C++ 提交中击败了78.79% 的用户
class Solution {
public:
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        if(!root2){
            return root1;
        }
        if(!root1){
            return root2;
        }
        root1->val += root2->val;
        root1->left = mergeTrees(root1->left, root2->left);
        root1->right = mergeTrees(root1->right, root2->right);
        return root1;
    }
};
