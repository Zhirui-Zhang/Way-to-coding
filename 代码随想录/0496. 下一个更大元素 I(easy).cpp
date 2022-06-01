法1：单调栈法，和739每日温度类似，不用管nums1数组，反正都是nums2的子集，直接求每一位对应的下个更大值，存入哈希表中记录即可
时间O(M+N)  空间O(N) M为nums1长度 N为nums2长度
执行用时：4 ms, 在所有 C++ 提交中击败了92.50% 的用户
内存消耗：8.5 MB, 在所有 C++ 提交中击败了67.72% 的用户
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size(), n = nums2.size();
        vector<int> res(m, -1);     // 最终返回数组，先初始化-1，若不存在就不用修改了
        unordered_map<int, int> hashmap;    // 记录nums2中每个元素对应下个更大元素的值
        stack<int> s;               // 单调栈，从栈顶到栈顶为递增数列
        for (int i = 0; i < n; ++i) {
            while (!s.empty() && nums2[s.top()] < nums2[i]) {
                hashmap[nums2[s.top()]] = nums2[i];     // 找到更大值时插入哈希表中
                s.pop();
            }
            s.push(i);      // 每次结束后将下标入栈
        }
        for (int i = 0; i < m; ++i) {       // 遍历nums1，若哈希表中存在更大值，插入res数组中，否则-1不变
            if (hashmap.find(nums1[i]) != hashmap.end()) res[i] = hashmap[nums1[i]];
        }
        return res;
    }
};