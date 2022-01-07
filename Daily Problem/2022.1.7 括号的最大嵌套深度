法1：遍历记录当前深度和最大深度即可
时间O(N) 空间O(1)
执行用时：0 ms, 在所有 C++ 提交中击败了100.00% 的用户
内存消耗：6.1 MB, 在所有 C++ 提交中击败了72.25% 的用户
class Solution {
public:
    int maxDepth(string s) {
        int cur = 0, depth = 0;
        for(char c : s)
        {
           if(c == '(')
            {
                ++cur;
                depth = max(depth, cur);
            }
            if(c == ')')
            {
                --cur;
            }
        }
        return depth;
    }
};
