法1：DFS+DP，本质其实就是后序遍历，更新每一次的路径最大值后返回某一侧子树的路径和到上一层。其实也不难，就是没想出来，做了这么多题了思路还是没打开，真是fw啊
时间O(N)  空间O(N) 
执行用时：24 ms, 在所有 C++ 提交中击败了59.85% 的用户
内存消耗：27.7 MB, 在所有 C++ 提交中击败了10.75% 的用户
class Solution {
public:
    int maxPathSum(TreeNode* root) {
        res = INT_MIN;
        dfs(root);      // 这里可以不用参数接收返回类型int的原因是没有变量接受这个返回值，则返回值变量的空间被自动释放了
                        // 即使用temp = dfs(root)  最后结果也是 temp <= res，故不需要这个左值用于接收
        return res;
    }
private:
    int res;
    int dfs(TreeNode* root)
    {
        if(!root)    return 0;
        int leftMax = max(0, dfs(root->left));      // 递归调用，若左子树提供的贡献值为负，则舍弃
        int rightMax = max(0, dfs(root->right));    // 右子树同理
        res = max(res, leftMax + root->val + rightMax);       // 更新当前路径下的res值为 左+根+右 与自身的较大值
        return root->val + max(leftMax, rightMax);  // 返回到上一层，返回的值为根加上左右子树中贡献值较大的树
    }
};
