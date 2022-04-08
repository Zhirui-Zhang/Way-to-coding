法1:DFS，比较简单，设置一个遍历cur记录当前遍历到的总和即可
时间O(N)  空间O(N)
执行用时：24 ms, 在所有 C++ 提交中击败了97.98% 的用户
内存消耗：32.7 MB, 在所有 C++ 提交中击败了26.16% 的用户
class Solution {
public:
    TreeNode* convertBST(TreeNode* root) {
        dfs(root);
        return root;
    }
private:
    int cur;
    void dfs(TreeNode* root){
        if(!root){
            return;
        }
        dfs(root->right);
        root->val += cur;
        cur = root->val;
        dfs(root->left);
    }
};


优化：其实放在一个函数里就可以了
class Solution {
public:
    TreeNode* convertBST(TreeNode* root) {
        if(root){
            dfs(root->right);
            root->val += cur;
            cur = root->val;
            dfs(root->left);
        }
        return root;
    }
private:
    int cur;
};
