法1：递归调用，方法类似DFS，注意new指针，空间大小为TreeNode，否则报错
执行用时：0 ms, 在所有 C++ 提交中击败了100.00% 的用户
内存消耗：9.3 MB, 在所有 C++ 提交中击败了5.01% 的用户
class Solution {
public:
    TreeNode* mirrorTree(TreeNode* root) {
        if(!root)   return root;
        TreeNode* res = new(TreeNode);  //这里注意new一块新的内存空间预留给该指针，否则下面赋值部分会报错
        res->val = root->val;
        if(root->right != NULL)    res->left = mirrorTree(root->right);     //其实可以不用判断是否为空的，如果空指针在下一次递归中直接返回了
        if(root->left != NULL)    res->right = mirrorTree(root->left);
        return res;
    }
};

法2：递归改进版，不需要新建res构造整个树，只改变原树root即可
其实很好理解，和下面队列的直接交换类似，先构建temp存储左节点，再让左节点等于右节点（递归调用），最后让右节点等于临时左节点temp（递归调用），返回root
执行用时：0 ms, 在所有 C++ 提交中击败了100.00% 的用户
内存消耗：8.9 MB, 在所有 C++ 提交中击败了60.36% 的用户
class Solution {
public:
    TreeNode* mirrorTree(TreeNode* root) {
        if(!root)   return root;
        TreeNode* temp = root->left;  
        root->left = mirrorTree(root->right);
        root->right = mirrorTree(temp);
        return root;
    }
};

法3：BFS，借用堆栈（先左后右） or 借用队列（先右后左），本文采用队列
执行用时：0 ms, 在所有 C++ 提交中击败了100.00% 的用户
内存消耗：9.1 MB, 在所有 C++ 提交中击败了8.10% 的用户
class Solution {
    public:
        TreeNode* mirrorTree(TreeNode* root) {
            if(!root)   return root;
            queue<TreeNode*> q;
            q.push(root);
            while(!q.empty())
            {
                TreeNode* temp = q.front();
                q.pop();
                if(temp->right != NULL)     q.push(temp->right);
                if(temp->left != NULL)     q.push(temp->left);

                TreeNode* node = temp->right;    //因为是指针，这里可以直接交换左右子树，以达到修改原root的节点的目的
                temp->right = temp->left;
                temp->left = node;
            }
            return root;
        }
    };
