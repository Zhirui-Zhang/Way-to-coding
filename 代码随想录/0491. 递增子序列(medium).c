法1：回溯法，如何去重没太想明白，用的set，属于投机取巧做法，看题解优化
时间O(N*2^N)最坏复杂度为全子集个数  空间O(N)最大深度为N
执行用时：60 ms, 在所有 C++ 提交中击败了16.56% 的用户
内存消耗：21.8 MB, 在所有 C++ 提交中击败了68.30% 的用户
class Solution {
public:
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        dfs(nums, 0);
        return vector<vector<int>> (s.begin(), s.end());
    }
private:
    vector<int> tmp;
    set<vector<int>> s;     // 用于每次加入前去重
    void dfs(vector<int>& nums, int pos) {
        if (tmp.size() >= 2) {      // 当tmp长度大于等于2时才加入
            s.insert(tmp);
        }
        for (; pos < nums.size(); ++pos) {
            if (tmp.empty() || nums[pos] >= tmp.back()) {   // 当tmp为空或nums[i] >= 尾端元素时加入并回溯
                tmp.push_back(nums[pos]);
                dfs(nums, pos + 1);
                tmp.pop_back();
            }            
        }
    }
};


优化：使用哈希表来判断本层节点是否已经添加过了，未添加过再考虑是否满足递增条件进行添加并递归到下一层
当然用数组的话效率会更高，定义一个 int visited[201] = {0}  每次判断 visited[nums[pos]+100] != 1 即可
举例 [4 7 6 7]  当第一个7加入后，unset[7]已存在，不能再考虑加入第二个7了
执行用时：48 ms, 在所有 C++ 提交中击败了44.84% 的用户
内存消耗：24.9 MB, 在所有 C++ 提交中击败了28.43% 的用户
class Solution {
public:
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        dfs(nums, 0);
        return res;
    }
private:
    vector<vector<int>> res;
    vector<int> tmp;
    void dfs(vector<int>& nums, int pos) {
        if (tmp.size() >= 2) {
            res.push_back(tmp);
        }
        unordered_set<int> unset;               // 定义一个仅用于本层的去重集合
        for (; pos < nums.size(); ++pos) {
            if (unset.find(nums[pos]) == unset.end() && (tmp.empty() || nums[pos] >= tmp.back())) {
                // 这里的判断逻辑有点绕，总之是当tmp为空或者尾端元素小于等于当前元素时，大前提还需要满足节点值不在本层中
                unset.insert(nums[pos]);        // 当本层尚未加入该nums[pos]值时，加入去重集合，并进入下一层递归
                tmp.push_back(nums[pos]);
                dfs(nums, pos + 1);
                tmp.pop_back();
            }            
        }
    }
};