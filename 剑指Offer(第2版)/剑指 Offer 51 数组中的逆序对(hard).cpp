法1：归并排序法，重要模板，好好总结并且背下来，题目就多了一行判断，当左半数组的值大于右半数组时，意味着左半数组之前的所有数据都大于该元素，因此res+=mid-i+1，其余完全一样，注意细节！！！
时间O(NlogN)归并排序复杂度  空间O(N)创建辅助数组temp占用N空间
执行用时：160 ms, 在所有 C++ 提交中击败了64.83% 的用户
内存消耗：43.4 MB, 在所有 C++ 提交中击败了52.59% 的用
class Solution {
public:
    int reversePairs(vector<int>& nums) {
        int n = nums.size();
        vector<int> temp(n);                // 初始化辅助数组temp，含有n个元素，用来临时存放排序后的nums数组
        MergeSort(nums, temp, 0, n - 1);
        return res;
    }
    
    // 关键部分，实现归并排序的函数，很多都是拆成了两个函数，即一个用于递归一个用于合并，其实一个函数也能写，而且好记一点，注意两个数组都要用引用
    void MergeSort(vector<int>& nums, vector<int>& temp, int left, int right)
    {
        if(left >= right)    return;                                  // 递归退出条件，左边界大于等于右边界，也就是递归至只有一个元素时，没必要排序，直接返回即可
        int mid = (left + right) / 2;
        MergeSort(nums, temp, left, mid);                             // 分别递归左半数组和右半数组，注意边界的写法
        MergeSort(nums, temp, mid + 1, right);
        
        // 接下来是结束递归，开始进入排序合并函数，先记录左右半边数组的起始位置，并记录整个数组长度，以便于最后进行排序后的元素复制
        int i = left, j = mid + 1, length = right - left + 1;         
        while(i <= mid && j <= right)
        {
            if(nums[i] <= nums[j])    temp[left++] = nums[i++];       // 右元素大时，复制左边的
            else
            {
                res += mid - i + 1;                                   // 左元素大时，复制右边的，同时注意更新res的值，以满足题目需要
                temp[left++] = nums[j++];                             // 例：2 3 6 7 与 0 1 4 5 当2 > 0时，意味左数组四个元素均大于0
            }
        }
        while(i <= mid)                                               // 若左边有剩余，复制左边的
        {   
            temp[left++] = nums[i++];
        }
        while(j <= right)                                             // 若右边有剩余，复制右边的
        {
            temp[left++] = nums[j++];
        }
        for(int k = 0; k < length; k++, right--)                    // 最后一定记得更新原nums数组，否则返回上一层递归时未排序，仍为原序列
        {                                                             // 注意这里排序的边界条件，由于此时left i j均发生变化，无法继续使用，改用right倒序复制元素
            nums[right] = temp[right];
        }
    }

private:
    int res = 0;
};
