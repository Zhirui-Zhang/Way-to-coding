法1：哈希表+桶排序，见笔记，数学思想比较多，核心在于统计出现次数最多任务的个数以及数量值，计算nums1并与num2比较返回较大值
时间O(N+26)  空间O(26)
执行用时：52 ms, 在所有 C++ 提交中击败了77.16% 的用户
内存消耗：33.6 MB, 在所有 C++ 提交中击败了74.79% 的用户
class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char, int> hash;
        for (auto task : tasks){
            hash[task]++;
        }
        int maxN = 0, cntN = 0;        // maxN记录整个数组出现次数最多的值，cntN表示有多少个出现次数最多的个数
        for (auto [k, v] : hash){
            if (v >= maxN){            // 若等于最大值cntN++，大于则重置为1，最后都要把maxN置为v值
                cntN = (v == maxN) ? cntN + 1 : 1;
                maxN = v;
            }
        }
        int num1 = tasks.size();      // num1为数组长度，num2记录若有空闲时间的总长度，比较两者中较大值即可
        int num2 = (maxN - 1) * (n + 1) + cntN;   // 核心计算公式！！！
        return max(num1, num2);
    }
};
