法1：DP法，关键点是每次内循环j从0开始，也就是s中从头开始判断，最后返回dp[n]
时间O(N^2)  空间O(N)
执行用时：12 ms, 在所有 C++ 提交中击败了62.56% 的用户
内存消耗：12.8 MB, 在所有 C++ 提交中击败了58.52% 的用户
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> un_set;   // 哈希表用来查找每个子串是否存在
        int n = s.size();
        for(auto word : wordDict)    un_set.insert(word);
        vector<bool> dp(n+1, false);    // 注意dp数组的长度为n+1，因为s为空时默认返回true
        dp[0] = true;
        for(int i = 1; i < n + 1; ++i)
        {
            for(int j = 0; j < i; ++j)  // j的范围从0到i，dp[i]意为从j开始是否能有子串匹配s.substr(j, i-j)
            {
                if(dp[j] && un_set.find(s.substr(j, i-j)) != un_set.end())
                {
                    dp[i] = true;       // 若能匹配，置为true并break
                    break;
                }
            }
        }
        return dp[n];                   // 最后返回dp[i]
    }
};
