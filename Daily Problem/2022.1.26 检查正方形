法1：哈希表法，注意哈希表的格式，类似二维数组，存储的参数为每个节点的个数
时间O(N)  空间O(1)不算二维数组的空间
执行用时：232 ms, 在所有 C++ 提交中击败了91.48% 的用户
内存消耗：91.8 MB, 在所有 C++ 提交中击败了46.59% 的用户
class DetectSquares {
public:
    DetectSquares() {

    }
    
    void add(vector<int> point) {
        int x = point[0], y = point[1];
        cnt[x][y]++;
    }
    
    int count(vector<int> point) {
        int res = 0, x0 = point[0], y0 =point[1];
        for(auto [k, v] : cnt[x0])
        {
            int y1 = k;   // k就是纵坐标
            if(y1 == y0)    continue;   // 注意等于给定坐标点时应跳过  
            int length = abs(y1-y0);    // 计算边长
            res += v * (cnt[x0+length][y1]*cnt[x0+length][y0]   // v为该点的总个数，乘以满足该点的两侧正方形总数
                      + cnt[x0-length][y1]*cnt[x0-length][y0]);
        }
        return res;
    }
private:
    unordered_map<int, unordered_map<int, int>> cnt;  // 记录所有坐标出现的次数，当二维数组用即可
};
