法1：遍历法，看评论没看懂，本意应该是难一点的，否则是弱智题
时间O(10^N)  空间O(1)不包括给定返回数组
执行用时：8 ms, 在所有 C++ 提交中击败了64.40% 的用户
内存消耗：11.2 MB, 在所有 C++ 提交中击败了36.87% 的用户
class Solution {
public:
    vector<int> printNumbers(int n) {
        vector<int> res;
        if(n <= 0) return res;
        int a = pow(10, n);
        for(int i = 1; i < a; i++)
        {
            res.push_back(i);
        }
        return res;
    }
};

法2：当考虑大数时，有可能会越界，所以原题应该是返回字符串类型string，利用递归法dfs
就不在题目的主函数中写了，在这里留作思考即可
时间O(10^N)  空间O(N)即递归深度，不包括给定返回字符串
class Solution {
public:
    string res;
    string printNumbers(int n) {            // 注意我把原题中的vector<int>返回类型改写成了返回string字符串类型！
        string temp(n, '0')                 // 初始temp字符串为n个'0'，依次修改temp[0]的字符值，例：n = 3， 从 000 到 100 200 到 900 进入递归
        dfs(temp, n, 0);
        return res;
    }
    void dfs(string& temp, int length, int pos)
    {
        if(pos == length)                  // 注意递归退出条件，当前数组位置超过数组长度时，存储当前字符串
        {
            saveNumber(temp);
            return;                         
        }
        for(int i = 0; i <= 9; i++)
        {
            s[pos] = i + '0';               // 注意利用数值初始化字符串的方法，加'0'即可
            dfs(temp, length, pos + 1);
        }
    }
    
    void saveNumber(string temp)          // 这个函数的作用仅仅是将temp存储到最终的res字符串中，无需修改temp，因此不需要引用参数
    {
         bool isZero = false;               // 设置布尔量判断前几位是否为零，若为零则不需要加入到字符串中，如"000"完全不加入，"001"前两位不加，"078"，前一位不加
         string s;
         for(int i = 0; i < temp.size(); i++)
         {
            if(!isZero && temp[i] != '0')   isZero = true;
                                            // 当标志位为false且temp当前位不为0时才置为true，当为true时加入到临时字符串s中，故"000"不改变任何值
            if(isZero)    s += temp[i];
         }
         if(!s.empty())                     // 只有为"000"时，s才为空，此时更新res字符串
         {
            res += s;
         }
    }
};
