法1：模拟法，并不难，只不过测试用例有几个恶心的容易超时，关键是卡在了下一次遍历的起点
时间O(N)最多只需要遍历两次，第一次到尽头发现还差一站，下次遍历从最后一站开始  空间O(1)
执行用时：72 ms, 在所有 C++ 提交中击败了32.75% 的用户
内存消耗：67.9 MB, 在所有 C++ 提交中击败了14.99% 的用户
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        for (int i = 0; i < n; ++i) {
            if (cost[i] > gas[i]) continue;     // 如果开不到下一站，直接pass
            int oil = gas[i] - cost[i];
            int j = (i + 1) % n;                // 否则从下一站开始测试
            while (j != i) {
                oil += gas[j] - cost[j];
                if (oil < 0) break;             // 如果开不到下一站，退出
                j = (j + 1) % n;
            }
            if (j == i) return i;               // 能环绕，返回下标i
            else if (j < i) break;              // 若还没之前开的远，说明无法到达，退出循环
            else i = j;                         // 否则从下一站开始遍历
        }
        return -1;
    }
};

法2：贪心法，每次累加计算当前剩余油量和总剩余油量
执行用时：60 ms, 在所有 C++ 提交中击败了75.39% 的用户
内存消耗：67.8 MB, 在所有 C++ 提交中击败了44.27% 的用户
时间O(N)  空间O(1)
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size(), res = 0, curOil = 0, totalOil = 0;
        for (int i = 0; i < n; ++i) {
            curOil += gas[i] - cost[i];
            totalOil += gas[i] - cost[i];
            if (curOil < 0) {
                res = i + 1;            // 起始位置更新为i+1
                curOil = 0;             // curSum从0开始
            }
        }
        if (totalOil < 0) return -1;    // 说明无论如何都跑不了一圈
        return res;
    }
};
