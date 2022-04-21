法1：逐位&1法，&后逻辑右移一位
时间O(logn)n为数值大小 空间O(1)
执行用时：4 ms, 在所有 C++ 提交中击败了39.53% 的用户
内存消耗：5.9 MB, 在所有 C++ 提交中击败了52.18% 的用户
class Solution {
public:
    int hammingWeight(uint32_t n) {
        int num = 0;
        while(n != 0)
        {
            if(n & 1 == 1)    num++;
            n >>= 1;  //注意这里是1，不是2！！
        }
        return num;
    }
};

法2：n&(n-1)法，每次使n中最右侧的1变为0，减少运算量
时间O(m)m为1的个数  空间O(1)
执行用时：0 ms, 在所有 C++ 提交中击败了100.00% 的用户
内存消耗：5.9 MB, 在所有 C++ 提交中击败了55.57% 的用户
class Solution {
public:
    int hammingWeight(uint32_t n) {
        int num = 0;
        while(n != 0)
        {
            num++;
            n &= n-1;
        }
        return num;
    }
};
