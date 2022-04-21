法1：快排法，练习一下模板，针对本题可以更快一点
时间O(NlogN)  空间O(logN)
执行用时：280 ms, 在所有 C++ 提交中击败了5.09% 的用户
内存消耗：10 MB, 在所有 C++ 提交中击败了12.31% 的用户
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int n = nums.size();
        QuickSort(nums, 0, n-1);
        return nums[n-k];
    }
private:
    void QuickSort(vector<int>& nums, int left, int right)
    {
        if(left >= right)    return;
        int i = left, j = right;
        while(i < j)
        {
            while(i < j && nums[left] <= nums[j])    --j;
            while(i < j && nums[left] >= nums[i])    ++i;
            swap(nums[i], nums[j]);
        }
        swap(nums[i], nums[left]);
        QuickSort(nums, left, i-1);
        QuickSort(nums, i+1, right);        // 交换到此处时i = j 且保证左侧值都小于nums[i] 右侧值都大于nums[i]，所以不需要在参数中放入i 只用i+1 i-1即可
    }
};

改进版：每次判断返回的右边界情况，若小于index则排右半部分，若大于排左半部分，若等于返回nums[index]即可
时间O(N)  空间O(logN)
执行用时：64 ms, 在所有 C++ 提交中击败了18.17% 的用户
内存消耗：9.8 MB, 在所有 C++ 提交中击败了51.80% 的用户
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int n = nums.size();
        return QuickSelection(nums, 0, n-1, n-k);
    }
private:
    int QuickSelection(vector<int>& nums, int left, int right, int index)
    {
        if(left >= right)    return nums[index];
        int j = partition(nums, left, right);
        if(j == index)    return nums[index];
        else if(j < index)    return QuickSelection(nums, j+1, right, index);
        else    return QuickSelection(nums, left, j-1, index);
    }

    int partition(vector<int>& nums, int left, int right)       // 划分排序，和之前的快排代码部分相同
    {
        int i = left, j = right;
        while(i < j)
        {
            while(i < j && nums[left] <= nums[j])    --j;
            while(i < j && nums[left] >= nums[i])    ++i;
            swap(nums[i], nums[j]);
        }
        swap(nums[i], nums[left]);
        return j;                   // 其实这里return i 还是 j 都是一样的，因为到交换到此处时i = j 且保证左侧值都小于nums[i] 右侧值都大于nums[i]
    }
};

法3：优先队列，小顶堆法，和剑指的那道题还有点小不同，注意一下写法
时间O(NlogK)  空间O(K)
执行用时：4 ms, 在所有 C++ 提交中击败了96.41% 的用户
内存消耗：9.8 MB, 在所有 C++ 提交中击败了51.95% 的用户
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int n = nums.size();
        priority_queue<int, vector<int>, greater<int>> q;
        for(int i = 0; i < k; ++i)    q.push(nums[i]);
        for(int i = k; i < n; ++i)
        {
            if(nums[i] > q.top())
            {
                q.pop();
                q.push(nums[i]);
            }
        }
        return q.top();
    }
};
