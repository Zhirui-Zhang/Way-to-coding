法1：哈希表，自己做的，就是字典树，每个哈希表存储首字符，后面挂一个vector<string>数组，每次find一边即可
时间O(NM)N为放入单词的个数，M为每个单词的长度，查找比较时会用到  空间O(26*M*N)
执行用时：120 ms, 在所有 C++ 提交中击败了7.54% 的用户
内存消耗：24.7 MB, 在所有 C++ 提交中击败了98.29% 的用户
class Trie {
private:
    unordered_map<char, vector<string>> un_map;
public:
    Trie() {

    }
    
    void insert(string word) {   
        un_map[word[0]].push_back(word);
    }
    
    bool search(string word) {
        char i = word[0];
        return un_map.find(i) != un_map.end() && find(un_map[i].begin(), un_map[i].end(), word) != un_map[i].end();
    }
    
    bool startsWith(string prefix) {
        char i = prefix[0];
        if(un_map.find(i) != un_map.end())
        {
            for(auto word : un_map[i])
            {
                int j = 1;
                for(; j < word.size() && j < prefix.size(); ++j)
                {
                    if(word[j] != prefix[j])    break;
                }
                if(j == prefix.size())    return true;
            }
        }
        return false;
    }
};

法2：字典树/前缀树，和我的解法不太一样，思考一样，注意若担心内存泄漏问题可使用智能指针
时间O(M)M为每次插入的字符串长度，N为插入单词的个数  空间O(26*M*N)
执行用时：56 ms, 在所有 C++ 提交中击败了60.78% 的用户
内存消耗：44 MB, 在所有 C++ 提交中击败了62.05% 的用户
class Trie {
private:
    bool isEnd; 
    Trie* next[26];     // 前缀树类中包含一个布尔值（表示该单词到此处完结）以及一个包含26个指针的数组
public:
    Trie() {
        isEnd = false;
        memset(next, 0, sizeof(next));      // 初始化参数，memset就是把26个指针均置为空（NULL），也可用for(int i = 0; i < 26; ++i)  next[i] = NULL;进行置空操作
    }
    
    void insert(string word) {
        Trie* node = this;                  // 回到初始节点，开始遍历
        for (char c : word) {
            if (node->next[c-'a'] == NULL) {    // 若还不存在当前字符，new出来后把node指向这个字符
                node->next[c-'a'] = new Trie();
            }
            node = node->next[c-'a'];       
        }
        node->isEnd = true;                 // 最后别忘把最后的字符处设为true，表示这个单词到此结束
    }
    
    bool search(string word) {
        Trie* node = this;                  // 回到初始节点，开始遍历
        for (char c : word) {
            if (node->next[c - 'a'] == NULL) {
                return false;
            }
            node = node->next[c - 'a'];
        }
        return node->isEnd;                 // 注意不是直接返回true，而是判断已有的单词中到此处是否结束，如已有apple搜索app，应返回false
    }
    
    bool startsWith(string prefix) {
        Trie* node = this;                  // 如果该字符不存在，返回false
        for (char c : prefix) {
            if (node->next[c - 'a'] == NULL) {
                return false;
            }
            node = node->next[c - 'a'];
        }
        return true;                        // 寻找前缀则不用考虑是否到此结束，把prefix单词遍历结束后即可返回true
    }
};
