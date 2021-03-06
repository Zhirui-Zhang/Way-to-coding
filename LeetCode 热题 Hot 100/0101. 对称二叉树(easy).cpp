法1：DFS，做过的easy题，没什么好说的
时间O(N)  空间O(N)
执行用时：4 ms, 在所有 C++ 提交中击败了74.90% 的用户
内存消耗：15.9 MB, 在所有 C++ 提交中击败了84.64% 的用户
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if(!root)    return true;
        return dfs(root->left, root->right);
    }
    bool dfs(TreeNode* l, TreeNode* r)
    {
        if(!l && !r)    return true;
        if(!l || !r || (l->val != r->val))    return false;   // 此时已经是l r不同时为空了，判断一个是否为空即可
        return dfs(l->left, r->right) && dfs(l->right, r->left);    // 此时一定是l r均不为空且val值相等
    }
};

法2：BFS，多一种方法，原理大同小异
复杂度不变
执行用时：4 ms, 在所有 C++ 提交中击败了74.90% 的用户
内存消耗：16.1 MB, 在所有 C++ 提交中击败了28.06% 的用户
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if(!root)    return true;
        return bfs(root->left, root->right);
    }
    bool bfs(TreeNode* l, TreeNode* r)
    {
        queue<TreeNode*> q;
        q.push(l);
        q.push(r);
        while(!q.empty())
        {
            l = q.front();
            q.pop();
            r = q.front();
            q.pop();
            if(!l && !r)    continue;
            if(!l || !r || (l->val != r->val))    return false; 
            q.push(l->left);
            q.push(r->right);
            q.push(l->right);
            q.push(r->left);
        }  
        return true;
    }
};
