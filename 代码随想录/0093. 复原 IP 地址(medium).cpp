法1：回溯法，判断是否为IP地址需要小心首位为0的情况，其次在处理 '.' 的时候也应注意，其他没有太大的难度
时间O(3^4 * s)  空间O(4)
执行用时：0 ms, 在所有 C++ 提交中击败了100.00% 的用户
内存消耗：6.4 MB, 在所有 C++ 提交中击败了50.89% 的用户
class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        if (s.size() > 12) return {};  // 算是剪枝，若长度大于12，直接返回空集
        dfs(s, 0, 0);
        return res;
    }
private:
    vector<string> res;
    string tmp;
    void dfs(string& s, int start, int num) {
        if (start == s.size()) {        // 当s全部遍历完成时，判断位数是否为4，若是需要去除最后一个'.'，加入res集合后再加回来
            if (num == 4) {
                tmp.pop_back();
                res.push_back(tmp);
                tmp += '.';
            }
            return;
        }
        if (num >= 4) return;           // 若已经大于4位，直接返回下一次递归即可
        for (int end = start; end < s.size() && end <= start + 2; end++) {
            string st = s.substr(start, end - start + 1);   
            if (checkS(st)) {           // 判断当前IP地址是否符合要求
                tmp += st;
                tmp += '.';
                dfs(s, end + 1, num + 1);
                for (int i = 0; i <= end - start + 1; i++) tmp.pop_back();      // 回溯操作，稍微麻烦了点
            }
        }
    }
    bool checkS(string& st) {           // 当多位数字且首位不为0且在范围0~255之间时返回真
        if (st.size() > 1 && st[0] == '0') return false;
        int i = stoi(st);
        if (i >= 0 && i <= 255) return true;
        else return false;
    }
};