法1：贪心+排序法，和合并区间的题类似，但是每一次要缩小合并区间，比如[1,6] [2,8]要缩成[2,6]，注意最后返回值res要加上未射爆的一组气球
时间O(NlogN)  空间O(logN)
执行用时：376 ms, 在所有 C++ 提交中击败了79.38% 的用户
内存消耗：87.6 MB, 在所有 C++ 提交中击败了82.59% 的用户
class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        int res = 0, n = points.size();
        sort(points.begin(), points.end(), [](const vector<int>& x, const vector<int>& y){return x[0] < y[0];});
        int start = points[0][0], end = points[0][1];
        for (int i = 1; i < n; ++i) {
            if (end < points[i][0]) {       // 如果end比下个区间的起始都小，令res++，并更新start和end
                ++res;
                start = points[i][0];
                end = points[i][1];
            } else {                        // 否则应缩小相同区间
                start = points[i][0];
                end = min(end, points[i][1]);
            }
        }
        return res + 1;                     // 注意最后还有一组没算上，res应加1
    }
};