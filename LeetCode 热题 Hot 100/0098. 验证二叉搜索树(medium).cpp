法1：DFS，前两次提交关键问题在于没有解决孙子节点与祖父节点之间的大小关系问题，例如[5,4,6,n,n,3,7]中3<5不成立，所以应该设置当前节点的上下界，递归判断左右节点是否都在上下界范围内
时间O(N) 空间O(N)
执行用时：4 ms, 在所有 C++ 提交中击败了97.22% 的用户
内存消耗：21.1 MB, 在所有 C++ 提交中击败了65.11% 的用户
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        return dfs(LONG_MIN, root, LONG_MAX);   // 由于测试案例中有INT_MAX的值，所以上下界需要比它还大，故采用LONG_MAX进行约束
    }
private:
    bool dfs(long lower, TreeNode* root, long upper)
    {
        if(!root)    return true;
        if(root->val <= lower || root->val >= upper)    return false;
        return dfs(lower, root->left, root->val) && dfs(root->val, root->right, upper);   // 左节点中以当前root为上界，右节点以root为下界
    }
};

法2：中序遍历，其结果应为递增数组，若不满足说明不是二叉搜索树
时间O(N)  空间O(N)
执行用时：16 ms, 在所有 C++ 提交中击败了24.48% 的用户
内存消耗：21.3 MB, 在所有 C++ 提交中击败了16.80% 的用户
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        long temp = LONG_MIN;       // temp用来暂时存储中序遍历数组上一个元素值
        stack<TreeNode*> s;
        while (root || !s.empty()) {      
            while (root) {
                s.push(root);
                root = root->left;
            }
            root = s.top();      
            s.pop();
            if(root->val <= temp)    return false;      // 如果不满足，说明不是递增数组，返回false
            temp = root->val;                           // 将temp的值替换成当前root的节点值后root指向右子树
            root = root->right;     
        }
        return true;
    }
};
