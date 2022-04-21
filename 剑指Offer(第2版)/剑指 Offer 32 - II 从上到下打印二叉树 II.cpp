同样为BFS搜索，利用队列存储，注意难点在于利用q.size()记录当前行的元素个数，以输出到一个临时数组temp_v中，在加入二维数组里面
执行用时：4 ms, 在所有 C++ 提交中击败了72.74% 的用户
内存消耗：12.1 MB, 在所有 C++ 提交中击败了84.88% 的用户
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> v;
        if(root == NULL)   return v;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty())
        {
            vector<int> temp_v;     //临时存储数组
            for(int i = q.size(); i > 0; i--)
            {
                TreeNode* temp_q = q.front();   //临时存储节点
                temp_v.push_back(temp_q->val);
                q.pop();
                if(temp_q->left != NULL)    
                {
                    q.push(temp_q->left);
                }
                if(temp_q->right != NULL)   
                {
                    q.push(temp_q->right);
                }
            }
            v.push_back(temp_v);
        }
        return v;
    }
};
