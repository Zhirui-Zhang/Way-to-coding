法1：二分查找+字符串哈希法，hard级别的题目，看不懂，复制答案慢慢看吧
时间O(NlogN)二分时间logN * find函数中遍历时长N  空间O(N)unorder_set占空间N
执行用时：688 ms, 在所有 C++ 提交中击败了83.24% 的用户
内存消耗：197.6 MB, 在所有 C++ 提交中击败了81.29% 的用户
class Solution {
public:
    string longestDupSubstring(string s) {
        n = s.size();
        int left = 1;
        int right = n - 1;
        int pos = -1;
        int len = 0;

        while(left <= right) 
        {
            int mid = (left + right) / 2;
            int start = find(mid, s);
            if (start != -1) 
            {
                len = mid;
                pos = start;
                left = mid + 1;
            } else 
            {
                right = mid - 1;
            }
        }

        if (pos == -1) return "";
        else return s.substr(pos, len);
    }

private:
    int n;
    unsigned long long prime = 31;
    int find(int len, string s)
        {
            unsigned long long hash = 0;
            unsigned long long power = 1;
            for (int i = 0; i < len; i++) 
            {
                hash = hash * prime + (s[i] - 'a');
                power *= prime;
            }
            unordered_set<unsigned long long> exist{hash};
            for(int i = len; i < n; i++) 
            {
                hash = hash * prime - power * (s[i-len] - 'a') + (s[i] - 'a');
                if (exist.count(hash)) return (i - len + 1);
                exist.insert(hash);
            }
            return -1;
        };
};
