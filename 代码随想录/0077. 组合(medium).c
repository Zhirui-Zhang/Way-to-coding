法1：回溯法，注意不能往回走，也不能重复，难度不大，找好边界条件即可
时间O(C ^k _n)即n个中取k个总组合数Cnk  空间O(N)
执行用时：20 ms, 在所有 C++ 提交中击败了59.41% 的用户
内存消耗：9.8 MB, 在所有 C++ 提交中击败了57.00% 的用户
class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        if (k > n) return res;
        dfs(0, k, 1, n);
        return res;
    }
private:
    vector<vector<int>> res;
    vector<int> tmp;
    void dfs(int pos, int k, int cur, int n) {
        if (pos == k) {
            res.push_back(tmp);
            return;
        }
        for (int i = cur; i <= n; ++i) {    // 避免回跳，从cur开始遍历
            tmp.push_back(i);
            dfs(pos + 1, k, i + 1, n);      // 避免重复，注意传入参数 i + 1
            tmp.pop_back();
        }
    }
};

优化：进行局部剪枝，同时减少传入的参数个数
class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        backtracking(n, k, 1);
        return result;
    }

private:
    vector<vector<int>> result;
    vector<int> path;
    void backtracking(int n, int k, int startIndex) {
        if (path.size() == k) {
            result.push_back(path);
            return;
        }
        for (int i = startIndex; i <= n - (k - path.size()) + 1; i++) { // 优化的地方，比如n = 4 k = 2 第一轮递归到3就可以了 没必要到4
            path.push_back(i); // 处理节点
            backtracking(n, k, i + 1);
            path.pop_back(); // 回溯，撤销处理的节点
        }
    }
};
