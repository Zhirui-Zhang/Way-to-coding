法1：DFS，为了满足空间复杂度要求，只能用DFS，就是判断条件那里出了点错误，导致提交失败，擦
时间O(N)  空间O(1)  题目要求的O(1)
执行用时：12 ms, 在所有 C++ 提交中击败了91.99% 的用户
内存消耗：23.4 MB, 在所有 C++ 提交中击败了67.97% 的用户
class Solution {
public:
    vector<int> findMode(TreeNode* root) {
        tmp = root;
        maxCnt = 1;
        curCnt = 0;
        dfs(root);
        return res;
    }
private:
    vector<int> res;
    TreeNode* tmp;      // 用来记录上一个节点
    int maxCnt;
    int curCnt;
    void dfs(TreeNode* root) {
        if (!root) return;
        dfs(root->left);
        if (tmp->val != root->val) curCnt = 1;
        else curCnt++;
        if (curCnt == maxCnt) res.push_back(root->val);     // 注意先判断节点是否值相等，更新计数curCnt，再判断是否需要加入res数组，这是导致第一次提交失败的原因
        if (curCnt > maxCnt) {
            maxCnt = curCnt;
            res.clear();
            res.push_back(root->val);
        }
        tmp = root;    // ！！！这句话非常重要，更新当前的tmp节点，使其在遍历右节点时就已经更新为根节点
        dfs(root->right);
    }
};