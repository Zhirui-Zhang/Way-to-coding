法1:DFS 很简单 右→根→左遍历，但是k这里要一直遍历一遍，思考一下如何在找到确定结点的时候提前退出？
执行用时：12 ms, 在所有 C++ 提交中击败了90.81% 的用户
内存消耗：23.5 MB, 在所有 C++ 提交中击败了65.95% 的用
class Solution {
public:
    int kthLargest(TreeNode* root, int k) {
        DFS(root, k);
        return res;
    }
private:
    int res;  //res存储结果
    void DFS(TreeNode* root, int& k)    //注意这里是引用，防止k在返回时值发生改变
    {
        if(root == NULL)    return;
        DFS(root->right, k);
        if(k == 1)    res = root->val;  //仅在找到该节点时给res赋值
        k--;
        DFS(root->left, k);
    } 
};

改进版：当找到节点时提前return返回
class Solution {
public:
    int kthLargest(TreeNode* root, int k) {
        DFS(root, k);
        return res;
    }
private:
    int res;
    void DFS(TreeNode* root, int& k)
    {
        if(root == NULL)    return;
        DFS(root->right, k);
        if(k == 0)    return;   //当k=0不变时，一路返回原函数
        if(--k == 0)    res = root->val;    
        DFS(root->left, k);
    } 
};
