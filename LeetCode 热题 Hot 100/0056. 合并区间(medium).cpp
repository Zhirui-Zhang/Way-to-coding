法1：排序法，关键是对intervals中的每个字数组依据首个元素大小进行排序，之后设置哨兵start end记录当前最大范围边界值，如果下一个数组的左边界大于end，则将[start, end]加入res中
例 [1 4] [2 3] [7 8] 处理时start = 1 end = 4 下一轮x = 2 y = 3时均不变  最后再加入[7 8]
时间O(NlogN)  空间O(logN)
执行用时：40 ms, 在所有 C++ 提交中击败了18.78% 的用户
内存消耗：18.4 MB, 在所有 C++ 提交中击败了52.45% 的用户
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> res;
        int n = intervals.size();
        sort(intervals.begin(), intervals.end());   // 依据intervals[i][0]的大小进行排序
     // sort(intervals.begin(), intervals.end(), [](vector<int>& x, vector<int>& y){return x[0] < y[0];});   也可利用lambda表达式精确比较方式
        int start = intervals[0][0], end = intervals[0][1];
        for(int i = 1; i < n; ++i)
        {
            int x = intervals[i][0], y = intervals[i][1];
            if(x > end)   // 仅当 x > 右边界的时候才能确保加入新数组[start, end]，并更新x
            {
                res.push_back(vector<int> {start, end});
                start = x;
            }
            end = max(end, y);    // 否则应每次更新end右边界值
        }
        res.push_back(vector<int> {start, end});    // 最后加入末尾未处理的数组
        return res;
    }
};
