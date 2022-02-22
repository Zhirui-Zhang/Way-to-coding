法1：BFS法，做过的题不再赘述，注意用size统计每一层需要输出的个数即可
时间O(N)  空间O(N)
执行用时：4 ms, 在所有 C++ 提交中击败了69.64% 的用户
内存消耗：11.9 MB, 在所有 C++ 提交中击败了98.30% 的用户
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if(!root)    return res;
        vector<int> temp;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty())
        {
            int s = q.size();
            while(s--)
            {
                TreeNode* t = q.front();
                q.pop();
                temp.push_back(t->val);
                if(t->left)    q.push(t->left);
                if(t->right)    q.push(t->right);
            }
            res.push_back(temp);
            temp.clear();
        }
        return res;
    }
};
