法1：双指针法，遍历贼简单
执行用时：156 ms, 在所有 C++ 提交中击败了81.50% 的用户
内存消耗：98.1 MB, 在所有 C++ 提交中击败了88.72% 的用户
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;
        vector<int> res;
        while(left < right)
        {
            if(nums[left] + nums[right] < target)    left++;
            else if(nums[left] + nums[right] > target)    right--;    
            else
            {
                res.push_back(nums[left]);
                res.push_back(nums[right]);
                break;
            }
        }
        return res;
    }
};

法2：二分法
