法1：简单暴力法，先判断出来给出的n对应的是几位数字，然后从第一个数字开始依次比较，知道找到对应的数字后逐位取余，得到最终的数字
时间O(N)主要是从num开始一个一个向后加复杂度过高，用二分法会快一点   空间O(1)
执行用时：152 ms, 在所有 C++ 提交中击败了100.00% 的用户
内存消耗：5.8 MB, 在所有 C++ 提交中击败了66.50% 的用户
class Solution {
public:
    int findNthDigit(int n) {
        if(n <= 9)    return n;         // 可以省略
        long i = 1, j = 9;              // 注意需要定义为长整型，否则下面sum += 的部分有可能会溢出
        long sum = 9;
        while(n > sum)                  // 用来确定处于几位数，用i表示
        {
            i++;
            j *= 10;
            sum += i * j;     
        }
        int num = j / 9, res = 0;       // num表示i位数从多少开始，即3位数从100开始
        long left = sum - i * j + 1;    // left表示100中1的位置是190号位置
        while(left <= n)                // 找到n表示数字的后一位数，之后num--
        {
            left += i;
            num++;
        }
        num--;
        while(left - n != 0)            // 逐位取余，得到表示的数字
        {
            res = num % 10;
            num /= 10;
            left--;
        }
        return res;
    }
};

优化版：刚开始想麻烦了，还一个一个向前推进找，根本没必要，已经确定num=100了，可以直接计算长度得到n对应的数字，取余求得相应的位数后求出res即可
时间O(1)计算位数最多8次，后面循环也是最多距离8位   空间O(1)
执行用时：0 ms, 在所有 C++ 提交中击败了100.00% 的用户
内存消耗：5.8 MB, 在所有 C++ 提交中击败了89.68% 的用户
class Solution {
public:
    int findNthDigit(int n) {
        int res;
        long i = 1, j = 9;
        long sum = 9;
        while(n > sum)
        {
            i++;
            j *= 10;
            sum += i * j;     
        }
        int num = j / 9;                                // 举例n = 201，此时i = 3, j = 900, left = 190，前面都一样，这里num = 100，length表示n和left之间的长度，为11
        long left = sum - i * j + 1;
        int length = n - left;
        num += length / i;                              
        int digit = i - length % i;                     // 算出n处num的值，为103，digit为从个位开始的第digit位，此处digit = 1，即103的个位数字，算出res即可
        while(digit--)
        {
            res = num % 10;
            num /= 10;
        }
        return res;
    }
};
