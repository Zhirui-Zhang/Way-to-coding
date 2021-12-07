法1：从头依次遍历法，自己想蒙圈了，看题解写出来的，考虑情况很多，容易迷糊，而且答案写的是有限状态自动机，我也没看懂，这道题就这样吧，太恶心人了，过一遍得了
时间O(N)  空间O(1)
执行用时：8 ms, 在所有 C++ 提交中击败了39.02% 的用户
内存消耗：5.9 MB, 在所有 C++ 提交中击败了83.61% 的用户
class Solution {
public:
    bool isNumber(string s) {
        int index = 0, n = s.size();
        bool eExist = false, dotExist = false, opExist = false, numExist = false;    // 依次为判断'e/E' '.' '+/-' '0-9'是否已经出现的标志位
        while(index < n && s[index] == ' ')    index++;                   // 跳过首部的空格
        for(; index < n; index++)
        {
            if(s[index] >= '0' && s[index] <='9')    numExist = true;     // 如果出现数字，将数字标志位置为true
            else if(s[index] == 'e' || s[index] == 'E')                   // 如果出现e/E，必须保证前面有数字位，并且后面也是数字位（且为整数），所以将eExist置为true，其他置为false
            {                                                             // 同时e/E具有唯一性
                if(numExist == false || eExist == true)    return false;  
                eExist = true;
                dotExist = false;
                opExist = false;
                numExist = false;
            }
            else if(s[index] == '+' || s[index] == '-')                    // 如果出现 + - 号，必须保证前一位不能是数字，也不能是dot，只能是空格或者e/E
            {
                if(numExist == true || dotExist == true)    return false;
                opExist = true;
            }
            else if(s[index] == '.')                                        // 如果出现 dot '.'   至少保证前后有一位数字
            {
                if(dotExist == true || eExist == true)    return false;     // 若已经出现过dot或者e/E，因为dot的唯一性 && e/E的后面不能有dot，只能为整数，因此返回false
                dotExist = true;
            }
            else if(s[index] == ' ')    break;                              // 如果出现空格，跳出循环
            else return false;                                              // 如果出现其他符号，返回false
        }
        while(index < n && s[index] == ' ')    index++;                     // 跳过尾部的空格
        return numExist && index == n;                                      // 最后返回是否存在数字&&数组已经遍历完成，若数字位为空或者未遍历完即退出说明该字符串不表示数值
    }
};
