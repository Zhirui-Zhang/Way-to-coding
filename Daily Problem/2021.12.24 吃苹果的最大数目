法1：贪心算法+优先队列，思路完全不对，太自闭了，感觉自己根本不适合刷题，又是怀疑人生的一个上午
时间O(NlogN)遍历需要N*每次插入堆中排序logN  空间O(N)
执行用时：180 ms, 在所有 C++ 提交中击败了28.18% 的用户
内存消耗：46.1 MB, 在所有 C++ 提交中击败了35.45% 的用户
核心思想是存入键值对pair<int,int>  根据即将腐烂天数的日期进行排序，先吃快要腐烂的苹果
class Solution {
public:
    int eatenApples(vector<int>& apples, vector<int>& days) {
        // 优先队列priority_queue中pair的比较规则：先比较第一个元素，第一个相等比较第二个，等价于map
        int res = 0, day = 0;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;

        while(day < days.size() || !q.empty())  // 当天数小于长度或者队列不为空时
        {
            if(day < days.size())    q.push(make_pair(day+days[day]-1, apples[day]));   // 如果还在生产苹果，把(过期时间，苹果数量)的pair加入小顶堆
            auto apple = q.top();
            while(apple.first < day)    // 如果当天最老的一批苹果要过期了，弹出堆，判断堆是否空，不空选取下一批要过期的苹果，即q.top()
            {
                q.pop();
                if(q.empty())    break;
                apple = q.top();
            }
            if(q.empty())               // 如果堆空了，今天不吃了，等待下一天生产的苹果
            {
                ++day;
                continue;
            }
            if(apple.second > 0)        // 如果当天有剩余苹果，吃掉一个后判断是否这一批是否还有剩余，若有再重新入堆
            {
                ++res;                  // ※这里很重要，先pop出去修改second的值后再push回来，因为apple=q.top()是一个复制的值，即使修改了也对top()中的值没有影响※
                q.pop();                // 故if(--apple.second <= 0) q.pop(); 语句是错误的，根本pop不出去
                apple.second--;
                if(apple.second > 0)    q.push(apple);
            }
            ++day;
        }
        return res;
    }
};


法2：更改为map实现，同样是根据腐烂天数进行内部排序，复杂度不变，注意map容器既可以用m[1] m[2]访问value值，也可以用迭代器iter->first iter->second访问键值对pair<int, int>
执行用时：116 ms, 在所有 C++ 提交中击败了91.82% 的用户
内存消耗：55.5 MB, 在所有 C++ 提交中击败了5.45% 的用户
class Solution {
public:
    int eatenApples(vector<int>& apples, vector<int>& days) {
        int res = 0, day = 0;
        map<int, int> m;
        while(day < days.size() || !m.empty())
        {
            if(day < days.size())    m[day+days[day]-1] += apples[day];     // 这里不同，需要记录的是同一天中腐烂掉苹果的总数，因为map中不允许m[2]有两个值存在
            while(!m.empty())
            {
                if(m.begin()->first < day || m.begin()->second == 0)    m.erase(m.begin());     // 如果天数已经大于腐烂的时间或者没有苹果存在，删除第一个值
                else                                                                            // 否则吃掉一个苹果并将原容器中的数量-1
                {
                    ++res;
                    --m.begin()->second;
                    break;
                }
            }
            ++day;
        }
        
        return res;
    }
};
