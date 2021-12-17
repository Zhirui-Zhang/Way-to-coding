easy题  数学公式即可
时间O(B/E)  空间O(1)
执行用时：0 ms, 在所有 C++ 提交中击败了100.00% 的用户
内存消耗：5.9 MB, 在所有 C++ 提交中击败了14.61% 的用户
class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int temp = numBottles % numExchange + numBottles / numExchange;     // temp表示换过一轮酒后剩余空瓶子数量
        int res = numBottles + numBottles / numExchange;                    // res表示换过一轮酒后总数量
        while(temp >= numExchange)                                          // 当空瓶子数大于可换瓶子数时，更新res和temp
        {
            res += temp / numExchange;
            temp = temp  % numExchange + temp / numExchange;
        }
        return res;
    }
};
