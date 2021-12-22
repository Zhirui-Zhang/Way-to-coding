法1：DP动态遍历法+哈希表
执行用时：12 ms, 在所有 C++ 提交中击败了71.62% 的用户
内存消耗：8.1 MB, 在所有 C++ 提交中击败了67.74% 的用户
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.empty())   return 0;   //判断空可省略
        unordered_map<char, int> un_map;
        int res = 0, temp = 0, n = s.size();
        for(int i = 0; i < n; i++)
        {
            char c = s[i];
            int j;
            if(un_map.find(c) == un_map.end())    j = -1;
            else    j = un_map[c];    //j表示查找字符c上一次出现的位置，如果之前不存在，置为-1
            un_map[c] = i;  //更新哈希表c的位置
            if(temp >= i - j)    temp = i - j;
            else    temp++ ;
            res = max(temp, res);
        }
        return res;
    }
};

法1优化版
执行用时：4 ms, 在所有 C++ 提交中击败了97.54% 的用户
内存消耗：8.1 MB, 在所有 C++ 提交中击败了69.75% 的用户
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> un_map;
        int res = 0, temp = 0, n = s.size();
        for(int i = 0; i < n; i++)
        {
            char c = s[i];
            int j;
            j = (un_map.find(c) == un_map.end()) ? -1 : un_map[c];
            un_map[c] = i;  //更新哈希表c的位置
            temp = (temp < i - j) ? temp + 1 : i - j;   //如果temp < i - j说明当前最长字符串延长了，故+1，否则说明中途断了，temp回到i-j，res保持不变即可
            res = max(temp, res);
        }
        return res;
    }
};

法2：双指针+哈希表
执行用时：16 ms, 在所有 C++ 提交中击败了56.13% 的用户
内存消耗：8.2 MB, 在所有 C++ 提交中击败了41.85% 的用户
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> un_map;
        int pre = -1, res = 0, n = s.size();    // 注意pre初始为-1，便于计算第一个字符长度
        for(int cur = 0; cur < n; cur++)
        {
            char c = s[cur];
            if(un_map.find(c) != un_map.end())  pre = max(pre, un_map[c]);  
            //注意这里要取max值，保证pre为最邻近的位置，反例 "abba" 当cur=3时，pre=1而un_map[a]=0，若pre取un_map[a]结果为3错误
            un_map[c] = cur;  //更新哈希表c的位置
            res = max(res, cur-pre);
        }
        return res;
    }
};
