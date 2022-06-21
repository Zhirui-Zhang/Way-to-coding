法1：递归法
时间O(logN)  空间O(logN)
执行用时：0 ms, 在所有 C++ 提交中击败了100.00% 的用户
内存消耗：5.9 MB, 在所有 C++ 提交中击败了19.34% 的用户
class Solution {
public:
    int numberOfSteps(int num) {
        if(num == 0)    return 0;
        if((num & 1) == 1)
        {
            return 1 + numberOfSteps(num-1);
        }
        else
        {
            return 1 + numberOfSteps(num >> 1);
        }
    }
};

法2：迭代法
时间O(logN)  空间O(N)
class Solution {
public:
    int numberOfSteps(int num) {
        int res = 0;
        while(num)
        {
            res++;
            if((num & 1) == 1)    num--;
            else num >>= 1;
        }
        return res;
    }
};
