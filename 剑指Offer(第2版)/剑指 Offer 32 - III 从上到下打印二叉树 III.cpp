法1：在temp_v的基础上再引入堆栈temp_s，倒序存储偶数行数组元素，用row表示奇偶行数
执行用时：0 ms, 在所有 C++ 提交中击败了100.00% 的用户
内存消耗：13.1 MB, 在所有 C++ 提交中击败了5.52% 的用户
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> v;
        if(root == NULL)   return v;
        queue<TreeNode*> q;
        q.push(root);
        int row = 1;    //当前行数
        while(!q.empty())
        {
            vector<int> temp_v;     //临时存储数组
            stack<int> temp_s;      //临时倒序存储数组
            for(int i = q.size(); i > 0; i--)
            {
                if(row % 2 == 0)    //偶数行倒序
                {
                    TreeNode* temp_q = q.front();   //临时存储节点
                    temp_s.push(temp_q->val);
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
                else    //奇数行正序
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
            }
            if(row % 2 == 0)    //偶数行倒序
            {
                for(int i = temp_s.size(); i > 0; i--)  
                //这里不能用for(int j = 0; j < temp_s.size(); j++)，因为temp_s的size随时在变化！！！
                {
                    temp_v.push_back(temp_s.top());
                    temp_s.pop();
                }
            }
            v.push_back(temp_v);
            row++;
        }
        return v;
    }
};

法2：temp_v.reverse()函数
执行用时：8 ms, 在所有 C++ 提交中击败了28.27% 的用户
内存消耗：12.1 MB, 在所有 C++ 提交中击败了89.68% 的用户
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> v;
        if(root == NULL)   return v;
        queue<TreeNode*> q;
        q.push(root);
        int row = 1;    //当前行数
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
            //偶数行倒序
            if(row % 2 == 0)    reverse(temp_v.begin(), temp_v.end());
            v.push_back(temp_v);
            row++;
        }
        return v;
    }
};

法3：采用双端队列deque而非queue进行层序遍历，奇数层正向入队，偶数层反向入队（此时先入队右节点，再入队左节点）
执行用时：0 ms, 在所有 C++ 提交中击败了100.00% 的用户
内存消耗：12.7 MB, 在所有 C++ 提交中击败了7.93% 的用户
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> v;
        if(root == NULL)   return v;
        deque<TreeNode*> q;
        q.push_back(root);  //根节点看作第0行，后端入队
        int row = 1;    //当前行数
        while(!q.empty())
        {
            vector<int> temp_v;     //临时存储数组
            for(int i = q.size(); i > 0; i--)
            {
                if(row % 2 == 0)    //偶数行倒序
                {
                    TreeNode* temp_q = q.front();   //临时存储front节点
                    temp_v.push_back(temp_q->val);
                    q.pop_front();  //弹出front节点
                    //此时需要先存储右子节点，再左子节点！！！
                    if(temp_q->right != NULL)   q.push_back(temp_q->right);     //后端入队
                    if(temp_q->left != NULL)   q.push_back(temp_q->left);
                    
                }
                else    //奇数行正序
                {
                    TreeNode* temp_q = q.back();   //临时存储back节点
                    temp_v.push_back(temp_q->val);
                    q.pop_back();   //弹出back节点
                    if(temp_q->left != NULL)   q.push_front(temp_q->left);   //前端入队
                    if(temp_q->right != NULL)   q.push_front(temp_q->right); 
                }
            }
            v.push_back(temp_v);
            row++;
        }
        return v;
    }
};
