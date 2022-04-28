法1：DFS法，两个额外函数，分别计算范围内的最大值，返回其下标，以及构造二叉树的DFS递归，类似前中序构建二叉树那道题
时间O(N^2)  空间O(N)
执行用时：72 ms, 在所有 C++ 提交中击败了84.77% 的用户
内存消耗：41.2 MB, 在所有 C++ 提交中击败了53.16% 的用户
class Solution {
public:
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        int n = nums.size();
        return dfs(nums, maxIndex(nums, 0, n - 1), 0, n - 1);
    }
private:
    int maxIndex(vector<int>& nums, int left, int right) {
        int temp = nums[left], res = left;
        for (int i = left + 1; i <= right; ++i) {
            if (nums[i] > temp) {
                res = i;
                temp = nums[i];
            }
        }
        return res;
    }
    TreeNode* dfs(vector<int>& nums, int pos, int left, int right) {
        // 参数意义分别为： pos:根节点的对应下标  left:左边界的下标  right:右边界的下标
        if (left > right) return nullptr;
        TreeNode* root = new TreeNode(nums[pos]);
        if (pos - 1 < left) root->left = nullptr;
        else root->left = dfs(nums, maxIndex(nums, left, pos - 1), left, pos - 1);
        if (pos + 1 > right) root->right = nullptr;
        else root->right = dfs(nums, maxIndex(nums, pos + 1, right), pos + 1, right);
        return root;
    }
};

随想录优化版：采用左闭右开区间，当left == right也可以直接返回nullptr
class Solution {
private:
    // 在左闭右开区间[left, right)，构造二叉树
    TreeNode* traversal(vector<int>& nums, int left, int right) {
        if (left >= right) return nullptr;

        // 分割点下标：maxIndex，可以不用单独构造一个函数计算最大值，还麻烦
        int maxIndex = left;
        for (int i = left + 1; i < right; ++i) {
            if (nums[i] > nums[maxIndex]) maxIndex = i;
        }

        TreeNode* root = new TreeNode(nums[maxIndex]);

        // 左闭右开：[left, maxIndex)
        root->left = traversal(nums, left, maxIndex);

        // 左闭右开：[maxIndex + 1, right)
        root->right = traversal(nums, maxIndex + 1, right);

        return root;
    }
public:
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        return traversal(nums, 0, nums.size());    // 左闭右开区间
    }
};
