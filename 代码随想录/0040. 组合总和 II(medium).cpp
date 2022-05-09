法1：回溯法，注意和I不同的地方在于需要去重，所以dfs前先排序，使相同的元素相邻，然后递归前判断是否已经使用过
时间O(N!)每个元素最多用一次，最大为全排列  空间O(N)最大递归深度为candidates数组长度，因为每个元素最多用一次
执行用时：8 ms, 在所有 C++ 提交中击败了50.75% 的用户
内存消耗：10.3 MB, 在所有 C++ 提交中击败了83.15% 的用户
class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        dfs(candidates, 0, target);
        return res;
    }
private:
    vector<vector<int>> res;
    vector<int> tmp;
    void dfs(vector<int>& candidates, int pos, int target) {
        if (target == 0) {          // 不需要再判断target < 0了
            res.push_back(tmp); 
            return;
        }
        for (int i = pos; i < candidates.size() && target - candidates[i] >= 0; i++) {  
            // 由于数组有序，可以进行剪枝优化，当target - candidates[i] < 0时直接退出
            if (i > pos && candidates[i] == candidates[i-1]) continue;      
            // 这里很重要，去重的关键操作， i > pos保证不在同一层中可以重复，同一层中不可重复，直接continue
            tmp.push_back(candidates[i]);
            dfs(candidates, i + 1, target - candidates[i]);
            tmp.pop_back();
        }
    }
};