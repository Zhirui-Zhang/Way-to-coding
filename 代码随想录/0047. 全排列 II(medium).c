法1：回溯法，注意去重的方法，和0491题类似，只不过也可以用数组代替哈希表，提高插入效率
时间O(N!)全排列复杂度  空间O(N)递归深度
执行用时：4 ms, 在所有 C++ 提交中击败了92.02% 的用户
内存消耗：8.7 MB, 在所有 C++ 提交中击败了58.34% 的用户
class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        int n = nums.size();
        vector<bool> visited(n, false);     // 定义一个记录是否访问过的数组visited
        dfs(nums, visited);
        return res;
    }
private:
    vector<vector<int>> res;
    vector<int> temp;
    void dfs(vector<int>& nums, vector<bool>& visited) {
        if (temp.size() == nums.size()) {
            res.push_back(temp);
            return;
        }
        int used[21] = {0};         // 利用数组对每一层进行简单的去重操作，比用哈希表反复的insert效率更高
        for (int i = 0; i < nums.size(); ++i) {
            if (!visited[i] && used[nums[i]+10] != 1) {     // 如果当前元素还未访问过且该层中对应的元素值也不存在，则进入下一次递归
                used[nums[i]+10] = 1;                       // 给该层的对应元素赋值，表示已经有重复的了
                temp.push_back(nums[i]);
                visited[i] = true;
                dfs(nums, visited);
                temp.pop_back();
                visited[i] = false;
            }
        }
    }
};

其他回溯写法：用一个visited数组即可，前提是对nums数组进行排序
class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<bool> visited(n, false);
        dfs(nums, visited);
        return res;
    }
private:
    vector<vector<int>> res;
    vector<int> temp;
    void dfs(vector<int>& nums, vector<bool>& visited) {
        if (temp.size() == nums.size()) {
            res.push_back(temp);
            return;
        }
        for (int i = 0; i < nums.size(); ++i) {
            // 这里同样可以写成 visited[i-1]  一个是树枝去重，一个是树层去重  实际上树层去重效率更高，最好用!visited[i-1]写法
            // 可用[1 1 1]举例试验
            if (i > 0 && nums[i] == nums[i-1] && !visited[i-1]) continue;
            if (!visited[i]) {
                temp.push_back(nums[i]);
                visited[i] = true;
                dfs(nums, visited);
                temp.pop_back();
                visited[i] = false;
            }
        }
    }
};