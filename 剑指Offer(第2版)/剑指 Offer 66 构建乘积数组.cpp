法1：建立左右双数组，分别计算由左至右和从右至左的两边遍历，最后将左右数组相乘得到最终数组   a=[1 2 3 4 5]
时间O(N)  空间O(N)
执行用时：24 ms, 在所有 C++ 提交中击败了32.77% 的用户
内存消耗：24.4 MB, 在所有 C++ 提交中击败了31.12% 的用户
class Solution {
public:
    vector<int> constructArr(vector<int>& a) {
        if(a.empty() || a.size() == 1)    return a;  // 特殊情况特殊处理
        int n = a.size();
        vector<int> L(n, 1);
        vector<int> R(n, 1);    // 两个数组均初始化为n个1
        for(int i = 0; i < n-1; i++)    // 注意这里的边界条件,否则容易越界
        {
            L[i+1] = L[i] * a[i];       // 从左往右遍历，L为[1 1 2 6 24]
        }
        for(int i = n-1; i > 0; i--)    // 注意这里的边界条件,否则容易越界
        {
            R[i-1] = R[i] * a[i];       // 从右往左遍历，R为[120 60 20 5 1]
        }
        for(int i = 0; i < n; i++)
        {
            L[i] *= R[i];               // 左右相乘,将最终结果赋值给L数组
        }
        return L;
    }
};

法2：优化后,简化为一个数组b即可
时间O(N)  空间O(1) 此处忽略题中已经需要建立的b数组，故只有一个临时变量temp
执行用时：16 ms, 在所有 C++ 提交中击败了86.60% 的用户
内存消耗：23.9 MB, 在所有 C++ 提交中击败了37.71% 的用户
class Solution {
public:
    vector<int> constructArr(vector<int>& a) {
        if(a.empty() || a.size() == 1)    return a;   // 特殊情况特殊处理
        int n = a.size();
        vector<int> b(n, 1);    // b初始化为n个1
        for(int i = 1; i < n; i++)     // 注意这里的边界条件,否则容易越界
        { 
            b[i] = b[i-1] * a[i-1];    // 一轮过后，数组b为[1 1 2 6 24]
        }
        int temp = 1;
        for(int i = n-2; i >= 0; i--)  // 注意这里的边界条件,否则容易越界
        {
            temp *= a[i+1];
            b[i] *= temp;
        }
        return b;
    }
};
