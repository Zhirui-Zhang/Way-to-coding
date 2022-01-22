法1：排序+双指针，刚开始想的哈希表用来判断是否已经重复太麻烦了，而且空间复杂度也较高
利用已排序好的数组特性，若nums[i]==nums[i-1]直接继续continue i++即可，在插入三元数组后也是一样，左右指针都不能和之前的值重复
时间O(N^2)  空间O(logN)为sort排序的递归深度
执行用时：68 ms, 在所有 C++ 提交中击败了83.34% 的用户
内存消耗：19.6 MB, 在所有 C++ 提交中击败了35.86% 的用户
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        // if(n < 3)    return {};    // 特殊情况，可省略
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        for(int i = 0; i < n - 2 && nums[i] <= 0; ++i)    // 注意小细节，这里的第一个数字必须不大于0，否则不可能三数之和为0
        {
            if(i > 0 && nums[i] == nums[i-1])    continue;    // 如果当前的第一个数值和上一次相等，continue以免重复
            int left = i + 1, right = n - 1;                  // 左右双指针法
            while(left < right)
            {
                if(nums[left] + nums[right] > -nums[i])    right--;   // 若和大于-nums[i] 右指针左移，否则相反
                else if(nums[left] + nums[right] < -nums[i])    left++;
                else
                {
                    res.push_back(vector<int> {nums[i], nums[left], nums[right]});    // 注意这里的新建vector写法，同时插入后左右指针都要继续移动
                    left++;
                    right--;
                    while(left < right && nums[left] == nums[left-1])    left++;      // 移动后判断是否和上一次的值相等，若相等继续移动，避免重复
                    while(left < right && nums[right] == nums[right+1])    right--;
                }
            }
        }
        return res;
    }
};
