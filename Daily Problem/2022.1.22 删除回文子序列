法1：模拟法，脑筋急转弯题，只有两个答案，不用过度了解，若本身为回文，只删除一次，否则先删除所有再删除所有b即可
！需要注意的是原题目是删除子序列，而不是子串！子序列可以是分散的，不改变原串前后顺序即可，而子串必须是连续的原串
时间O(N)  空间O(1)
执行用时：4 ms, 在所有 C++ 提交中击败了5.35% 的用户
内存消耗：6.1 MB, 在所有 C++ 提交中击败了32.10% 的用户
class Solution {
public:
    int removePalindromeSub(string s) {
        int i = 0, j = s.size() - 1;
        while(i <= j)
        {
            if(s[i] != s[j])    return 2;
            ++i;
            --j;
        }
        return 1;
    }
};
