法1：二分查找，细节太多了，好好回顾，核心思想是找到第k小的元素，依次比较A[k/2-1]和B[k/2-1]的值，若A小，则最多有k-2个值小于它，更新k的值继续查找，直至有一个数组遍历结束或者k==1退出返回
例1：a[4]=[1 3 4 9] b[9]=[1 2 3 4 5 6 7 8 9]  例2：a[4]=[1 2 3 4]  b[4]=[5 6 7 8]
时间O(log(m+n))  空间O(1)
执行用时：28 ms, 在所有 C++ 提交中击败了67.07% 的用户
内存消耗：86.8 MB, 在所有 C++ 提交中击败了83.80% 的用户
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        // 归纳为求两个数组合并后第k小的数，其中k=(n1+n2+1)/2 长度和为奇数 ((n1+n2)/2+(n1+n2)/2+1)/2 长度和为偶数
        int total = nums1.size() + nums2.size();
        if(total % 2 == 1)    return getKthnumber(nums1, nums2, (total+1)/2);
        else    return (getKthnumber(nums1, nums2, total/2) + getKthnumber(nums1, nums2, total/2 + 1)) / 2.0;
    }
private:
    int getKthnumber(vector<int>& nums1, vector<int>& nums2, int k)  // 函数功能：寻找第k小的数字
    {
        int n1 = nums1.size(), n2 = nums2.size();
        int index1 = 0, index2 = 0;    // 定义数组1和数组2的当前下标值，初始为0
        while(true)
        {
            // 以下三种为边界退出情况
            // 如果数组1已遍历完仍未找到第k小的数，直接返回数组2中第k小的数，反之亦然
            if(index1 == n1)    return nums2[index2 + k - 1];
            if(index2 == n2)    return nums1[index1 + k - 1];
            // 若k=1，意为找两个数组中最小的值，返回两者当前下标对应的较小值即为最小的数
            if(k == 1)    return min(nums1[index1], nums2[index2]);
            // 更新数组1 2的新起点为新的k/2-1，注意新起点不能越界，若越界直接取数组末尾值
            int newIndex1 = min(index1 + k/2 - 1, n1 - 1), newIndex2 = min(index2 + k/2 - 1, n2 - 1);
            // 若n1较小，可以排除n1之前的数，更新k和index1的值，反之亦然
            if(nums1[newIndex1] <= nums2[newIndex2])    
            {
                k -= newIndex1 - index1 + 1;        // 通常情况下，这里可以直接 k -= k/2 的，但是有时newIndex1 = n1 - 1时不满足条件，所以保险起见，用newIndex1来代替
                index1 = newIndex1 + 1;
            }
            else
            {
                k -= newIndex2 - index2 + 1;
                index2 = newIndex2 + 1;
            }
        }
    }
};
