法1：单调栈法，和上一道题如出一辙，只不过是统计了每一行的高度数组，输入上道题的函数中求解即可
时间O(MN)外循环为M，内循环为2N，总和为O(MN)  空间O(N)
执行用时：44 ms, 在所有 C++ 提交中击败了48.56% 的用户
内存消耗：13.3 MB, 在所有 C++ 提交中击败了45.38% 的用户
class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int res = 0, m = matrix.size(), n = matrix[0].size();
        vector<int> heights(n, 0);
        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(matrix[i][j] == '0')    heights[j] = 0;
                else heights[j]++;    // 注意如果当前值为1，可以直接继承上一行的值并+1，即使是第一行也同样可以0+1=1
            }
            res = max(res, largestRectangleArea(heights));    // 每一行过后计算当前行最大矩形面积
        }
        return res;
    }
private:
    int largestRectangleArea(vector<int>& heights) {
        int res = 0;
        heights.push_back(0);
        stack<int> s;
        for(int i = 0; i < heights.size(); ++i)
        {
            while(!s.empty() && heights[s.top()] > heights[i])
            {
                int height = heights[s.top()];
                s.pop();
                int width = (s.empty() ? i : i-s.top()-1);
                res = max(res, height*width);
            }
            s.push(i);
        }
        return res;
    }
};
