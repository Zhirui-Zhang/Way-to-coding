法1；位运算，逐位比较即可
时间O(logN)  空间O(1)
执行用时：0 ms, 在所有 C++ 提交中击败了100.00% 的用户
内存消耗：5.8 MB, 在所有 C++ 提交中击败了50.40% 的用户
class Solution {
public:
    int hammingDistance(int x, int y) {
        int res = 0;
        while(x || y){
            int a = x & 1;
            int b = y & 1;
            if(a != b){
                res++;
            }
            x >>= 1;
            y >>= 1;
        }
        return res;
    }
};

改进：直接异或就行，这都没想到啊
class Solution {
public:
    int hammingDistance(int x, int y) {
        int s = x ^ y, res = 0;
        while (s) {
            if(s & 1){
              res++;
            }
            s >>= 1;
        }
        return ret;
    }
};

法2：n&n-1啊，直接比较有1的位数就行，我擦又没想起来
class Solution {
public:
    int hammingDistance(int x, int y) {
        int s = x ^ y, ret = 0;
        while (s) {
            s &= s - 1;
            ret++;
        }
        return ret;
    }
};
