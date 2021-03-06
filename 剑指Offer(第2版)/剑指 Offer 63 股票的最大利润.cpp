法1：暴力法 复杂度你n^2 无奈的算法...正统方法肯定是动态规划法
执行用时：1764 ms, 在所有 C++ 提交中击败了5.04% 的用户
内存消耗：12.5 MB, 在所有 C++ 提交中击败了73.59% 的用户
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.empty())    return 0;
        int res = 0, n = prices.size();
        for(int i = 0; i < n - 1; i++)
        {
            for(int j = i + 1; j < n; j++)
            {
                if(prices[j] - prices[i] > res)     res = prices[j] - prices[i];
            }
        }
        return res;
    }
};

法2：动态规划法，明明很简单，为什么没想到啊！！假设允许当天买入当天卖出，max_res存储最大利润，min_res存储当前最小值
重点在于max_res min_res的初始值设定
※注意使用max（）  min()自带函数和顺序遍历！※
执行用时：4 ms, 在所有 C++ 提交中击败了89.94% 的用户
内存消耗：12.4 MB, 在所有 C++ 提交中击败了90.05% 的用户
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.empty())    return 0;     //此时可以省略空集判断，若为空，自动跳出循环遍历
        int max_res = 0, min_res = INT_MAX;     //min_res初始值设为无穷大
        for(int price : prices)     //遍历数组
        {
            max_res = max(max_res, price - min_res);
            min_res = min(price, min_res);
        }
        return max_res;
    }
};
