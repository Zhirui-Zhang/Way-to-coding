法1：DFS+BFS  借助深度函数，层序遍历所有节点，计算左右子树深度差，空间复杂度过高，需要改善
此时最坏时间O(n^2)平均O(nlogn)  空间O(n)-链表时，递归调用层数为n
执行用时：8 ms, 在所有 C++ 提交中击败了89.23% 的用户
内存消耗：20.5 MB, 在所有 C++ 提交中击败了19.21% 的用户
class Solution {
public:
    bool isBalanced(TreeNode* root) {
        if(root == NULL)    return true;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty())
        {
            TreeNode* temp = q.front();
            if(abs(maxDepth(temp->left) - maxDepth(temp->right)) > 1)    return false;
            q.pop();
            if(temp->left != NULL)    q.push(temp->left);
            if(temp->right != NULL)    q.push(temp->right);
        }
        return true;
    }
    int maxDepth(TreeNode* root) {
        if(root == NULL)    return 0;
        return 1 + max(maxDepth(root->left), maxDepth(root->right));
    }
};

上面方法改进版：
执行用时：8 ms, 在所有 C++ 提交中击败了89.23% 的用户
内存消耗：20.4 MB, 在所有 C++ 提交中击败了59.33% 的用户
class Solution {
public:
    bool isBalanced(TreeNode* root) {
        if(root == NULL)    return true;
        return abs(maxDepth(root->left) - maxDepth(root->right)) <= 1 && isBalanced(root->left) && isBalanced(root->right);
        //只有（根节点+左节点+右节点）均满足高度条件时才返回真
    }
    int maxDepth(TreeNode* root) {
        if(root == NULL)    return 0;
        return 1 + max(maxDepth(root->left), maxDepth(root->right));
    }
};

法2：后序遍历+剪枝法     核心思想是递归从根节点开始向上遍历，依次计算左右节点的高度，如果相差大于1，返回一个负值（-1只是一个值，没有实际意义），否则依次向上递归
时间空间复杂度均为O(n)
执行用时：8 ms, 在所有 C++ 提交中击败了89.23% 的用户
内存消耗：20.5 MB, 在所有 C++ 提交中击败了23.97% 的用户
class Solution {
public:
    bool isBalanced(TreeNode* root) {
        return dfs(root) >= 0;  //返回负值说明不是平衡二叉树，否则任意正值都为真
    }
    int dfs(TreeNode* root) {
        if(root == NULL)    return 0;
        int leftHeight = dfs(root->left);
        int rightHeight = dfs(root->right);
        if(leftHeight == -1 || rightHeight == -1 || abs(leftHeight - rightHeight) > 1)    return -1;    //若相差大于1，返回负值
        else    return max(leftHeight, rightHeight) + 1;    //计算当前子节点的高度
    }
};
