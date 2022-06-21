法1：排序法，注意lambda表达式的写法，先按照攻击力降序，防御力升序的顺序严格排列，随后遍历数组，同时记录当前最大防御力的值，比较计算弱角色的个数
时间O(NlogN)排序时间   空间O(logN)排序时间
执行用时：640 ms, 在所有 C++ 提交中击败了37.20% 的用户
内存消耗：139.9 MB, 在所有 C++ 提交中击败了23.19% 的用户
class Solution {
public:
    int numberOfWeakCharacters(vector<vector<int>>& properties) {
        sort(properties.begin(), properties.end(), [](auto& x, auto& y){return x[0] > y[0] || x[0] == y[0] && x[1] < y[1];});    
        // 表达式写法！注意是严格降序，或者相等时按防御力严格升序，比较时不能出现等于情况
        int max_def = INT_MIN;
        int res = 0;
        for(auto p : properties)
        {
            if(p[1] < max_def)    res++;    // 严格小于时才累加，由于攻击力一定小于之前的，若当前角色防御力也小于则为弱角色，+1即可，注意不要加多，是一个弱角色就行
            else    max_def = p[1];
        }
        return res;
    }
};
