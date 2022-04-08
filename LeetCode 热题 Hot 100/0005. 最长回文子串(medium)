首先介绍回文子串就是正反遍历一样的字符串，暴力法略，时间空间都不好，还可能会超时
法1：动态规划法dp，核心思想构建dp[n][n]数组，只利用一般的长度，初始化对角线上的元素值，之后以长度length=2为起点依次遍历，比较是s[i] s[j]的值，如相等按照上一次的dp[i+1][j-1]情况赋值
时间O(N^2)  空间O(N^2)
执行用时：672 ms, 在所有 C++ 提交中击败了11.75% 的用户
内存消耗：29.4 MB, 在所有 C++ 提交中击败了46.53% 的用户
class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        if(n == 1)    return s;   // 特殊情况考虑
        vector<vector<bool>> dp(n, vector<bool>(n));
        for(int i = 0; i < n; ++i)
        {
            dp[i][i] = true;      // 初始化对角线的元素值，即每个字符本身都是回文子串
        }
        int start = 0, maxLength = 1;   // 设置最后截取字串的起点和长度
        for(int length = 2; length <= n; ++length)  // 字串长度从2到n
        { 
            for(int i = 0; i <= n - length; ++i)    // i的范围可以到n 但没必要  最多遍历到 n-length处
            {
                int j = i + length - 1;           // 对应j的位置
                if(j >= n)    break;              // 如果j越界了，直接退出
                if(s[i] != s[j])    dp[i][j] = false;   // 不等置false
                else                              // 否则判断length是否等于2，等于直接为true，否则根据上一状态值决定
                {
                    if(length == 2)    dp[i][j] = true;
                    else    dp[i][j] = dp[i+1][j-1];
                }
                if(dp[i][j] && length > maxLength)  // 若该字串为true且长度增长，则更新起点和长度
                {
                    start = i;
                    maxLength = length;
                }
            }
        }
        return s.substr(start, maxLength);
    }
};

法2：中心扩展算法，分别考虑单个字符扩展和相邻两个字符向外扩展，取最长的字符串并更新
时间O(N^2)   空间O(1)
执行用时：16 ms, 在所有 C++ 提交中击败了91.43% 的用户
内存消耗：6.8 MB, 在所有 C++ 提交中击败了98.75% 的用户
class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        if(n == 1)    return s;   // 特殊情况考虑
        int start = 0;            //记录回文子串起始位置
        int end = 0;            //记录回文子串终止位置
        int len = 1;             //记录最大回文子串的长度
        for(int i = 0; i < n; i++)
        {
            int len1 = expendaroundcenter(s,i,i);   //一个元素为中心
            int len2 = expendaroundcenter(s,i,i+1); //两个元素为中心
            len = max(max(len1,len2),len);      // 更新len长度
            if(len > end-start+1)               // 若更新成功，再更新start 和 end位置
            {
                start = i - (len-1)/2;      // 注意这里更新计算start和end的方法，由于左侧比右侧长度少1，故计算方式不同
                end = i+len/2;
            }
        }
        return s.substr(start,len);
    }
private:
    int expendaroundcenter(string& s,int left,int right)
    //计算以left和right为中心的回文串长度，返回最长字串长度
    {
        while(left >= 0 && right < s.size() && s[left] == s[right])
        {
            left--;
            right++;
        }
        return right-left-1;        // 注意返回值计算方式，指的是right和left之间的所有元素，不包括两侧
    }
};
