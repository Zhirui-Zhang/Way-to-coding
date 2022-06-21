法1：双向遍历，建立两个数组left和right，分别从左向右和从右向左记录当前一侧的最小/最大值，随后从下标[1,n-1]遍历，依次比较nums[i]与左右的大小关系，原理为：
在 nums[i] 的左边存在一个元素小于 nums[i] 等价于在 nums[i] 的左边的最小元素小于 nums[i]
在 nums[i] 的右边存在一个元素大于 nums[i] 等价于在 nums[i] 的右边的最大元素大于 nums[i]
时间O(N)  空间O(N)
执行用时：64 ms, 在所有 C++ 提交中击败了24.16% 的用户
内存消耗：64.8 MB, 在所有 C++ 提交中击败了5.03% 的用户
class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int n = nums.size();
        if(n < 3)    return false;
        vector<int> left(n);
        vector<int> right(n);
        left[0] = nums[0];
        right[n-1] = nums[n-1];
        for(int i = 1; i < n; i++)
        {
            left[i] = min(left[i-1], nums[i]);
        }
        for(int i = n-2; i >= 0; i--)
        {
            right[i] = max(right[i+1], nums[i]);
        }
        for(int i = 1; i < n - 1; i++)
        {
            if(left[i] < nums[i] && nums[i] < right[i])    return true;
        }
        return false;
    }
};

法2：贪心算法，(first,second,num)是一个递增的三元子序列，始终维护first<second，并保证first和second都尽可能的小
遍历数组中的元素记为num，若大于second返回true，若大于first小于second更新second，否则小于first更新first
具体解释：若为[3 5 1 7 3]first=3 second=5 num=1时替换first，隐含表示有一个比1大比5小的数在5之前，故遍历到7时可以直接输出true
时间O(N)  空间O(1)
执行用时：52 ms, 在所有 C++ 提交中击败了71.71% 的用户
内存消耗：60.2 MB, 在所有 C++ 提交中击败了8.89% 的用户
class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int n = nums.size();
        if(n < 3)    return false;
        int first = nums[0], second = INT_MAX;
        for(int i = 1; i < n; ++i)
        {
            if(nums[i] > second)    return true;
            if(nums[i] > first)    second = nums[i];
            else first = nums[i];
        }
        return false;
    }
};
