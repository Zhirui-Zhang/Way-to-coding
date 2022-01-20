法1：博弈论问题，有点超纲了，理解即可，考虑到Alice可以选择模1或者模2先手，也就是可以耍阴招让Bob必败
记录每一个数mod3的余数，若==0的为偶数则必须满足模1和模2的数都存在，若==0的为奇数必须满足1比2多3个及以上或者2比1多3个及以上
时间O(N)   空间O(1)
执行用时：148 ms, 在所有 C++ 提交中击败了82.19% 的用户
内存消耗：124.4 MB, 在所有 C++ 提交中击败了53.04% 的用户
class Solution {
public:
    bool stoneGameIX(vector<int>& stones) {
        int cnt0 = 0, cnt1 = 0, cnt2 = 0;
        for (int val: stones) 
        {
            int type = val % 3; 
            if(type == 0)    ++cnt0;
            else if(type == 1)    ++cnt1;
            else ++cnt2;
        }
        if(cnt0 % 2 == 0)    return cnt1 >= 1 && cnt2 >= 1;
        else return (cnt1 - cnt2 >= 3) || (cnt2 - cnt1 >= 3);
    }
};
