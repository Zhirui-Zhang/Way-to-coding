法1：BFS法，把队列设为pair<TreeNode*, unsigned long long>的形式，每次入队时记录节点和当前下标的值
计算每一层的左右最大差值，即可得到最大宽度值
时间O(N)  空间O(N)
执行用时：4 ms, 在所有 C++ 提交中击败了96.93% 的用户
内存消耗：16.9 MB, 在所有 C++ 提交中击败了58.48% 的用户
class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        if (!root) return 0;
        // 这个下标值太大了，没见过这么大的范围，或者int的话入队前取个模也可以
        unsigned long long res = 1;
        // pair<节点, 节点下标>  注意每层下标都是1~n，而不是连续数组
        queue<pair<TreeNode*, unsigned long long>> q;
        q.push({root, 0});
        while (!q.empty()) {
            int n = q.size();
            // 入队前计算一下当前层的宽度，如果放在最后计算，最后一层就是空了，数据溢出
            res = max(res, q.back().second - q.front().second + 1);
            for (int i = 0; i < n; ++i) {
                auto tmp = q.front();
                q.pop();
                // 左右节点下标并不是2i+1 2i+2，而是2i-1 2i
                if (tmp.first->left) q.push({tmp.first->left, tmp.second * 2 - 1});
                if (tmp.first->right) q.push({tmp.first->right, tmp.second * 2});
            }
        }
        return (int)res;
    }
};