两个哈希表，没想到这个复杂度居然可以，题目并不难，统计记录两个哈希表和为0的乘积总和即可
时间O(N^2)  空间O(N^2)
执行用时：188 ms, 在所有 C++ 提交中击败了69.14% 的用户
内存消耗：26.9 MB, 在所有 C++ 提交中击败了5.83% 的用户
class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        int res = 0;
        unordered_map<int, int> m1;
        unordered_map<int, int> m2;
        for (auto n1 : nums1) {
            for (auto n2 : nums2) {
                m1[n1+n2]++;
            }
        }
        for (auto n3 : nums3) {
            for (auto n4 : nums4) {
                m2[n3+n4]++;
            }
        }
        for (auto [k, v] : m1) {
            if (m2.find(-k) != m2.end()) {
                res += m2[-k] * m1[k];
            }
        }
        return res;
    }
};

改进：用一个哈希表就行了，两个空间开销太大，复杂度不变
执行用时：212 ms, 在所有 C++ 提交中击败了37.21% 的用户
内存消耗：23.6 MB, 在所有 C++ 提交中击败了62.39% 的用户
class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        int res = 0;
        unordered_map<int, int> m;
        for (auto n1 : nums1) {
            for (auto n2 : nums2) {
                m[n1+n2]++;
            }
        }
        for (auto n3 : nums3) {
            for (auto n4 : nums4) {
                if (m.find(-n3-n4) != m.end()) {
                    res += m[-n3-n4];
                }
            }
        }
        return res;
    }
};

