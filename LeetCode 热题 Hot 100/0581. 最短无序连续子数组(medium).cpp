法1：双指针法，被忽悠想了一下午的单调栈，结果还是双指针好用，一个从左往右记录右边界的逆序位置，一个从右往左记录左边界的逆序位置，相减即可，例题见笔记
时间O(N)  空间O(1）
执行用时：16 ms, 在所有 C++ 提交中击败了97.75% 的用户
内存消耗：25.7 MB, 在所有 C++ 提交中击败了98.09% 的用户
class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int n = nums.size();
        int cur_max = INT_MIN, cur_min = INT_MAX;       // 注意初始化写法，当前最大值和最小值分别初始化为MIN和MAX
        int left = -1, right = - 1;                    // 设置左右指针，依次从左遍历和从右遍历，分别更新右指针和左指针
        for(int i = 0; i < n; ++i){
            if(nums[i] < cur_max){                      // 注意如果判断条件为小于相等的话，不能实现完全递增，如[1 2 3 3 3]输出3实际应为0
                right = i;
            }
            else{
                cur_max = nums[i];                       // 从左遍历时找最大值，若当前值为逆序则调整右指针，否则更新cur_max
            }
        }
        for(int i = n - 1; i >= 0; --i){
            if(nums[i] > cur_min){
                left = i;                                 // 从右遍历时找最小值，若当前值为逆序则调整左指针，否则更新cur_min
            }
            else{
                cur_min = nums[i];
            }
        } 
        return left == -1 ? 0 : right - left + 1;       // 注意最后特殊情况的判断，如果数组本身就是有序的，则left right两个指针的值都不会改变，判断一下即可
    }
};

法2：排序法，复制一个原数组，排个序后逐位判断哪个不一样，相减即可
时间O(NlogN)  空间O(N）
执行用时：36 ms, 在所有 C++ 提交中击败了18.66% 的用户
内存消耗：26.7 MB, 在所有 C++ 提交中击败了18.34% 的用户
class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int n = nums.size();
        vector<int> temp(nums);
        sort(temp.begin(), temp.end());
        int left = 0;
        while (left < n && nums[left] == temp[left]) {
            left++;
        }
        int right = nums.size() - 1;
        while (right >= 0 && nums[right] == temp[right]) {
            right--;
        }
        return left == n ? 0 : right - left + 1;
    }
};
