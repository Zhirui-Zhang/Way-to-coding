法1：单调栈法，和496题原理相同，只不过由于题目要求循环，需要在原数组基础上扩展一倍，且res数组需要判断下标是否越界即可
时间O(N)  空间O(N)
执行用时：40 ms, 在所有 C++ 提交中击败了23.09% 的用户
内存消耗：24.4 MB, 在所有 C++ 提交中击败了15.93% 的用户
class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        nums.resize(2 * n);     // 按原数组顺序扩展一倍
        for (int i = n; i < 2 * n; ++i) {
            nums[i] = nums[i - n];
        }
        vector<int> res(n, -1);
        stack<int> s;
        for (int i = 0; i < 2 * n; ++i) {       // 循环下标范围变为 2n
            while (!s.empty() && nums[s.top()] < nums[i]) {
                if (s.top() < n) res[s.top()] = nums[i];    // 注意在修改res数组前需要判断当前下标是否越界
                s.pop();
            }
            s.push(i);
        }
        return res;
    }
};

优化版：其实不用扩展nums数组，循环两次即可完成要求，其中下标采用取余的形式！
时间O(N)  空间O(N)
执行用时：32 ms, 在所有 C++ 提交中击败了61.41% 的用户
内存消耗：23.3 MB, 在所有 C++ 提交中击败了49.60% 的用户
class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n, -1);
        stack<int> s;
        for (int i = 0; i < 2 * n; ++i) {       // 循环下标范围变为 2n
            while (!s.empty() && nums[s.top()] < nums[i % n]) {
                res[s.top()] = nums[i % n];    // 注意在修改res数组前需要判断当前下标是否越界
                s.pop();
            }
            s.push(i % n);
        }
        return res;
    }
};