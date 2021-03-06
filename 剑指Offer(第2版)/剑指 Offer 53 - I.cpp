法1：暴力法
执行用时: 8 ms
内存消耗: 13 MB
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int num = 0;
        for(int i = 0; i < nums.size(); i++)
        {
            if(nums[i] == target)   num++;
        }
        return num;
    }
};

法2：二分法
执行用时：8 ms, 在所有 C++ 提交中击败了65.40% 的用户
内存消耗：12.9 MB, 在所有 C++ 提交中击败了53.59% 的用户
class Solution {
public:
    int search(vector<int>& nums, int target) {
    int left = 0, right = nums.size() - 1;
    //寻找左边界
    int lIndex = -1;
    while(left <= right)
    {
        int mid = (left + right) / 2;
        if(nums[mid] >= target)
        {
            right = mid - 1;
            lIndex = mid;
        }
        else
        {
            left = mid + 1;
        }
    }

    if(lIndex == -1)    return 0;   //第一次没找到即可退出

    //寻找右边界
    left = 0, right = nums.size() - 1;
    int rIndex = nums.size();
    while(left <= right)
    {
        int mid = (left + right) / 2;
        if(nums[mid] <= target)
        {
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
            rIndex = mid;
        }
    }
    return rIndex - lIndex;
    }
};

法3：STL模板调用
执行用时：8 ms, 在所有 C++ 提交中击败了65.40% 的用户
内存消耗：12.8 MB, 在所有 C++ 提交中击败了88.06% 的用户
class Solution {
public:
    int search(vector<int>& nums, int target) {
        return upper_bound(nums.begin(), nums.end(), target) - lower_bound(nums.begin(), nums.end(), target);
    }
};
