法1：贪心+排序法，有点难度，主要是思考当区间重复时应如何更新start和end，比如前一段完全覆盖后一段的情况以及两段起点相等的情况
时间O(NlogN)  空间O(logN)
执行用时：428 ms, 在所有 C++ 提交中击败了19.55% 的用户
内存消耗：87.7 MB, 在所有 C++ 提交中击败了33.57% 的用户
class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int res = 0, n = intervals.size();
        sort(intervals.begin(), intervals.end(), cmp);          // 按照左端对齐排序
        int start = intervals[0][0], end = intervals[0][1];
        for (int i = 1; i < n; ++i) {
            int x = intervals[i][0], y = intervals[i][1];
            if (start == x || end > x) {                        
                // 当两段起点相同或end大于第二段起点时，一定要删除一段（至于删除前一段or后一段无所谓，不影响）
                // 然后更新end时要取两个范围的min值
                ++res;                  
                end = min(end, y);
            } else {        // 否则说明第二段范围与第一段不重合，无需删除，直接更新start和end即可
                start = x;              
                end = y;
            }
        }
        return res;
    }
private:
    static bool cmp(const vector<int>& x, const vector<int>& y) {
        if (x[0] == y[0]) return x[1] < y[1];
        return x[0] < y[0];
    }
};