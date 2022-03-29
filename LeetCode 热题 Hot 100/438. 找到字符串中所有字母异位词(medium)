法1：滑动窗口，自己的暴力哈希表做法超时了，还是得滑动窗口啊，重点是知道了vector也可以直接相等比较？长知识了
时间O(N)  空间O(N)
执行用时：16 ms, 在所有 C++ 提交中击败了42.51% 的用户
内存消耗：8.5 MB, 在所有 C++ 提交中击败了45.51% 的用户
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int n = s.size(), m = p.size();
        if(m > n)    return {};
        vector<int> res;
        vector<int> vs(26, 0), vp(26, 0);     // 其实直接用哈希表也可以，但是不知道哈希表是否可以直接用==比较是否相等？实验验证不可以==比较
        for(int i = 0; i < m; ++i){           // 先遍历p的长度，若相等插入下标0
            vs[s[i]-'a']++;
            vp[p[i]-'a']++;
        }
        if(vs == vp){
            res.push_back(0);
        }
        for(int i = m; i < n; ++i){           // 注意边界条件！！！
            int j = i - m;
            vs[s[j]-'a']--;
            vs[s[i]-'a']++;
            if(vs == vp)    res.push_back(j+1);
        }
        return res;
    }
};

哈希表版本，增加check函数比较是否相等
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int n = s.size(), m = p.size();
        if(m > n)    return {};
        vector<int> res;
        unordered_map<char, int> ms;
        unordered_map<char, int> mp;
        for(int i = 0; i < m; ++i){
            ms[s[i]-'a']++;
            mp[p[i]-'a']++;
        }
        if(check(ms, mp)){
            res.push_back(0);
        }
        for(int i = m; i < n; ++i){
            int j = i - m;
            ms[s[j]-'a']--;
            ms[s[i]-'a']++;
            if(check(ms, mp))    res.push_back(j+1);
        }
        return res;
    }
private:
    bool check(unordered_map<char, int>& ms, unordered_map<char, int>& mp){
        for(auto [k, v] : mp){
            if(ms[k] != v){
                return false;
            }  
        }
        return true;
    }
};
