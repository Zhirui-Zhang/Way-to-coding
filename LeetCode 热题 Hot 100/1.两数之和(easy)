法1：暴力法略，两种解法，一是哈希表，记录每次 target-nums[i] 是否存在，存在输出，不存在记录当前un_map[nums[i]]=i
时间O(N)  空间O(N)
执行用时：8 ms, 在所有 C++ 提交中击败了92.56% 的用户
内存消耗：10.4 MB, 在所有 C++ 提交中击败了47.89% 的用户
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> un_map;
        for(int i = 0; i < nums.size(); ++i)
        {
            auto iter = un_map.find(target - nums[i]);
            if(iter != un_map.end())    return {i, iter->second};
            else un_map[nums[i]] = i;
        }
        return {};
    }   
};

法2：快速排序法后遍历一遍即可
时间O(NlogN)  空间O(N)res数组占据N
执行用时：272 ms, 在所有 C++ 提交中击败了37.18% 的用户
内存消耗：10.2 MB, 在所有 C++ 提交中击败了53.34% 的用户
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int> res(nums);
        QuickSort(res, 0, n-1);
        int left = 0, right = n-1, num1 = 0, num2 = 0;
        while(left <= right)
        {
            if(res[left] + res[right] > target)
            {
                --right;
            }
            else if(res[left] + res[right] < target)
            {
                ++left;
            }
            else
            {
                num1 = res[left];
                num2 = res[right];
                break;
            }
        }
    vector<int> temp;
    for(int i = 0; i < n; ++i)
    {
        if(nums[i] == num1 || nums[i] == num2)    temp.push_back(i);
    }
        return temp;
    }

private:
    void QuickSort(vector<int>& res, int left, int right)
    {
        if(left >= right)    return;
        int i = left, j = right;
        while(i < j)
        {
            while(i < j && res[left] <= res[j])    --j;
            while(i < j && res[left] >= res[i])    ++i;
            swap(res[i], res[j]);
        }
        swap(res[left], res[i]);
        QuickSort(res, left, i-1);
        QuickSort(res, i+1, right);
    }
};
