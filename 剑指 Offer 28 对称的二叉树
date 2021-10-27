法1：DFS，构建新判断函数，递归调用
执行用时：8 ms, 在所有 C++ 提交中击败了39.74% 的用户
内存消耗：15.9 MB, 在所有 C++ 提交中击败了57.82% 的用户
class Solution {
public:
    bool leftVSright(TreeNode* l, TreeNode* r)
    {
        if(l == NULL && r == NULL)  return true;
        else if(l == NULL || r == NULL)   return false;   //此时只有l r一个为空或都不为空的情况
        else if(l->val == r->val)   
            return leftVSright(l->left, r->right) && leftVSright(l->right, r->left);  //左右子树需完全对称才行
        else return false;  //此时仅为l r均不为空且值不相等
    }
    bool isSymmetric(TreeNode* root) {
        if(!root)   return true;  //空集居然是对称的，amazing!
        bool res = false;
        TreeNode *l = root->left, *r = root->right;
        res = leftVSright(l, r);
        return res;
    }
};

法2：上面代码的简化版，精简了部分变量，节省空间，效果不错
执行用时：4 ms, 在所有 C++ 提交中击败了81.69% 的用户
内存消耗：15.8 MB, 在所有 C++ 提交中击败了86.47% 的用户
class Solution {
public:
    bool leftVSright(TreeNode* l, TreeNode* r)
    {
        if(l == NULL && r == NULL)  return true;    //同时为空说明相等，返回true
        else if(l == NULL || r == NULL || l->val != r->val)   return false;     //上面简化，把有一个为空和都不空但数值不等归为一类，返回false  
        else return leftVSright(l->left, r->right) && leftVSright(l->right, r->left);
    }
    bool isSymmetric(TreeNode* root) {
        if(!root)   return true;
        return leftVSright(root->left, root->right);    //直接带入新函数，去除新建左右子树变量以及res结果布尔值变量
    }
};
