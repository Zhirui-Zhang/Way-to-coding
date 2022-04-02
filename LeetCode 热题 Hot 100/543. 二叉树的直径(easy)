法1：DFS，真的是easy吗，还是我太蠢了，想了好久还是借助评论区提醒做出来的，关键是设置一个全局变量，而且还是得写dfs函数，我一直想在一个函数里写，好像不太行
时间O(N) 空间O(N)
执行用时：8 ms, 在所有 C++ 提交中击败了76.62% 的用户
内存消耗：19.7 MB, 在所有 C++ 提交中击败了65.64% 的用户
class Solution {
public:
    int diameterOfBinaryTree(TreeNode* root) {
        dfs(root);
        return res;
    }
private:
    int res;
    int dfs(TreeNode* root){
        if(!root){
            return 0;
        }
        int left = dfs(root->left);
        int right = dfs(root->right);
        res = max(res, left+right);     // 每次更新全局变量res和左右子树和的较大值
        return 1 + max(left, right);    // 但返回的是1+左右子树中的较大值，便于下一次计算
    }
};
