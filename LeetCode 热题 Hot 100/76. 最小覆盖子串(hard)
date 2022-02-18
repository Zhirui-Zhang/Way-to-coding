法1：双指针+滑动窗口，思路比较重要，设置两个哈希表，一个存储s，一个存储t，hashT不变，对s设置双指针遍历
采用例1 s = "ADOBECODEBANC"  t = "ABC"
时间O(N)  空间O(C)C为哈希表中存储的字符集大小，最多也就为所有大小写字母加起来52个
执行用时：24 ms, 在所有 C++ 提交中击败了46.77% 的用户
内存消耗：8.2 MB, 在所有 C++ 提交中击败了21.58% 的用户
class Solution {
public:
    string minWindow(string s, string t) {
        string res;
        int len = 0;
        unordered_map<char, int> hashS, hashT;
        for(auto c : t)    hashT[c]++;    // 第一遍记录t中所有值的出现次数，以后hashT就不变了
        for(int i = 0, j = 0; i < s.size(); ++i)    // 设置双指针，都为单调递增指针
        {
            hashS[s[i]]++;                // 先对当前字符哈希表值+1
            if(hashS[s[i]] <= hashT[s[i]])    len++;    // 若+1后仍 <= hashT，说明尚未包含t中的所有元素，令len++   例中len首次等于3时，j~i为"ADOBEC"
            while(hashS[s[j]] > hashT[s[j]])    // 此处为滑动窗口，若左指针哈希值大于hashT说明t中元素出现重复，应滑动左指针至合适位置，可简写成 hashS[s[j++]]--
            {
                hashS[s[j]]--;            // 例中首次滑动出现在 j~i 为 "ADOBECODEBA"  此时j应移动至"CODEBA"
                j++;
            }
            if(len == t.size())     // 当存储长度len为t.size()时说明 j 到 i 的子串中已包含t中所有的元素，视情况当res为空或长度小于res的值时更新res
            {
                if(res.empty() || i-j+1 < res.size())    res = s.substr(j, i-j+1);
            }
        }
        return res;
    }
};
