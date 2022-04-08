法1：二叉树模拟法，做过的题，比二分法简单
时间O(M+N)  空间O(1)
执行用时：92 ms, 在所有 C++ 提交中击败了76.16% 的用户
内存消耗：14.4 MB, 在所有 C++ 提交中击败了69.01% 的用户
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(), n = matrix[0].size();
        int i = m - 1, j = 0;
        while(i >= 0 && j < n)
        {
            if(matrix[i][j] == target)    return true;
            else if(matrix[i][j] < target)    j++;
            else    i--;
        }
        return false;
    }
};

法2：二分法，考虑一下两种特殊情况即可
时间O(MlogN)  空间O(1)
public boolean searchMatrix(int[][] matrix, int target) {
    if (matrix.length == 0 || matrix[0].length == 0) {
        return false;
    }
    for (int i = 0; i < matrix.length; i++) {
        if (matrix[i][0] > target) {        // 如果第一元素都大于target，那么一定不存在，返回false即可
            break;
        }
        if(matrix[i][matrix[i].length - 1] < target){
            continue;                       // 如果最后一个元素都小于target，直接下一行
        } 
        int col = binarySearch(matrix[i], target);
        if (col != -1) {                    // 否则二分查找
            return true;
        }
    }
    return false;
}

//二分查找
private int binarySearch(int[] nums, int target) {
    int start = 0;
    int end = nums.length - 1;
    while (start <= end) {
        int mid = (start + end) >>> 1;
        if (nums[mid] == target) {
            return mid;
        } else if (nums[mid] < target) {
            start = mid + 1;
        } else {
            end = mid - 1;
        }
    }
    return -1;
}
