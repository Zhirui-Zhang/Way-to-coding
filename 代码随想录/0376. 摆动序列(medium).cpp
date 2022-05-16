法1：贪心法，其实就是模拟，比较与上一次差的符号是否相同，注意需要考虑差为0的情况
时间O(N)  空间O(1)
执行用时：0 ms, 在所有 C++ 提交中击败了100.00% 的用户
内存消耗：6.9 MB, 在所有 C++ 提交中击败了54.14% 的用户
class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int res = 1, tmp = nums[0], index = 0;
        bool status = true;
        for (int i = 1; i < nums.size(); ++i) {     // 目的是找到第一个不为0的差值，给status赋初值，让res=2并记录当前下标和元素值
            int dif = nums[i] - tmp;
            if (dif == 0) continue;
            else {
                status = (dif > 0) ? true : false;
                ++res;
                index = i;
                tmp = nums[i];
                break;
            }
        }
        for (int i = index + 1; i < nums.size(); ++i) {
            int dif = nums[i] - tmp;
            if ((dif > 0 && !status) || (dif < 0 && status)) {      // 注意这里的简化判断写法，只要与上一次符号不同就对status取反并++res
                status = !status;
                ++res;
            }
            tmp = nums[i];                      // 同时令tmp = nums[i]即可，隐藏条件若同号也可直接取max(dif>0) min(dif<0)
        }

        return res;
    }
};

优化：其实不需要tmp变量记录前一个值，也不需要status记录正负，只需要记录上一次的差值比较即可，为零的情况也可以归纳入preDiff >= 0中
class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        if (nums.size() <= 1) return nums.size();
        int curDiff = 0; // 当前一对差值
        int preDiff = 0; // 前一对差值
        int result = 1;  // 记录峰值个数，序列默认序列最右边有一个峰值
        for (int i = 0; i < nums.size() - 1; i++) {
            curDiff = nums[i + 1] - nums[i];        // 注意这里的减法，让nums[i + 1] - nums[i]
            // 出现峰值，隐含去掉当前差值为0的情况了
            if ((curDiff > 0 && preDiff <= 0) || (preDiff >= 0 && curDiff < 0)) {
                result++;
                preDiff = curDiff;
            }
        }
        return result;
    }
};
