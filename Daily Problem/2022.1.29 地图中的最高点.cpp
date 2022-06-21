法1：BFS，模板题怎么都没想到啊，在原数组中修改，第一遍记录水坑位置，改为0，入队，其他的记为-1，表示未访问过，随后BFS每次高度+1，注意模板的写法！
时间O(MN)  空间O(1)
执行用时：256 ms, 在所有 C++ 提交中击败了95.20% 的用户
内存消耗：105.4 MB, 在所有 C++ 提交中击败了94.40% 的用户

vector<vector<int>> dist{{1, 0}, {-1, 0}, {0, 1}, {0, -1}};    // 这里四个方向数组的写法，很常用！！！
class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        int m = isWater.size(), n = isWater[0].size();
        queue<pair<int, int>> q;    // q的类型为pair，表示方法为first 和 second
        for(int i = 0; i < m; ++i)
        {
            for(int j = 0; j < n; ++j)
            {
                if(isWater[i][j] == 1)
                {
                    isWater[i][j] = 0;
                    q.push(make_pair(i, j));       // 入队的写法  make_pair(i, j)
                }
                else    isWater[i][j] = -1;   // 这里陆地记为-1的目的是之后遍历时用来确认是否已经访问过
            }
        }
        int height = 1;   // 第一轮初始高度，每次遍历后高度+1
        while(!q.empty())
        {
            int size = q.size();
            while(size--)   // 遍历这一轮高度为1的所有点，再height++
            {
                auto p = q.front();     // p的类型为 pair<int, int>
                for(auto& d : dist)      // d的类型为 vector<int> 长度为2，且要用&，避免拷贝构造浪费大量时间
                {
                    int x = p.first + d[0], y = p.second + d[1];    // 注意这里pair类型的写法！
                    if(x >= 0 && x < m && y >= 0 && y < n && isWater[x][y] == -1)   // 最后还要加上是否已经访问过即该点值是否为-1 
                    {
                        isWater[x][y] = height;     // 更新为这一轮的统一高度
                        q.push(make_pair(x, y));    // 再次入队
                    }
                }
                q.pop();    // 出队
            }
            height++;       // 下一轮高度+1
        }
        return isWater;
    }
};
