法1：哈希表+DP法，重复题，解法略，可惜第一遍还没完全写出来，真蠢啊
时间O(N)  空间O(N)
执行用时：8 ms, 在所有 C++ 提交中击败了88.06% 的用户
内存消耗：8.2 MB, 在所有 C++ 提交中击败了60.87% 的用户
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int res = 0, temp = 0;      // temp表示当前遍历到的最长子串
        unordered_map<char, int> un_map;
        for(int i = 0; i < s.size(); ++i)
        {
            int j;
            j = (un_map.find(s[i]) == un_map.end()) ? -1 : un_map[s[i]];
            un_map[s[i]] = i;
            temp = (temp < i - j) ? temp + 1 : i - j;   // 注意这里需要比较temp和i - j的大小来判断是否更新temp
            res = max(temp, res);
        }
        return res;
    }
};
