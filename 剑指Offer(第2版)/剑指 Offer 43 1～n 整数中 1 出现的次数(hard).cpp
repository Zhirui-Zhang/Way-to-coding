法1：DFS 加 DP两种方法结合，DP数组用来存放dp[digit]表示digit位数字共出现多少次1，递归用来计算从digit-1位到n之间增加了多少个1的数量
时间O(logN)最多10位数字  空间O(logN)两个数组最多10位，递归深度也是最多为10，可惜空间消耗不太满意，有待改进
执行用时：0 ms, 在所有 C++ 提交中击败了100.00% 的用户
内存消耗：6.1 MB, 在所有 C++ 提交中击败了7.56% 的用户
class Solution {
public:
    int countDigitOne(int n) {
        if(n <= 9)    return 1;                                         // 当n为两位数字以上时再进入主程序
        int digit = 1;                                                  // digit表示n的位数。例526的digit=3
        int temp = n;
        while(temp /= 10)    digit++;
        vector<int> dp(digit + 1, 0);                                   // dp存储digit位共含有多少个1，如1位含1个，2位0-99含20个，3位0-999含300个
        vector<int> num(digit + 1, 0);                                  // num记录每一位上的数字，长度都设置digit+1，便于表示
        int base = 10;
        dp[1] = 1;
        num[1] = n % 10;
        n /= 10;
        for(int i = 2; i < dp.size() - 1; i++)                          // 循环求dp和num数组的数值，至第digit-1位，否则base和dp数组会发生溢出
        {                                                               // dp[0 1 20 0]    num[0 6 2 5]
            dp[i] += dp[i-1]  * 10 + base;
            base *= 10;
            num[i] = n % 10;
            n /= 10;
        }
        num[digit] = n % 10;
        int res = dfs(dp, num, base, digit);                            // dfs递归计算digit-1位到数字n之间1出现的个数
        return res;
    }
    int dfs(vector<int>& dp, vector<int>& num, int base, int digit)
    {
        if(digit == 0)    return 0;                                     // 退出条件，位数为0
        if(num[digit] == 1)                                             // 当前位数字为0或1时需特殊处理，>1时一般处理即可
        {
            int temp1 = pow(10, digit-1), temp2 = pow(10, digit-1); 
            int i = digit;
            while(--i)
            {
                temp2 += num[i] * pow(10, i-1);                         // temp2记录当前数字，temp1记录10^digit-1，相减得到两者之间存在的1次数
            }
            return temp2 - temp1 + 1 + dp[digit - 1] + dfs(dp, num, base / 10, digit - 1);
        }
        if(num[digit] == 0)    return dfs(dp, num, base / 10, digit - 1); // ==0时，后面直接省略，dfs即可
        else
        {
            return base + num[digit] * dp[digit - 1] + dfs(dp, num, base / 10, digit - 1);  // >1时需100+5*20+10+2*1+1，即分割成0~499+500~519+520~526
        }
    }
};

法2：找规律，实在不好想，我还是老老实实dp吧
digit表示当前位数，依次为1 10 100，high为digit之前的数值，low为之后的，cur为个位上的数，如当n=526 digit=10时，high=5 low=6 cur=2
时间O(logN) 空间O(1)
class Solution {
public:
    int countDigitOne(int n) {
        long digit = 1; // digit 需为 long 型，因为比如 n 是 INT_MAX，digit 会在最后一次循环越界
        int high = n / 10, cur = n % 10, low = 0;       // 初始high=52 cur=6 low=0 digit=1
        int res = 0;

        while (high != 0 || cur != 0) {                // 退出迭代条件
            if (cur == 0) {
                res += high * digit;
            }
            else if (cur == 1) {
                res += high * digit + low + 1;
            }
            else {
                res += (high + 1) * digit;              // 例 526 中 res = (52+1)*1+(5+1)*10+(0+1)*100
            }

            low += cur * digit;
            cur = high % 10;
            high /= 10;
            digit *= 10; 
        }

        return res;
    }
};
