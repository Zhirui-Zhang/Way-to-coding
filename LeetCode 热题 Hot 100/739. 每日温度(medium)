法1：单调栈法，从后向前遍历并不难，注意边界条件为>=，表示如果温度相等时不满足严格升高，也要出栈
时间O(N)  空间(N)
执行用时：128 ms, 在所有 C++ 提交中击败了84.26% 的用户
内存消耗：83.1 MB, 在所有 C++ 提交中击败了80.84% 的用户
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> res(n, 0);
        stack<int> s;
        for(int i = n - 1; i >= 0; --i){      // 倒序遍历
            while(!s.empty() && temperatures[i] >= temperatures[s.top()]){
                s.pop();                      // 当栈不为空且当前温度>=栈顶元素时出栈，寻找下一个较大的温度
            }
            res[i] = s.empty() ? 0 : s.top() - i;   // 若为空说明不存在该温度，置0，否则用栈顶元素相减即可
            s.push(i);                        // 每一次遍历都将当前下标入栈
        }
        return res;
    }
};
