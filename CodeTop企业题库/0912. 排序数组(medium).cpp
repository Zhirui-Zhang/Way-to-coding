尝试默写三种排序算法，得经常回顾，要不细节很容易遗忘
1.快排法，超时
时间O(NlogN)  空间O(logN)
class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        int n = nums.size();
        quickSort(nums, 0, n - 1);
        return nums;
    }

private:
    void quickSort(vector<int>& nums, int left, int right) {
        if (left >= right) return;
        int i = left, j = right;
        while (i < j) {
            while (i < j && nums[left] <= nums[j]) --j;
            while (i < j && nums[left] >= nums[i]) ++i;
            swap(nums[i], nums[j]);
        }
        swap(nums[left], nums[i]);
        quickSort(nums, left, i - 1);
        quickSort(nums, i + 1, right);
    }
};

1.5随机化快速排序，每次随机选取一个点pivot和nums[left]交换，可以避免超时
时间O(NlogN)  空间O(logN)
class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        int n = nums.size();
        quickSort(nums, 0, n - 1);
        return nums;
    }

private:
    void quickSort(vector<int>& nums, int left, int right) {
        if (left >= right) return;        
        int pivot = rand() % (right - left + 1) + left;     // 选取[left, right]区间中的任意一点下标pivot
        swap(nums[left], nums[pivot]);                      // 交换nums[pivot]和nums[left]
        int i = left, j = right;
        while (i < j) {
            while (i < j && nums[left] <= nums[j]) --j;
            while (i < j && nums[left] >= nums[i]) ++i;
            swap(nums[i], nums[j]);
        }
        swap(nums[left], nums[i]);
        quickSort(nums, left, i - 1);
        quickSort(nums, i + 1, right);
    }
};

2.归并排序法
时间O(NlogN)  空间O(N)
class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> tmp(n, 0);
        mergeSort(nums, tmp, 0, n - 1);
        return nums;
    }

private:    
    void mergeSort(vector<int>& nums, vector<int>& tmp, int left, int right) {
        if (left >= right) return;
        int mid = (left + right) / 2;
        mergeSort(nums, tmp, left, mid);
        mergeSort(nums, tmp, mid + 1, right);
        int i = left, j = mid + 1, len = right - left + 1;
        while (i <= mid && j <= right) {
            if (nums[i] < nums[j]) tmp[left++] = nums[i++];
            else tmp[left++] = nums[j++];
        }
        while (i <= mid) tmp[left++] = nums[i++];
        while (j <= right) tmp[left++] = nums[j++];
        for (int k = 0; k < len; ++k, --right) {        // 这里很关键，把已经排好序的tmp数组再拷贝回nums数组中，倒序拷贝
            nums[right] = tmp[right];
        }
    }
};

3.堆排序法
时间O(NlogN)  空间O(1)
class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        buildHeap(nums);    // 先建成大顶堆，再排序调整为升序
        return nums;
    }

private:
    void buildHeap(vector<int>& nums) {
        int n = nums.size();
        for (int i = (n - 2) / 2; i >= 0; --i) {
            adjustHeap(nums, i, n);     // 从第一个非叶子节点向前依次下沉置换
        }
        for (int i = n - 1; i > 0; --i) {
            swap(nums[0], nums[i]);     
            // 由于根节点是当前最大值，最后一个节点是当前最小值，每次交换根节点和最后一个节点，然后舍弃最后一个节点，重新进行堆排序
            adjustHeap(nums, 0, i);
        }
    }

    void adjustHeap(vector<int>& nums, int index, int n) {
        int child_index = 2 * index + 1;
        int parent = nums[index];
        while (child_index < n) {
            // 判断是否存在右子节点且右子节点大于左子节点时，令下标变为右子节点
            if (child_index + 1 < n && nums[child_index + 1] > nums[child_index]) child_index++;
            if (parent >= nums[child_index]) break;     // parent已经是三个节点中的最大值，退出
            nums[index] = nums[child_index];            // 否则交换较大子节点值，并更新父子节点索引，进入下一轮
            index = child_index;
            child_index = 2 * child_index + 1;
        }
        nums[index] = parent;   // 最后交换最初的parent值
    }
};