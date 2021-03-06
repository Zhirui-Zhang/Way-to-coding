法1：DFS很简单，但是题目进阶要求用迭代求
时间O(N)  空间O(N)
执行用时：4 ms, 在所有 C++ 提交中击败了40.28% 的用户
内存消耗：8.1 MB, 在所有 C++ 提交中击败了84.21% 的用户
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        dfs(root);
        return res;
    }
private:
    vector<int> res;
    void dfs(TreeNode* root)
    {
        if(!root)    return;
        dfs(root->left);
        res.push_back(root->val);
        dfs(root->right);
    }
};

法2：迭代法，利用栈，每次从判断左子树是否为空入手，若不空将其入栈并将左子树置为空，否则加入res并pop，选择右子树入栈
时间O(N)  空间O(N)
执行用时：0 ms, 在所有 C++ 提交中击败了100.00% 的用户
内存消耗：7.9 MB, 在所有 C++ 提交中击败了97.86% 的用户
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        if(!root)    return res;
        stack<TreeNode*> s;
        s.push(root);
        while(!s.empty())
        {
            TreeNode* temp = s.top();
            if(temp->left)
            {
                s.push(temp->left);
                temp->left = nullptr;       // 若左子树存在，入栈并指向空
            }
            else    
            {
                res.push_back(temp->val);
                s.pop();
                if(temp->right)    s.push(temp->right);
            }
        }
        return res;
    }
};

改进：不用修改原节点的方法，但其实最后root的值也发生了改变，如果不想改变可以在最开始就复制一个root节点
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        stack<TreeNode*> stk;
        while (root != nullptr || !stk.empty()) {       // 这个循环条件不太好想，root经常为空，但只有栈也为空时说明已遍历完成，退出
            while (root != nullptr) {
                stk.push(root);
                root = root->left;
            }
            root = stk.top();       // 这一步是为当上一步指向的右子树为空时准备的，使其重新回到上一个需要遍历右子树的节点
            stk.pop();
            res.push_back(root->val);
            root = root->right;     // 这里也很重要，每次退出前指向右子树，哪怕右子树为空，也能避免重复回到之前的root节点
        }
        return res;
    }
};

借机总结一下二叉树三种遍历的迭代写法，大体就是把代码顺序调换一下，栈中前序push左子树，中序push根节点，后续push右子树，后序最后注意要把res反转一下
1.前序遍历      即  中 -> 左 -> 右
    vector<int> preorderTraversal(TreeNode* root) 
    {
        stack<TreeNode*> s;
        vector<int> res;
        while(root || !s.empty())       // 循环条件相同，两者都不空时
        {
            while(root)                 // root不空时，先加入右子树，再加入root值，然后指向左子树
            {
                if(root->right)    s.push(root->right);
                res.push_back(root->val);
                root=root->left;
            }
            if(!s.empty())
            {
                root=s.top();               // 令root重新指向栈顶节点并pop出去，注意一定要判断s是否为空，因为到最后一个右节点时s已经空了，此时再弹出会报错绑定错误！血与泪的教训啊md
                s.pop();
            }
        }
        return res;        
    }

2.中序遍历          即  左 -> 中 -> 右
    vector<int> inorderTraversal(TreeNode* root) 
    {
        stack<TreeNode*> s;
        vector<int> res;
        while(root || !s.empty())      
        {
            while(root)              
            {
                s.push(root);
                root=root->left;
            }
            root=s.top();           
            s.pop();
            res.push_back(root->val);
            root = root->right;
        }
        return res;        
    }
    
3.后序遍历           即  左 -> 右 -> 中
    vector<int> postorderTraversal(TreeNode* root) 
    {
        stack<TreeNode*> s;
        vector<int> res;
        while(root || !s.empty())      
        {
            while(root)              
            {
                if(root->left)    s.push(root->left);
                res.push_back(root->val);
                root=root->right;
            }
            if(!s.empty())
            {   
                root=s.top();           // 后序也是同理，必须判断s是否为空，在最后的左节点出会报错！！！
                s.pop();
            }
        }
        reverse(res.begin(), res.end());        // 注意最后要将res数组反转后输出
        return res;        
    }
