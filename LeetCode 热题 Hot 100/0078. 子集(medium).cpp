法1：回溯+剪枝法，很简单
时间O(2^N)  空间O(N)temp空间和递归深度均为N
执行用时：0 ms, 在所有 C++ 提交中击败了100.00% 的用户
内存消耗：6.8 MB, 在所有 C++ 提交中击败了95.77% 的用户
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        dfs(nums, 0);
        return res;
    }
private:
    vector<vector<int>> res;
    vector<int> temp;
    void dfs(vector<int>& nums, int pos)
    {
        res.push_back(temp);                 // 退出前先加入子集，可以获得一个空集
        if (pos == nums.size())    return;   // 退出条件，当前遍历位置超过数组长度，其实可以省略，因为在下面的for循环中就已经规定了右边界
        for (; pos < nums.size(); pos++) {
            temp.push_back(nums[pos]);       // 压入一个后立即保存该子集，每次递归结束返回后记得弹出最后一个元素
            dfs(nums, pos + 1);
            temp.pop_back();
        }          
    }
};
