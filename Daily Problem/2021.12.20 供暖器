法1：类似双指针法，先对两数组进行排序，确保距离最小的值相邻，之后遍历依次记录每个houses和heaters之间的最小值，最后取整个数组的最大值
时间O(M+N)和O(MlogM + NlogN)中的max，应是O(MlogM + NlogN)   空间O(logM + logN)和O(N)dist数组占O(N) 中的max
执行用时：60 ms, 在所有 C++ 提交中击败了37.06% 的用户
内存消耗：25.1 MB, 在所有 C++ 提交中击败了5.08% 的用户
class Solution {
public:
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        int n = houses.size(), m = heaters.size(), pos = 0, res = 0;
        sort(houses.begin(), houses.end());
        sort(heaters.begin(), heaters.end());
        vector<int> dist(n, INT_MAX);       // dp数组，记录每个每个houses与heaters之间的最小值
        for(int i = 0; i < n; ++i)
        {
            for(int j = pos; j < m; ++j)    // 这里j要从上一次最小的pos开始，减少一部分工作量
            {
                int temp = abs(houses[i] - heaters[j]);
                if(temp <= dist[i])         // 若值小于，更新dist数组，并记录下一次起始位置pos
                {
                    dist[i] = temp;
                    pos = j;
                }
                else
                {
                    break;
                }
            }
        }
        for(int i = 0; i < n; ++i)          // 取dist数组中的最大值
        {
            res = dist[i] > res ? dist[i] : res;
        }
        return res;
    }
};

自我改进版：取消dist数组的空间，而是每次i循环结束时更新res为节点最大值
时间O(MlogM + NlogN)  空间O(logM + logN)
执行用时：48 ms, 在所有 C++ 提交中击败了75.54% 的用户
内存消耗：24.7 MB, 在所有 C++ 提交中击败了27.66% 的用户
class Solution {
public:
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        int n = houses.size(), m = heaters.size(), pos = 0, res = 0;
        sort(houses.begin(), houses.end());
        sort(heaters.begin(), heaters.end());
        for(int i = 0; i < n; ++i)
        {
            int temp = abs(houses[i] - heaters[pos]);
            for(int j = pos + 1; j < m; ++j)
            {
                int dist = abs(houses[i] - heaters[j]);
                if(dist <= temp)
                {
                    temp = dist;
                    pos = j;
                }
                else break;
            }
            res = max(temp, res);
        }
        return res;
    }
};

优化版：不用dist数组记录每个节点，而是每个遍历时取min max的值
时间O(MlogM + NlogN)  空间O(logM + logN)
class Solution {
public:
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        sort(houses.begin(), houses.end());
        sort(heaters.begin(), heaters.end());
        int ans = 0;
        for (int i = 0, j = 0; i < houses.size(); i++) {
            int curDistance = abs(houses[i] - heaters[j]);
            while (j < heaters.size() - 1 && abs(houses[i] - heaters[j]) >= abs(houses[i] - heaters[j + 1])) {
                j++;
                curDistance = min(curDistance, abs(houses[i] - heaters[j]));
            }
            ans = max(ans, curDistance);
        }
        return ans;
    }
};
