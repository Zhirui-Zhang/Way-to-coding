法1：双指针法，很奇怪的一道题，倒是不难，但是要注意它返回的是数组而不是新长度，意思是一定要把前n个数组修改好了才行，采用快慢指针法
时间O(N)  空间O(1)
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int pre = 0;
        for (int cur = 0; cur < nums.size(); ++cur) {
            if (nums[cur] != val) {
                nums[pre++] = nums[cur];        // 遇到目标值后慢指针就不动了，直到快指针不为目标值时给慢指针赋值，例题中最后结果为[0 1 3 0 4 0 4 2] pre=5
            }
        }
        return pre;
    }
};
