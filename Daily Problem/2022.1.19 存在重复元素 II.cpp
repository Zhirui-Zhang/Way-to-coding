法1：哈希表存储+遍历即可
时间 O(N)  空间O(N)
执行用时：148 ms, 在所有 C++ 提交中击败了52.94% 的用户
内存消耗：75.3 MB, 在所有 C++ 提交中击败了40.39% 的用户
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, int> un_map;
        for(int i = 0; i < nums.size(); ++i)
        {
            if(un_map.find(nums[i]) != un_map.end())
            {
                if(i - un_map[nums[i]] <= k)    return true;
            }
            un_map[nums[i]] = i;
        }
        return false;
    }
};
