法1：回溯法，困难题，看懂就行了，也是用回溯法，注意dfs有返回值，且记录结构为哈希表中套map集合，很不好想
时间O(N!)由于找到一条立刻返回，实际远小于N!  空间O(N)递归深度为原数组长度
执行用时：16 ms, 在所有 C++ 提交中击败了83.42% 的用户
内存消耗：13.5 MB, 在所有 C++ 提交中击败了64.57% 的用户
class Solution {
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        vector<string> res;
        for (auto& t : tickets) {
            targets[t[0]][t[1]]++; // 记录映射关系
        }
        res.push_back("JFK"); // 起始机场
        dfs(tickets.size(), res);
        return res;
    }
    
private:
    // unordered_map<出发机场, map<到达机场, 航班次数>> targets  
    // 注意第二个参数map<string, int>中是按字典序存放的到达机场
    // 之所以map中第二个参数不用bool是因为某条航线次数可能大于1，说明可以一条航线可以重复飞多次，故只能用int记录
    unordered_map<string, map<string, int>> targets;
    bool dfs(int ticketNum, vector<string>& res) {
        if (res.size() == ticketNum + 1) {
            // 返回条件，只要满足size == Num + 1即可实现全部机票的重排
            // 由于找到一种顺序即可，该dfs有bool类型的返回值，只要找到一路返回
            return true;
        }
        for (auto& target : targets[res.back()]) {     // 从每个res数组的最后一个元素开始遍历，实现下一张机票的排列
            if (target.second > 0) { 
                // 记录到达机场是否飞过了
                res.push_back(target.first);
                target.second--;
                if (dfs(ticketNum, res)) return true;
                res.pop_back();     // 注意可能会有死循环的情况发生，所以如果上一层dfs为false时应回溯，进行下一次递归
                target.second++;
            }
        }
        return false;
    }
};

