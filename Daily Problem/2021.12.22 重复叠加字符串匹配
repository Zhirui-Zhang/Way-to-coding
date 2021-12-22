法1：利用string中find函数的性质，find()返回值是子串在母串中的位置（下标记录），如果没有找到，那么会返回一个特别的标记 npos 。（返回值可以看成是一个 int 型的数）
时间O(N(M/N+1))find函数的复杂度+添加a的次数？结果存疑，find函数的复杂度是多少？  空间O(N(M/N+1))temp存储b长度的变量
执行用时：4 ms, 在所有 C++ 提交中击败了86.50% 的用户
内存消耗：6.6 MB, 在所有 C++ 提交中击败了78.84% 的用户
class Solution {
public:
    int repeatedStringMatch(string a, string b) {
        string temp = a;
        int n1 = a.size(), n2 = b.size();
        int num = n2 / n1 + 2;      // 理解这里很关键，也就是说b最多存放a的次数为n2/n1+2次，头尾各多一次，例 a="abcd"n1=4 b="dabcda"n2=6
        for(int i = 1; i <= num; i++)
        {
            if(temp.find(b) != -1)  // 当temp中有b时说明添加次数合适，返回次数i
            {
                return i;
            }
            else
            {
                temp += a;          // 当temp中没有b时，继续重叠字符串a
            }
        }
        return -1;
    }
};

法2：KMP算法，等我好好学学再来写这道题
