简单，模拟法即可
时间空间均为O(1)
执行用时：20 ms, 在所有 C++ 提交中击败了52.00% 的用户
内存消耗：5.8 MB, 在所有 C++ 提交中击败了61.26% 的用户
class Solution {
public:
    int dayOfYear(string date) {
        int year = stoi(date.substr(0, 4));
        int month = stoi(date.substr(5, 2));
        int day = stoi(date.substr(8, 2));

        int amount[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        if (year % 4 == 0) {
            ++amount[1];
        }

        int ans = 0;
        for (int i = 0; i < month - 1; ++i) {
            ans += amount[i];
        }
        return ans + day;
    }
};
