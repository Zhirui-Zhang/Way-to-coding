法1：排序＋哈希表，需要对哈希表存储的内容进一步深入了解，掌握度还是不够
时间O(NKlogK) N为strs的长度，K为str中的字符数，时间复杂度为排序算法的复杂度  空间O(NK)为哈希表存储空间
执行用时：40 ms, 在所有 C++ 提交中击败了25.44% 的用户
内存消耗：20.1 MB, 在所有 C++ 提交中击败了31.90% 的用户
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> res;
        string temp;    // 每次用于复制strs中的str
        unordered_map<string, vector<string>> un_map;   // 注意哈希表的内容，存储类型为字符串数组，即un_map[aet] = {"eat", "tea", "ate"}
        for(auto str : strs)      // 第一次遍历，对每个子串排序后，加入到对应的哈希表中
        {
            temp = str;
            sort(temp.begin(), temp.end());
            un_map[temp].push_back(str);
        } 
        for(auto [k, v] : un_map)     // 第二次遍历，对哈希表中的每个值即vector<string>类型加入到res中
        {
            res.push_back(un_map[k]);
        }
        return res;
    }
};
