法1：哈希表+分治法，又是做过的题，但是细节太多，没有全部掌握，好好反思一下，注意三个位置参数的表示的意义
时间O(N)  空间O(N)
执行用时：16 ms, 在所有 C++ 提交中击败了75.33% 的用户
内存消耗：25.8 MB, 在所有 C++ 提交中击败了33.17% 的用户
class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = inorder.size();
        for(int i = 0; i < n; ++i)
        {
            un_map[inorder[i]] = i; 
        }
        return mergeTree(preorder, 0, 0, n - 1);    // 这三个参数很重要，也比较难记，依次表示preorder中的根节点位置、inorder中的左边界位置、inorder中的右边界位置！！！
    }
private:
    unordered_map<int, int> un_map;
    TreeNode* mergeTree(vector<int>& preorder, int root, int l, int r)
    {
        if(l > r)    return nullptr;    // 返回条件
        int i = un_map[preorder[root]]; // 定义一个inorder中的节点位置，便于计算左右边界长度
        TreeNode* temp = new TreeNode(preorder[root]);
        temp->left = mergeTree(preorder, root + 1, l, i - 1);             // 注意三个参数的写法
        temp->right = mergeTree(preorder, root + i - l + 1, i + 1, r);    // 注意三个参数的写法
        return temp;
    }
};
