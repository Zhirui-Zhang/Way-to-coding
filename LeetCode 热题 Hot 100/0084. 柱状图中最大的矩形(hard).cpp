法1：单调栈，和之前接雨水的题目很像，想的不到位没做出来，属是不应该，注意在原数组的末尾加入一个0，以便于遍历结束后弹出栈中的所有元素并计算之前所有矩形的面积
时间O(N)  空间O(N)
执行用时：112 ms, 在所有 C++ 提交中击败了59.30% 的用户
内存消耗：75.3 MB, 在所有 C++ 提交中击败了14.87% 的用户
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int res = 0;
        heights.push_back(0);   // 尾部加入0
        stack<int> s;
        for(int i = 0; i < heights.size(); ++i)
        {
            while(!s.empty() && heights[s.top()] > heights[i])    // 当前高度小于栈顶元素高度时计算面积，保证为单调递增栈
            {
                int height = heights[s.top()];    // 矩形的高记作height
                s.pop();                                      // 注意这里计算width时不应该用temp = s.top()后 width = i - temp，因为这样并不是该点高度持续值，总之在例中可以看出来
                int width = (s.empty() ? i : i-s.top()-1);    // ！！！矩形的宽记作width，注意当栈为空时说明从头到i都为宽，记作i即可，否则为i-s.top()-1
                res = max(res, height*width);     // 更新res
            }
            s.push(i);    // 每轮遍历后入栈
        }
        return res;
    }
};
