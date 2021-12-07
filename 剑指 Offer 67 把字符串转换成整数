法1：遍历法，注意将res设为long型，以便于后续比较INT_MIN和INT_MAX，如果仍然是int型将发生溢出报错，
时间O(N)  空间O(1) 
执行用时：4 ms, 在所有 C++ 提交中击败了66.77% 的用户
内存消耗：6 MB, 在所有 C++ 提交中击败了92.07% 的用户
class Solution {
public:
    int strToInt(string str) {
        int index = 0, n = str.size();
        long res = 0;
        bool negative = false;        // 记录正负标志位
        while(index < n && str[index] == ' ')    index++;   // 跳过前面的空格
        if(str[index] == '+' || str[index] == '-')          // 跳过第一个+-号，且如果是-号，标志位置为true
        {
            if(str[index] == '-')    negative = true;
            index++;
        }
        for(; index < n; index++)                           // 依次遍历，如果不是0-9之间的数字，break
        {
            if(str[index] >= '0' && str[index] <= '9')
            {
                int num = str[index] - '0';                 // 记录当前的数字位，注意写法  str[index] - '0'
                res = res * 10 + num;
                if(negative)                                // 判断是否越界
                {
                    if(-res < INT_MIN)    return INT_MIN;
                }
                else if(res > INT_MAX)    return INT_MAX;
            }
            else break;
        }
        return negative ? -res : res;                       // 最终输出正or负res
    }
};

法2：不利用long型，因为可能违反题目规定，增加一个溢出判定，同时优化部分代码，减少了分正负判定的部分，都按照INT_MAX判定即可
执行用时：0 ms, 在所有 C++ 提交中击败了100.00% 的用户
内存消耗：6.1 MB, 在所有 C++ 提交中击败了88.66% 的用户
class Solution {
public:
    int strToInt(string str) {
        int index = 0, n = str.size();
        int res = 0;
        bool negative = false;
        while(index < n && str[index] == ' ')    index++;
        if(str[index] == '+' || str[index] == '-')    
        {
            if(str[index] == '-')    negative = true;
            index++;
        }
        for(; index < n; index++)
        {
            if(str[index] >= '0' && str[index] <= '9')
            {
                int num = str[index] - '0';                                     // Ps:int类型值的范围为[-2147483648, 2147483647]
                if((res > INT_MAX / 10) || (res == INT_MAX / 10 && num > 7))    // 这里很关键，溢出判定，取消正负分情况判断，当res > 214748364时，直接返回
                {                                                               // 当 res = 214748364 时判断下一位num大小，若为8or9返回INT_MAX/MIN
                    return negative ? INT_MIN : INT_MAX;
                }
                else res = res * 10 + num;
            }
            else break;
        }
        return negative ? -res : res;
    }
};
