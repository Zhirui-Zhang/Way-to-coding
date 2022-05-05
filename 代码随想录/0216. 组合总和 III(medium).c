法1：回溯法，可以剪枝，注意细节和边界条件即可
时间O(9!)最坏情况为N的全排列，但一般不会达到  空间O(k)递归深度
执行用时：0 ms, 在所有 C++ 提交中击败了100.00% 的用户
内存消耗：6.3 MB, 在所有 C++ 提交中击败了40.49% 的用户
class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        dfs(k, n, 1);
        return res;
    }
private:
    vector<vector<int>> res;
    vector<int> tmp;
    void dfs(int k, int n, int cur) {
        if (tmp.size() == k) {
            if (n == 0) res.push_back(tmp);
            return;
        }
        for (int i = cur; i <= 9; ++i) {
            tmp.push_back(i);
            dfs(k, n - i, i + 1);
            tmp.pop_back();
        }
    }
};