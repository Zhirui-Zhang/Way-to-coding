法1：遍历模拟法，非常恶心人的简单题，过一遍得了
时间O(N)  空间O(1)
执行用时：0 ms, 在所有 C++ 提交中击败了100.00% 的用户
内存消耗：6.9 MB, 在所有 C++ 提交中击败了60.43% 的用户
class Solution {
public:
    int countValidWords(string sentence) {
        int ans = 0, n = sentence.size();
        string s = sentence;
        for(int i = 0; i < n; i++) 
        {
            if (s[i] == ' ') continue;
            int hyphen = 0;
            int dot = 0;
            bool valid = true;
            while(s[i] != ' ' && i < n) 
            {
                // 不含数字
                if (s[i] <= '9' && s[i] >= '0') valid = false;
                if (s[i] == '-') 
                {
                    // 最多只有一个 划线
                    hyphen++;
                    // 前后必须是字母
                    if (i-1 < 0 || s[i-1] < 'a' || s[i-1] > 'z') valid = false;
                    if (i+1 >= n ||s[i+1] < 'a' || s[i+1] > 'z') valid = false;
                }
                // 分词符号只能有一个
                if (s[i] == '.' || s[i] == '!' || s[i] == ',') 
                {
                    dot++;
                    if (i+1 < n && s[i+1] != ' ') valid =false;
                }
                i++;
            }
            // 合法
            if (valid && dot <= 1 && hyphen <= 1) 
            {
                ans++;
            }
        }
        
        return ans;
    }
};
