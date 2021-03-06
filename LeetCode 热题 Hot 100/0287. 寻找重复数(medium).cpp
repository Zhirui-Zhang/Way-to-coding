法1：二分法，按照题目要求，以空间换时间，依据抽屉原理，10个球放9个抽屉，必有一个抽屉有两个以上的球
时间O(NlogN)  空间O(1)
执行用时：124 ms, 在所有 C++ 提交中击败了26.46% 的用户
内存消耗：59.7 MB, 在所有 C++ 提交中击败了70.27% 的用户
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int left = 1, right = nums.size() - 1;    // 左右指针分别为1和N，代表数组[1, N]的范围
        while(left < right)                       // 注意边界条件  不是 <=
        {
            int mid = (left + right) >> 1;        // 取中间数
            int cnt = 0;  
            for(auto num : nums)                  // 遍历数组，查找中间数左边元素的数量
            {
                if(num <= mid)    cnt++;
            }
            if(cnt > mid)    right = mid;         // 若cnt大于mid说明在左半边，否则在右半边
            else    left = mid + 1;
        }
        return left;
    }
};

法2：快慢指针法，类似于之前的环形链表，以数组的值作为下一次的下标，先让两个指针走，相遇时让slow退回到0，再一起走直到相遇时退出
执行用时：72 ms, 在所有 C++ 提交中击败了97.35% 的用户
内存消耗：59.8 MB, 在所有 C++ 提交中击败了57.34% 的用户
时间O(N)  空间O(1)
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow = nums[0], fast = nums[nums[0]];
        while(slow != fast)
        {
            fast = nums[nums[fast]];
            slow = nums[slow];
        }
        slow = 0;
        while(slow != fast)
        {
            slow = nums[slow];
            fast = nums[fast];
        }
        return slow;
    }
};
