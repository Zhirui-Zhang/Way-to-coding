法1：三指针法，和三数之和基本思路一样，但是不是三数之和为0了，而是改为target目标值，细节略有不同，同时为了避免重复，i j指针都需要判断是否发生重复
时间O(N^3) 空间O(1)
执行用时：56 ms, 在所有 C++ 提交中击败了74.61% 的用户
内存消耗：12.6 MB, 在所有 C++ 提交中击败了97.34% 的用户
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> res;
        int n = nums.size();
        sort(nums.begin(), nums.end());
        for (int i = 0; i < n - 3; ++i) {       // 注意这里因为不是三数之和为零的题目了，target为任意值，不能仅仅因为nums[i]>0就退出
            if (i > 0 && nums[i] == nums[i-1])    continue;   // 防止i指针发生重复
            for (int j = i + 1; j < n - 2; ++j) {
                if (j > i + 1 && nums[j] == nums[j-1])    continue;   // 防止j指针发生重复，注意条件为当j的下标超过i两个以上时再做判断，否则nums[i]和nums[j]相同的情况被忽略了
                int sum = nums[i] + nums[j];      // 存储当前的两数之和
                int left = j + 1, right = n - 1;
                while (left < right) {
                    if (nums[left] + nums[right] > target - sum) {    // 注意这里不要写 sum + nums[left] + nums[right] > target 因为测试用例计算前四个数的和会越界，要用减法
                        right--;
                    } else if (nums[left] + nums[right] < target - sum) {
                        left++;
                    } else {
                        res.push_back({nums[i], nums[j], nums[left], nums[right]});   // 当四数之和相等时的处理和三数之和相同，左右同时收缩指针并去重
                        left++;
                        right--;
                        while (left < right && nums[left] == nums[left-1])    left++; 
                        while (left < right && nums[right] == nums[right+1])    right--;
                    }
                }
            }    
        }
        return res;
    }
};
