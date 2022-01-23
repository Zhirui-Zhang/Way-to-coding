法1：哈希表+有序集合，利用multiset容器，特点是可以有序存放重复的元素，如输入[3 1 5 3 4]  s里面存放[1 3 3 4 5]
时间O(logN)是multiset中排序的时间  空间O(N)
执行用时：408 ms, 在所有 C++ 提交中击败了79.51% 的用户
内存消耗：163.4 MB, 在所有 C++ 提交中击败了36.55% 的用户
class StockPrice {
public:
    StockPrice() {
        cur_day = 0;    // 初始化时间戳
    }
    
    void update(int timestamp, int price) {
        cur_day = max(timestamp, cur_day);
        int pre_price = m.count(timestamp) ? m[timestamp]: -1;  // 记录当前天的价格是否需要更新，若不更新记录为一个任意负值
        m[timestamp] = price;
        if(pre_price > 0)   // 若需要更新，先删除原股票价格，注意不可以直接s.erase(pre_price)会报错（原因还不太清楚）总之测试用例11/18
        {
            auto itr = s.find(pre_price);
            if(itr != s.end())    s.erase(itr);
        }
        s.insert(price);    // 插入新价格，容器自动排序
    }
    
    int current() {
        return m[cur_day];  
    }
    
    int maximum() {
        return *s.rbegin();   // 注意rbegin()是逆向的第一个元素，即队尾元素，不同于end()队尾的下一个位置
    }
    
    int minimum() {
        return *s.begin();
    }
private:
    int cur_day;    // 记录当前最大时间戳，注意要在构造函数中再初始化，不建议在类定义时初始化
    unordered_map<int, int> m;  // 记录每个时间戳对应的股票价格，实时更新
    multiset<int> s;    // 先判断是否更新之前的股票，若有更新删除原价格，之后统一插入新价格后对输入的股票进行排序
};
