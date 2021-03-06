法1：将原字符串数组存储为用分钟表示的数字数组，排序后遍历该数组，计算前后两个相邻的时间差 !最后还要计算第一个元素和最后一个的差值! 即第一个元素加上24h后减去最后一个元素
时间O(NlogN)  空间O(N)
执行用时：12 ms, 在所有 C++ 提交中击败了66.91% 的用户
内存消耗：13.4 MB, 在所有 C++ 提交中击败了32.02% 的用户
class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        vector<int> temp;
        int res = INT_MAX;
        for(auto t : timePoints)
        {
            int hour = stoi(t.substr(0, 2));
            int minute = stoi(t.substr(3, 2));
            temp.push_back(60*hour+minute);
        }
        sort(temp.begin(), temp.end());
        for(int i = 1; i < temp.size(); ++i)
        {
            int diff = temp[i] - temp[i-1];
            if(diff == 0)    return diff;
            res = min(res, diff);
        }
        return min(res, temp[0]+1440-temp[temp.size()-1]);
    }
};

优化：增加一句  if(timePoints.size() > 1440)    return 0;  因为最多只有1440个时间节点，如果多于该数字，一定有重复，返回0即可
