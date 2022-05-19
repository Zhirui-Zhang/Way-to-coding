法1：贪心法，其实就和合并区间那道题差不多，但是想要巧解确实不容易，可见图片
第一次遍历记录所有字母对应的最大下标，第二次遍历当i == 最大下标时记录res即可
时间O(N)  空间O(26)
执行用时：0 ms, 在所有 C++ 提交中击败了100.00% 的用户
内存消耗：6.4 MB, 在所有 C++ 提交中击败了67.03% 的用户
class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int> res;
        int n = s.size();
        int tmp[26] = {0};
        for (int i = 0; i < n; ++i) {
            tmp[s[i] - 'a'] = i;            // 桶排序，每次更改对应桶的值
        }
        int left = -1, right = 0;           // 令left = -1，便于计算前后边界
        for (int i = 0; i < n; ++i) {
            int j = tmp[s[i] - 'a'];
            right = max(right, j);
            if (i == right) {               // 只有当当前下标i == right对应元素最大下标时，才加入区间res
                res.push_back(right - left);
                left = i;
            }
        }
        return res;
    }
};