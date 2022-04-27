法1：BFS法，比递归简单多了，每次入队出队前统计一下队首元素的值即可，就是最左侧的节点值
时间O(N) 空间O(N)
执行用时：8 ms, 在所有 C++ 提交中击败了80.81% 的用户
内存消耗：21.3 MB, 在所有 C++ 提交中击败了32.83% 的用户
class Solution {
public:
    int findBottomLeftValue(TreeNode* root) {
        int res = root->val;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            int size = q.size();
            res = q.front()->val;
            while (size--) {
                TreeNode* tmp = q.front();
                q.pop();
                if (tmp->left) q.push(tmp->left);
                if (tmp->right) q.push(tmp->right);
            }  
        }
        return res;
    }
};

法2：DFS法，随想录的答案，还得利用回溯，有点不太好想，记录一下吧
class Solution {
public:
    int maxLen = INT_MIN;       // 记录当前的最大高度
    int maxleftValue;           // 记录当前的最左子树值
    void traversal(TreeNode* root, int leftLen) {
        if (root->left == NULL && root->right == NULL) {
            if (leftLen > maxLen) {     // 递归到叶子节点时，讨论是否更新最大高度和最左子树值
                maxLen = leftLen;
                maxleftValue = root->val;
            }
            return;
        }
        if (root->left) {
            traversal(root->left, leftLen + 1); // 隐藏着回溯
        }
        if (root->right) {
            traversal(root->right, leftLen + 1); // 隐藏着回溯
        }
        return;
    }
    int findBottomLeftValue(TreeNode* root) {
        traversal(root, 0);
        return maxleftValue;
    }
};
