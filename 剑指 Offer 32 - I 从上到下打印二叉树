法1：层序遍历，利用队列queue<TreeNode*> q
执行用时：0 ms, 在所有 C++ 提交中击败了100.00% 的用户
内存消耗：11.9 MB, 在所有 C++ 提交中击败了49.05% 的用户
class Solution {
public:
    vector<int> levelOrder(TreeNode* root) {
        vector<int> v;
        if(root == NULL)   return v;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty())
        {
            TreeNode* temp = q.front();
            v.push_back(temp->val);
            q.pop();
            if(temp->left != NULL)    q.push(temp->left);
            if(temp->right != NULL)   q.push(temp->right);
        }
        return v;
    }
};
