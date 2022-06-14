法1：BFS+哈希表，核心思想在于遍历出队字符串的每个字符位，将其改变为26个字母测试是否存在
时间O(26*M*N)M为每个单词长度，N为整个wordList长度  空间O(N)两个哈希表一个队列空间都是O(N)
执行用时：116 ms, 在所有 C++ 提交中击败了48.74% 的用户
内存消耗：15.5 MB, 在所有 C++ 提交中击败了44.18% 的用户
class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> wordSet;      // 可以直接写成(wordList.begin(), wordList.end())的形式
        for (auto word : wordList) {
            wordSet.insert(word);
        }
        if (wordSet.find(endWord) == wordSet.end()) return 0;   // 如果endWord不在集合中，直接返回0
        unordered_map<string, int> visitMap;    // 用一个map记录每个单词是否访问过，如访问过，value表示到这里一共多少步
        visitMap[beginWord] = 1;    // 初始单词步骤设为1
        queue<string> q;            // 利用队列进行BFS
        q.push(beginWord);
        while (!q.empty()) {
            string word = q.front();
            q.pop();
            int len = visitMap[word];   // 记录当前单词长度
            for (int i = 0; i < word.size(); ++i) {     // 遍历每一个字母位置，将其改为26个字母轮换测试是否存在
                string tmpWord = word;
                for (int j = 0; j < 26; ++j) {
                    tmpWord[i] = 'a' + j;
                    if (tmpWord == endWord) return len + 1;     // 如果找到转换单词，返回长度+1
                    if (wordSet.find(tmpWord) != wordSet.end() && visitMap.find(tmpWord) == visitMap.end()) {
                        // wordSet中存在tmpWord，并且tmpWord没有被访问过，则添加访问信息，并将该单词入队
                        visitMap[tmpWord] = len + 1;
                        q.push(tmpWord);
                    }
                }
            }
        }
        return 0;   // 遍历全部单词都未返回说明不存在，返回0
    }
};