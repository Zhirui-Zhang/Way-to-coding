法1：回溯法，注意需要去重，去重方法和组合那道题一样，套路记住即可
时间O(2^N)  空间O(N)递归深度为数组长度N
执行用时：4 ms, 在所有 C++ 提交中击败了54.53% 的用户
内存消耗：7.5 MB, 在所有 C++ 提交中击败了61.50% 的用户
class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        dfs(nums, 0);
        return res;
    }
private:
    vector<vector<int>> res;
    vector<int> tmp;
    void dfs(vector<int>& nums, int pos) {
        res.push_back(tmp);
        for (int i = pos; i < nums.size(); ++i) {
            if (i > pos && nums[i] == nums[i-1]) continue;      // 注意去重判断，i > pos
            tmp.push_back(nums[i]);
            dfs(nums, i + 1);
            tmp.pop_back();
        }
    }
};