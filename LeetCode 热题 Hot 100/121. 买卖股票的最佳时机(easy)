法1：DP法，维护两个变量即可，一个取min，一个取max
时间O(N)  空间O(1)
执行用时：96 ms, 在所有 C++ 提交中击败了80.94% 的用户
内存消耗：91.2 MB, 在所有 C++ 提交中击败了42.52% 的用户
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int res = 0, temp = INT_MAX;
        for(auto price : prices)
        {
            temp = min(price, temp);
            res = max(res, price - temp);
        }
        return res;
    }
};
