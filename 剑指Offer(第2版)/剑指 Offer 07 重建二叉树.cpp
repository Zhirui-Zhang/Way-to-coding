法1：分治+递归调用  时间空间均为O(n)
执行用时：16 ms, 在所有 C++ 提交中击败了66.25% 的用户
内存消耗：24.7 MB, 在所有 C++ 提交中击败了67.00% 的用户
class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if(inorder.empty())     return NULL;    //其实可以不用考虑为空
        this->preorder = preorder;      //将私用数据成员拷贝为已给定的前序遍历数组
        for(int i = 0; i < inorder.size(); i++)
        {
            un_map[inorder[i]] = i;     //依次给哈希表赋值，key值为节点的val，val值为节点所在位置
        }
        return recur(0, 0, inorder.size() - 1);
    }

private:
    vector<int> preorder;
    unordered_map<int, int> un_map;
    TreeNode* recur(int root, int left, int right)  //三个参数分别表示 根节点在前序遍历的索引 root 、子树在中序遍历的左边界 left 、子树在中序遍历的右边界 right
    {
        if(left > right)    return NULL;    //中止递归条件，注意left和right不能相等
        TreeNode* temp = new TreeNode(preorder[root]);  //构建新节点方式
        int i = un_map[preorder[root]];     //i记录中序遍历中根节点的所在位置，i-1为左子树右边界，i+1为右子树左边界
        //接下来进入分治算法，左右子树分别递归，root+1为root的左子树根节点位置
        temp->left = recur(root + 1, left, i - 1);
        temp->right = recur(root + i - left + 1, i + 1, right);    //右子树的根节点位置计算为 i - left + root + 1，含义为 根节点索引 + 左子树长度 + 1
        return temp;
    }
};
