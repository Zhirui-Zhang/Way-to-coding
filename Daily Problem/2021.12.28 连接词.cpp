法1：前缀树+dfs+记忆化搜索  根本不想看，算了，毁灭吧，累了
struct Trie {
    bool e; // is end
    vector<Trie*> c;
    Trie() {
        this->c = vector<Trie*>(26, NULL);
        this->e = false;
    }
};

class Solution {
public:
    Trie* t;
    unordered_map<int, unordered_map<int, int>> m;

    void insert(string& w) {
        Trie* cur = t;
        for (auto c: w) {
            if (cur->c[c-'a'] == NULL) cur->c[c-'a'] = new Trie();
            cur = cur->c[c-'a'];
        }
        cur->e = true;
    }

    bool dfs(int pos, string& target, int which) {
        if (m[which][pos] == 1) return false; // which只是为了方便记忆化搜索
        Trie* cur = t; // cur指向trie根节点
        if (pos >= target.size()) return true; // 如果 pos 已经超过单词范围；说明匹配成功
        for (int i = pos; i < target.size(); i++) {
            if (cur->c[target[i]-'a'] == NULL) break; // 如果前缀树上不存在这个字母，说明单词不可能被匹配
            if (cur->c[target[i]-'a']->e) { // 如果当前位置可以被之前某个单词完整匹配
                if (dfs(i+1, target, which)) return true; // 尝试匹配 target[i+1:] 
            }
            cur = cur->c[target[i]-'a']; // 比较trie的下一个节点
        }
        m[which][pos] = 1; // 如果当前单词当前位置开始不可能有解，记录状态，防止重复搜索
        return false;
    }

    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        sort(words.begin(), words.end(), [&](string &a, string &b) {
            return a.size() < b.size();
        });
        vector<string> ans;
        t = new Trie();

        for (int i = 0; i < words.size(); i++) {
            if (words[i] == "") continue;
            if (dfs(0, words[i], i)) {
                ans.push_back(words[i]);
            }
            insert(words[i]);
        }

        return ans;
    }

    
};
