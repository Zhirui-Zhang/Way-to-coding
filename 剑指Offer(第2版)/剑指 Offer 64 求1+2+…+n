法1：递归，运用&&运算符
执行用时：0 ms, 在所有 C++ 提交中击败了100.00% 的用户
内存消耗：6.2 MB, 在所有 C++ 提交中击败了17.41% 的用户
class Solution {
public:
    int sumNums(int n) {
        n && (n += sumNums(n-1));     //该表达式重点在于递归改变了n的值大小
        return n;
    }
};

法2：math函数  n*(n+1)/2.
执行用时：0 ms, 在所有 C++ 提交中击败了100.00% 的用户
内存消耗：5.9 MB, 在所有 C++ 提交中击败了83.25% 的用户
class Solution {
public:
    int sumNums(int n) {
        int res = pow(n, 2) + n;
        return res >> 1;
    }
};
