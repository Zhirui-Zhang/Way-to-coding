法1：两个递归函数，属实是麻烦了，再好好改进一下
执行用时：876 ms, 在所有 C++ 提交中击败了5.34% 的用户
内存消耗：13.8 MB, 在所有 C++ 提交中击败了85.08% 的用户
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == NULL || root == p || root == q)     return root;
        if((isExist(root->left, p) && isExist(root->right, q)) || (isExist(root->left, q) && isExist(root->right, p)))    return root;  //若p q在两侧，返回root
        if(isExist(root->left, p))    return lowestCommonAncestor(root->left, p, q);    //否则都在root左侧或右侧，递归调用并返回
        else    return lowestCommonAncestor(root->right, p, q);
    } 
    bool isExist(TreeNode* a, TreeNode* b)    //该函数的作用是判断a的子树中是否有b
    {
        if(a == NULL)    return false;
        if(a == b || isExist(a->left, b) || isExist(a->right, b))    return true;
        else return false;
    }
};

改进版DFS
执行用时：8 ms, 在所有 C++ 提交中击败了99.53% 的用户
内存消耗：13.9 MB, 在所有 C++ 提交中击败了79.91% 的用户
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == NULL || root == p || root == q)     return root;
        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);
        if(left == NULL && right == NULL)    return NULL;   //若左右都为空，说明p q不在该节点的两侧，返回空
        if(left == NULL)    return right;   //左为空，说明p q都在右侧
        if(right == NULL)    return left;   //右为空，说明p q都在左侧
        else    return root;    //若左右都不为空，说明p q在root的两侧，此时返回root即可
    }
};
