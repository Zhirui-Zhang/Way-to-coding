法1：回溯（递归）法，返回条件不太好想，应当左括号多于总数n or 右括号多于总数n or 右括号数多于左括号数时返回，当左右相等且==n时存储该字符串
时间O(N)时间不对，可能是2^N级别  空间O(N)递归深度为2n
执行用时：0 ms, 在所有 C++ 提交中击败了100.00% 的用户
内存消耗：14.9 MB, 在所有 C++ 提交中击败了18.19% 的用户
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        dfs(temp, n, 0, 0);    
        return res;                                                                      
    }
private:
    vector<string> res;
    string temp;
    void dfs(string temp, int n, int left, int right)   // left right 分别表示左括号( 和 右括号) 的出现个数
    {
        if(right > left || left > n || right > n)    return;    // 注意返回条件，其中right > left是防止右括号出现在左括号前面，其实 right > n 可以省略
        if(left == right && left == n)          // 存储条件
        {
            res.push_back(temp);
            return;
        }
        dfs(temp + '(', n, left + 1, right);
        dfs(temp + ')', n, left, right + 1);
    }
};
