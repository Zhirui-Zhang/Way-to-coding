法1：累加法即可
执行用时：0 ms, 在所有 C++ 提交中击败了100.00% 的用户
内存消耗：5.8 MB, 在所有 C++ 提交中击败了65.69% 的用户
class Solution {
public:
    int totalMoney(int n) {
        int week = n / 7, day = n % 7;
        int total = 0;
        for(int i = 1; i <= week; ++i)
        {
            total += (i + 3) * 7;
        }
        for(int i = 1; i <= day; ++i)
        {
            total += week + i;
        }
        return total;
    }
};
