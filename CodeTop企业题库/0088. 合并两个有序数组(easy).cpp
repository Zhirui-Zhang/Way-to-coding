法1：三指针法，从后向前遍历即可，注意最后nums2剩余时需要全部挪过去
时间O(M+N)  空间O(1)
执行用时：0 ms, 在所有 C++ 提交中击败了100.00% 的用户
内存消耗：8.7 MB, 在所有 C++ 提交中击败了83.80% 的用户
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = m - 1, j = n - 1, k = m + n - 1;
        while (i >= 0 && j >= 0) {
            if (nums2[j] > nums1[i]) nums1[k--] = nums2[j--];
            else nums1[k--] = nums1[i--];
        }
        while (j >= 0) nums1[k--] = nums2[j--];
    }
};