法1：dfs回溯，比较简单，注意保存当前数组并弹出，且添加一个判断是否访问过的visited数组
时间O(N*N!)因为全排列总数就为N!个  空间O(N)
执行用时：4 ms, 在所有 C++ 提交中击败了62.96% 的用户
内存消耗：7.5 MB, 在所有 C++ 提交中击败了65.94% 的用户
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        int n = nums.size();
        vector<bool> visited(n, false);
        dfs(nums, visited);
        return res;
    }
private:
    vector<vector<int>> res;
    vector<int> temp;
    void dfs(vector<int>& nums, vector<bool>& visited)
    {
        if(temp.size() == nums.size())
        {
            res.push_back(temp);
            return;
        }
        for(int i = 0; i < nums.size(); ++i)
        {
            if(!visited[i])     // 当前节点未访问过时进入回溯
            {
                temp.push_back(nums[i]);
                visited[i] = true;
                dfs(nums, visited);
                temp.pop_back();
                visited[i] = false;
            }
        }
    }
};
