法1：贪心法，比跳跃Ⅰ难，重点是要记录当前跳跃覆盖范围和下一步跳跃覆盖范围，并当达到当前最大时判断是否可以跳出
时间O(N)  空间O(1)
执行用时：16 ms, 在所有 C++ 提交中击败了45.52% 的用户
内存消耗：16.1 MB, 在所有 C++ 提交中击败了88.00% 的用户
class Solution {
public:
    int jump(vector<int>& nums) {
        if (nums.size() == 1) return 0;     // 当数组只有一个元素时不需要跳，返回0，可省略
        int res = 0, curDistance = 0, nextDistance = 0, n = nums.size();        // 记录当前可走的最大范围以及下一步的最大范围
        for (int i = 0; i < n; ++i) {
            nextDistance = max(nextDistance, nums[i] + i);
            if (i == curDistance) {         // 当达到当前最大时，判断1.已经能跳出返回res 2.下一步能跳出返回res+1
                if (curDistance >= n - 1) break;
                else {
                    curDistance = nextDistance;
                    ++res;
                    if (nextDistance >= n - 1) break;
                }
            }
        }
        return res;
    }
};

优化：只需要查看是否能到达n-1的位置即可，因为下一步一定能到达
class Solution {
public:
    int jump(vector<int>& nums) {
        int curDistance = 0;    // 当前覆盖的最远距离下标
        int ans = 0;            // 记录走的最大步数
        int nextDistance = 0;   // 下一步覆盖的最远距离下标
        for (int i = 0; i < nums.size() - 1; i++) { // 注意这里是小于nums.size() - 1，这是关键所在
            nextDistance = max(nums[i] + i, nextDistance); // 更新下一步覆盖的最远距离下标
            if (i == curDistance) {                 // 遇到当前覆盖的最远距离下标
                curDistance = nextDistance;         // 更新当前覆盖的最远距离下标
                ans++;
            }
        }
        return ans;
    }
};