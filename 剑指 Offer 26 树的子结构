法1：※DFS，但是需要注意的点有很多，好好反思注释※
执行用时：32 ms, 在所有 C++ 提交中击败了93.23% 的用户
内存消耗：32.9 MB, 在所有 C++ 提交中击败了31.65% 的用户
class Solution {
public:
    bool doesAHaveB(TreeNode* A, TreeNode* B)   //引入新函数！！!
    {
        if(!B)    return true;  //B空，不管A空不空，直接返回真，注意先判断B，因为B可能因为没有子树而提前结束
        else if(!A)    return false;    //B不空A空，必返回假
        else if(A->val != B->val)   return false;   //不等，返回假
        else    return doesAHaveB(A->left, B->left) && doesAHaveB(A->right, B->right);
        //若相等，继续判断左右子树是否同时相等，否则仍不成立
    }

    bool isSubStructure(TreeNode* A, TreeNode* B) 
    {
        if(!A || !B)   return false;    //A或B有一个为假即退出
        bool res = false;   //初始变量为假
        if(A->val == B->val)    res = doesAHaveB(A, B);     //进入新函数进一步判断是否为A子树
        if(!res)    res = isSubStructure(A->left, B);   //若不等，从左子树入手
        if(!res)    res = isSubStructure(A->right, B);  //再不等，从右子树入手
        return res;
    }
};
