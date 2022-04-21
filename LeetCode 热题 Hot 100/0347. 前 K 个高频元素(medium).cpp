法1：哈希+快排法，自我感觉复杂度不满足要求，结果还挺好，期待优化方案
时间最坏O(NlogN)为每个元素只出现一次，此时K=N，在第一句特殊情况中已考虑  空间O(N)
执行用时：4 ms, 在所有 C++ 提交中击败了99.85% 的用户
内存消耗：13.3 MB, 在所有 C++ 提交中击败了65.10% 的用户
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        if(k == nums.size())    return nums;
        vector<int> res;
        unordered_map<int, int> un_map;   // 哈希表记录每个数组出现的次数
        for(auto num : nums){
            un_map[num]++;
        }
        vector<pair<int, int>> temp;      // temp里面存放哈希表中的数值对
        for(auto [k, v] : un_map){
            temp.push_back({k, v});
        }
        sort(temp.begin(), temp.end(), [](auto x, auto y){return x.second > y.second;});  // 按照出现次数排序
        for(int i = 0; i < k; ++i){       // 放入频率最高的前K个元素
            res.push_back(temp[i].first);
        }
        return res;
    }
};

法2：小顶堆，优先队列法，其实就是TopK问题的小顶堆，只不过堆里面存放的是pair类型，注意下比较方式即可，重点注意queue的写法以及cmp为static类型！！！
时间O(NlogK)  空间O(N)
执行用时：16 ms, 在所有 C++ 提交中击败了45.49% 的用户
内存消耗：13.4 MB, 在所有 C++ 提交中击败了34.60% 的用户
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> res;
        unordered_map<int, int> un_map;
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(&cmp)> q(cmp);      // 注意写法！！！
        for(auto num : nums){
            un_map[num]++;
        }
        for(auto [key, val] : un_map){
            if(q.size() == k){
                if(q.top().second < val){
                    q.pop();
                    q.push({key, val});
                }
            }
            else{
                q.push({key, val});
            }
        }
        while(!q.empty()){
            res.push_back(q.top().first);
            q.pop();
        }
        return res;
    }

private:
    static bool cmp(pair<int, int>& x, pair<int, int>& y){
        return x.second > y.second;
    }
};

定义时还可以写成类的形式，然后重载小括号运算符，直接传入q的第三个参数即可
struct cmp
{
    bool operator()(pair<int, int>& a, pair<int, int>& b){ return a.second > b.second; }
};
之后
priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> q;
