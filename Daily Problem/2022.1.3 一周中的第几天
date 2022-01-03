法1：模拟法，算出之前总共多少天，之后根据1971.1.1是星期五推算这一天的星期，方法为(x+3)%7，同时注意2100年不是闰年！
闰年定义：四年一闰；百年不闰，四百年再闰。
时间O(C)  空间O(C)均为常数
执行用时：0 ms, 在所有 C++ 提交中击败了100.00% 的用户
内存消耗：5.9 MB, 在所有 C++ 提交中击败了12.68% 的用户
class Solution {
public:
    string dayOfTheWeek(int day, int month, int year) {
        vector<string> eg = {"Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"};
        vector<int> everyMonth = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30};
        int totalDays = 365 * (year - 1971) + (year - 1969) / 4;
        for(int i = 0; i < month - 1; ++i)
        {
            totalDays += everyMonth[i];
        }
        if(year % 4 == 0 && year % 100 != 0 && month >= 3)    totalDays++;    
        totalDays += day;
        return eg[(totalDays + 3) % 7];
    }
};
