法1：属实是有点恶心了，重点放在前两部分吧，练习创建一个邻接矩阵表示有向权重图，后面的BFS看完了解一下吧，整迷糊了都
时间O(ML+Q*(L+M))M为边的数量，Q为询问数量，L为字符串长度  空间O(NL+M)N为点的数量
执行用时：0 ms, 在所有 C++ 提交中击败了100.00% 的用户
内存消耗：8.1 MB, 在所有 C++ 提交中击败了28.18% 的用户
class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        int m = equations.size(), n = queries.size();
        vector<double> res(n, -1.0);

        unordered_map<string, int> un_map;  // 哈希表记录每个字符串对应的节点下标，注意"ab"不是"a*b"的组合
        int num = 0;    // num用于统计一共出现了多少个节点，下面是建立图的节点的过程，每个节点的下标记为num后num++
        for(int i = 0; i < m; ++i){
            string x = equations[i][0], y = equations[i][1];
            if(un_map.find(x) == un_map.end()){     // 例 a/b=2  b/c=3  最后un[a]=0 un[b]=1 un[c]=2 num=3
                un_map[x] = num;
                num++;
            }
            if(un_map.find(y) == un_map.end()){
                un_map[y] = num;
                num++;
            }
        }

        vector<vector<pair<int, double>>> edges(num);    // 下面是建立每两个节点对应边权重的过程，注意每个edge的类型为pair组成的vector
        for(int i = 0; i < m; ++i){                     
            int x = un_map[equations[i][0]], y = un_map[equations[i][1]];
            edges[x].push_back({y, values[i]});
            edges[y].push_back({x, 1.0 / values[i]});
            // 例 a/b=2  下标a=0 b=1 则edges[0]中存(1, 2)表示b*2  edges[1]中存(0, 0.5)表示a*0.5
        }

        for(int i = 0; i < n; ++i){
            string x = queries[i][0], y = queries[i][1];
            if(un_map.find(x) == un_map.end() || un_map.find(y) == un_map.end()){
                continue;        // 若不存在，下一个
            }
            else
            {
                double result = 0;      // 若存在，设除法结果为0
                int ia = un_map[x], ib = un_map[y];
                if(ia == ib){
                    result = 1.0;
                }
                else{
                    queue<int> q;   // 队列q存储每个相关的点
                    q.push(ia);
                    vector<double> temp(num, -1.0);     // 数组temp存放当前乘积值，只有temp[ia]为1.0
                    temp[ia] = 1.0;

                    while(!q.empty() && temp[ib] < 0){   // 循环条件
                        int e = q.front();
                        q.pop();
                        for(auto [k, v] : edges[e]){    // 遍历该节点对应的每条边，更新temp数组的值
                            if(temp[k] < 0){            // 如果当前边对应的乘积值<0，更新该乘积值，并把该节点入队
                                temp[k] = temp[e] * v;
                                q.push(k);
                            }
                        }
                    }
                    result = temp[ib];  // 最后令res等于相应节点的乘积
                }
                res[i] = result;
            }            
        }
        return res;
    }
};
